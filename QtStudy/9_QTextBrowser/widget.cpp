#include "widget.h"
#include <QTextBrowser>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextBrowser *tb = new QTextBrowser(this);
    tb->setSource(QUrl("index.html"));
    tb->setGeometry(0,0,500,500);
}

Widget::~Widget() {}
