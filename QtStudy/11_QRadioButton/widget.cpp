#include "widget.h"
#include <QRadioButton>
#include <QButtonGroup>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500,500);
    buttonGroup = new QButtonGroup(this);
    for(int i=0; i<4; i++){
        QString str=QString("RadioButton%1").arg(i+1);
        radioButton[i] = new QRadioButton(str,this);
        radioButton[i]->move(10, 10+20*i);
        buttonGroup->addButton(radioButton[i]);
    }
    for(int i=0; i<4; i++){
        QString str=QString("RadioButton2-%1").arg(i+1);
        radioButton2[i] = new QRadioButton(str,this);
        radioButton2[i]->move(10, 10+100+20*i);
    }
}

Widget::~Widget() {}
