#ifndef COURSE_H
#define COURSE_H
#include <QString>
class Course {
private:
    QString courseName;
    QString grade;
public:
    Course* coursePrev;
    Course* courseNext;

    Course(QString name) : courseName(name), grade(""), coursePrev(nullptr), courseNext(nullptr) { }

    QString getCourseName() {
        return courseName;
    }
    QString getGrade() {
        return grade;
    }
    void setCourseName(QString course) {
        this->courseName = course;
    }
    void setGrade(QString grade) {
        this->grade = grade;
    }
};


#endif // COURSE_H
