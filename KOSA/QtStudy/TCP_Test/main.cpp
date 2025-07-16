

#include <QApplication>
#include <QCoreApplication>
#include <QTimer>
#include "TCPServer.h"

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    TCPServer server;

    // 서버 시작
    if (!server.startServer(8080)) {
        return -1;
    }

    // 5초마다 브로드캐스트 메시지 전송
    QTimer broadcastTimer;
    QObject::connect(&broadcastTimer, &QTimer::timeout, [&server]() {
        static int counter = 0;
        server.sendMessageToAll(QString("Server broadcast #%1").arg(++counter));
    });
    broadcastTimer.start(5000);

    qDebug() << "Server is running. Press Ctrl+C to quit.";

    return app.exec();
}
