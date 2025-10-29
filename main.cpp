#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[]) {
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
            manager->insertStudent(
                studentQuery.value("studentID").toInt(),
                studentQuery.value("name").toString(),
                studentQuery.value("year").toString(),
                studentQuery.value("major").toString(),
                studentQuery.value("GPA").toDouble());
    }

    QSqlQuery courseQuery("SELECT studentID, courseName, grade FROM enrollment;");
    while (courseQuery.next()) {
            manager->addCourse(
                manager->createObject(courseQuery.value("studentID").toInt()),
                courseQuery.value("courseName").toString(),
                courseQuery.value("grade").toString());
    }
    MainWindow w;
    w.show();
    delete manager;
    return application.exec();
}

