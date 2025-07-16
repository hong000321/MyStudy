#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QNetworkReply>
#include <QListView>
#include <QStandardItemModel>

#include <QProgressBar>
#include <QWebEngineView>


QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QComboBox *combo;
    QNetworkAccessManager *manager;
    QListView *listView;
    QStandardItemModel *model;

    QWebEngineView *webView;
    QProgressBar *progress;

public slots:
    void openRssFeed();
    void replyFinished(QNetworkReply*);
    void listViewDoubleClicked(const QModelIndex & index);

    void downloadProgress(qint64 bytes, qint64 bytesTotal);
};

class ListView : public QListView {
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MAINWINDOW_H
