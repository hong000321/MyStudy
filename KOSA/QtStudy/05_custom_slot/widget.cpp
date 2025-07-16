#include "widget.h"

#include <QApplication>
#include <QPushButton>
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit", this);
    quit->move(10,10);
    quit->resize(75,35);
    quit->setGeometry(50,10,75,35); //(x,y,w,h)

    QLabel *hello = new QLabel("hello",this);
    hello->setGeometry(20,100,100,100); //(x,y,w,h)
    hello->resize(100,100);

    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));
    // connect(quit,SIGNAL(clicked()),this,[](){qApp->quit();});
    // quit->show();
    // QObject::connect(quit, SIGNAL(clicked()),qApp, SLOT(quit()));
}

Widget::~Widget() {}

void Widget::slotQuit(){
    qDebug("slotQuit");
    // qApp->quit();
    emit clicked();
}
