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
    QSqlQuery studentQuery("SELECT studentID, name, year, major, GPA FROM student;");
    if (!studentQuery.exec()) {
        qDebug() << "failed:" << studentQuery.lastError().text();
    } else {
        qDebug() << "successed";
    }
    while(studentQuery.next()) {
        int studentID = studentQuery.value("studentID").toInt();
        QString name = studentQuery.value("name").toString();
        QString year = studentQuery.value("year").toString();
        QString major = studentQuery.value("major").toString();
        double GPA = studentQuery.value("GPA").toDouble();

        manager->insertStudent(studentID, name, year, major, GPA);
        manager->debugInsertList();
    }

    QSqlQuery checkQuery;
    if (checkQuery.exec("SELECT EXISTS (SELECT 1 FROM enrollment)"))  {
        if (checkQuery.next() && checkQuery.value(0).toBool()) {

            QSqlQuery courseQuery("SELECT studentID, courseName, grade FROM enrollment");
            if (!courseQuery.exec()) {
                qDebug() << "쿼리 실패:" << courseQuery.lastError().text();
            } else {
                while (courseQuery.next()) {
                    int studentID = courseQuery.value("studentID").toInt();
                    QString courseName = courseQuery.value("courseName").toString();
                    QString grade = courseQuery.value("grade").toString();
                    Student* stn = manager->createObject(studentID);
                    manager->addCourse(stn, courseName);
                    manager->updateGrade(stn, courseName, grade);
                    manager->debugCourseList();
                }
            }
        }
    }
    MainWindow w;
    w.show();
    delete manager;
    return a.exec();
}
