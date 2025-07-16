// ====================
// TCPServer.h
// ====================
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QList>

class TCPServer : public QObject
{
    Q_OBJECT

public:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();

    bool startServer(quint16 port = 8080);
    void stopServer();
    void sendMessageToAll(const QString &message);
    void sendMessageToClient(QTcpSocket *client, const QString &message);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onDataReceived();

private:
    QTcpServer *m_server;
    QList<QTcpSocket*> m_clients;

    void removeClient(QTcpSocket *client);
};

#endif // TCPSERVER_H
