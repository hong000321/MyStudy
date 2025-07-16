#ifndef CUSTOMMESGHANDLER_H
#define CUSTOMMESGHANDLER_H

#include <QApplication>
#include <stdio.h>
#include <stdlib.h>

void myDebugMsg(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    switch(type){
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", qPrintable(msg));
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", qPrintable(msg));
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", qPrintable(msg));
        abort();
    }

}

// typedef void (*QtMessageHandler)(QtMsgType, const QMessageLogContext&, const QString&);
// Q_EXPORT QtMessageHandler qInstallMessageHandler(QtMessageHandler);

#endif // CUSTOMMESGHANDLER_H
