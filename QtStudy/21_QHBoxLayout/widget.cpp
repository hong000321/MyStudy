#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *pushButton1 = new QPushButton();
    pushButton1->setText("Button1");
    QPushButton *pushButton2 = new QPushButton("Button2");
    QPushButton *pushButton3 = new QPushButton("Button3",this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->setContentsMargins(0,0,0,0);
    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addWidget(pushButton2);
    hBoxLayout->addWidget(pushButton3);

}

Widget::~Widget() {}
