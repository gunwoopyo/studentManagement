#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>

#include "Student.h"
class Management {
public:
    static Student* manageHead;
    Student* createObject(int studentID);
    void insertStudent(int studentID, QString name, QString major, QString year);
    void insertStudent(int studentID, QString name, QString major, QString year, double GPA);
    void deleteStudent(int studentID);

    void addCourse(Student* student, QString courseName);
    void deleteCourse(Student* student, QString courseName);

    void updateGrade(Student* student, QString courseName, QString grade);

    bool checkCourseName(Student* student, QString courseName);    // 과목이 중복되면 true
    bool checkStudentID(int studentID);    // 아이디가 중복되면 false

    void debugInsertList();
    void debugCourseList();

    void deleteStudentDB(int studentID);
    void deleteCourseDB(int studentID, QString courseName);
private slots:
public slots:
};

#endif // MANAGEMENT_H
