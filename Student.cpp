#include <QDebug>
#include "Management.h"

double Student::calculateGPA() {
    double totalGrade = 0.0;
    int count = 0;
    double GPA = 0.0;
    Course* currentCourse = courseList;

    while(currentCourse != nullptr) {
        QString grade = currentCourse->getGrade();
        if (grade == "A+") {
            totalGrade += 4.5;
        }
        else if (grade == "A") {
            totalGrade += 4.0;
        }
        else if (grade == "B+") {
            totalGrade += 3.5;
        }
        else if (grade == "B") {
            totalGrade += 3.0;
        }
        else if (grade == "C+") {
            totalGrade += 2.5;
        }
        else if (grade == "C") {
            totalGrade += 2.0;
        }
        else if (grade == "F") {
            totalGrade += 0.0;
        }
        else if (grade == "") {
            currentCourse = currentCourse->courseNext;
            continue;
        }
        count++;
        currentCourse = currentCourse->courseNext;
    }


    if(count == 0) {
        GPA = 0;
    }
    else {
        GPA = totalGrade / count;
        GPA = std::round(GPA * 100) / 100;
    }

    return GPA;
}

