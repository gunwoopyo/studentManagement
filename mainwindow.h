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
class MainWindow : public QMainWindow
{
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
private slots:
public slots:

    void showMessegeAndClear(const QString& title, const QString& message, const QString& target);
    void onMajorChanged(const QString &major);  // 전공 변경 슬롯
    void onTabChanged(int index);  // 탭 변경 시 호출될 슬롯
    void totalStudentCount();

    void setCourseInfo(int& studentID, QString& name, QString& year, QString& major, QString& courseName);
    void setStudentInfo(int& studentID, QString& name, QString& year, QString& major);

    void on_searchStudentIDTextEntered();              // 학번 입력
    void on_searchNameTextEntered();                   // 이름 입력
    void on_clearStudentFieldPushButton_clicked();     // 입력 초기화 버튼
    void clearStudentField();                          // 입력값 초기화

    void on_searchStudentPushButton_clicked();          // 학생 검색 버튼
    void searchStudent(int stnID, QString name, QString year, QString major);   // 학생 검색 테이블
    void on_searchAllStudentButton_clicked();           // 학생 전체 조회 버튼

     void on_registrationStudentPushButton_clicked();    // 학생 등록 버튼
    void on_studentTable_cellClicked(int row);          // 학생 삭제 셀 클릭
    void on_deleteStudentPushButton_clicked();          // 학생 삭제 버튼
    void studentTable(Student* student);    // 학생 조회 테이블
    void applyStudentTableRow(QTableWidget* studentTable, int row, Student* currentStudent);   // 학생테이블 행 삽입
    void applyStudentTableRowColors(QTableWidget* studentTable);     // 학생 테이블 행 색 적용






    void searchStudent(int stnID, QString name, QString year, QString major, QString  courseName);  // 학생 검색 테이블


    void courseTable(Student* student);
    void courseAllTable();
    void applyCourseTableRowColors(QTableWidget* courseTable);



    void on_courseStudentIDTextEntered();               // 학번 입력
    void on_courseNameTextEntered();                    // 이름 입력
    void on_clearCourseTextPushButton_clicked();        // 입력 초기화 버튼
    void on_courseSearchPushButton_clicked();           // 학생 조회 버튼
    void on_courseAllSearchPushButton_clicked();        // 학생 전체 조회 버튼
    void on_courseAddPushButton_clicked();              // 과목 추가 버튼
    void on_courseTable_cellClicked(int row);           // 과목 셀 클릭
    void on_deleteCoursePushButton_clicked();           // 과목 삭제 버튼
    void on_courseGradePushButton_clicked();            // 학점 등록 버튼
    void clearCourseField();
    void setCourseFieldEnabled(bool enabled);



    void on_searchAscPushButton_clicked();
    void on_searchDescPushButton_clicked();
    void bubbleSort(QTableWidget* table, int column, bool ascending = true);
    void clearAllStudents();       // 종료 전 모든 객체 delete
    void saveStudentsBeforeClose();    // 종료 전 DB에 데이터 저장
};

#endif // MAINWINDOW_H
