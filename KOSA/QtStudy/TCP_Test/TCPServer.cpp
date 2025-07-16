// ====================
// TCPServer.cpp
// ====================
#include "TCPServer.h"

TCPServer::TCPServer(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
{
    connect(m_server, &QTcpServer::newConnection,
            this, &TCPServer::onNewConnection);
}

TCPServer::~TCPServer()
{
    stopServer();
}

bool TCPServer::startServer(quint16 port)
{
    if (m_server->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port:" << port;
        return true;
    } else {
        qDebug() << "Failed to start server:" << m_server->errorString();
        return false;
    }
}

void TCPServer::stopServer()
{
    if (m_server->isListening()) {
        // 모든 클라이언트 연결 종료
        for (QTcpSocket *client : m_clients) {
            client->disconnectFromHost();
            client->deleteLater();
        }
        m_clients.clear();

        m_server->close();
        qDebug() << "Server stopped";
    }
}

void TCPServer::sendMessageToAll(const QString &message)
{
    QByteArray data = message.toUtf8() + "\n";
    for (QTcpSocket *client : m_clients) {
        if (client->state() == QTcpSocket::ConnectedState) {
            client->write(data);
        }
    }
    qDebug() << "Broadcast message:" << message;
}

void TCPServer::sendMessageToClient(QTcpSocket *client, const QString &message)
{
    if (client && client->state() == QTcpSocket::ConnectedState) {
        QByteArray data = message.toUtf8() + "\n";
        client->write(data);
        qDebug() << "Sent to client:" << message;
    }
}

void TCPServer::onNewConnection()
{
    while (m_server->hasPendingConnections()) {
        QTcpSocket *client = m_server->nextPendingConnection();
        m_clients.append(client);

        connect(client, &QTcpSocket::disconnected,
                this, &TCPServer::onClientDisconnected);
        connect(client, &QTcpSocket::readyRead,
                this, &TCPServer::onDataReceived);

        qDebug() << "New client connected:" << client->peerAddress().toString()
                 << ":" << client->peerPort();
        qDebug() << "Total clients:" << m_clients.size();

        // 환영 메시지 전송
        sendMessageToClient(client, "Welcome to Qt TCP Server!");
    }
}

void TCPServer::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (client) {
        qDebug() << "Client disconnected:" << client->peerAddress().toString();
        removeClient(client);
        client->deleteLater();
    }
}

void TCPServer::onDataReceived()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    while (client->canReadLine()) {
        QByteArray data = client->readLine();
        QString message = QString::fromUtf8(data).trimmed();

        qDebug() << "Received from" << client->peerAddress().toString()
                 << ":" << message;

        // Echo back to sender
        sendMessageToClient(client, "Echo: " + message);

        // 특별한 명령어 처리
        if (message.toLower() == "quit") {
            client->disconnectFromHost();
        } else if (message.toLower() == "broadcast") {
            sendMessageToAll("Broadcast message from " +
                             client->peerAddress().toString());
        }
    }
}

void TCPServer::removeClient(QTcpSocket *client)
{
    m_clients.removeAll(client);
    qDebug() << "Client removed. Total clients:" << m_clients.size();
}


