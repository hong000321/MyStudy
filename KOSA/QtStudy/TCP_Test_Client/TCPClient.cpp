// ====================
// TCPClient.cpp
// ====================
#include "TCPClient.h"

TCPClient::TCPClient(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_heartbeatTimer(new QTimer(this))
    , m_serverPort(0)
{
    connect(m_socket, &QTcpSocket::connected,
            this, &TCPClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected,
            this, &TCPClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead,
            this, &TCPClient::onDataReceived);
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
            this, &TCPClient::onErrorOccurred);

    // 하트비트 타이머 설정 (30초마다)
    m_heartbeatTimer->setInterval(30000);
    connect(m_heartbeatTimer, &QTimer::timeout,
            this, &TCPClient::onHeartbeat);
}

TCPClient::~TCPClient()
{
    disconnectFromServer();
}

void TCPClient::connectToServer(const QString &host, quint16 port)
{
    m_serverHost = host;
    m_serverPort = port;

    qDebug() << "Connecting to" << host << ":" << port;
    m_socket->connectToHost(host, port);
}

void TCPClient::disconnectFromServer()
{
    m_heartbeatTimer->stop();
    if (m_socket->state() != QTcpSocket::UnconnectedState) {
        m_socket->disconnectFromHost();
        if (m_socket->state() != QTcpSocket::UnconnectedState) {
            m_socket->waitForDisconnected(3000);
        }
    }
}

void TCPClient::sendMessage(const QString &message)
{
    if (isConnected()) {
        QByteArray data = message.toUtf8() + "\n";
        qint64 written = m_socket->write(data);
        if (written == -1) {
            qDebug() << "Failed to write data:" << m_socket->errorString();
        } else {
            qDebug() << "Sent:" << message;
        }
    } else {
        qDebug() << "Not connected to server";
    }
}

bool TCPClient::isConnected() const
{
    return m_socket->state() == QTcpSocket::ConnectedState;
}

void TCPClient::onConnected()
{
    qDebug() << "Connected to server";
    m_heartbeatTimer->start();
    emit connected();
}

void TCPClient::onDisconnected()
{
    qDebug() << "Disconnected from server";
    m_heartbeatTimer->stop();
    emit disconnected();
}

void TCPClient::onDataReceived()
{
    while (m_socket->canReadLine()) {
        QByteArray data = m_socket->readLine();
        QString message = QString::fromUtf8(data).trimmed();

        qDebug() << "Received:" << message;
        emit messageReceived(message);
    }
}

void TCPClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    QString errorString = m_socket->errorString();
    qDebug() << "Socket error:" << errorString;
    emit errorOccurred(errorString);
}

void TCPClient::onHeartbeat()
{
    if (isConnected()) {
        sendMessage("HEARTBEAT");
    }
}



