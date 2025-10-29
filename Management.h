#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "Student.h"

class Management {
public:
    static Student* manageHead;

    // 학번을 통해 학생 정보가 존재한다면 객체를 생성하는 함수
    Student* createObject(int studentID);

    // 학생 객체를 생성해 링크드 리스트에 삽입하는 함수
    void insertStudent(int studentID, QString name, QString major, QString year);
    void insertStudent(int studentID, QString name, QString major, QString year, double GPA);

    // 학생 객체를 링크드 리스트에서 삭제하는 함수
    void deleteStudent(int studentID);

    // 수강 과목 추가 함수
    void addCourse(Student* student, QString courseName);

    // 수강 과목 및 학점 동시에 추가하는 함수
    void addCourse(Student* student, QString courseName, QString grade);

    // 수강 과목을 삭제하는 함수
    void deleteCourse(Student* student, QString courseName);

    // 수강 과목의 학점을 등록하는 함수
    void updateGrade(Student* student, QString courseName, QString grade);

    // 특정 학생 객체의 수강 과목을 조회해 존재하는 과목이 있으면 true 리턴
    bool checkCourseName(Student* student, QString courseName);

    // 매개변수에 입력한 학생이 존재하면 false 리턴
    bool checkStudentID(int studentID);

    // 학생 객체 삽입 or 삭제 시 메모리 주소 디버그
    void debugInsertList();

    // 수강 과목 삽입 or 삭제 시 메모리 주소 디버그
    void debugCourseList();

    // 특정 학생 정보를 DB에서 삭제하는 함수
    void deleteStudentDB(int studentID);

    // 특정 학생의 수강 과목을 DB에서 삭제하는 함수
    void deleteCourseDB(int studentID, QString courseName);

};
#endif // MANAGEMENT_H

