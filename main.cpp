#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("student_db");
    db.setUserName("gunwoopyo");
    db.setPassword("rjsdn2939");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "DB 연결 실패:" << db.lastError().text();
    } else {
        qDebug() << "DB 연결 성공";
        qDebug() << "main==================================================================================";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
