#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Management.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Management* manager= new Management();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    Ui::MainWindow *ui;
    int searchTableStudentID = 0;
    int courseTableStudentID = 0;
    QString courseTableCourseName;

public:
    void setStudentInfo(int& studentID, QString& name, QString& year, QString& major);  // 학생 등록 탭 - 학생 정보 텍스트 입력 함수
    void clearStudentField();     //  필드 입력값 초기화 함수
    void searchStudent(int stnID, QString name, QString year, QString major);  //  학생 검색 함수
    void insertStudentTableRow(Student* student, int row);  //  searchTable 행 삽입 함
    void studentTable(Student* student = nullptr);  //  학생 조회 함수
    void applyStudentTableRowColors(QTableWidget* studentTable);  //  searchTable 행 컬러 적용
    void totalStudentCount();  //  총 등록 학생 수 출력 함수
    void bubbleSort(QTableWidget* table, int column, bool ascending = true);   //  버블정렬 함수

    void setCourseInfo(int& studentID, QString& name, QString& year, QString& major, QString& courseName);  //  학생 정보 텍스트 입력 함수
    void clearCourseField();  //  학생 정보 입력 필드 초기화 함수
    void setCourseFieldEnabled(bool enabled);  //  학생 정보 입력 필드 활성화 및 비활성화 함수
    void courseTable(Student* singleStduent = nullptr);   // 수강 과목 조회 함수
    void applyCourseTableRowColors(QTableWidget* courseTable);  //  수강 과목 courseTable 행의 컬러 적용 함수
    void searchStudent(int studentID, QString name, QString year, QString major, QString  courseName);  //  학생 조회 함수
    bool matchesStudent(Student* student, int studentID, const QString& name, const QString& year, const QString& major, const QString& courseName);// 입력 받은 학생 정보가 학생 객체에 존재하면 true
    void addStudentsToCourseTable(Student* student, const QString& courseName, int& row);
    void clearAllStudents();  // 프로그램 종료 전 모든 객체 delete 함수
    void saveStudentsBeforeClose();  // 프로그램 종료 전 DB에 학생 정보 저장 함수
    void showMessegeAndClear(const QString& title, const QString& message, const QString& target);  // 성공 or 실패 메시지 출력 and 입력 필드 Clear 하는 함수

public slots:
    void onSearchTableDoubleClicked();     //  테이블 행 더블 클릭 함수
    void on_searchStudentIDTextEntered();  // 학번 입력 시 유효성 검사 함수
    void on_searchNameTextEntered();       //  이름 입력 시 유효성 검사 함수
    void on_clearStudentFieldPushButton_clicked();  // 필드 입력 초기화 버튼 함수
    void on_searchStudentPushButton_clicked();  // 학생 검색 버튼 함수
    void on_searchAllStudentButton_clicked();   //  학생 전체 조회 버튼 함수
    void on_registrationStudentPushButton_clicked();   //  학생 등록 버튼 함수
    void on_studentTable_cellClicked(int row);   //  searchTable테이블 셀 클릭 함수
    void on_deleteStudentPushButton_clicked();  //  학생 삭제 버튼 함수
    void on_searchAscPushButton_clicked();  //  오름차순 클릭 버튼 함수
    void on_searchDescPushButton_clicked();  // 내림차순 클릭 버튼 함수

    void on_courseStudentIDTextEntered();  //  학번 입력 시 유효성 검사 함수
    void on_courseNameTextEntered();  //  이름 입력 시 유효성 검사 함수
    void on_clearCourseFieldPushButton_clicked();  //  학생 정보 입력 필드 초기화 버튼 함수
    void on_courseSearchPushButton_clicked();  //  학생 조회 버튼 함수
    void on_courseAllSearchPushButton_clicked();  // 학생 전체 조회 버튼 함수
    void on_courseAddPushButton_clicked();  //  수강 과목 추가 버튼 함수
    void on_courseTable_cellClicked(int row);  // courseTable 셀 클릭 함수
    void on_deleteCoursePushButton_clicked();  //  수강 과목 삭제 버튼 함수
    void on_courseGradePushButton_clicked();  //  수강 과목 학점 등록 버튼
    void onMajorChanged(const QString &major);  //  전공에 따른 수강 과목을 콤보박스에 출력하는 함수
    void onTabChanged(int index);  // 탭 변경 시 호출되는 함수

private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);
};

#endif // MAINWINDOW_H
