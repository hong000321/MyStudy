#include "ServerMainWindow.h"
#include "ui_ServerMainWindow.h"

ServerMainWindow::ServerMainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerMainWindow)
{
    ui->setupUi(this);
}

ServerMainWindow::~ServerMainWindow()
{
    delete ui;
}
