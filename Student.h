#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "Course.h"

class Student {
private:
    int studentID;
    QString name;
    QString year;
    QString major;
    double GPA;

public:
    Course* courseList;
    Student* studentPrev;
    Student* studentNext;

    Student(int ID, QString n, QString y, QString m) : studentID(ID), name(n), year(y), major(m), GPA(0),
        courseList(nullptr), studentPrev(nullptr), studentNext(nullptr) { }

    Student(int ID, QString n, QString y, QString m, double G) : studentID(ID), name(n), year(y), major(m), GPA(G),
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
