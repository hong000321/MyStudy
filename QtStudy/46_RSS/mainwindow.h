#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QNetworkReply>
#include <QListView>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QComboBox *combo;
    QNetworkAccessManager *manager;


public slots:
    void openRssFeed();
    void replyFinished(QNetworkReply*);

};

class ListView : public QListView {
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MAINWINDOW_H
