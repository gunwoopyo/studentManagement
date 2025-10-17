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
private:
    Ui::MainWindow *ui;
    int searchTableStudentID = 0;
    int courseTableStudentID = 0;
    QString courseTableCourseName = "";

private slots:

public slots:
    void onMajorChanged(const QString &major);  // 전공 변경 슬롯
    void onTabChanged(int index);  // 탭 변경 시 호출될 슬롯

    void on_searchStudentIDTextEntered();
    void on_searchNameTextEntered();

    void on_searchStudentPushButton_clicked();  // 학생 조회 버튼
    void searchTable();
    void searchStudentTable(int stnID, QString name, QString year, QString major); // 학생 조회 테이블
    void on_searchAllStudentButton_clicked();          // 학생 전체 조회 버튼
    void on_registrationStudentPushButton_clicked();   // 학생 등록 버튼

    void on_deleteStudentTable_cellClicked(int row);    // 학생 삭제 셀 선택
    void on_deleteStudentPushButton_clicked();        // 학생 삭제 버튼
    void searchClear();







    void on_courseNameTextEntered();
    void on_courseStudentIDTextEntered();

    void on_deleteCourseTable_cellClicked(int row);
    void on_deleteCoursePushButton_clicked(); // 과목 삭제




    void on_courseSearchPushButton_clicked();   // 학생 조회
    void courseSearchTable(int stnID, QString name, QString year, QString major);
    void on_courseAllSearchPushButton_clicked();



    void on_courseAddPushButton_clicked();      // 과목 추가
    void courseClear();
    void courseTable(Student* stn);

    void on_courseGradePushButton_clicked();  // 성적 등록!!!!!!!!




    // void on_updateSearchPushButton_clicked();        // 성적 조회
    // void gradeTable(Student* stn);
    // void gradeFrameClear();

    void on_searchAscPushButton_clicked();
    void on_searchDescPushButton_clicked();
    void bubbleSortTable(QTableWidget* table, int column, bool ascending = true);

    void clearAllStudents();

    void saveDataBeforeClose();
};

#endif // MAINWINDOW_H
