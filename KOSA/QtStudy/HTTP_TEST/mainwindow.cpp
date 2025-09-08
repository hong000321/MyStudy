#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    runHTTP();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::runHTTP(){
    httpServer = new QHttpServer(this);
    httpServer->route("/", [] () {
        return "<br>hello world</br>";
    });

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen() || !httpServer->bind(tcpServer)) {
        delete tcpServer;
        return;
    }
    qDebug() << "Listening on port" << tcpServer->serverPort();
}
