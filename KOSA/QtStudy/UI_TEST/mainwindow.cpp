#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(tr("텍스트 입니다."),this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
