#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);




    onMajorChanged(ui->courseMajorComboBox->currentText());
    connect(ui->courseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);  // 전공 바뀔 시 수강 과목 바뀜.

    connect(ui->searchStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_searchStudentIDTextEntered);
    connect(ui->searchStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_searchNameTextEntered);
    connect(ui->searchTable, &QTableWidget::cellClicked, this, &MainWindow::on_studentTable_cellClicked);
    ui->searchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 테이블에서 데이터 수정할 수 xxx
    ui->searchTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // 클릭시 행 전체 선택

    connect(ui->courseStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_courseStudentIDTextEntered);
    connect(ui->courseStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_courseNameTextEntered);
    connect(ui->courseTable, &QTableWidget::cellClicked, this, &MainWindow::on_courseTable_cellClicked);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 테이블에서 데이터 수정할 수 xxx
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);   // 클릭시 행 전체 선택
}


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

void MainWindow::showMessegeAndClear(const QString& title, const QString& message) {
    clearStudentField();
    clearCourseField();
    if (title == "성공") {
        QMessageBox::information(this, title, message);
    }
    else {
        QMessageBox::warning(this, title, message);
    }
}



void MainWindow::on_searchStudentIDTextEntered() {
    QString studentID = ui->searchStudentIDText->text().trimmed();
    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentIDToString) {
        showMessegeAndClear("실패", "학번은 숫자로 입력해주세요.    ");
        ui->searchStudentIDText->clear();
        ui->searchStudentIDText->setFocus();
    }
}
void MainWindow::onTabChanged(int index)    // 탭 클릭시 행 및 내용 지우기
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
void MainWindow::on_clearStudentTextPushButton_clicked() {
    showMessegeAndClear("성공", "입력이 초기화 되었습니다.    ");
    return;
}
void MainWindow::on_clearCourseTextPushButton_clicked() {
    setCourseFieldEnabled(true);
    showMessegeAndClear("성공", "입력이 초기화 되었습니다.    ");
    return;
}
void MainWindow::on_courseStudentIDTextEntered() {
    QString studentID = ui->courseStudentIDText->text().trimmed();

    bool studentIDToString;
    studentID.toInt(&studentIDToString);
    if (!studentID.isEmpty() && !studentIDToString) {
        showMessegeAndClear("입력 오류", "학번은 숫자만 입력 가능합니다.   ");
        ui->courseStudentIDText->setFocus();
    }
}

void MainWindow::on_studentTable_cellClicked(int clickedRow) {
    int studentIDColumn = 0;
    searchTableStudentID = ui->searchTable->item(clickedRow, studentIDColumn)->text().toInt();
}

void MainWindow::on_deleteStudentPushButton_clicked() {
    if(ui->searchTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제할 행을 선택해주세요.   ");
        return;
    }

    manager->deleteStudent(searchTableStudentID);
    manager->deleteStudentDB(searchTableStudentID);
    studentTable(Management::manageHead);
    totalStudentCount();
    showMessegeAndClear("성공", "학생 삭제 완료!   ");
}


void MainWindow::onMajorChanged(const QString &major) {
    ui->courseNameComboBox->clear();
    ui->courseNameComboBox->addItem("");
    if (major == "컴퓨터공학과") {
        ui->courseNameComboBox->addItem("운영체제");
        ui->courseNameComboBox->addItem("자료구조");
        ui->courseNameComboBox->addItem("알고리즘");
    }
    else if (major == "전자공학과") {
        ui->courseNameComboBox->addItem("회로이론");
        ui->courseNameComboBox->addItem("신호처리");
        ui->courseNameComboBox->addItem("전자기학");
    }
    else if (major == "기계공학과") {
        ui->courseNameComboBox->addItem("열역학");
        ui->courseNameComboBox->addItem("유체역학");
        ui->courseNameComboBox->addItem("재료역학");
    }
}

void MainWindow::on_ascPushButton_clicked() {
    int col = ui->searchSortComboBox->currentIndex();
    qDebug() << ui->searchSortComboBox->currentText();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSort(ui->searchTable, col, true);
        return;
    }
    bubbleSort(ui->searchTable, col-1, true);
}
void MainWindow::on_descPushButton_clicked() {
    int col = ui->searchSortComboBox->currentIndex();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSort(ui->searchTable, col, false);
        return;
    }
    bubbleSort(ui->searchTable, col-1, false);
}
void MainWindow::bubbleSort(QTableWidget* table, int column, bool ascending) {
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
        showMessegeAndClear("실패", "학생 정보를 입력해주세요.   ");
    }
    else {
        searchStudent(studentID, name, year, major);
        ui->searchTable->rowCount() > 0 ? showMessegeAndClear("성공", "학생 정보 조회 완료.   ") :showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ");
    }
}

void MainWindow:: on_searchAllStudentButton_clicked(){
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ");
        return;
    }
    studentTable(Management::manageHead);
    showMessegeAndClear("성공", "학생 정보 전체 조회 완료.   ");
}



void MainWindow::totalStudentCount() {
    int count = ui->searchTable->rowCount();
    ui->totalStudent->setText(QString("총 등록 학생 수 : %1명").arg(count));
}










void MainWindow::studentTable(Student* currentStudent) {
    ui->searchTable->setRowCount(0);
    int row = 0;
    while (currentStudent != nullptr) {
        applyStudentTableRow(ui->searchTable, row, currentStudent);
        row++;
        currentStudent = currentStudent->studentNext;
    }
    applyStudentTableRowColors(ui->searchTable);
    totalStudentCount();
}




void MainWindow::searchStudent(int stnID, QString name, QString year, QString major) {
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
            applyStudentTableRow(ui->searchTable, row, currentStudent);
            row++;
        }
        currentStudent = currentStudent->studentNext;
    }
    applyStudentTableRowColors(ui->searchTable);
}

void MainWindow::applyStudentTableRow(QTableWidget* searchTable, int row, Student* currentStudent) {
    int column = 0;
    searchTable->insertRow(row);
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getName()));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getYear()));
    searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getMajor()));
    searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getGPA())));
}


void MainWindow::applyStudentTableRowColors(QTableWidget* studentTable) {
    for (int row = 0; row < studentTable->rowCount(); row++) {
        QColor backgroundColor = (row % 2 == 0) ? QColor("#ffffff") : QColor("#f0f0f0");

        for (int column = 0; column < studentTable->columnCount(); column++) {
            QTableWidgetItem* data = studentTable->item(row, column);
            if (data)
                data->setBackground(backgroundColor);
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
        showMessegeAndClear("실패", "정보를 모두 입력해주세요.   ");
        return;
    }
    if(manager->checkStudentID(studentID)){     // 학번이 중복되지 않으면 실행
        manager->insertStudent(studentID, name, year, major);
        studentTable(Management::manageHead);
        totalStudentCount();
        showMessegeAndClear("등록 완료", "새로운 학생이 등록되었습니다.   ");
        return;
    }
    showMessegeAndClear("실패", "이미 등록한 학번입니다.   ");
}

void MainWindow::setCourseInfo(int& studentID, QString& name, QString& year, QString& major, QString& courseName) {
    studentID = ui->courseStudentIDText->text().toInt();
    name = ui->courseStudentNameText->text();
    year = ui->courseYearComboBox->currentText();
    major = ui->courseMajorComboBox->currentText();
    courseName = ui->courseNameComboBox->currentText();
}

void MainWindow::on_courseSearchPushButton_clicked() {
    int studentID;
    QString name, year, major, courseName;
    setCourseInfo(studentID, name, year, major, courseName);

    if (studentID == 0 && name.isEmpty() && year.isEmpty() && major.isEmpty() && courseName.isEmpty()) {
        showMessegeAndClear("실패", "학생 정보를 입력해주세요.   ");
        return;
    }
    searchStudent(studentID, name, year, major, courseName);
    ui->courseTable->rowCount() > 0 ? showMessegeAndClear("성공", "조회 완료하였습니다.   "): showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ");
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
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생이 없습니다.   ");
        return;
    }
    searchAllStudent();
    showMessegeAndClear("성공", "전체 조회되었습니다.   ");
}


void MainWindow::searchAllStudent() {
    ui->courseTable->setRowCount(0);
    int row = 0;
    Student* currentStudent = Management::manageHead;

    while(currentStudent != nullptr) {
       Course* currentCourse = currentStudent->courseList;
        if(currentCourse == nullptr) {
           ui->courseTable->insertRow(row);
           ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
           ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
           ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
           ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
           row++;
        }
        else {
            while(currentCourse != nullptr) {
                ui->courseTable->insertRow(row);
                ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
                ui->courseTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
                ui->courseTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
                ui->courseTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
                ui->courseTable->setItem(row, 4,  new QTableWidgetItem(currentCourse->getCourseName()));
                ui->courseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
                row++;
                currentCourse = currentCourse->courseNext;
            }
        }
        currentStudent = currentStudent->studentNext;
    }
}



void MainWindow::courseTable(Student* student) {
    ui->courseTable->setRowCount(0);
    Course* currentCourse = student->courseList;
    int row = 0;
    int column = 0;
    if(currentCourse == nullptr) {
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getStudentID())));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getName()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getYear()));
        ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getMajor()));
    }
    else {
        while (currentCourse != nullptr) {
            ui->courseTable->insertRow(row);
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getStudentID())));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getYear()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(student->getMajor()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->courseTable->setItem(row, column++, new QTableWidgetItem(currentCourse->getGrade()));
            column = 0;
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
    applyCourseTableRowColors(ui->courseTable);
}

void MainWindow::on_courseTable_cellClicked(int clickedRow) {
    // 필드 비활성화
    setCourseFieldEnabled(false);

    // 클릭한 행의 학번 저장.
    int studentIDIndex = 0;
    int courseNameIndex = 4;
    int gradeIndex = 5;
    courseTableStudentID = ui->courseTable->item(clickedRow, studentIDIndex)->text().toInt();

    // 클릭시 필드에 학생 정보 출력
    Student* student = manager->createObject(courseTableStudentID);
    ui->courseStudentIDText->setText(QString::number(student->getStudentID()));
    ui->courseStudentNameText->setText(student->getName());
    ui->courseYearComboBox->setCurrentText(student->getYear());
    ui->courseMajorComboBox->setCurrentText(student->getMajor());

    // 선택한 행에서 수강 과목이 존재할 경우 -->  과목 이름 변수에 저장.
    QTableWidgetItem* courseData = ui->courseTable->item(clickedRow, courseNameIndex);
    if(courseData != nullptr) {
        CourseTableCourseName = courseData->text();
        ui->courseNameComboBox->setCurrentText(CourseTableCourseName);
    }
    else {
        CourseTableCourseName = "";
    }
}

void MainWindow::on_courseAddPushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    if (ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "테이블의 행을 선택해주세요.   ");
        return;
    }
    if(ui->courseNameComboBox->currentText().isEmpty()) {
        showMessegeAndClear("실패", "수강할 과목을 선택해주세요.   ");
        return;
    }
    if(manager->checkCourseName(student, ui->courseNameComboBox->currentText())) {
        showMessegeAndClear("실패", "이미 추가한 과목입니다.   ");
        return;
    }
    manager->addCourse(student, ui->courseNameComboBox->currentText());
    courseTable(student);
    showMessegeAndClear("성공", "수강 과목 등록 성공하였습니다.   ");
}


void MainWindow::on_deleteCoursePushButton_clicked() {
    int courseNameColumn = 4;
    if(ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제할 행을 선택해주세요.   ");
        return;
    }
    if(ui->courseTable->item(ui->courseTable->currentRow(), courseNameColumn) == nullptr) {
        showMessegeAndClear("실패", "수강 과목을 먼저 등록해주세요.   ");
        return;
    }

    Student* student = manager->createObject(courseTableStudentID);
    manager->deleteCourse(student, CourseTableCourseName);
    manager->deleteCourseDB(courseTableStudentID, CourseTableCourseName);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공","과목 삭제 완료.   ");
}


void MainWindow::on_courseGradePushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString grade = ui->courseGradeComboBox->currentText();

    if(courseTableStudentID == 0) {
        showMessegeAndClear("실패", "학점 등록할 행을 선택해주세요.   ");
        return;
    }
    if(student->courseList == nullptr) {
        showMessegeAndClear("실패", "수강 과목 등록해주세요.   ");
        return;
    }
    if(grade.isEmpty()){
        showMessegeAndClear("실패", "학점을 등록해주세요.   ");
        return;
    }
    manager->updateGrade(student, CourseTableCourseName, grade);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공", "성적 등록에 성공했습니다.   ");
}






void MainWindow::applyCourseTableRowColors(QTableWidget* courseTable) {
    int prevStudentID = 0;
    QColor currentColor = QColor("#ffffff");
    for (int row = 0; row < courseTable->rowCount(); row++) {
        QTableWidgetItem* idItem = courseTable->item(row, 0);  // 0번 열 = 학번
        if (!idItem)
            continue;

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
void MainWindow::clearCourseField() {
    ui->courseStudentIDText->clear();
    ui->courseStudentNameText->clear();
    ui->courseYearComboBox->setCurrentIndex(0);
    ui->courseMajorComboBox->setCurrentIndex(0);
    ui->courseNameComboBox->setCurrentIndex(0);
    ui->courseGradeComboBox->setCurrentIndex(0);
    ui->courseTable->clearSelection();
    CourseTableCourseName = "";
    courseTableStudentID = 0;

}
void MainWindow::saveStudentDataBeforeClose() {
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

void MainWindow::clearAllStudentsObjects() {
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
    saveStudentDataBeforeClose();

    clearAllStudentsObjects();
    qDebug() << "클리어 후 헤드 포인터 주소 : " << Management::manageHead  << "  mainwindow.cpp ";
    delete manager;
    delete ui;
}
