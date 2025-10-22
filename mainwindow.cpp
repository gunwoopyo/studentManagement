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
    //this->setFixedSize(1000, 750);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    connect(ui->courseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->courseMajorComboBox->currentText());

    connect(ui->searchStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_searchStudentIDTextEntered);
    connect(ui->searchStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_searchNameTextEntered);
    connect(ui->searchTable, &QTableWidget::cellClicked, this, &MainWindow::on_deleteStudentTable_cellClicked);
    ui->searchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->searchTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->courseStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_courseStudentIDTextEntered);  // 학번 창 입력 시 이벤트.
    connect(ui->courseNameText, &QLineEdit::editingFinished, this, &MainWindow::on_courseNameTextEntered);
    connect(ui->courseTable, &QTableWidget::cellClicked, this, &MainWindow::on_courseTable_cellClicked);   //셀 클릭 시 이벤트 발생.
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 셀에서 수정할 수 없음.
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);   // 클릭 시 행 전체 선택.
}
void MainWindow::showWarningAndClear(const QString& title, const QString& message) {
    searchClear();
    courseClear();
    QMessageBox::warning(this, title, message);
}
void MainWindow::showInformingAndClear(const QString& title, const QString& message) {
    QMessageBox::information(this, title, message);
    searchClear();
    courseClear();

}
void MainWindow::on_searchStudentIDTextEntered() {
    QString studentID = ui->searchStudentIDText->text().trimmed();
    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentIDToString) {
        showWarningAndClear("실패", "학번은 숫자로 입력해주세요.    ");
        ui->searchStudentIDText->clear();
        ui->searchStudentIDText->setFocus();
    }
}
void MainWindow::on_searchNameTextEntered() {
    QString name = ui->searchStudentNameText->text().trimmed();
    if(!name.contains(QRegularExpression("^[a-zA-Z가-힣]+$"))) {
        QMessageBox::warning(this, "입력 오류", "이름은 알파벳 또는 올바른 한글 문자만 가능합니다.    ");
        ui->searchStudentNameText->clear();
        ui->searchStudentNameText->setFocus();
        return;
    }
}
void MainWindow::on_courseNameTextEntered() {
    QString name = ui->courseNameText->text().trimmed();
    if (!name.contains(QRegularExpression("^[a-zA-Z가-힣]+$"))) {
        QMessageBox::warning(this, "입력 오류", "이름은 알파벳 또는 올바른 한글 문자만 가능합니다.    ");
        ui->courseNameText->clear();
        ui->courseNameText->setFocus();
        return;
    }
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
    Student* currentStudent = manager->createObject(studentIDInt);

    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentIDToString) {
        showWarningAndClear("입력 오류", "학번은 숫자만 입력 가능합니다.   ");
        ui->courseStudentIDText->setFocus();
        return;
    }
    else if (currentStudent) {
        ui->courseNameText->setText(currentStudent->getName());
        ui->courseYearComboBox->setCurrentText(currentStudent->getYear());
        ui->courseMajorComboBox->setCurrentText(currentStudent->getMajor());
        return;
    }
    else {
        showWarningAndClear("찾을 수 없음", "해당 학번의 학생이 없습니다.    ");
        return;
    }
}
void MainWindow::on_deleteStudentTable_cellClicked(int row) {
    QTableWidgetItem* studentID = ui->searchTable->item(row, 0);
    searchTableStudentID = studentID->text().toInt();
}
void MainWindow::on_deleteStudentPushButton_clicked() {
    if(searchTableStudentID == 0) {
        showWarningAndClear("실패", "삭제할 셀을 선택해주세요.   ");
        return;
    }
    else {
        QSqlQuery query;
        query.prepare("DELETE FROM student WHERE studentID = :id;");
        query.bindValue(":id", searchTableStudentID);
        query.exec();

        query.prepare("DELETE FROM enrollment WHERE studentID = :id;");
        query.bindValue(":id", searchTableStudentID);
        query.exec();

        manager->deleteStudent(searchTableStudentID);
        searchTable(Management::manageHead);
        totalStudentCount();
        showInformingAndClear("성공", "학생 삭제 완료!   ");
    }

}
void MainWindow::onTabChanged(int index)     // 탭 클릭시 행 및 내용 지우기
{
    switch (index) {
    case 0: // 검색 탭
        searchClear();
        break;
    case 1: // 과목 탭
        courseClear();
    }
}
void MainWindow::onMajorChanged(const QString &major) {
    ui->courseCourseNameComboBox->clear();        // 기존 과목 제거
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
    qDebug() << ui->searchSortComboBox->currentText();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSortTable(ui->searchTable, col, true);
        return;
    }
    bubbleSortTable(ui->searchTable, col-1, true);
}
void MainWindow::on_searchDescPushButton_clicked() {
    int col = ui->searchSortComboBox->currentIndex();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSortTable(ui->searchTable, col, false);
        return;
    }
    bubbleSortTable(ui->searchTable, col-1, false);
}
void MainWindow::bubbleSortTable(QTableWidget* table, int column, bool ascending)
{
    int rows = table->rowCount();
    int cols = table->columnCount();

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            QTableWidgetItem* a = table->item(j, column);
            QTableWidgetItem* b = table->item(j + 1, column);
            if (!a || !b)
                continue;

            QString aText = a->text();
            QString bText = b->text();
            qDebug() << "텍스트 a : " << aText << " 텍스트 b : " <<bText;

            bool okA, okB;
            double numA = aText.toDouble(&okA);
            double numB = bText.toDouble(&okB);

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
    applySearchTableRowColors(ui->searchTable);
}
void MainWindow::setSearchStudentInfo(int& studentID, QString& name, QString& year, QString& major) {
    studentID = ui->searchStudentIDText->text().toInt();
    name = ui->searchStudentNameText->text();
    year = ui->searchYearComboBox->currentText();
    major = ui->searchMajorComboBox->currentText();
}
void MainWindow::on_searchStudentPushButton_clicked() {
    int studentID;
    QString name, year, major;
    setSearchStudentInfo(studentID, name, year, major);

    if(studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty()) {    // 모두 빈칸인 경우
        showWarningAndClear("실패", "학생 정보를 입력해주세요.    ");
        return;
    }
    else {
        searchStudentTable(studentID, name, year, major);
        bool result = ui->searchTable->rowCount() > 0;
        result ? showInformingAndClear("성공", "학생 정보 조회 완료.   ")
               :showWarningAndClear("실패", "존재하는 학생이 없습니다.   ");
    }
}
void MainWindow:: on_searchAllStudentButton_clicked(){
    if(Management::manageHead == nullptr) {
        showWarningAndClear("실패", "존재하는 학생이 없습니다.   ");
        return;
    }
    else {
        searchTable(Management::manageHead);
        showInformingAndClear("성공", "학생 정보 전체 조회 완료.   ");
        return;
    }
}
void MainWindow::searchTable(Student* headPointer) {
    ui->searchTable->setRowCount(0);  // 테이블 초기화
    int row = 0;
    while (headPointer != nullptr) { // 행으로 이동
        applySearchTableRow(ui->searchTable, row, headPointer);
        row++;
        headPointer = headPointer->studentNext;
    }
    applySearchTableRowColors(ui->searchTable);
    totalStudentCount();
}
void MainWindow::totalStudentCount() {
    int count = ui->searchTable->rowCount();
    ui->totalStudent->setText(QString("총 등록 학생 수 : %1명").arg(count));
}
void MainWindow::searchStudentTable(int stnID, QString name, QString year, QString major) {
    ui->searchTable->setRowCount(0);
    int row = 0;
    Student* currentStudent = Management::manageHead;
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
            applySearchTableRow(ui->searchTable, row, currentStudent);
            row++;
        }
        currentStudent = currentStudent->studentNext;
    }
    applySearchTableRowColors(ui->searchTable);
}
void MainWindow::applySearchTableRow(QTableWidget* searchTable, int row, Student* currentStudent) {
    int column = 0;
    searchTable->insertRow(row);
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getName()));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getYear()));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getMajor()));
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getGPA())));
}
void MainWindow::applySearchTableRowColors(QTableWidget* studentTable) {
    for (int row = 0; row < studentTable->rowCount(); row++) {
        QColor backgroundColor = (row % 2 == 0) ? QColor("#ffffff") : QColor("#f0f0f0");

        for (int column = 0; column < studentTable->columnCount(); column++) {
            QTableWidgetItem* data = studentTable->item(row, column);
            if (data)
                data->setBackground(backgroundColor);
        }
    }
}
void MainWindow::searchClear() {
    ui->searchStudentIDText->clear();
    ui->searchStudentNameText->clear();
    ui->searchYearComboBox->setCurrentIndex(0);
    ui->searchMajorComboBox->setCurrentIndex(0);
    searchTableStudentID = 0;
    ui->searchTable->clearSelection();
}
void MainWindow::on_registrationStudentPushButton_clicked() {
    int studentID;
    QString name, year, major;
    setSearchStudentInfo(studentID, name, year, major);

    if (studentID == 0 || name.isEmpty() || year.isEmpty() || major.isEmpty()) {
        showWarningAndClear("실패", "정보를 모두 입력해주세요   ");
        return;
    }
    else if(manager->checkStudentID(studentID)){     // 학번이 중복되지 않으면 실행
        manager->insertStudent(studentID, name, year, major);
        searchTable(Management::manageHead);
        totalStudentCount();
        showInformingAndClear("등록 완료", "새로운 학생이 등록되었습니다.   ");
        return;
    }
    else {
        showWarningAndClear("실패", "이미 등록한 학번입니다.   ");
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
    else {
        courseSearchTable(studentID, name, year, major, courseName);
        bool result = ui->courseTable->rowCount() > 0;
        result ? showInformingAndClear("성공", "조회 완료하였습니다.    ")
               : showWarningAndClear("실패", "존재하는 학생이 없습니다.    ");
    }
}
void MainWindow::courseSearchTable(int stnID, QString name, QString year, QString major, QString courseName) {
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

        if (!courseName.isEmpty()) {
            Course* tempCourse = currentStudent->courseList;
            bool hasCourse = false;

            while (tempCourse != nullptr) {
                if (tempCourse->getCourseName() == courseName) {
                    hasCourse = true;
                    break;
                }
                tempCourse = tempCourse->courseNext;
            }

            if (!hasCourse)
                match = false;
        }
        if (match) {
            Course* currentCourse = currentStudent->courseList;
            if (currentCourse == nullptr) {
                ui->courseTable->insertRow(row);
                ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
                ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
                ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
            }
            else {
                while (currentCourse != nullptr) {
                    if (!courseName.isEmpty() && currentCourse->getCourseName() != courseName) {
                        currentCourse = currentCourse->courseNext;
                        continue;
                    }
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
    applyCourseTableRowColors(ui->courseTable);
}
void MainWindow::on_courseAllSearchPushButton_clicked() {
    ui->courseTable->setRowCount(0);
    if(Management::manageHead == nullptr) {
        showWarningAndClear("실패", "존재하는 학생이 없습니다.   ");
        return;
    }
    else {
        Student* currentStudent = Management::manageHead;
        int row = 0;
        while (currentStudent != nullptr) {
            Course* currentCourse = currentStudent->courseList;
            if (currentCourse == nullptr) {
                insertCourseTable(row++, currentStudent, nullptr);
            }
            else {
                while (currentCourse != nullptr) {
                    insertCourseTable(row++, currentStudent, currentCourse);
                    currentCourse = currentCourse->courseNext;
                }
            }
            currentStudent = currentStudent->studentNext;
        }
        showInformingAndClear("성공", "전체 조회되었습니다.   ");
    }
}
void MainWindow::insertCourseTable(int row, Student* student, Course* course) {
    ui->courseTable->insertRow(row);
    ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(student->getStudentID())));
    ui->courseTable->setItem(row, 1, new QTableWidgetItem(student->getName()));
    ui->courseTable->setItem(row, 2, new QTableWidgetItem(student->getYear()));
    ui->courseTable->setItem(row, 3, new QTableWidgetItem(student->getMajor()));

    if (course != nullptr) {
        ui->courseTable->setItem(row, 4, new QTableWidgetItem(course->getCourseName()));
        ui->courseTable->setItem(row, 5, new QTableWidgetItem(course->getGrade()));
    }
    applyCourseTableRowColors(ui->courseTable);
}
void MainWindow::courseTable(Student* stn) {
    qDebug() << "1";
    ui->courseTable->setRowCount(0);
    Course* currentCourse = stn->courseList;
    int row = 0;
    int column = 0;
    if(currentCourse == nullptr) {
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getName()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getYear()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getMajor()));
    }
    else {
        while (currentCourse != nullptr) {
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(stn->getStudentID())));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getYear()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stn->getMajor()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getGrade()));
            column = 0;
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
    applyCourseTableRowColors(ui->courseTable);
}
void MainWindow::on_courseTable_cellClicked(int row) {
    QTableWidgetItem* studentID = ui->courseTable->item(row, 0);
    courseTableStudentID = studentID->text().toInt();
    Student* stn = manager->createObject(courseTableStudentID);

    ui->courseStudentIDText->setText(QString::number(stn->getStudentID()));
    ui->courseNameText->setText(stn->getName());
    ui->courseYearComboBox->setCurrentText(stn->getYear());
    ui->courseMajorComboBox->setCurrentText(stn->getMajor());

    QTableWidgetItem* courseName = ui->courseTable->item(row, 4);

    if(courseName) {
        courseTableCourseName = courseName->text();
        ui->courseCourseNameComboBox->setCurrentText(courseTableCourseName);
    }
    else {
        ui->courseCourseNameComboBox->setCurrentText("");
    }
}
void MainWindow::on_courseAddPushButton_clicked() {
    int studentID = ui->courseStudentIDText->text().toInt();
    Student* student = manager->createObject(studentID);
    QString courseName = ui->courseCourseNameComboBox->currentText();

    if(studentID == 0 || courseName.isEmpty()) {
        showWarningAndClear("실패", "학생 정보 또는 수강 과목을 입력해주세요.   ");
        return;
    }
    else if(manager->checkCourseName(student, courseName)) {
        showWarningAndClear("실패","이미 추가한 과목입니다.   ");
        return;
    }
    else {
        manager->addCourse(student, courseName);
        courseTable(student);
        showInformingAndClear("등록 완료","새로운 과목이 추가되었습니다.   ");
    }
}
void MainWindow::on_deleteCoursePushButton_clicked() {
    if(courseTableStudentID == 0) {
        showWarningAndClear("실패", "삭제하고 싶은 셀을 선택해주세요.   ");
        return;
    }
    else if(ui->courseCourseNameComboBox->currentText().isEmpty()) {
        showWarningAndClear("실패","수강 과목 먼저 등록해주세요.   ");
        return;
    }
    else {
        Student* student = manager->createObject(courseTableStudentID);
        manager->deleteCourse(student, courseTableCourseName);
        double GPA =  student->calculateGPA();
        student->SetGPA(GPA);
        courseTable(student);
        manager->debugCourseList();

        QSqlQuery query;
        query.prepare("DELETE FROM enrollment WHERE studentID = :id AND courseName = :courseName;");
        query.bindValue(":id", courseTableStudentID);
        query.bindValue(":courseName", courseTableCourseName);
        query.exec();
        showInformingAndClear("성공","과목 삭제 완료.   ");
    }
}
void MainWindow::on_courseGradePushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString grade = ui->courseGradeComboBox->currentText();

    if(courseTableStudentID == 0) {
        showWarningAndClear("실패", "학점 등록할 행을 선택해주세요.   ");
        return;
    }
    else if(student->courseList == nullptr || grade.isEmpty()){
        showWarningAndClear("실패", "수강 과목을 등록 또는 학점을 등록해주세요.   ");
        return;
    }
    else {
        manager->updateGrade(student, courseTableCourseName, grade);
        double GPA =  student->calculateGPA();
        student->SetGPA(GPA);
        courseTable(student);
        showInformingAndClear("성공","성적 등록에 성공했습니다.   ");
    }
}
void MainWindow::applyCourseTableRowColors(QTableWidget* courseTable) {
    int prevStudentID = 0;
    QColor currentColor = QColor("#ffffff");
    for (int row = 0; row < courseTable->rowCount(); row++) {
        QTableWidgetItem* idItem = courseTable->item(row, 0);  // 0번 열 = 학번
        if (!idItem) continue;

        int studentID = idItem->text().toInt();

        if (studentID != prevStudentID) {
            currentColor = (currentColor == QColor("#ffffff")) ? QColor("#f0f0f0") : QColor("#ffffff");
            prevStudentID = studentID;
        }

        for (int column = 0; column < courseTable->columnCount(); column++) {
            QTableWidgetItem* data = courseTable->item(row, column);
            if(data)
                data->setBackground(currentColor);
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
    ui->courseTable->clearSelection();
}
void MainWindow::saveDataBeforeClose() {
    Student* currentStudent = Management::manageHead;
    QSqlQuery studentQuery;

    while(currentStudent != nullptr) {
        studentQuery.prepare(R"(
        INSERT INTO student(studentID, name, year, major, GPA) VALUES(:studentID, :name, :year, :major, :GPA)
        ON DUPLICATE KEY UPDATE GPA = VALUES(GPA))");
        studentQuery.bindValue(":GPA", currentStudent->getGPA());
        studentQuery.exec();

        Course* currentCourse = currentStudent->courseList;
        QSqlQuery courseQuery;

        while(currentCourse != nullptr) {
            courseQuery.prepare(R"(
            INSERT INTO enrollment(studentID, courseName, grade) VALUES(:studentID, :courseName, :grade)
            ON DUPLICATE KEY UPDATE courseName = VALUES(courseName), grade = VALUES(grade))");
            courseQuery.bindValue(":studentID", currentStudent->getStudentID());
            courseQuery.bindValue(":courseName", currentCourse->getCourseName());
            courseQuery.bindValue(":grade", currentCourse->getGrade());
            courseQuery.exec();
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
