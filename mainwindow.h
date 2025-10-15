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

private slots:
    void onMajorChanged(const QString &major);  // 전공 변경 슬롯
    void onTabChanged(int index);  // 탭 변경 시 호출될 슬롯

public slots:
    void on_searchAscPushButton_clicked();
    void on_searchDescPushButton_clicked();
    void bubbleSortTable(QTableWidget* table, int column, bool ascending = true);

    void on_searchStudentSearchButton_clicked();      // 학생 조회
    void on_searchStudentAllSearchButton_clicked();   // 학생 전체 조회
    void searchStudentTable(int stnID, QString name, QString year, QString major);

    void on_searchRegistrationPushButton_clicked();    // 학생 등록
    void on_searchDeletePushButton_clicked();   // 학생 삭제
    void registrationTable();
    void searchClear();





    void on_courseSearchPushButton_clicked();   // 과목 조회
    void on_courseAddPushButton_clicked();      // 과목 추가
    void on_courseDeletePushButton_clicked();   // 과목 삭제
    void courseTable(Student* stn);
    void courseFrameClear();

    // void on_updateSearchPushButton_clicked();        // 성적 조회
    // void on_updateRegistrationGradePushButton_clicked();  // 성적 등록
    // void gradeTable(Student* stn);
    // void gradeFrameClear();

    void clearAllStudents();

    void saveDataBeforeClose();
};

#endif // MAINWINDOW_H
