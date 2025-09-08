#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtHttpServer/QHttpServer>
#include <QTcpServer>

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
    void runHTTP();

private:
    Ui::MainWindow *ui;
    QHttpServer* httpServer;  // 추가
    QTcpServer* tcpServer;    // 추가

};
#endif // MAINWINDOW_H
