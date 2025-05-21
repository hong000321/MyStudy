#include "widget.h"
#include <QToolBox>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QToolBox *toolbox = new QToolBox(this);
    toolbox->resize(300,380);
    QDial *dial = new QDial(toolbox);
    QCalendarWidget *calendarWidget = new QCalendarWidget(toolbox);
    QTextEdit *textEdit = new QTextEdit("QTextEdit", toolbox);
    toolbox->addItem(dial, "Page &1");
    toolbox->addItem(calendarWidget, "Page &2");
    toolbox->addItem(textEdit, "Page &3");
    // toolbox->show();
}

Widget::~Widget() {}
