#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpserver>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool start();
    void stop();

private slots:
    void onNewConnection();
    void onClientReadyRead();
    void onClientDisconnected();
private:
    Ui::MainWindow *ui;
    QTcpServer *m_tcpServer;
    quint16 m_port;
    QList<QTcpSocket*> m_clientSockets;

    void sendHtmlResponse(QTcpSocket *socket, const QString &title, const QString &body);
    void sendTextResponse(QTcpSocket *socket, const QString &text);
    void sendNotFoundResponse(QTcpSocket *socket);


};
#endif // MAINWINDOW_H
