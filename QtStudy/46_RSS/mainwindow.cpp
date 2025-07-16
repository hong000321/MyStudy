#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar *toolbar = addToolBar(tr("Open"));
    // RSS 피드를 열기 위한 콤보 박스
    combo = new QComboBox;
    ListView *lv = new ListView;
    combo->setView(lv);
    combo->setEditable(true);
    combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(combo, SIGNAL(activated(int)), SLOT(openRssFeed()));
    toolbar->addWidget(combo);

    // 저장된 RSS 데이터 표시
    QSettings settings("QRss.ini", QSettings::IniFormat);
    int size = settings.beginReadArray("rssFeeds");
    for(int i=0; i<size; i++){
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        combo->addItem(url);
    }

    settings.endArray();
    if(size == 0){
        combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");
    }

    QAction *act = new QAction(tr("Open RSS Feed"),this);
    act->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    connect(act, SIGNAL(triggered()), SLOT(openRssFeed()));
    toolbar->addAction(act);



    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));




}

MainWindow::~MainWindow()
{
    delete ui;
    QSettings settings("QRss.ini", QSettings::IniFormat);
    settings.beginWriteArray("rssFeeds");
    settings.remove("");
    for(int i=0; i<combo->count(); i++){
        settings.setArrayIndex(i);
        settings.setValue("url", combo->itemText(i));
    }
    settings.endArray();
}


void MainWindow::openRssFeed(){
    int i = combo->findText(combo->currentText());
    if(i!= -1){
        combo->setCurrentIndex(i);
    }else{
        combo->addItem(combo->currentText());
        combo->setCurrentIndex(combo->count()-1);
    }
    manager->get(QNetworkRequest(QUrl(combo->currentText())));
}


void MainWindow::replyFinished(QNetworkReply* netReply){
    QString str(netReply->readAll());
    qDebug("%s", qPrintable(str));
}


void ListView::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete){
        event->accept();
        QModelIndexList l= selectedIndexes();
        if(l.length() > 0){
            model() ->removeRow(l.at(0).row(), l.at(0).parent());
        }
    }else{
        QListView::keyPressEvent(event);
    }
}

