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
        qDebug() << "main==========================================================";
    }


    Management* manager= new Management();
    QSqlQuery query("SELECT studentID, name, year, major, GPA FROM student;");

    if (!query.exec()) {
        qDebug() << "failed:" << query.lastError().text();
    } else {
        qDebug() << "successed";
    }
    while(query.next()) {
        int studentID = query.value("studentID").toInt();
        QString name = query.value("name").toString();
        QString year = query.value("year").toString();
        QString major = query.value("major").toString();
        double GPA = query.value("GPA").toDouble();

        manager->insertStudent(studentID, name, year, major, GPA);
        manager->Management::debugInsertList();
    }

    MainWindow w;
    w.show();
    delete manager;
    return a.exec();
}
