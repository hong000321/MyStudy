#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QTextEdit
{
    Q_OBJECT

public:
    explicit Widget(quint16 port, QWidget *parent = nullptr);
    ~Widget();
    bool start();
    void stop();

private slots:
    void onNewConnection();
    void onClientReadyRead();
    void onClientDisconnected();

private:
    Ui::Widget *ui;
    QTcpServer *m_tcpServer;
    quint16 m_port;
    QList<QTcpSocket*> m_clientSockets;

    void sendHtmlResponse(QTcpSocket *socket, const QString &title, const QString &body);
    void sendTextResponse(QTcpSocket *socket, const QString &text);
    void sendNotFoundResponse(QTcpSocket *socket);

};
#endif // WIDGET_H
