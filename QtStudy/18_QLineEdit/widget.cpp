#include "widget.h"
#include <QLineEdit>
#include <QCompleter>
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(10,10,200,20);

    QStringList CompletionList;
    CompletionList << "Bryan" << "Bart" << "Kelvin" << "Beth" << "Brad" << "Kelly";
    QCompleter *stringCompleter = new QCompleter(CompletionList,lineEdit);
    stringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    // lineEdit->setEchoMode(QLineEdit::Password);
    lineEdit->setCompleter(stringCompleter);
    lineEdit->setInputMask("aaaaaa");
    lineEdit->setPlaceholderText("input the number");

    QLabel *label = new QLabel("test",this);
    label->setGeometry(10,40,200,20);

    QObject::connect(lineEdit,&QLineEdit::editingFinished,label,[&](){label->setText(lineEdit->text());});

}

Widget::~Widget() {}
