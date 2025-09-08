#include <QCoreApplication>
#include <QHttpServer>
#include <QHttpServerRequest>
#include <QHttpServerResponse>
#include <QHostAddress>
#include <QDebug>
#include <QFile>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // HTTP 서버 인스턴스 생성
    QHttpServer server;

    // 기본 경로("/") 핸들러
    server.route("/", []() {
        return "Welcome to QHttpServer!";
    });

    // 경로 파라미터 처리 예제
    server.route("/user/<arg>", [](const QString &name) {
        return QString("Hello, %1!").arg(name);
    });

    // JSON 응답 예제
    server.route("/api", []() {
        QJsonObject response;
        response["status"] = "success";
        response["message"] = "API is working";
        return QHttpServerResponse(response);
    });

    // 정적 파일 서빙 (예: index.html)
    server.route("/<arg>", QHttpServerRequest::Method::Get, [](const QUrl &url) {
        const QString path = ":/static/" + url.path(); // 리소스 파일 경로
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
            return QHttpServerResponse::notFound();

        return QHttpServerResponse(file.readAll(), "text/html");
    });

    // 서버 시작 (포트 8080)
    const quint16 port = 8080;
    if (!server.listen(QHostAddress::Any, port)) {
        qCritical() << "Server failed to start on port" << port;
        return 1;
    }

    qInfo() << "Server running on http://localhost:" << port;
    return app.exec();
}
