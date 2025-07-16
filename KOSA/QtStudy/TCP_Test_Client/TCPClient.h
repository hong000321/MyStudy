// ====================
// TCPClient.h
// ====================
#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

class TCPClient : public QObject
{
    Q_OBJECT

public:
    explicit TCPClient(QObject *parent = nullptr);
    ~TCPClient();

    void connectToServer(const QString &host, quint16 port);
    void disconnectFromServer();
    void sendMessage(const QString &message);
    bool isConnected() const;

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString &message);
    void errorOccurred(const QString &error);

private slots:
    void onConnected();
    void onDisconnected();
    void onDataReceived();
    void onErrorOccurred(QAbstractSocket::SocketError error);
    void onHeartbeat();

private:
    QTcpSocket *m_socket;
    QTimer *m_heartbeatTimer;
    QString m_serverHost;
    quint16 m_serverPort;
};

#endif // TCPCLIENT_H
