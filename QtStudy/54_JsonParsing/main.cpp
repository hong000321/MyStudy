#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

void sendRequest();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


    sendRequest();
    return a.exec();
}


void sendRequest(){
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // HTTP 요청
    // QNetworkRequest req(QUrl(QString("https://microsoftedge.github.io/Demos/json-dummy-data/64KB.json")));
    QNetworkRequest req(QUrl(QString("https://timeapi.io/api/Time/current/zone?timeZone=Asia/Seoul")));
    // QNetworkRequest req( QUrl( QString("http://worldtimeapi.org/api/timezone/Asia/Seoul") ) );

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError){
        QString strReply = (QString)reply->readAll();
        qDebug() << "Response: " << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();

        qDebug()<< "year:" << jsonObj["year"].toInt();
        qDebug()<< "month:" << jsonObj["month"].toInt();
        qDebug()<< "day:" << jsonObj["day"].toInt();
        delete reply;

    }else{
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }
}
