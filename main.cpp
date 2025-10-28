#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("localhost");
    DB.setDatabaseName("student_db");
    DB.setUserName("gunwoopyo");
    DB.setPassword("rjsdn2939");
    DB.setPort(3306);
    DB.open();

    Management* manager= new Management();

    QSqlQuery studentQuery("SELECT studentID, name, year, major, GPA FROM student;");
    while(studentQuery.next()) {

        int studentID = studentQuery.value("studentID").toInt();
        QString name = studentQuery.value("name").toString();
        QString year = studentQuery.value("year").toString();
        QString major = studentQuery.value("major").toString();
        double GPA = studentQuery.value("GPA").toDouble();

        manager->insertStudent(studentID, name, year, major, GPA);
    }



    QSqlQuery courseQuery("SELECT studentID, courseName, grade FROM enrollment");
    while (courseQuery.next()) {

        int studentID = courseQuery.value("studentID").toInt();
        QString courseName = courseQuery.value("courseName").toString();
        QString grade = courseQuery.value("grade").toString();

        Student* student = manager->createObject(studentID);
        manager->addCourse(student, courseName);
        manager->updateGrade(student, courseName, grade);
    }

    MainWindow w;
    w.show();
    delete manager;
    return application.exec();
}
