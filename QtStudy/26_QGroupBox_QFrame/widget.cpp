#include "widget.h"
#include <QgroupBox>
#include <QFormLayout>
#include <QtWidgets>
#include <QFrame>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList labels;
    labels << "&IP Address" << "&Mac Address" << "&Date";
    QLineEdit* lineEdit[3];
    QFormLayout *formLayout = new QFormLayout;
    for(int i=0; i<3; i++){
        lineEdit[i] = new QLineEdit(this);
        formLayout->addRow(labels.at(i),lineEdit[i]);
    }
    QGroupBox *groupBox = new QGroupBox("&Widget Group",this);
    groupBox->move(5,5);
    groupBox->setLayout(formLayout);
    // resize(groupBox->sizeHint().width()+10,
    //        groupBox->sizeHint().height()+10);

    //================================================
    // QFrame
    QGroupBox *groupBox2 = new QGroupBox("&Frame Group",this);
    QFormLayout *formLayout2 = new QFormLayout;

    int tmp_y = groupBox->y() + groupBox->sizeHint().height()+10;
    int tmp_h = 50;
    int tmp_w = groupBox->sizeHint().width();

    QFrame *plainLine = new QFrame(this);
    plainLine->setGeometry(QRect(0,tmp_y,tmp_w,tmp_h));
    plainLine->setLineWidth(2);
    plainLine->setFrameStyle(QFrame::HLine | QFrame::Plain);

    QFrame *raisedLine = new QFrame(this);
    raisedLine->setGeometry(QRect(0,tmp_y+10,tmp_w,tmp_h));
    raisedLine->setLineWidth(2);
    raisedLine->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QFrame *sunkenLine = new QFrame(this);
    sunkenLine->setGeometry(QRect(0,tmp_y+20,tmp_w,tmp_h));
    sunkenLine->setFrameStyle(QFrame::HLine | QFrame::Sunken);

    formLayout2->addRow(plainLine);
    formLayout2->addRow(raisedLine);
    formLayout2->addRow(sunkenLine);

    groupBox2->move(5,tmp_y);
    groupBox2->setLayout(formLayout2);
    resize(groupBox->sizeHint().width()+10,
           groupBox->sizeHint().height()+ groupBox2->sizeHint().height()+10);

}

Widget::~Widget() {}
