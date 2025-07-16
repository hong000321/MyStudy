#include "widget.h"
#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel("0",this);
    label->setGeometry(10,200,100,100);

    resize(500,500);
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    // connect(buttonGroup, SIGNAL(idClicked(int)),SLOT(selectButton(int)));
    connect(buttonGroup, &QButtonGroup::idClicked,[=](int id)mutable{label->setText(QString::number(id+1));});
    for(int i=0;i<4;i++){
        QString str = QString("CheckBox%1").arg(i+1);
        checkBox[i] = new QCheckBox(str,this);
        checkBox[i]->move(10, 20+20*i);
        buttonGroup->addButton(checkBox[i],i);
    }
}

Widget::~Widget() {}

void Widget::selectButton(int id){
    printf("%d\n",id);
    QButtonGroup *buttonGroup = (QButtonGroup*)sender();
    QCheckBox *button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)",id+1,(button->isChecked()?"On":"Off"));
    QString str;
    str.setNum(id);
    label->setText(str);
}
