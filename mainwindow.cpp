#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->courseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->courseMajorComboBox->currentText());

    connect(ui->searchStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_searchStudentIDTextEntered);
    connect(ui->searchStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_searchNameTextEntered);

    connect(ui->searchTable, &QTableWidget::cellClicked, this, &MainWindow::on_deleteStudentTable_cellClicked);
    ui->searchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->searchTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->courseStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_courseStudentIDTextEntered);
    connect(ui->courseNameText, &QLineEdit::editingFinished, this, &MainWindow::on_courseNameTextEntered);

    connect(ui->courseTable, &QTableWidget::cellClicked, this, &MainWindow::on_courseTable_cellClicked);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::showWarningAndClear(const QString& title, const QString& message) {
    searchClear();
    courseClear();
    QMessageBox::warning(this, title, message);
}
void MainWindow::showInformingAndClear(const QString& title, const QString& message) {
    searchClear();
    courseClear();
    ui->searchTable->clearSelection();
    ui->courseTable->clearSelection();
    QMessageBox::information(this, title, message);
}

void MainWindow::on_searchStudentIDTextEntered() {
    QString studentID = ui->searchStudentIDText->text().trimmed();
    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentIDToString) {
        showWarningAndClear("실패", "학번은 숫자로 입력해주세요.    ");
        ui->searchStudentIDText->setFocus();
        return;
    }

}


void MainWindow::on_searchNameTextEntered() {
    QString name = ui->searchStudentNameText->text().trimmed();
    if (!name.contains(QRegularExpression("^[a-zA-Z]+$"))) {
        QMessageBox::warning(this, "입력 오류", "이름은 문자만 가능합니다.    ");
        ui->searchStudentNameText->clear();
        ui->searchStudentNameText->setFocus();
        return;
    }
    return;
}

void MainWindow::on_clearStudentDataPushButton_clicked() {
    showInformingAndClear("성공", "입력이 초기화 되었습니다.    ");
    return;
}
void MainWindow::on_clearCourseDataPushButton_clicked() {
    showInformingAndClear("성공", "입력이 초기화 되었습니다.    ");
    return;
}






void MainWindow::on_courseStudentIDTextEntered() {
    QString studentID = ui->courseStudentIDText->text().trimmed();
    int studentIDInt = ui->courseStudentIDText->text().toInt();

    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentIDToString) {
        showWarningAndClear("입력 오류", "학번은 숫자만 입력 가능.   " );
        ui->courseStudentIDText->setFocus();
        return;
    }

    Student* currentStudent = manager->createObject(studentIDInt);
    if (currentStudent) {
        ui->courseNameText->setText(currentStudent->getName());
        ui->courseYearComboBox->setCurrentText(currentStudent->getYear());
        ui->courseMajorComboBox->setCurrentText(currentStudent->getMajor());
        return;
    } else {
        showWarningAndClear("찾을 수 없음", "해당 학번의 학생이 없습니다.    ");
        return;
    }
}
void MainWindow::on_courseNameTextEntered() {

    QString name = ui->courseNameText->text().trimmed();
    if (!name.contains(QRegularExpression("^[a-zA-Z]+$"))) {
        QMessageBox::warning(this, "입력 오류", "이름은 문자만 가능합니다.    ");
        ui->courseNameText->clear();
        ui->courseNameText->setFocus();
        return;
    }
    return;
}


void MainWindow::on_deleteStudentTable_cellClicked(int row) {
    QTableWidgetItem* studentID = ui->searchTable->item(row, 0);
    searchTableStudentID = studentID->text().toInt();
    qDebug() << searchTableStudentID;
}





void MainWindow::on_deleteStudentPushButton_clicked() {
    if(searchTableStudentID == 0) {
        showWarningAndClear("실패", "삭제할 셀을 선택해주세요.");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM student WHERE studentID = :id;");
    query.bindValue(":id", searchTableStudentID);
    query.exec();

    query.prepare("DELETE FROM enrollment WHERE studentID = :id;");
    query.bindValue(":id", searchTableStudentID);
    query.exec();

    manager->deleteStudent(searchTableStudentID);
    searchTable();
    showInformingAndClear("성공", "학생 삭제 완료!    ");
    return;
}

void MainWindow::onTabChanged(int index)     // 탭 클릭시 행 및 내용 지우기
{
    switch (index) {
    case 0: // 검색 탭
        searchClear();
        break;
    case 1: // 과목 탭
        courseClear();
        ui->courseTable->clearSelection();
    }
}

void MainWindow::onMajorChanged(const QString &major) {
    ui->courseCourseNameComboBox->clear();// 기존 과목 제거
    ui->courseCourseNameComboBox->addItem("");
    if (major == "컴퓨터공학과") {
        ui->courseCourseNameComboBox->addItem("운영체제");
        ui->courseCourseNameComboBox->addItem("자료구조");
        ui->courseCourseNameComboBox->addItem("알고리즘");
    }
    else if (major == "전자공학과") {
        ui->courseCourseNameComboBox->addItem("회로이론");
        ui->courseCourseNameComboBox->addItem("신호처리");
        ui->courseCourseNameComboBox->addItem("전자기학");
    }
    else if (major == "기계공학과") {
        ui->courseCourseNameComboBox->addItem("열역학");
        ui->courseCourseNameComboBox->addItem("유체역학");
        ui->courseCourseNameComboBox->addItem("재료역학");
    }
}

void MainWindow::on_searchAscPushButton_clicked() {
    int col = ui->searchSortComboBox->currentIndex();
    qDebug() << col;   // 선택된 항목의 인덱스
    bubbleSortTable(ui->searchTable, col-1, true);
}
void MainWindow::on_searchDescPushButton_clicked() {
    int col = ui->searchSortComboBox->currentIndex();
    bubbleSortTable(ui->searchTable, col-1, false);
}
void MainWindow::bubbleSortTable(QTableWidget* table, int column, bool ascending)
{
    int rows = table->rowCount();
    int cols = table->columnCount();
    qDebug() << rows;
    qDebug() << cols;

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            QTableWidgetItem* a = table->item(j, column);
            QTableWidgetItem* b = table->item(j + 1, column);
            if (!a || !b)
                continue;

            QString aText = a->text();
            QString bText = b->text();

            bool okA, okB;
            double numA = aText.toDouble(&okA);
            double numB = bText.toDouble(&okB);
            qDebug() << "aText" << aText  << "numA :" << numA << "okA : " << okA;

            bool swap = (okA && okB) ? (ascending ? numA > numB : numA < numB): (ascending ? aText > bText : aText < bText);

            if (swap) {
                // 행 전체 교환
                for (int c = 0; c < cols; ++c) {
                    QTableWidgetItem* tmp = table->takeItem(j, c);
                    table->setItem(j, c, table->takeItem(j + 1, c));
                    table->setItem(j + 1, c, tmp);
                }
            }
        }
    }
}





void MainWindow::on_searchStudentPushButton_clicked() {
    int studentID = ui->searchStudentIDText->text().toInt();
    QString name = ui->searchStudentNameText->text();
    QString year = ui->searchYearComboBox->currentText();
    QString major = ui->searchMajorComboBox->currentText();

    if(studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty()) {    // 모두 빈칸인 경우
        showWarningAndClear("실패", "학생 정보를 입력해주세요.    ");
        return;
    }
    searchStudentTable(studentID, name, year, major);

    bool result = ui->searchTable->rowCount() > 0;
    result ? showInformingAndClear("성공", "학생 정보 조회 완료.   ")
        : showWarningAndClear("실패", "존재하는 학생이 없습니다.    ");
}

void MainWindow:: on_searchAllStudentButton_clicked(){
    if(Management::manageHead == nullptr) {
        showWarningAndClear("실패", "존재하는 학번이 없습니다.   ");
        return;
    }
    else {
        searchTable();
        showInformingAndClear("성공", "학생 정보 전체 조회 완료.   ");
    }
}



void MainWindow::searchStudentTable(int stnID, QString name, QString year, QString major) {
    ui->searchTable->setRowCount(0);
    Student* currentStudent = Management::manageHead;
    int row = 0;
    while (currentStudent != nullptr) {
        bool match = true;
        if (stnID != 0 && currentStudent->getStudentID() != stnID)
            match = false;
        if (!name.isEmpty() && currentStudent->getName() != name)
            match = false;
        if (!year.isEmpty() && currentStudent->getYear() != year)
            match = false;
        if (!major.isEmpty() && !currentStudent->getMajor().contains(major, Qt::CaseInsensitive))
            match = false;

        if (match) {
            ui->searchTable->insertRow(row);
            ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
            ui->searchTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
            ui->searchTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
            ui->searchTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
            ui->searchTable->setItem(row, 4, new QTableWidgetItem(QString::number(currentStudent->getGPA())));
        }
        currentStudent = currentStudent->studentNext;
    }
}
void MainWindow::searchClear() {
    ui->searchStudentIDText->clear();
    ui->searchStudentNameText->clear();
    ui->searchYearComboBox->setCurrentIndex(0);
    ui->searchMajorComboBox->setCurrentIndex(0);
    searchTableStudentID = 0;
}



void MainWindow::on_registrationStudentPushButton_clicked() {
    int studentID = ui->searchStudentIDText->text().toInt();
    QString name = ui->searchStudentNameText->text();
    QString year = ui->searchYearComboBox->currentText();
    QString major = ui->searchMajorComboBox->currentText();

    if (studentID == 0 || name.isEmpty() || year.isEmpty() || major.isEmpty()) {
        showWarningAndClear("실패", "정보를 모두 입력해주세요   ");
        return;
    }
    else if(manager->checkStudentID(studentID)){   // 학번이 중복되지 않으면 진입
        manager->insertStudent(studentID, name, year, major);
        manager->debugInsertList();
        searchTable();
        showInformingAndClear("등록 완료", "새로운 학생이 등록되었습니다.   ");
        return;
    }
    else {
        showWarningAndClear("실패", "이미 등록한 학번입니다.   ");
        return;
    }
}






void MainWindow::searchTable() {
    ui->searchTable->setRowCount(0);  // 테이블 초기화
    int row = 0;
    Student* currentStudent = Management::manageHead;
    while (currentStudent != nullptr) { // 행으로 이동
        ui->searchTable->insertRow(row);  // 행 추가
        ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->searchTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
        ui->searchTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
        ui->searchTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
        ui->searchTable->setItem(row, 4, new QTableWidgetItem(QString::number(currentStudent->getGPA())));
        currentStudent = currentStudent->studentNext;
        row++;
    }
}


void MainWindow::on_courseSearchPushButton_clicked() {
    int studentID = ui->courseStudentIDText->text().toInt();
    QString name = ui->courseNameText->text();
    QString year = ui->courseYearComboBox->currentText();
    QString major = ui->courseMajorComboBox->currentText();
    QString courseName = ui->courseCourseNameComboBox->currentText();

    if (studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty() && courseName.isEmpty()) {
        showWarningAndClear("실패", "학생 정보를 입력해주세요.   ");
        return;
    }
    courseSearchTable(studentID, name, year, major);
    bool result = ui->courseTable->rowCount() > 0;
    result ? showInformingAndClear("성공", "조회 완료하였습니다.    ")
        : showWarningAndClear("실패", "존재하는 학생이 없습니다.    ");
}


void MainWindow::courseSearchTable(int stnID, QString name, QString year, QString major) {
    ui->courseTable->setRowCount(0);
    Student* currentStudent = Management::manageHead;

    int row = 0;
    while (currentStudent != nullptr) {
        bool match = true;
        if (stnID != 0 && currentStudent->getStudentID() != stnID)
            match = false;

        if (!name.isEmpty() && currentStudent->getName() != name)
            match = false;

        if (!year.isEmpty() && currentStudent->getYear() != year)
            match = false;

        if (!major.isEmpty() && currentStudent->getMajor() != major)
            match = false;


        if (match) {
            Course* currentCourse = currentStudent->courseList;
            if (currentCourse == nullptr) {
                ui->courseTable->insertRow(row);
                ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
                ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
                ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
                return;
            }
            else {
                while (currentCourse != nullptr) {
                    ui->courseTable->insertRow(row);
                    ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                    ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
                    ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
                    ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
                    ui->courseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
                    if(!currentCourse->getGrade().isEmpty()) {
                        ui->courseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
                    }
                    currentCourse = currentCourse->courseNext;
                    row++;
                }
            }
        }
        currentStudent  =currentStudent->studentNext;
    }
}

void MainWindow::on_courseAllSearchPushButton_clicked() {
    int row = 0;
    ui->courseTable->setRowCount(0);
    if(Management::manageHead == nullptr) {
        showWarningAndClear("실패", "존재하는 학번이 없습니다.    ");
        ui->courseTable->setRowCount(0);
        return;
    }
    Student* currentStudent = Management::manageHead;
    while (currentStudent != nullptr) {
        Course* currentCourse = currentStudent->courseList;
        if (currentCourse == nullptr) {
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
            ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
            ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
            ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
            row++;
        }
        else {
            while (currentCourse != nullptr) {
                ui->courseTable->insertRow(row);
                ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
                ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
                ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
                ui->courseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
                ui->courseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
                row++;
                currentCourse = currentCourse->courseNext;
            }
        }
        currentStudent = currentStudent->studentNext;
    }
    showInformingAndClear("성공", "전체 조회되었습니다.    ");
}




void MainWindow::on_courseTable_cellClicked(int row) {
    QTableWidgetItem* studentID = ui->courseTable->item(row, 0);
    courseTableStudentID = studentID->text().toInt();

    Student* stn = manager->createObject(courseTableStudentID);

    ui->courseStudentIDText->setText(QString::number(stn->getStudentID()));
    ui->courseNameText->setText(stn->getName());
    ui->courseYearComboBox->setCurrentText(stn->getYear());
    ui->courseMajorComboBox->setCurrentText(stn->getMajor());

    // 과목 데이터
    QTableWidgetItem* courseName = ui->courseTable->item(row, 4);
    if(courseName) {
        courseTableCourseName = courseName->text();
        qDebug() << courseTableCourseName;
        ui->courseCourseNameComboBox->setCurrentText(courseTableCourseName);
    }
}

void MainWindow::on_courseAddPushButton_clicked() {
    int studentID = ui->courseStudentIDText->text().toInt();
    QString year = ui->courseYearComboBox->currentText();
    QString major = ui->courseMajorComboBox->currentText();
    QString courseName = ui->courseCourseNameComboBox->currentText();

    if(studentID == 0 || year.isEmpty() || major.isEmpty() || courseName.isEmpty()) {
        showWarningAndClear("실패","정보를 모두 입력해주세요.   ");
        return;
    }
    Student* stn = manager->createObject(studentID);   // 학번의 객체가 존재하면 객체 리턴
    Course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseName) {
            showWarningAndClear("실패","이미 추가한 과목입니다.   ");
        }
        currentCourse = currentCourse->courseNext;
    }
    manager->addCourse(stn, courseName);
    courseTable(stn);
    showInformingAndClear("등록 완료","새로운 과목이 추가되었습니다.    ");
    return;
}
void MainWindow::on_deleteCoursePushButton_clicked() {
    if(courseTableStudentID == 0) {
        showWarningAndClear("실패", "삭제하고 싶은 셀을 선택해주세요.   ");
        return;
    }
    if(ui->courseCourseNameComboBox->currentText().isEmpty()) {
        showWarningAndClear("실패","수강 과목 먼저 등록해주세요.   ");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM enrollment WHERE studentID = :id AND courseName = :courseName;");
    query.bindValue(":id", courseTableStudentID);
    query.bindValue(":courseName", courseTableCourseName);
    query.exec();

    if(Student* stn = manager->createObject(courseTableStudentID)) {
        manager->deleteCourse(stn, courseTableCourseName);
        courseTable(stn);
        manager->debugCourseList();
        showInformingAndClear("성공","과목 삭제 완료.    ");
        return;
    }
}






void MainWindow::on_courseGradePushButton_clicked() {
    if(courseTableStudentID == 0) {
        showWarningAndClear("실패", "삭제할 행을 선택해주세요.   ");
        return;
    }
    Student* stn = manager->createObject(courseTableStudentID);
    if(stn->courseList == nullptr){
        showWarningAndClear("실패", "수강 과목을 등록해주세요.   ");
        return;
    }
    QString grade = ui->courseGradeComboBox->currentText();
    if(grade.isEmpty()){
        showWarningAndClear("실패", "학점을 입력해주세요.  ");
        return;
    }
    Course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseTableCourseName) {
            manager->updateGrade(stn, courseTableCourseName, grade);
            double GPA =  stn->calculateGPA();
            stn->SetGPA(GPA);
            courseTable(stn);
            showInformingAndClear("성공","성적 등록에 성공했습니다.   ");
            return;
        }
        currentCourse = currentCourse->courseNext;
    }
}







void MainWindow::courseTable(Student* stn) {
    ui->courseTable->setRowCount(0);
    Course* currentCourse = stn->courseList;
    int row = 0;
    if(currentCourse == nullptr) {
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->courseTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
        ui->courseTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
        ui->courseTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));
    }
    else {
        while (currentCourse != nullptr) {
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
            ui->courseTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
            ui->courseTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
            ui->courseTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));
            ui->courseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->courseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
}
void MainWindow::courseClear() {
    ui->courseStudentIDText->clear();
    ui->courseNameText->clear();
    ui->courseYearComboBox->setCurrentIndex(0);
    ui->courseMajorComboBox->setCurrentIndex(0);
    ui->courseCourseNameComboBox->setCurrentIndex(0);
    ui->courseGradeComboBox->setCurrentIndex(0);
    courseTableCourseName = "";
    courseTableStudentID = 0;
}




void MainWindow::saveDataBeforeClose() {
    Student* currentStudent = Management::manageHead;
    QSqlQuery studentQuery;

    while(currentStudent != nullptr) {
        studentQuery.prepare(R"(
        insert into student (studentID, name, year, major, GPA)
        values (:studentID, :name, :year, :major, :GPA)
        on duplicate key update
            name = values(name),
            year = values(year),
            major = values(major),
            GPA = values(GPA))");

        studentQuery.bindValue(":studentID", currentStudent->getStudentID());
        studentQuery.bindValue(":name", currentStudent->getName());
        studentQuery.bindValue(":year", currentStudent->getYear());
        studentQuery.bindValue(":major", currentStudent->getMajor());
        studentQuery.bindValue(":GPA", currentStudent->getGPA());

        if (!studentQuery.exec()) {
            qWarning() << "학생 저장 실패:" << studentQuery.lastError().text();
        }



        Course* currentCourse = currentStudent->courseList;
        QSqlQuery courseQuery;
        while(currentCourse != nullptr) {
            courseQuery.prepare(R"(
            insert into enrollment(studentID, courseName, grade)
            VALUES(:studentID, :courseName, :grade)
            ON DUPLICATE KEY UPDATE
                courseName = VALUES(courseName),
                grade = VALUES(grade)
            )");

            courseQuery.bindValue(":studentID", currentStudent->getStudentID());
            courseQuery.bindValue(":courseName", currentCourse->getCourseName());
            courseQuery.bindValue(":grade", currentCourse->getGrade());
            if (!courseQuery.exec()) {
                qWarning() << "과목 저장 실패:" << courseQuery.lastError().text();
            }
            currentCourse = currentCourse->courseNext;
        }
        currentStudent = currentStudent->studentNext;
    }
}


void MainWindow::clearAllStudents() {
    Student* currentStudent = Management::manageHead;
    while (currentStudent != nullptr) {
        Course* currentCourse = currentStudent->courseList;
        while(currentCourse != nullptr){
            Course* tempCourse = currentCourse;
            currentCourse = currentCourse->courseNext;
            delete tempCourse;
        }
        Student* tempStudent = currentStudent;
        currentStudent = currentStudent->studentNext;
        delete tempStudent;
    }
    Management::manageHead = nullptr;
}



MainWindow::~MainWindow()
{
    saveDataBeforeClose();
    clearAllStudents();
    qDebug() << "클리어 후 헤드 포인터 주소 : " << Management::manageHead  << "  mainwindow.cpp ";
    delete manager;
    delete ui;
}
