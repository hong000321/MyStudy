#include "mainwindow.h"

#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


#define QUERYMODEL 0

#if QUERYMODEL==0
#include <QSqlTableModel>
#include <QSqlRecord>
#endif

static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sample.db");
    //db.setDatabaseName(":memory:");
    if(!db.open())return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(id INTEGER PRIMARY KEY,"
               "firstname VARCHAR(20) NOT NULL, lastname VARCHAR(20));");
    query.exec("INSERT INTO person VALUES(101, 'Yongsu', 'Kang');");
    query.exec("INSERT INTO person(firstname, lastname) VALUES('Soomi', 'Kim')"); // ; 세미콜론 없어도 동작은 함
    query.exec("INSERT INTO person(firstname, lastname) "
               "VALUES ('Jia', 'Lee'), ('YoungJin', 'Suh'),('YoungHwa','Ryu');");
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    if(!createConnection()) return -1;

#if QUERYMODEL==1
    QSqlQueryModel queryModel;
    queryModel.setQuery("SELECT * FROM person");
    queryModel.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    queryModel.setHeaderData(1, Qt::Horizontal, QObject::tr("First Name"));
    queryModel.setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));

#else // TABLEMODEL
    QSqlTableModel queryModel;
    queryModel.setTable("person");
    // queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
    queryModel.select();

    QSqlRecord rec = queryModel.record();
    qDebug() << "Number of columns: " <<rec.count();
    int nameCol = rec.indexOf("firstname");
    for(int i=0; i<queryModel.rowCount(); ++i){
        QSqlRecord r = queryModel.record(i);
        qDebug() << r.value(nameCol).toString();
    }

    QSqlQuery query("SELECT MAX(id) FROM person;");
    int idCol = rec.indexOf("id");
    query.exec();
    while(query.next())
        qDebug() << query.value(idCol).toInt();

    QTableView *tableview = new QTableView;
    tableview->setModel(&queryModel);
    tableview->setWindowTitle(QObject::tr("Query Model"));
    tableview->show();


#endif
    return a.exec();
}
