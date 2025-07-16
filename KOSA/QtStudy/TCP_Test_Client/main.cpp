
// ====================
// main.cpp (Client Example)
// ====================

#include <QCoreApplication>
#include <QTimer>
#include <QTextStream>
#include "TCPClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    TCPClient client;

    // 연결 이벤트 처리
    QObject::connect(&client, &TCPClient::connected, []() {
        qDebug() << "Connected to server successfully!";
    });

    QObject::connect(&client, &TCPClient::disconnected, []() {
        qDebug() << "Disconnected from server!";
    });

    QObject::connect(&client, &TCPClient::messageReceived, [](const QString &message) {
        qDebug() << "Server says:" << message;
    });

    QObject::connect(&client, &TCPClient::errorOccurred, [](const QString &error) {
        qDebug() << "Connection error:" << error;
    });

    // 서버에 연결
    client.connectToServer("127.0.0.1", 8080);

    // 테스트 메시지 전송
    QTimer messageTimer;
    QObject::connect(&messageTimer, &QTimer::timeout, [&client]() {
        static int counter = 0;
        if (client.isConnected()) {
            client.sendMessage(QString("Hello from client #%1").arg(++counter));
        }
    });
    messageTimer.start(3000);

    return app.exec();
}
