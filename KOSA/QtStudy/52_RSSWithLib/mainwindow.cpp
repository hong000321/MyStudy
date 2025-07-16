#include "mainwindow.h"
#include <QtWidgets>
#include "saveurls.h"
#include <QDomDocument>
#include <QDomNodeList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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
    // QSettings settings("QRss.ini", QSettings::IniFormat);
    // int size = settings.beginReadArray("rssFeeds");
    // for(int i=0; i<size; i++){
    //     settings.setArrayIndex(i);
    //     QString url = settings.value("url").toString();
    //     combo->addItem(url);
    // }

    // settings.endArray();
    // if(size == 0){
    //     combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");
    // }

    QAction *act = new QAction(tr("Open RSS Feed"),this);
    act->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    connect(act, SIGNAL(triggered()), SLOT(openRssFeed()));
    toolbar->addAction(act);

    // Dom Document for rss
    listView = new QListView;
    connect(listView, SIGNAL(doubleClicked(QModelIndex)), SLOT(listViewDoubleClicked(QModelIndex)));
    model = new QStandardItemModel(0,1,this);
    listView->setModel(model);


    // RSS 피드 다운로드와 웹 페이지 표시를 위한 프로그래스바
    progress = new QProgressBar(this);
    statusBar()->addPermanentWidget(progress);

    //웹 기반의 내용 표시
    webView = new QWebEngineView(this);
    webView->load(QUrl("about:blank"));
    connect(webView, SIGNAL(loadProgress(int)), progress, SLOT(setValue(int)));


    // QSettings 를 사용한 라이브러리
    // 저장된 url 을 불러온다.
    QLibrary lib("SaveUrls");
    if(!lib.isLoaded()) lib.load();
    SaveUrls *saveUrl = (SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList = saveUrl->load();
    for(int i=0; i<urlList.count(); i++){
        combo->addItem(urlList.at(i));
    }
    if(lib.isLoaded()) lib.unload();

    if(urlList.count() == 0){
        // combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");
    }

    QSplitter *splitter = new QSplitter;
    splitter->addWidget(listView);
    splitter->addWidget(webView);
    this->setCentralWidget(splitter);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));

    openRssFeed();

}

MainWindow::~MainWindow()
{
    QLibrary lib("SaveUrls");
    if(!lib.isLoaded()) lib.load();
    SaveUrls *saveUrl = (SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList;
    for(int i=0; i<combo->count(); i++){
        urlList.append(combo->itemText(i));
    }
    saveUrl->save(urlList);
    if(lib.isLoaded()) lib.unload();
    // QSettings settings("QRss.ini", QSettings::IniFormat);
    // settings.beginWriteArray("rssFeeds");
    // settings.remove("");
    // for(int i=0; i<combo->count(); i++){
    //     settings.setArrayIndex(i);
    //     settings.setValue("url", combo->itemText(i));
    // }
    // settings.endArray();
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

    // RSS webpage view signal
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(combo->currentText())));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(downloadProgress(qint64,qint64)));
}


void MainWindow::replyFinished(QNetworkReply* netReply){
    QString str(netReply->readAll());
    qDebug("%s", qPrintable(str));

    QVariant vt = netReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if(!vt.isNull()){
        qDebug()<< "Redirection to:" << vt.toUrl().toString();
        QNetworkReply *reply = manager->get(QNetworkRequest(vt.toUrl()));
        connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(downloadProgress(qint64,qint64)));

    }else{
        QDomDocument doc;
        QString error;
        if(!doc.setContent(str,false, &error)){
            qDebug("Error");
            webView->setHtml(QString("<h1>Error</h1>")+error);
        }else{
            QDomElement docElem = doc.documentElement();
            QDomNodeList nodeList = docElem.elementsByTagName("item");

            model->clear();
            model->insertColumn(0);
            for(int i=0; i<nodeList.length(); i++){
                QDomNode node = nodeList.item(i);
                QDomElement e = node.toElement();
                QString strTitle = e.elementsByTagName("title").item(0).firstChild().nodeValue();
                QString strLink = e.elementsByTagName("link").item(0).firstChild().nodeValue();
                QString strDescription = e.elementsByTagName("description").item(0).firstChild().nodeValue();
                QString strToolTip = "<b>" + strTitle + "</b>" + "<br/><br/>" + strDescription + "<br/><br/>" + strLink;
                model->insertRows(model->rowCount(),1);
                QModelIndex index = model->index(model->rowCount()-1,0);
                model->setData(index,strTitle, Qt::DisplayRole);
                model->setData(index, style()->standardIcon(QStyle::SP_FileIcon), Qt::DecorationRole);
                model->setData(index, strToolTip, Qt::ToolTipRole);
                model->setData(index, strLink, Qt::UserRole);
                model->itemFromIndex(index)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            }
        }
    }
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


void MainWindow::listViewDoubleClicked(const QModelIndex &index){
    // Q_UNUSED(index);
    qDebug("listViewDoubleClicked");
    QString strLink = index.data(Qt::UserRole).toString();

    qDebug() << strLink;
    webView->load(QUrl(strLink));
}


void MainWindow::downloadProgress(qint64 bytes, qint64 bytesTotal){
    if(bytesTotal == -1){
        progress->setMinimum(0);
        progress->setMaximum(0);
    }else{
        progress->setMaximum(100);
        int percent = bytes*100 / bytesTotal;
        progress->setValue(percent);
    }
}
