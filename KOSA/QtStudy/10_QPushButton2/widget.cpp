#include "widget.h"
#include <QPushButton>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *pushButton  = new QPushButton("Push&Button", this);
    pushButton->setCheckable(true);
    QObject::connect(pushButton, &QPushButton::toggled,
            [&](bool flag){qDebug()<<"toggled"; if(!flag) qApp->quit();});
}

Widget::~Widget() {}
