#include "Management.h"
#include <QDebug>
Student* Management::manageHead = nullptr;


void Management::insertStudent(int studentID, QString name, QString major, QString year) {
    Student* newStudent = new Student(studentID, name, major, year);
    if (manageHead == nullptr) {
        manageHead = newStudent;
    }
    else {
        Student* currentStudent = manageHead;
        while (currentStudent->studentNext != nullptr) {
            currentStudent = currentStudent->studentNext;
        }
        currentStudent->studentNext = newStudent;
        newStudent->studentPrev = currentStudent;
    }
}
void Management::deleteStudent(int studentID){
    Student* currentStudent = manageHead;
    while(currentStudent != nullptr) {
        if(currentStudent->getStudentID() == studentID) {
            if(currentStudent->studentPrev == nullptr) {
                if (currentStudent->studentNext == nullptr) {
                    // 노드가 마지막 1개 존재하는 경우.
                    manageHead = nullptr;
                } else {
                    // 헤드 노드가 가리키는 맨첫번째 노드인 경우
                    manageHead = currentStudent->studentNext;
                    currentStudent->studentNext->studentPrev = nullptr;
                }
            }
            else if(currentStudent->studentNext == nullptr) {
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
            }
            else {    // 중간 노드일 경우
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
                currentStudent->studentNext->studentPrev = currentStudent->studentPrev;
            }
            delete currentStudent;
            return;
        }
        currentStudent = currentStudent->studentNext;
    }
}


void Management::addCourse(Student* stn, QString courseName) {
    Course* newCourse = new Course(courseName);   // grade 는 일단 널.
    if(stn->courseList == nullptr) {
        stn->courseList = newCourse;
        newCourse->coursePrev = nullptr;
    }
    else {
        Course* currentCourse = stn->courseList;
        while(currentCourse->courseNext != nullptr){
            currentCourse = currentCourse->courseNext;
        }
        currentCourse->courseNext = newCourse;
        newCourse->coursePrev = currentCourse;
    }

    qDebug() << "### 과목 추가 주소 디버그 ======================================================================";
    int index = 0;
    Course* currentCourse = stn->courseList;
    if(currentCourse == nullptr) {
        qDebug() << "Student list is empty";
        return ;
    }
    while(currentCourse != nullptr) {

        qDebug()<<"학번"<<stn->getStudentID() << " 과목 노드"<<index  <<   " 이전 과목 주소" << currentCourse->coursePrev << " 현재 주소 :" << currentCourse
                 <<" 다음 주소 :" << currentCourse->courseNext;

        currentCourse = currentCourse ->courseNext;
        index++;
    }
}

void Management::deleteCourse(Student* stn, QString courseName) {
    Course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseName) {
            // 지우려는 객체로 진입
            // 헤드포인터가 가리키는 노드가 1개만 남은 경우
            if(currentCourse->coursePrev == nullptr){
                if(currentCourse->courseNext == nullptr) {;
                    stn->courseList = nullptr;
                }
                else {  // 노드가 여러 개일 때 헤드포인터가 가리키는 노드를 지우려 하는 경우
                    stn->courseList = currentCourse->courseNext ;
                    currentCourse->courseNext->coursePrev = nullptr;
                }
            }   // 앞뒤로 사이에 낀 노드를 삭제하려는 경우
            else if (currentCourse->coursePrev != nullptr && currentCourse->courseNext != nullptr) {
                currentCourse->coursePrev->courseNext = currentCourse->courseNext;
                currentCourse->courseNext->coursePrev = currentCourse->coursePrev;
            }
            else {    // 맨 마지막의 노드를 삭제하려는 경우
                currentCourse->coursePrev->courseNext = nullptr;
            }
            delete currentCourse;
            return;
        }
        currentCourse = currentCourse->courseNext;
    }
}
void Management::updateGrade(Student* stn, QString courseName, QString grade) {
    Course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseName){
            currentCourse->setGrade(grade);
        }
        currentCourse = currentCourse->courseNext;
    }
}
bool Management::checkStudentID(int studentID) {
    Student* currentStudent = manageHead;
    while(currentStudent != nullptr) {
        if(currentStudent->getStudentID() == studentID){
            return false;
        }
        currentStudent = currentStudent->studentNext;
    }
    return true;
}
Student* Management::searchStudentID(int studentID) {
    Student* current = manageHead;
    while (current != nullptr) {
        if(current->getStudentID() == studentID){
            return current;
        }
        current = current->studentNext;
    }
    return nullptr;
}
void Management::debugInsertList() {
    int index = 0;

    if(Management::manageHead == nullptr) {
        qDebug() << "Student list is empty";
        return ;
    }
    Student* currentStudent = Management::manageHead;
    qDebug() << "==========================================================================================================";
    while(currentStudent != nullptr) {
        qDebug()<<"학번"<<currentStudent->getStudentID()<<" 이름"<<currentStudent->getName()<<"학년"<<currentStudent->getYear()<<" 전공"<<currentStudent->getMajor() <<
            " 노드"<<index  <<   " 이전 주소" << currentStudent->studentPrev <<
            " 현재 주소 :" << currentStudent <<" 다음주소 :" << currentStudent->studentNext;

        currentStudent = currentStudent ->studentNext;
        index++;
    }
}

void Management::debugCourseList() {
    qDebug() << "### 과목 삭제 주소 디버그 ======================================================================================";
    if(Management::manageHead->courseList == nullptr) {
        qDebug() << "Student courseList is empty";
        return;
    } else {
        Student* currentStudent = Management::manageHead;
        while(currentStudent != nullptr) {
            Course* currentCourse = currentStudent->courseList;
            while(currentCourse != nullptr) {
                qDebug() <<  "학번" << currentStudent->getStudentID()  << " 추가한 과목 " << currentCourse->getCourseName()   <<
                " 이전 과목 주소" << currentCourse->coursePrev << " 현재 주소 :" << currentCourse <<" 다음주소 :" << currentCourse->courseNext;

                currentCourse = currentCourse->courseNext;
            }
            return;
        }
    }
}












