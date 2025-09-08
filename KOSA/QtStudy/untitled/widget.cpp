#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QDateTime>

Widget::Widget(quint16 port, QWidget *parent)
    : QTextEdit(parent)
    , ui(new Ui::Widget)
    , m_port(port)
{
    ui->setupUi(this);
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer, &QTcpServer::newConnection, this, &Widget::onNewConnection);
}

Widget::~Widget( )
{
    stop( );
    delete ui;
    // m_tcpServer는 this의 자식이므로 자동으로 삭제
    // m_clientSockets의 소켓들도 연결 해제 시 deleteLater( )로 처리
}

bool Widget::start( )
{
    if (!m_tcpServer->listen(QHostAddress::Any, m_port)) {
        QString str = QString("Server could not start on port %1 : %2").arg(m_port).arg(m_tcpServer->errorString( ));
        append(str);
        return false;
    }
    QString str = QString("Server started on port %1").arg(m_port);
    append(str);
    return true;
}

void Widget::stop( )
{
    if (m_tcpServer->isListening( )) {
        m_tcpServer->close( );
        append("Server stopped.");
    }
    // 모든 클라이언트 연결 종료
    for (QTcpSocket *socket : std::as_const(m_clientSockets)) {
        socket->disconnectFromHost( );
    }
    // 리스트는 onClientDisconnected에서 비워지므로 여기서 clear( )는 필요하지 않지만
    // 즉시 정리하고 싶다면 socket->deleteLater( ) 후 m_clientSockets.clear( ) 호출 가능
}

void Widget::onNewConnection( )
{
    QTcpSocket *clientSocket = m_tcpServer->nextPendingConnection( );
    if (clientSocket) {
        QString str = QString("New connection from: %1 : %2").arg(                     clientSocket->peerAddress( ).toString( )).arg(clientSocket->peerPort( ));
        append(str);
        connect(clientSocket, &QTcpSocket::readyRead, this, &Widget::onClientReadyRead);
        connect(clientSocket, &QTcpSocket::disconnected, this, &Widget::onClientDisconnected);
        m_clientSockets.append(clientSocket);
    }
}

void Widget::onClientReadyRead( )
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender( ));
    if (!socket) return;

    QByteArray requestData = socket->readAll( );
    QString requestString(requestData);
    QString str = QString("Received from %1 : %2").arg(                                       socket->peerAddress( ).toString( )).arg(socket->peerPort( ));
    append(str);
    str = QString("--- Request --- \n%1--- End Request ---\n").arg(requestString);
    append(str);

    // 매우 간단한 HTTP 요청 파싱
    QStringList requestLines = requestString.split("\r\n");
    if (requestLines.isEmpty( )) {
        socket->disconnectFromHost( );
        return;
    }

    QStringList requestLineParts = requestLines.first( ).split(" ");
    if (requestLineParts.size( ) < 2) { 	// METHOD PATH HTTP/VERSION
        socket->disconnectFromHost( );
        return;
    }

    QString method = requestLineParts.at(0);
    QString path = requestLineParts.at(1);

    if (method == "GET") {
        if (path == "/") {
            QString htmlBody = QString("<h1>Welcome!</h1>"                              "<p>This is a simple Qt HTTP Server.</p><p>Current time: %1</p>")
            .arg(QDateTime::currentDateTime( ).toString(Qt::ISODate));
            sendHtmlResponse(socket, "Qt HTTP Server", htmlBody);
        } else if (path == "/hello") {
            sendTextResponse(socket, "Hello from Qt Server!");
        } else {
            sendNotFoundResponse(socket);
        }
    } else {
        // 다른 메소드는 지원하지 않음 (예: 405 Method Not Allowed)
        // 여기서는 간단히 연결 종료
        sendNotFoundResponse(socket); // 또는 sendMethodNotAllowedResponse(socket);
    }

    // HTTP/1.0 또는 요청에 "Connection: close"가 있는 경우 바로 닫음
    // 여기서는 간단하게 응답 후 바로 연결을 닫는다.
    // 지속적인 연결 (Keep-Alive)을 지원하려면 더 복잡한 처리가 필요
    socket->disconnectFromHost( );
    if (socket->state( ) == QAbstractSocket::UnconnectedState) {
        // 이미 disconnected 슬롯이 호출되었을 수 있음
        m_clientSockets.removeAll(socket);
        socket->deleteLater( );
    }
}

void Widget::onClientDisconnected( )
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender( ));
    if (!socket) return;

    QString str = QString("Client disconnected: %1 : %2").arg(                                      socket->peerAddress( ).toString( )).arg(socket->peerPort( ));
    append(str);
    m_clientSockets.removeAll(socket);
    socket->deleteLater( ); 		// 소켓 객체 안전하게 삭제
}

void Widget::sendHtmlResponse(QTcpSocket *socket, const QString &title,                                                        const QString &body)
{
    QString htmlContent = QString(
                              "<!DOCTYPE html>\n"
                              "<html>\n"
                              "<head>\n"
                              "<meta charset=\"UTF-8\">\n"
                              "<title>%1</title>\n"
                              "</head>\n"
                              "<body>\n"
                              "%2\n"
                              "</body>\n"
                              "</html>"
                              ).arg(title, body);

    QByteArray response;
    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/html; charset=UTF-8\r\n");
    response.append("Content-Length: " + QByteArray::number(htmlContent.toUtf8( ).size( )) + "\r\n");
    response.append("Connection: close\r\n"); 	// 응답 후 연결 닫음 명시
    response.append("\r\n");
    response.append(htmlContent.toUtf8( ));

    socket->write(response);
    append(response);
}

void Widget::sendTextResponse(QTcpSocket *socket, const QString &text)
{
    QByteArray response;
    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/plain; charset=UTF-8\r\n");
    response.append("Content-Length: " +                                 QByteArray::number(text.toUtf8( ).size( )) + "\r\n");
    response.append("Connection: close\r\n");
    response.append("\r\n");
    response.append(text.toUtf8( ));

    socket->write(response);
    append(response);
}

void Widget::sendNotFoundResponse(QTcpSocket *socket)
{
    QString body = "<h1>404 Not Found</h1><p>The requested resource was not found on this server.</p>";
    QString htmlContent = QString(
                              "<!DOCTYPE html>\n"
                              "<html><head><meta charset=\"UTF-8\">"                              "<title>404 Not Found</title></head>\n"
                              "<body>%1</body></html>"
                              ).arg(body);

    QByteArray response;
    response.append("HTTP/1.1 404 Not Found\r\n");
    response.append("Content-Type: text/html; charset=UTF-8\r\n");
    response.append("Content-Length: " +                                  QByteArray::number(htmlContent.toUtf8( ).size( )) + "\r\n");
    response.append("Connection: close\r\n");
    response.append("\r\n");
    response.append(htmlContent.toUtf8( ));

    socket->write(response);
    append(response);
}
