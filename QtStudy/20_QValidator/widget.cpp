#include "widget.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDoubleValidator *doubleValidator = new QDoubleValidator(this);
    doubleValidator->setRange(10.0,100.0,3);
    doubleValidator->setBottom(10.0);
    doubleValidator->setTop(100.0);
    doubleValidator->setDecimals(5);

    QIntValidator *intValidator = new QIntValidator(this);
    intValidator->setBottom(13);
    intValidator->setTop(19);

    // QRegularExpression re("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})(\\.(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})){3}$");
    QRegularExpressionValidator* regExpValidator = new QRegularExpressionValidator(re,this);

    QLineEdit *lineEditDouble = new QLineEdit(this);
    lineEditDouble->setValidator(doubleValidator);

    QLineEdit *lineEditInt = new QLineEdit(this);
    lineEditInt->setValidator(intValidator);

    QLineEdit *lineEditRegExp = new QLineEdit(this);
    // lineEditRegExp->setInputMask("000.000.000.000;_");
    lineEditRegExp->setValidator(regExpValidator);
    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->setGeometry(QRect(300,300,1000,1000));
    formLayout->addRow("&Double",lineEditDouble);
    formLayout->addRow("&Int",lineEditInt);
    formLayout->addRow("&Regular Expression",lineEditRegExp);

    setWindowTitle("Validator");
}

Widget::~Widget() {}
