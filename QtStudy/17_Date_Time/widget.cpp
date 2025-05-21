#include "widget.h"
#include <QTime>
#include <QDate>
#include <QDateEdit>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTimeEdit *timeEdit = new QTimeEdit(this);
    timeEdit->setTime(QTime::currentTime());
    timeEdit->setGeometry(10,10,200,20);
    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(),this);
    dateEdit->setCalendarPopup(true);
    dateEdit->setGeometry(10,110,200,20);
    dateEdit->setDisplayFormat("yy-MM-dd");
}

Widget::~Widget() {}
