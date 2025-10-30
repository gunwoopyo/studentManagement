#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QMouseEvent>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->searchTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::onSearchTableDoubleClicked); // searchTable 에서 특정 행 더블 클릭 시 courseTable로 넘어가 학생 정보 출력
    connect(ui->courseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged); // 수강 과목 페이지에서 전공 바꿀 시 수강 과목 변경 함수
    onMajorChanged(ui->courseMajorComboBox->currentText());

    connect(ui->searchStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_searchStudentIDTextEntered);  // 학생 등록 페이지 - 학번 입력 시 유효성 검사 함수
    connect(ui->searchStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_searchNameTextEntered); // 학생 등록 페이지 - 이름 입력 시 유효성 검사 함수
    connect(ui->searchTable, &QTableWidget::cellClicked, this, &MainWindow::on_studentTable_cellClicked);  // 학생 등록 페이지의 테이블 클릭 함수
    ui->searchTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 학생 등록 테이블에서 데이터 수정할 수 X
    ui->searchTable->setSelectionBehavior(QAbstractItemView::SelectRows); // 학생 등록 테이블에서 행 클릭시 셀이 아닌 행 전체 선택

    connect(ui->courseStudentIDText, &QLineEdit::editingFinished, this, &MainWindow::on_courseStudentIDTextEntered);  // 과목 페이지 - 학번 입력 시 유효성 검사 함수
    connect(ui->courseStudentNameText, &QLineEdit::editingFinished, this, &MainWindow::on_courseNameTextEntered);  // 과목 페이지 - 이름 입력 시 유효성 검사 함수
    connect(ui->courseTable, &QTableWidget::cellClicked, this, &MainWindow::on_courseTable_cellClicked);  // 과목 페이지의 테이블 클릭 함수
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 과목 테이블에서 데이터 수정할 수 X
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);   // 과목 테이블에서 행 클릭스 셀이 아닌 행 전체 선택

    ui->searchStudentIDText->setPlaceholderText("숫자 입력(최대 4자리)");
    ui->searchStudentNameText->setPlaceholderText("한글 입력(최대 5자리)");
    ui->courseStudentIDText->setPlaceholderText("숫자 입력(최대 4자리)");
    ui->courseStudentNameText->setPlaceholderText("한글 입력(최대 5자리)");
}



void MainWindow::onSearchTableDoubleClicked() {
    ui->tabWidget->setCurrentIndex(1);
    clearCourseField();
    courseTable(manager->createObject(searchTableStudentID));
}


void MainWindow::mousePressEvent(QMouseEvent* event) { // 테이블 클릭 시
    QWidget* clickedWidget = childAt(event->pos());
    if (clickedWidget != ui->searchTable  &&  !ui->searchTable->isAncestorOf(clickedWidget)) {
        ui->searchTable->clearSelection();     // 셀 행 열 모두 해제
    }
    if (clickedWidget != ui->courseTable  &&  !ui->courseTable->isAncestorOf(clickedWidget)) {
        clearCourseField();             // 셀 행 열 모두 해제 및 입력창 필드 모두 해제
        setCourseFieldEnabled(true);    // 입력창 필드 활성화
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::showMessegeAndClear(const QString& title, const QString& message, const QString& clearTargetField) {
    QMessageBox messageBox(this);
    messageBox.setWindowTitle(title);
    messageBox.setText(message);

    if(title == "성공") {
        messageBox.setIcon(QMessageBox::Information);
    }
    else {
        messageBox.setIcon(QMessageBox::Warning);
    }

    QRect mainWindowGeometry  = this->frameGeometry();
    QPoint mainWindowCenter  = mainWindowGeometry.center();
    QSize messageBoxSize = messageBox.sizeHint();
    QPoint messageBoxPosition = mainWindowCenter - QPoint(messageBoxSize.width()/2, messageBoxSize.height()/2);

    messageBox.move(messageBoxPosition);
    messageBox.exec();

    (clearTargetField == "clearStudentField"   ?   clearStudentField()   :   clearCourseField());
}

void MainWindow::onTabChanged(int index) {
    switch (index) {
    case 0:
        clearStudentField();
        break;
    case 1:
        clearCourseField();
    }
}




void MainWindow::on_clearStudentFieldPushButton_clicked() {
#include <QMessageBox>
#include "mainwindow.h"
    showMessegeAndClear("성공", "입력 초기화 완료  ", "clearStudentField");
    return;
}

void MainWindow::on_clearCourseFieldPushButton_clicked() {
    setCourseFieldEnabled(true);
    showMessegeAndClear("성공", "입력 초기화 완료  ", "clearCourseField");
    return;
}

void MainWindow::on_searchStudentIDTextEntered() {
    bool isNum;
    ui->searchStudentIDText->text().trimmed().toInt(&isNum);
    if (!isNum) {
        showMessegeAndClear("실패", "학번은 숫자로 입력해주세요  ", "clearStudentField");
        ui->searchStudentIDText->setFocus();
        return;
    }
    if(ui->searchStudentIDText->text().trimmed().length() > 4) {
        showMessegeAndClear("실패", "학번은 숫자 4자리까지만 입력 가능  ", "clearStudentField");
        ui->searchStudentIDText->setFocus();
    }
}
void MainWindow::on_courseStudentIDTextEntered() {
    bool isNum;
    ui->courseStudentIDText->text().trimmed().toInt(&isNum);
    if (!isNum) {
        showMessegeAndClear("실패", "학번은 숫자로 입력해주세요  ", "clearCourseField");
        ui->courseStudentIDText->setFocus();
        return;
    }
    if(ui->courseStudentIDText->text().trimmed().length() > 4) {
        showMessegeAndClear("실패", "학번은 4자리 숫자까지만 입력 가능  ", "clearCourseField");
        ui->courseStudentIDText->setFocus();
    }
}

//a-zA-Z
void MainWindow::on_searchNameTextEntered() {
    QString name = ui->searchStudentNameText->text().trimmed();
    if(!name.contains(QRegularExpression("^[가-힣]+$"))) {
        showMessegeAndClear("실패", "올바른 한글만 가능합니다  ", "clearStudentField");
        ui->searchStudentNameText->setFocus();
        return;
    }
    if(name.length() > 5) {
        showMessegeAndClear("실패", "이름은 5자리까지만 입력 가능  ", "clearStudentField");
        ui->searchStudentNameText->setFocus();
    }
}

//a-zA-Z
void MainWindow::on_courseNameTextEntered() {
    QString name = ui->courseStudentNameText->text().trimmed();
    if (!name.isEmpty() && !name.contains(QRegularExpression("^[가-힣]+$"))) {
        showMessegeAndClear("실패", "올바른 한글만 가능합니다  ", "clearCourseField");
        ui->courseStudentNameText->setFocus();
        return;
    }
    if(name.length() > 5) {
        showMessegeAndClear("실패", "이름은 5자리까지만 입력 가능  ", "clearCourseField");
        ui->courseStudentNameText->setFocus();
    }
}



void MainWindow::on_studentTable_cellClicked(int clickedRow) {
    int studentIDColumn = 0;
    searchTableStudentID = ui->searchTable->item(clickedRow, studentIDColumn)->text().toInt();
}

void MainWindow::on_deleteStudentPushButton_clicked() {
    if(ui->searchTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제할 행을 선택해주세요  ", "clearStudentField");
        return;
    }
    manager->deleteStudent(searchTableStudentID);
    manager->deleteStudentDB(searchTableStudentID);
    studentTable();
    showMessegeAndClear("성공", "학생 정보 삭제 완료  ", "clearStudentField");
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
    if(ui->searchSortComboBox->currentText() == "정렬 기준") {
        showMessegeAndClear("실패", "다시 선택해주세요  ", "clearStudentField");
        return;
    }

    int column = ui->searchSortComboBox->currentIndex();
    if(ui->searchSortComboBox->currentText() == "평균 학점") {
        bubbleSort(ui->searchTable, column, true);
        return;
    }
    bubbleSort(ui->searchTable, column-1, true);
}

void MainWindow::on_searchDescPushButton_clicked() {
    if(ui->searchSortComboBox->currentText() == "정렬 기준") {
        showMessegeAndClear("실패", "다시 선택해주세요  ", "clearStudentField");
        return;
    }

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
        for (int row = 0;  row < rowCount - i - 1;  row++) {
            QTableWidgetItem* currentRowItem = table->item(row, column);
            QTableWidgetItem* nextRowItem = table->item(row + 1, column);

            bool currentIsNum, nextIsNum; // 숫자로 변환 가능하면 true,

            // double로 변환 성공 : currentIsNum -> true, currentRowData에 저장.
            // double로 변환 실패 : currentIsNum -> false, 0 저장.
            double currentRowData = currentRowItem->text().toDouble(&currentIsNum);
            double nextRowData = nextRowItem->text().toDouble(&nextIsNum);


            // 정렬 대상이 숫자인지 아닌지 확인 --> 현재 행, 다음 행이 모두 숫자면 text() xxx
            if(((currentIsNum && nextIsNum)   ?   (ascending  ?  currentRowData  >  nextRowData  :  currentRowData  <  nextRowData)
                                              :   (ascending  ?  currentRowItem->text() > nextRowItem->text()  :  currentRowItem->text()  <  nextRowItem->text())))

            // setItem(행 번호, 열 번호, 뽑을 데이터)
            // swap
            for (int col = 0; col < columnCount; col++) {
                QTableWidgetItem* tmp = table->takeItem(row, col);
                table->setItem(row, col, table->takeItem(row + 1, col));
                table->setItem(row + 1, col, tmp);
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
        showMessegeAndClear("실패", "학생 정보를 입력해주세요  ", "clearStudentField");
        return;
    }
    searchStudent(studentID, name, year, major);
    ui->searchTable->rowCount() > 0   ?   showMessegeAndClear("성공", "학생 정보 조회 완료!  ", "clearStudentField")
                                    :   showMessegeAndClear("실패", "존재하는 학생 정보가 없습니다  ", "clearStudentField");
}

void MainWindow:: on_searchAllStudentButton_clicked() {
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생 정보가 없습니다  ", "clearStudentField");
        return;
    }
    studentTable();
    showMessegeAndClear("성공", "학생 정보 전체 조회 완료!  ", "clearStudentField");
}



void MainWindow::totalStudentCount() {
    int count = ui->searchTable->rowCount();
    ui->totalStudent->setText(QString("총 등록 학생 수 : %1명").arg(count));
}





void MainWindow::searchStudent(int studentID, QString name, QString year, QString major) {
    ui->searchTable->setRowCount(0);
    int row = 0;
    Student* currentStudent = Management::manageHead;
    while (currentStudent != nullptr) {
        bool studentFounded = true;

        if (studentID != 0 && currentStudent->getStudentID() != studentID)
            studentFounded = false;

        if (!name.isEmpty() && currentStudent->getName() != name)
            studentFounded = false;

        if (!year.isEmpty() && currentStudent->getYear() != year)
            studentFounded = false;

        if (!major.isEmpty() && currentStudent->getMajor() != major)
            studentFounded = false;

        // 만약 major 콤보박스로만 학생 조회를 했다면 나머지 변수는 empty 이므로 통과.
        // 반복문을 통해 입력한 전공을 가진 학생의 전공과 같으면 match는 true. 객체 정보를 테이블로 출력.
        if (studentFounded == true) {
            insertStudentTableRow(currentStudent, row);
            row++;
        }
        currentStudent = currentStudent->studentNext;
    }
    applyStudentTableRowColors(ui->searchTable);
}

void MainWindow::insertStudentTableRow(Student* student, int row) {
    int column = 0;
    ui->searchTable->insertRow(row);
    ui->searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getStudentID())));
    ui->searchTable->setItem(row, column++, new QTableWidgetItem(student->getName()));
    ui->searchTable->setItem(row, column++, new QTableWidgetItem(student->getYear()));
    ui->searchTable->setItem(row, column++, new QTableWidgetItem(student->getMajor()));
    if(student->getGPA() == 0.0) {
        ui->searchTable->setItem(row, column++, new QTableWidgetItem("학점 미입력"));
    }
    else {
        ui->searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(student->getGPA())));
    }
}


void MainWindow::applyStudentTableRowColors(QTableWidget* studentTable) {
    for (int row = 0;  row < studentTable->rowCount();  row++) {   // 행 잡고 각 컬럼 반복 --> 이중 for문
        QColor backgroundColor = (row % 2 == 0)   ?   QColor("#ffffff")   :   QColor("#f0f0f0");  // 짝수 행과 홀수 행 색 다르게 함.

        for (int column = 0;  column < studentTable->columnCount();  column++) {
            studentTable->item(row, column)->setBackground(backgroundColor);
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
        showMessegeAndClear("실패", "정보를 모두 입력해주세요  ", "clearStudentField");
        return;
    }
    if(!manager->checkStudentID(studentID)){  // 학번이 중복되면 실패
        showMessegeAndClear("실패", "이미 등록되어 있는 학번입니다  ", "clearStudentField");
        return;
    }
    manager->insertStudent(studentID, name, year, major);
    studentTable();
    showMessegeAndClear("성공", "학생 정보 등록 완료  ", "clearStudentField");
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
        showMessegeAndClear("실패", "학생 정보를 입력해주세요  ", "clearCourseField");
        return;
    }


    searchStudent(studentID, name, year, major, courseName);
    ui->courseTable->rowCount() > 0 ?  showMessegeAndClear("성공", "학생 정보 조회 완료!  ", "clearCourseField")
                                    :  showMessegeAndClear("실패", "존재하는 학생정보가 없습니다  ", "clearCourseField");
}

bool MainWindow::matchesStudent(Student* student, int studentID, const QString& name, const QString& year, const QString& major, const QString& courseName) {

    if (studentID != 0 && student->getStudentID() != studentID)
        return false;

    if (!name.isEmpty() && student->getName() != name)
        return false;

    if (!year.isEmpty() && student->getYear() != year)
        return false;

    if (!major.isEmpty() && student->getMajor() != major)
        return false;

    if (!courseName.isEmpty()) {
        Course* currentCourse = student->courseList;

        while(currentCourse != nullptr) {
            if (currentCourse->getCourseName() == courseName) {
                return true;
            }
            currentCourse = currentCourse->courseNext;
        }
        return false;
    }

    return true;
}


void MainWindow::addStudentsToCourseTable(Student* student, const QString& courseName, int& row) {
    Course* currentCourse = student->courseList;
    // 수강 과목이 없는 경우
    if (currentCourse == nullptr) {
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(student->getStudentID())));
        ui->courseTable->setItem(row, 1, new QTableWidgetItem(student->getName()));
        ui->courseTable->setItem(row, 2, new QTableWidgetItem(student->getYear()));
        ui->courseTable->setItem(row, 3, new QTableWidgetItem(student->getMajor()));
        row++;
        return;
    }

    while(currentCourse != nullptr) {
        if(!courseName.isEmpty() && currentCourse->getCourseName() != courseName) {
            currentCourse = currentCourse->courseNext;
            continue;
        }
        ui->courseTable->insertRow(row);
        ui->courseTable->setItem(row, 0, new QTableWidgetItem(QString::number(student->getStudentID())));
        ui->courseTable->setItem(row, 1, new QTableWidgetItem(student->getName()));
        ui->courseTable->setItem(row, 2, new QTableWidgetItem(student->getYear()));
        ui->courseTable->setItem(row, 3, new QTableWidgetItem(student->getMajor()));
        ui->courseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));

        if(!currentCourse->getGrade().isEmpty())
            ui->courseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));

        row++;
        currentCourse = currentCourse->courseNext;
    }

}



void MainWindow::searchStudent(int studentID, QString name, QString year, QString major, QString courseName) {
    ui->courseTable->setRowCount(0);   // 행 개수 0으로 설정 --> all 데이터 삭제
    int row = 0;
    Student* currentStudent = Management::manageHead;

    while (currentStudent != nullptr) {
        if (matchesStudent(currentStudent, studentID, name, year, major, courseName) == true) {
            addStudentsToCourseTable(currentStudent, courseName, row);
        }
        currentStudent = currentStudent->studentNext;
    }

    applyCourseTableRowColors(ui->courseTable);
}


// studentTable() --> null
// studentTable(something) --> not null.
void MainWindow::studentTable(Student* student) {
    int row = 0;
    ui->searchTable->setRowCount(0);

    Student* currentStudent =  (student != nullptr)  ?  student  :  Management::manageHead;
    while(currentStudent != nullptr) {
        int column = 0;
        ui->searchTable->insertRow(row);
        ui->searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getName()));
        ui->searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getYear()));
        ui->searchTable->setItem(row, column++, new QTableWidgetItem(currentStudent->getMajor()));
        if(currentStudent->getGPA() == 0) {
            ui->searchTable->setItem(row, column++, new QTableWidgetItem("학점 미입력"));
        }
        else {
            ui->searchTable->setItem(row, column++, new QTableWidgetItem(QString::number(currentStudent->getGPA())));
        }

        // 학생 혼자면 While문 돌지 않고 break로 While문 탈출
        if(student != nullptr) {
            break;
        }

        row++;
        currentStudent = currentStudent->studentNext;
    }

    totalStudentCount();   // 총 학생 수
    applyStudentTableRowColors(ui->searchTable);
}



// courseTable() 호출 --> null
// courseTable(something) 호출 --> not null
void MainWindow::courseTable(Student* singleStduent) {
    int row = 0;
    ui->courseTable->setRowCount(0);
    Student* currentStudent = singleStduent   ?   singleStduent   :   Management::manageHead;   // 삼항 연산자로 head인지 판단.

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

        //  학생 혼자면 while문 돌지 않고 break로 반복문 탈출
        if(singleStduent != nullptr) {
            break;
        }

        currentStudent = currentStudent->studentNext;
    }
    applyCourseTableRowColors(ui->courseTable);
}


void MainWindow::on_courseAddPushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString courseName = ui->courseCourseNameComboBox->currentText();

    if (ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "테이블 행을 선택해주세요  ", "clearCourseField");
        return;
    }
    if(courseName.isEmpty()) {
        showMessegeAndClear("실패", "수강 과목을 선택해주세요  ", "clearCourseField");
        return;
    }
    if(manager->checkCourseName(student, courseName)) {
        showMessegeAndClear("실패", "이미 추가한 과목입니다  ", "clearCourseField");
        return;
    }
    manager->addCourse(student, courseName);
    courseTable(student);
    showMessegeAndClear("성공", "수강 과목 등록 성공!  ", "clearCourseField");
}


void MainWindow::on_courseAllSearchPushButton_clicked() {
    if(Management::manageHead == nullptr) {
        showMessegeAndClear("실패", "존재하는 학생 정보가 없습니다  ", "clearCourseField");
        return;
    }
    courseTable();
    showMessegeAndClear("성공", "학생 정보 전체 조회 완료!  ", "clearCourseField");
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

    // 선택한 행에서 수강 과목이 존재할 경우 -->  과목 이름 변수에 저장.
    int courseNameIndex = 4;
    QTableWidgetItem* courseName = ui->courseTable->item(clickedRow, courseNameIndex);
    if(courseName != nullptr) {
        courseTableCourseName = courseName->text();
        ui->courseCourseNameComboBox->setCurrentText(courseTableCourseName);
    }
    else {
        courseTableCourseName = "";
        ui->courseCourseNameComboBox->setCurrentText("");
    }
}




void MainWindow::on_deleteCoursePushButton_clicked() {
    if(ui->courseTable->selectedItems().isEmpty()) {
        showMessegeAndClear("실패", "삭제하고 싶은 행을 선택해주세요  ", "clearCourseField");
        return;
    }

    int courseNameColumn = 4;
    if(ui->courseTable->item(ui->courseTable->currentRow(), courseNameColumn)->text().isEmpty()) {
        showMessegeAndClear("실패", "수강 과목을 등록해주세요  ", "clearCourseField");
        return;
    }
    Student* student = manager->createObject(courseTableStudentID);
    manager->deleteCourse(student, courseTableCourseName);
    manager->deleteCourseDB(courseTableStudentID, courseTableCourseName);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공","과목 삭제 완료  ", "clearCourseField");
}


void MainWindow::on_courseGradePushButton_clicked() {
    Student* student = manager->createObject(courseTableStudentID);
    QString grade = ui->courseGradeComboBox->currentText();

    if(courseTableStudentID == 0) {
        showMessegeAndClear("실패", "테이블 행을 선택해주세요  ", "clearCourseField");
        return;
    }
    if(student->courseList == nullptr) {
        showMessegeAndClear("실패", "수강 과목 등록해주세요  ", "clearCourseField");
        return;
    }
    if(grade.isEmpty()){
        showMessegeAndClear("실패", "학점을 등록해주세요  ", "clearCourseField");
        return;
    }
    manager->updateGrade(student, courseTableCourseName, grade);
    student->SetGPA(student->calculateGPA());
    courseTable(student);
    showMessegeAndClear("성공", "성적 등록 성공!  ", "clearCourseField");
}


void MainWindow::applyCourseTableRowColors(QTableWidget* courseTable) {
    int studentIDColumn = 0;
    int prevStudentID = 0;
    QColor currentColor = QColor("#ffffff");

    for (int row = 0; row < courseTable->rowCount(); row++) {  // 행 간 학번이 같으면 똑같은 색. 다르면 다른색.
        int studentID = courseTable->item(row, studentIDColumn)->text().toInt();

        if (prevStudentID != studentID) {  // 이전 학번과 행의 학번이 다르면 색 변경.
            currentColor =  (currentColor == QColor("#ffffff"))  ?  QColor("#f0f0f0")  :  QColor("#ffffff");
            prevStudentID = studentID;
        }

        for (int column = 0;  column < courseTable->columnCount();  column++) {  // 특정 행의 모든 컬럼에 같은 색 대입.
            QTableWidgetItem* cellPointer = courseTable->item(row, column);

            if(cellPointer == nullptr) {
                cellPointer = new QTableWidgetItem();   // cellPointer에 참조값 생성 ((동적 생성))
                courseTable->setItem(row, column, cellPointer);
            }

            cellPointer->setBackground(currentColor);
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
            INSERT INTO enrollment(studentID, courseName, grade)
            VALUES(:studentID, :courseName, :grade)
            ON DUPLICATE KEY UPDATE
            courseName = VALUES(courseName), grade = VALUES(grade))");
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


MainWindow::~MainWindow() {
    saveStudentsBeforeClose();
    clearAllStudents();
    delete manager;
    delete ui;
}
