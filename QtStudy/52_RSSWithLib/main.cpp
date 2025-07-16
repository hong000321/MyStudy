#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "CustomMesgHandler.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myDebugMsg);
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "46_RSS_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setObjectName("parentMainWindow");
    w.show();
    w.dumpObjectTree();
    return a.exec();
}
