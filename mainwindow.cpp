#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    onMajorChanged(ui->courseMajorComboBox->currentText());
    connect(ui->courseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);  // 전공 바뀔 시 수강 과목 바뀜.

    connect(ui->searchStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_searchStudentIDTextEntered);   // 학번 입력
    connect(ui->searchStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_searchNameTextEntered);      // 이름 입력
    connect(ui->searchTable, &QTableWidget::cellClicked, this, &MainWindow::on_studentTable_cellClicked);      // 학생 테이블 클릭
    ui->searchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 테이블에서 데이터 수정할 수 X
    ui->searchTable->setSelectionBehavior(QAbstractItemView::SelectRows);   // 클릭시 행 전체 선택

    connect(ui->courseStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_courseStudentIDTextEntered);    // 학번 입력
    connect(ui->courseStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_courseNameTextEntered);       // 이름 입력
    connect(ui->courseTable, &QTableWidget::cellClicked, this, &MainWindow::on_courseTable_cellClicked);    // 과목 테이블 클릭
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 테이블에서 데이터 수정할 수 X
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);   // 클릭시 행 전체 선택
}

// 테이블 바깥 클릭 시
void MainWindow::mousePressEvent(QMouseEvent* event) {
    QWidget* clickedWidget = childAt(event->pos());
    if (clickedWidget != ui->searchTable && !ui->searchTable->isAncestorOf(clickedWidget)) {
        ui->searchTable->clearSelection();
    }
    if (clickedWidget != ui->courseTable && !ui->courseTable->isAncestorOf(clickedWidget)) {
        clearCourseField();
        setCourseFieldEnabled(true);
    }
    QMainWindow::mousePressEvent(event);
}




void MainWindow::showMessegeAndClear(const QString& title, const QString& message, const QString& target) {
    (target == "student"  ?  clearStudentField()  :  clearCourseField());
    (title == "성공"  ?  QMessageBox::information(this, title, message)  :  QMessageBox::warning(this, title, message));
}





void MainWindow::onTabChanged(int index)
{
    switch (index) {
    case 0:
        clearStudentField();
        break;
    case 1:
        clearCourseField();
    }
}


void MainWindow::on_searchNameTextEntered() {
    QString name = ui->searchStudentNameText->text().trimmed();
    if(!name.contains(QRegularExpression("^[a-zA-Z가-힣]+$"))) {
        QMessageBox::warning(this, "입력 오류", "알파벳 또는 올바른 한글만 가능합니다.    ");
        ui->searchStudentNameText->clear();
        ui->searchStudentNameText->setFocus();
        return;
    }
}
void MainWindow::on_courseNameTextEntered() {
    QString name = ui->courseStudentNameText->text().trimmed();
    if (!name.isEmpty() && !name.contains(QRegularExpression("^[a-zA-Z가-힣]+$"))) {
        QMessageBox::warning(this, "입력 오류", "알파벳 또는 올바른 한글만 가능합니다.    ");
        ui->courseStudentNameText->clear();
        ui->courseStudentNameText->setFocus();
        return;
    }
}
void MainWindow::on_clearStudentFieldPushButton_clicked() {
    showMessegeAndClear("성공", "입력이 초기화 되었습니다.    ", "student");
    return;
}
void MainWindow::on_clearCourseTextPushButton_clicked() {
    setCourseFieldEnabled(true);
    showMessegeAndClear("성공", "입력이 초기화 되었습니다.    ", "course");
    return;
}



void MainWindow::on_searchStudentIDTextEntered() {
    bool ok;
    ui->searchStudentIDText->text().trimmed().toInt(&ok);
    if (!ok) {
        showMessegeAndClear("실패", "학번은 숫자로 입력해주세요.   ", "student");
        ui->searchStudentIDText->clear();
        ui->searchStudentIDText->setFocus();
    }
}

void MainWindow::on_courseStudentIDTextEntered() {
    bool ok;
    ui->courseStudentIDText->text().trimmed().toInt(&ok);
    if (!ok) {
        showMessegeAndClear("실패", "학번은 숫자로 입력해주세요.  ", "course");
        ui->courseStudentIDText->setFocus();
    }
}

void MainWindow::on_studentTable_cellClicked(int clickedRow) {
    int studentIDColumn = 0;
    searchTableStudentID = ui->searchTable->item(clickedRow, studentIDColumn)->text().toInt();
}

void MainWindow::on_deleteStudentPushButton_clicked() {
    if(ui->searchTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제할 행을 선택해주세요.   ", "student");
        return;
    }
    manager->deleteStudent(searchTableStudentID);
    manager->deleteStudentDB(searchTableStudentID);
    studentTable(Management::manageHead);
    totalStudentCount();  // 총 학생 수
    showMessegeAndClear("성공", "학생 삭제 완료!   ", "student");
}


void MainWindow::onMajorChanged(const QString &major) {
    ui->courseCourseNameComboBox->clear();
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
    int column = ui->searchSortComboBox->currentIndex();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSort(ui->searchTable, column, true);
        return;
    }
    bubbleSort(ui->searchTable, column-1, true);
}

void MainWindow::on_searchDescPushButton_clicked() {
    int column = ui->searchSortComboBox->currentIndex();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSort(ui->searchTable, column, false);
        return;
    }
    bubbleSort(ui->searchTable, column-1, false);
}

void MainWindow::bubbleSort(QTableWidget* table, int column, bool ascending) {
    int rowCount = table->rowCount();
    int columnCount = table->columnCount();

    for (int i = 0; i < rowCount - 1; i++) {
        for (int currentRowIndex = 0; currentRowIndex < rowCount - i - 1; currentRowIndex++) {
            QTableWidgetItem* currentRowItem = table->item(currentRowIndex, column);
            QTableWidgetItem* nextRowItem = table->item(currentRowIndex + 1, column);
            if (currentRowItem == nullptr || nextRowItem == nullptr)
                continue;

            bool currentNumeric, nextNumeric;  // 숫자로 변환 가능하면 true,

            double currentRowData = currentRowItem->text().toDouble(&currentNumeric);  // 숫자로 변환하지 못 하면 0.0
            double nextRowData = nextRowItem->text().toDouble(&nextNumeric);

            if (((currentNumeric && nextNumeric)
                ? (ascending  ?  currentRowData > nextRowData  :  currentRowData < nextRowData)
                : (ascending  ?  currentRowItem->text() > nextRowItem->text()  :  currentRowItem->text() < nextRowItem->text())))


            for (int columnIndex = 0; columnIndex < columnCount; columnIndex++) {
                QTableWidgetItem* tmp = table->takeItem(currentRowIndex, columnIndex);
                table->setItem(currentRowIndex, columnIndex, table->takeItem(currentRowIndex + 1, columnIndex));
                table->setItem(currentRowIndex + 1, columnIndex, tmp);
            }

        }
    }
    applyStudentTableRowColors(ui->searchTable);
}


void MainWindow::setStudentInfo(int& studentID, QString& name, QString& year, QString& major) {
    studentID = ui->searchStudentIDText->text().toInt();
    name = ui->searchStudentNameText->text();
    year = ui->searchYearComboBox->currentText();
    major = ui->searchMajorComboBox->currentText();
}

void MainWindow::on_searchStudentPushButton_clicked() {
    int studentID;
    QString name, year, major;
    setStudentInfo(studentID, name, year, major);

    if(studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty()) {
        showMessegeAndClear("실패", "학생 정보를 입력해주세요.   ", "student");
    }
    else {
        searchStudent(studentID, name, year, major);
        ui->searchTable->rowCount() > 0 ? showMessegeAndClear("성공", "학생 정보 조회 완료.   ", "student")
                                        : showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ", "student");
    }
}

void MainWindow:: on_searchAllStudentButton_clicked(){
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ", "student");
        return;
    }
    studentTable(Management::manageHead);
    showMessegeAndClear("성공", "학생 정보 전체 조회 완료.   ", "student");
}

void MainWindow::totalStudentCount() {
    int count = ui->searchTable->rowCount();
    ui->totalStudent->setText(QString("총 등록 학생 수 : %1명").arg(count));
}
















void MainWindow::searchStudent(int stnID, QString name, QString year, QString major) {
    ui->searchTable->setRowCount(0);

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
            int row = 0;
            applyStudentTableRow(ui->searchTable, row, currentStudent);
            row++;
        }
        currentStudent = currentStudent->studentNext;
    }

    applyStudentTableRowColors(ui->searchTable);
}




void MainWindow::applyStudentTableRowColors(QTableWidget* studentTable) {
    for (int row = 0; row < studentTable->rowCount(); row++) {
        QColor backgroundColor = (row % 2 == 0) ? QColor("#ffffff") : QColor("#f0f0f0");

        for (int column = 0; column <  studentTable->columnCount(); column++) {
            QTableWidgetItem* cellData = studentTable->item(row, column);
            if (cellData) {
                cellData->setBackground(backgroundColor);
            }
        }
    }
}


void MainWindow::clearStudentField() {
    ui->searchStudentIDText->clear();
    ui->searchStudentNameText->clear();
    ui->searchYearComboBox->setCurrentIndex(0);
    ui->searchMajorComboBox->setCurrentIndex(0);
    searchTableStudentID = 0;
    ui->searchTable->clearSelection();
}


//  수강 과목 데이터 입력창 활성화 및 비활성화 함수
void MainWindow::setCourseFieldEnabled(bool enabled) {
    ui->courseStudentIDText->setEnabled(enabled);
    ui->courseStudentNameText->setEnabled(enabled);
    ui->courseYearComboBox->setEnabled(enabled);
    ui->courseMajorComboBox->setEnabled(enabled);
}


void MainWindow::on_registrationStudentPushButton_clicked() {
    int studentID;
    QString name, year, major;
    setStudentInfo(studentID, name, year, major);
    if (studentID == 0 || name.isEmpty() || year.isEmpty() || major.isEmpty()) {
        showMessegeAndClear("실패", "정보를 모두 입력해주세요.   ", "student");
        return;
    }
    if(!manager->checkStudentID(studentID)){ // 학번이 중복되면 실패
        showMessegeAndClear("실패", "이미 등록한 학번입니다.   ", "student");
        return;
    }
    manager->insertStudent(studentID, name, year, major);
    studentTable(Management::manageHead);
    totalStudentCount();
    showMessegeAndClear("등록 완료", "새로운 학생이 등록되었습니다.   ", "student");
}

void MainWindow::setCourseInfo(int& studentID, QString& name, QString& year, QString& major, QString& courseName) {
    studentID = ui->courseStudentIDText->text().toInt();
    name = ui->courseStudentNameText->text();
    year = ui->courseYearComboBox->currentText();
    major = ui->courseMajorComboBox->currentText();
    courseName = ui->courseCourseNameComboBox->currentText();
}

void MainWindow::on_courseSearchPushButton_clicked() {
    int studentID;
    QString name, year, major, courseName;
    setCourseInfo(studentID, name, year, major, courseName);

    if (studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty() && courseName.isEmpty()) {
        showMessegeAndClear("실패", "학생 정보를 입력해주세요.   ", "course");
        return;
    }
    searchStudent(studentID, name, year, major, courseName);
    ui->courseTable->rowCount() > 0 ?showMessegeAndClear("성공", "조회 완료하였습니다.  ", "course") : showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ", "course");
}

void MainWindow::searchStudent(int stnID, QString name, QString year, QString major, QString courseName) {
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
            Course* currentCourse = currentStudent->courseList;
            bool hasCourse = false;

            while (currentCourse != nullptr) {
                if (currentCourse->getCourseName() == courseName) {
                    hasCourse = true;
                    break;
                }
                currentCourse = currentCourse->courseNext;
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


void MainWindow::studentTable(Student* currentStudent) {
    int row = 0;
    ui->searchTable->setRowCount(0);
    while (currentStudent != nullptr) {
        applyStudentTableRow(ui->searchTable, row, currentStudent);  // 한 행씩 출력
        row++;
        currentStudent = currentStudent->studentNext;
    }
    totalStudentCount();
    applyStudentTableRowColors(ui->searchTable);
}
void MainWindow::applyStudentTableRow(QTableWidget* searchTable, int row, Student* student) {
    int column = 0;
    searchTable->insertRow(row);
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getStudentID())));
    searchTable->setItem(row, column++, new QTableWidgetItem(student->getName()));
    searchTable->setItem(row, column++, new QTableWidgetItem(student->getYear()));
    searchTable->setItem(row, column++, new QTableWidgetItem(student->getMajor()));
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getGPA())));
}






void MainWindow::courseTable(Student* stduent) {
    int row = 0;
    ui->courseTable->setRowCount(0);
    Course* currentCourse = stduent->courseList;

    if(currentCourse == nullptr) {
        int column = 0;
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(stduent->getStudentID())));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getName()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getYear()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getMajor()));
    }
    else {
        while(currentCourse != nullptr) {
            int column = 0;
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(stduent->getStudentID())));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getYear()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(stduent->getMajor()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getGrade()));
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
}


void MainWindow::on_courseAddPushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString courseName = ui->courseCourseNameComboBox->currentText();

    if (ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "테이블의 행을 선택해주세요.  ", "course");
        return;
    }
    if(courseName.isEmpty()) {
        showMessegeAndClear("실패", "수강할 과목을 선택해주세요.  ", "course");
        return;
    }
    if(manager->checkCourseName(student, courseName)) {
        showMessegeAndClear("실패", "이미 추가한 과목입니다. ", "course");
        return;
    }
    manager->addCourse(student, courseName);
    courseTable(student);
    showMessegeAndClear("성공", "수강 과목 등록 성공하였습니다. ", "course");
}



void MainWindow::on_courseAllSearchPushButton_clicked() {
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ", "course");
        return;
    }
    courseAllTable();
    applyCourseTableRowColors(ui->courseTable);
    showMessegeAndClear("성공", "전체 조회되었습니다.   ", "course");
}

void MainWindow::courseAllTable() {
    ui->courseTable->setRowCount(0);
    int row = 0;
    Student* currentStudent = Management::manageHead;
    while(currentStudent != nullptr) {
        Course* currentCourse = currentStudent->courseList;
        if(currentCourse == nullptr) {
            int column = 0;
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getYear()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getMajor()));
            row++;
        }
        else {
            while(currentCourse != nullptr) {
                int column = 0;
                ui->courseTable->insertRow(row);
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getName()));
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getYear()));
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getMajor()));
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getCourseName()));
                ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getGrade()));
                row++;
                currentCourse = currentCourse->courseNext;
            }
        }

        currentStudent = currentStudent->studentNext;
    }
}








// courseTable 셀 클릭
void MainWindow::on_courseTable_cellClicked(int clickedRow) {
    setCourseFieldEnabled(false);

    int studentIDColumn = 0;
    courseTableStudentID = ui->courseTable->item(clickedRow, studentIDColumn)->text().toInt();

    Student* student = manager->createObject(courseTableStudentID);
    ui->courseStudentIDText->setText(QString::number(student->getStudentID()));
    ui->courseStudentNameText->setText(student->getName());
    ui->courseYearComboBox->setCurrentText(student->getYear());
    ui->courseMajorComboBox->setCurrentText(student->getMajor());

    // 선택한 행에서 수강 과목이 존재할 경우 -->  과목 이름 변수에 저장 및 필드에 출력
    int courseNameIndex = 4;
    QTableWidgetItem* courseData = ui->courseTable->item(clickedRow, courseNameIndex);
    if(courseData != nullptr) {
        courseTableCourseName = courseData->text();
        ui->courseCourseNameComboBox->setCurrentText(courseTableCourseName);
    }
    else {
        courseTableCourseName = "";
        ui->courseCourseNameComboBox->setCurrentText("");
    }
}




void MainWindow::on_deleteCoursePushButton_clicked() {
    if(ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제할 행을 선택해주세요.   ", "course");
        return;
    }
    int courseNameColumn = 4;
    if(ui->courseTable->item(ui->courseTable->currentRow(), courseNameColumn) == nullptr) {
        showMessegeAndClear("실패", "수강 과목을 먼저 등록해주세요.   ", "course");
        return;
    }
    Student* student = manager->createObject(courseTableStudentID);
    manager->deleteCourse(student, courseTableCourseName);
    manager->deleteCourseDB(courseTableStudentID, courseTableCourseName);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공","과목 삭제 완료.  ", "course");
}


void MainWindow::on_courseGradePushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString grade = ui->courseGradeComboBox->currentText();

    if(courseTableStudentID == 0) {
        showMessegeAndClear("실패", "학점 등록할 행을 선택해주세요.   ", "course");
        return;
    }
    if(student->courseList == nullptr) {
        showMessegeAndClear("실패", "수강 과목 등록해주세요.   ", "course");
        return;
    }
    if(grade.isEmpty()){
        showMessegeAndClear("실패", "학점을 등록해주세요.   ", "course");
        return;
    }
    manager->updateGrade(student, courseTableCourseName, grade);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공", "성적 등록에 성공했습니다.   ", "course");
}


void MainWindow::applyCourseTableRowColors(QTableWidget* courseTable) {
    int prevStudentID = 0;
    QColor currentColor = QColor("#ffffff");

    for (int row = 0; row < courseTable->rowCount(); row++) {
        int studentID = courseTable->item(row, 0)->text().toInt();

        if (studentID != prevStudentID) {  // 이전 학번과 클릭한 학번이 다를 때.
            currentColor = (currentColor == QColor("#ffffff")) ? QColor("#f0f0f0") : QColor("#ffffff");
            prevStudentID = studentID;
        }

        for (int column = 0; column < courseTable->columnCount(); column++) {
            QTableWidgetItem* cellData = courseTable->item(row, column);
            if(cellData)
                cellData->setBackground(currentColor);
        }
    }

}
void MainWindow::clearCourseField() {
    ui->courseStudentIDText->clear();
    ui->courseStudentNameText->clear();
    ui->courseYearComboBox->setCurrentIndex(0);
    ui->courseMajorComboBox->setCurrentIndex(0);
    ui->courseCourseNameComboBox->setCurrentIndex(0);
    ui->courseGradeComboBox->setCurrentIndex(0);

    ui->courseTable->clearSelection();
    courseTableStudentID = 0;
    courseTableCourseName = "";
}



void MainWindow::saveStudentsBeforeClose() {
    Student* currentStudent = Management::manageHead;
    QSqlQuery studentQuery;

    while(currentStudent != nullptr) {
        studentQuery.prepare(R"(
        INSERT INTO student(studentID, name, year, major, GPA)
        VALUES(:studentID, :name, :year, :major, :GPA)
        ON DUPLICATE KEY UPDATE
        name = VALUES(name), year = VALUES(year), major = VALUES(major), GPA = VALUES(GPA))");
        studentQuery.bindValue(":studentID", currentStudent->getStudentID());
        studentQuery.bindValue(":name", currentStudent->getName());
        studentQuery.bindValue(":year", currentStudent->getYear());
        studentQuery.bindValue(":major", currentStudent->getMajor());
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
            currentCourse = currentCourse->courseNext;   // delete 전 노드 먼저 옮김
            delete tempCourse;
        }
        Student* tempStudent = currentStudent;
        currentStudent = currentStudent->studentNext;    // delete 전 노드 먼저 옮김
        delete tempStudent;
    }

    Management::manageHead = nullptr;
}

MainWindow::~MainWindow()
{
    saveStudentsBeforeClose();
    clearAllStudents();
    qDebug() << "클리어 후 헤드 포인터 주소 : " << Management::manageHead  << "  mainwindow.cpp ";
    delete manager;
    delete ui;
}
