#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "Course.h"

class Student {
private:
    int studentID;
    QString name;
    QString major;
    QString year;
    double GPA;

public:
    Course* courseList;
    Student* studentPrev;
    Student* studentNext;

    Student(int ID, QString n, QString m, QString y) : studentID(ID), name(n), major(m), year(y), GPA(0),
        courseList(nullptr), studentPrev(nullptr), studentNext(nullptr) { }

    int getStudentID() { return studentID; }
    QString getName() { return name; }
    QString getMajor() { return major; }
    QString getYear() { return year; }
    double getGPA() { return GPA; }

    void SetGPA(double g) { this->GPA = g; }
    double calculateGPA();

public slots:
};

#endif // STUDENT_H
