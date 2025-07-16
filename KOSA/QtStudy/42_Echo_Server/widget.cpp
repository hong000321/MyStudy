#include "widget.h"
#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>

#define BLOCK_SIZE 1024
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    infoLabel = new QLabel(this);
    QPushButton *quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), SLOT(clientConnect()));
    if(!tcpServer->listen()){
        QMessageBox::critical(this, tr("Echo Server"),\
                                                      tr("Unable to start the server: %1.").arg(tcpServer->errorString()));
        close();
        return;
    }

    infoLabel->setText(tr("The server is running on port %1.").arg(tcpServer->serverPort()));
    setWindowTitle(tr("Echo Server"));


}


void Widget::clientConnect(){
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));
    connect(clientConnection, SIGNAL(readyRead()), SLOT(echoData()));

}

void Widget::echoData(){
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender());
    if(clientConnection->bytesAvailable()>BLOCK_SIZE)return;
    QByteArray bytearray = clientConnection->read(BLOCK_SIZE);
    clientConnection->write(bytearray);
    infoLabel->setText(QString(bytearray));
}


Widget::~Widget() {}
