#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "Student.h"

class Management {
public:
    static Student* manageHead;

    void insertStudent(int studentID, QString name, QString major, QString year);
    void insertStudent(int studentID, QString name, QString major, QString year, double GPA);
    void deleteStudent(int studentID);

    void addCourse(Student* stn, QString courseName);
    void addCourse(Student* stn, QString courseName, QString grade);
    void deleteCourse(Student* stn, QString courseName);

    void updateGrade(Student* stn, QString courseName, QString grade);
    bool checkCourseName(Student* stn, QString courseName);

    bool checkStudentID(int studentID);
    Student* createObject(int studentID);

    void debugInsertList();
    void debugCourseList();
private slots:
public slots:
};

#endif // MANAGEMENT_H
