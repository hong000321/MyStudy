#include "mainwindow.h"

#include <QApplication>
#include <QLineEdit>
#include <QCompleter>
#include <QFileSystemModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    QLineEdit *lineEdit = new QLineEdit;

    QCompleter *completer = new QCompleter(lineEdit);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    completer->setModel(model);
    lineEdit->setCompleter(completer);

    lineEdit->show();

    return a.exec();
}
