/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *search;
    QFrame *searchFrame;
    QLineEdit *searchStudentIDText;
    QComboBox *searchYearComboBox;
    QLabel *searchYear;
    QComboBox *searchMajorComboBox;
    QLabel *searchMajor;
    QLabel *searchStudentID;
    QLineEdit *searchStudentNameText;
    QLabel *searchStudentName;
    QPushButton *registrationStudentPushButton;
    QTableWidget *searchTable;
    QLabel *label;
    QComboBox *searchSortComboBox;
    QToolButton *searchAscPushButton;
    QToolButton *searchDescPushButton;
    QPushButton *deleteStudentPushButton;
    QPushButton *searchStudentPushButton;
    QPushButton *searchAllStudentButton;
    QLabel *label_7;
    QPushButton *clearStudentDataPushButton;
    QWidget *addCourse;
    QFrame *addCourseFrame;
    QLineEdit *courseStudentIDText;
    QLabel *courseStudentID;
    QLabel *courseMajor;
    QLabel *courseYear;
    QComboBox *courseYearComboBox;
    QLabel *courseName;
    QLineEdit *courseNameText;
    QPushButton *courseAddPushButton;
    QLabel *courseCourseName;
    QComboBox *courseCourseNameComboBox;
    QComboBox *courseMajorComboBox;
    QTableWidget *courseTable;
    QLabel *label_6;
    QPushButton *courseSearchPushButton;
    QPushButton *courseAllSearchPushButton;
    QLabel *courseGrade;
    QComboBox *courseGradeComboBox;
    QPushButton *courseGradePushButton;
    QPushButton *deleteCoursePushButton;
    QPushButton *clearCourseDataPushButton;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(979, 743);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 60, 931, 621));
        search = new QWidget();
        search->setObjectName("search");
        searchFrame = new QFrame(search);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setGeometry(QRect(40, 70, 851, 101));
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Raised);
        searchStudentIDText = new QLineEdit(searchFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(70, 30, 101, 26));
        searchYearComboBox = new QComboBox(searchFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(430, 30, 101, 26));
        searchYear = new QLabel(searchFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(390, 30, 31, 18));
        QFont font1;
        font1.setPointSize(12);
        searchYear->setFont(font1);
        searchMajorComboBox = new QComboBox(searchFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(610, 30, 101, 26));
        searchMajor = new QLabel(searchFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(570, 30, 31, 18));
        searchMajor->setFont(font1);
        searchStudentID = new QLabel(searchFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(30, 30, 31, 18));
        searchStudentID->setFont(font1);
        searchStudentNameText = new QLineEdit(searchFrame);
        searchStudentNameText->setObjectName("searchStudentNameText");
        searchStudentNameText->setGeometry(QRect(250, 30, 101, 26));
        searchStudentName = new QLabel(searchFrame);
        searchStudentName->setObjectName("searchStudentName");
        searchStudentName->setGeometry(QRect(210, 30, 31, 18));
        searchStudentName->setFont(font1);
        registrationStudentPushButton = new QPushButton(searchFrame);
        registrationStudentPushButton->setObjectName("registrationStudentPushButton");
        registrationStudentPushButton->setGeometry(QRect(750, 20, 71, 51));
        QFont font2;
        font2.setPointSize(11);
        registrationStudentPushButton->setFont(font2);
        searchTable = new QTableWidget(search);
        if (searchTable->columnCount() < 5)
            searchTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        searchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        searchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        searchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        searchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        searchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        searchTable->setObjectName("searchTable");
        searchTable->setGeometry(QRect(120, 250, 721, 281));
        searchTable->horizontalHeader()->setDefaultSectionSize(140);
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 220, 81, 18));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        label->setFont(font3);
        searchSortComboBox = new QComboBox(search);
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->setObjectName("searchSortComboBox");
        searchSortComboBox->setGeometry(QRect(210, 210, 111, 31));
        searchAscPushButton = new QToolButton(search);
        searchAscPushButton->setObjectName("searchAscPushButton");
        searchAscPushButton->setGeometry(QRect(340, 210, 26, 31));
        searchDescPushButton = new QToolButton(search);
        searchDescPushButton->setObjectName("searchDescPushButton");
        searchDescPushButton->setGeometry(QRect(370, 210, 26, 31));
        deleteStudentPushButton = new QPushButton(search);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(750, 210, 91, 31));
        deleteStudentPushButton->setFont(font2);
        searchStudentPushButton = new QPushButton(search);
        searchStudentPushButton->setObjectName("searchStudentPushButton");
        searchStudentPushButton->setGeometry(QRect(720, 30, 81, 31));
        searchStudentPushButton->setFont(font2);
        searchAllStudentButton = new QPushButton(search);
        searchAllStudentButton->setObjectName("searchAllStudentButton");
        searchAllStudentButton->setGeometry(QRect(810, 30, 81, 31));
        searchAllStudentButton->setFont(font2);
        label_7 = new QLabel(search);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 30, 231, 31));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        label_7->setFont(font4);
        clearStudentDataPushButton = new QPushButton(search);
        clearStudentDataPushButton->setObjectName("clearStudentDataPushButton");
        clearStudentDataPushButton->setGeometry(QRect(630, 30, 81, 31));
        clearStudentDataPushButton->setFont(font2);
        tabWidget->addTab(search, QString());
        addCourse = new QWidget();
        addCourse->setObjectName("addCourse");
        addCourseFrame = new QFrame(addCourse);
        addCourseFrame->setObjectName("addCourseFrame");
        addCourseFrame->setGeometry(QRect(40, 70, 851, 101));
        addCourseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addCourseFrame->setFrameShadow(QFrame::Shadow::Raised);
        courseStudentIDText = new QLineEdit(addCourseFrame);
        courseStudentIDText->setObjectName("courseStudentIDText");
        courseStudentIDText->setGeometry(QRect(110, 20, 101, 26));
        courseStudentID = new QLabel(addCourseFrame);
        courseStudentID->setObjectName("courseStudentID");
        courseStudentID->setGeometry(QRect(60, 20, 31, 18));
        courseStudentID->setFont(font1);
        courseMajor = new QLabel(addCourseFrame);
        courseMajor->setObjectName("courseMajor");
        courseMajor->setGeometry(QRect(60, 60, 31, 18));
        courseMajor->setFont(font1);
        courseYear = new QLabel(addCourseFrame);
        courseYear->setObjectName("courseYear");
        courseYear->setGeometry(QRect(520, 20, 31, 18));
        courseYear->setFont(font1);
        courseYearComboBox = new QComboBox(addCourseFrame);
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->setObjectName("courseYearComboBox");
        courseYearComboBox->setGeometry(QRect(560, 20, 101, 26));
        courseName = new QLabel(addCourseFrame);
        courseName->setObjectName("courseName");
        courseName->setGeometry(QRect(290, 20, 31, 18));
        courseName->setFont(font1);
        courseNameText = new QLineEdit(addCourseFrame);
        courseNameText->setObjectName("courseNameText");
        courseNameText->setGeometry(QRect(340, 20, 101, 26));
        courseAddPushButton = new QPushButton(addCourseFrame);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(750, 20, 71, 51));
        courseAddPushButton->setFont(font2);
        courseCourseName = new QLabel(addCourseFrame);
        courseCourseName->setObjectName("courseCourseName");
        courseCourseName->setGeometry(QRect(270, 60, 61, 20));
        courseCourseName->setFont(font1);
        courseCourseNameComboBox = new QComboBox(addCourseFrame);
        courseCourseNameComboBox->addItem(QString());
        courseCourseNameComboBox->setObjectName("courseCourseNameComboBox");
        courseCourseNameComboBox->setEnabled(true);
        courseCourseNameComboBox->setGeometry(QRect(340, 60, 101, 26));
        courseMajorComboBox = new QComboBox(addCourseFrame);
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->setObjectName("courseMajorComboBox");
        courseMajorComboBox->setEnabled(true);
        courseMajorComboBox->setGeometry(QRect(110, 60, 101, 26));
        courseTable = new QTableWidget(addCourse);
        if (courseTable->columnCount() < 6)
            courseTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        courseTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        courseTable->setObjectName("courseTable");
        courseTable->setGeometry(QRect(70, 280, 801, 251));
        courseTable->horizontalHeader()->setDefaultSectionSize(130);
        label_6 = new QLabel(addCourse);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 250, 81, 18));
        label_6->setFont(font3);
        courseSearchPushButton = new QPushButton(addCourse);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(720, 30, 81, 31));
        courseSearchPushButton->setFont(font2);
        courseAllSearchPushButton = new QPushButton(addCourse);
        courseAllSearchPushButton->setObjectName("courseAllSearchPushButton");
        courseAllSearchPushButton->setGeometry(QRect(810, 30, 81, 31));
        courseAllSearchPushButton->setFont(font2);
        courseGrade = new QLabel(addCourse);
        courseGrade->setObjectName("courseGrade");
        courseGrade->setGeometry(QRect(570, 250, 31, 18));
        courseGrade->setFont(font1);
        courseGradeComboBox = new QComboBox(addCourse);
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->setObjectName("courseGradeComboBox");
        courseGradeComboBox->setGeometry(QRect(610, 240, 91, 31));
        courseGradePushButton = new QPushButton(addCourse);
        courseGradePushButton->setObjectName("courseGradePushButton");
        courseGradePushButton->setGeometry(QRect(720, 240, 71, 31));
        courseGradePushButton->setFont(font2);
        deleteCoursePushButton = new QPushButton(addCourse);
        deleteCoursePushButton->setObjectName("deleteCoursePushButton");
        deleteCoursePushButton->setGeometry(QRect(800, 240, 71, 31));
        deleteCoursePushButton->setFont(font2);
        clearCourseDataPushButton = new QPushButton(addCourse);
        clearCourseDataPushButton->setObjectName("clearCourseDataPushButton");
        clearCourseDataPushButton->setGeometry(QRect(630, 30, 81, 31));
        clearCourseDataPushButton->setFont(font2);
        label_8 = new QLabel(addCourse);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 30, 231, 31));
        label_8->setFont(font4);
        tabWidget->addTab(addCourse, QString());
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(420, 30, 211, 41));
        QFont font5;
        font5.setPointSize(19);
        font5.setBold(true);
        label_9->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 979, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchYearComboBox->setItemText(0, QString());
        searchYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        searchYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        searchYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        searchYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        searchYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        searchYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        searchYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        searchMajorComboBox->setItemText(0, QString());
        searchMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        searchMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        searchMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        searchMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        searchStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        searchStudentName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        registrationStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem = searchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = searchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = searchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = searchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = searchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\355\217\211\352\267\240 \355\225\231\354\240\220", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        searchSortComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\354\240\225\353\240\254 \352\270\260\354\244\200", nullptr));
        searchSortComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        searchSortComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        searchSortComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        searchSortComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\355\217\211\352\267\240 \355\225\231\354\240\220", nullptr));

        searchAscPushButton->setText(QCoreApplication::translate("MainWindow", " \342\206\221", nullptr));
        searchDescPushButton->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        deleteStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\202\255\354\240\234", nullptr));
        searchStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        searchAllStudentButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214  \353\223\261\353\241\235  \354\202\255\354\240\234  \354\210\230\354\240\225", nullptr));
        clearStudentDataPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(search), QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 \354\210\230\354\240\225", nullptr));
        courseStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        courseMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        courseYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        courseYearComboBox->setItemText(0, QString());
        courseYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        courseYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        courseYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        courseYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        courseYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        courseYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        courseName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        courseAddPushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200", nullptr));
        courseCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        courseCourseNameComboBox->setItemText(0, QString());

        courseMajorComboBox->setItemText(0, QString());
        courseMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        QTableWidgetItem *___qtablewidgetitem5 = courseTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = courseTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = courseTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = courseTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = courseTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = courseTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        courseAllSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        courseGrade->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        courseGradeComboBox->setItemText(0, QString());
        courseGradeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "A+", nullptr));
        courseGradeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "A", nullptr));
        courseGradeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "B+", nullptr));
        courseGradeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "B", nullptr));
        courseGradeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "C+", nullptr));
        courseGradeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "C", nullptr));
        courseGradeComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "F", nullptr));

        courseGradePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        deleteCoursePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        clearCourseDataPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \353\260\217 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addCourse), QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \353\260\217 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \352\264\200\353\246\254 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
