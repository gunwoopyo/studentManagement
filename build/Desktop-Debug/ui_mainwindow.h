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
    QComboBox *searchSortComboBox;
    QToolButton *searchAscPushButton;
    QToolButton *searchDescPushButton;
    QPushButton *deleteStudentPushButton;
    QLabel *totalStudent;
    QLabel *label;
    QPushButton *clearStudentTextPushButton;
    QPushButton *searchStudentPushButton;
    QPushButton *searchAllStudentButton;
    QWidget *addCourse;
    QFrame *addCourseFrame;
    QLineEdit *courseStudentIDText;
    QLabel *courseStudentID;
    QLabel *courseYear;
    QComboBox *courseYearComboBox;
    QLabel *courseName;
    QLineEdit *courseStudentNameText;
    QComboBox *courseCourseNameComboBox;
    QLabel *courseCourseName;
    QLabel *courseMajor;
    QComboBox *courseMajorComboBox;
    QPushButton *courseAddPushButton;
    QTableWidget *courseTable;
    QPushButton *courseSearchPushButton;
    QPushButton *courseAllSearchPushButton;
    QPushButton *clearCourseTextPushButton;
    QLabel *label_2;
    QPushButton *deleteCoursePushButton;
    QComboBox *courseGradeComboBox;
    QPushButton *courseGradePushButton;
    QLabel *label_3;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(981, 745);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 60, 931, 631));
        tabWidget->setTabletTracking(false);
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        search = new QWidget();
        search->setObjectName("search");
        searchFrame = new QFrame(search);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setGeometry(QRect(50, 80, 821, 81));
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Plain);
        searchStudentIDText = new QLineEdit(searchFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(70, 30, 91, 26));
        searchYearComboBox = new QComboBox(searchFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(420, 30, 91, 26));
        searchYear = new QLabel(searchFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(380, 30, 31, 18));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        searchYear->setFont(font1);
        searchMajorComboBox = new QComboBox(searchFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(590, 30, 101, 26));
        searchMajor = new QLabel(searchFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(550, 30, 31, 18));
        searchMajor->setFont(font1);
        searchStudentID = new QLabel(searchFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(30, 30, 31, 18));
        searchStudentID->setFont(font1);
        searchStudentNameText = new QLineEdit(searchFrame);
        searchStudentNameText->setObjectName("searchStudentNameText");
        searchStudentNameText->setGeometry(QRect(250, 30, 91, 26));
        searchStudentName = new QLabel(searchFrame);
        searchStudentName->setObjectName("searchStudentName");
        searchStudentName->setGeometry(QRect(210, 30, 31, 18));
        searchStudentName->setFont(font1);
        registrationStudentPushButton = new QPushButton(searchFrame);
        registrationStudentPushButton->setObjectName("registrationStudentPushButton");
        registrationStudentPushButton->setGeometry(QRect(730, 20, 71, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        registrationStudentPushButton->setFont(font2);
        registrationStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchTable = new QTableWidget(search);
        if (searchTable->columnCount() < 5)
            searchTable->setColumnCount(5);
        QFont font3;
        font3.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        searchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        searchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font3);
        searchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        searchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        searchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        searchTable->setObjectName("searchTable");
        searchTable->setGeometry(QRect(90, 270, 741, 301));
        searchTable->horizontalHeader()->setDefaultSectionSize(140);
        searchSortComboBox = new QComboBox(search);
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->setObjectName("searchSortComboBox");
        searchSortComboBox->setGeometry(QRect(540, 230, 111, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        searchSortComboBox->setFont(font4);
        searchAscPushButton = new QToolButton(search);
        searchAscPushButton->setObjectName("searchAscPushButton");
        searchAscPushButton->setGeometry(QRect(660, 230, 26, 31));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        searchAscPushButton->setFont(font5);
        searchDescPushButton = new QToolButton(search);
        searchDescPushButton->setObjectName("searchDescPushButton");
        searchDescPushButton->setGeometry(QRect(690, 230, 26, 31));
        searchDescPushButton->setFont(font5);
        deleteStudentPushButton = new QPushButton(search);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(740, 230, 91, 31));
        deleteStudentPushButton->setFont(font2);
        deleteStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        totalStudent = new QLabel(search);
        totalStudent->setObjectName("totalStudent");
        totalStudent->setGeometry(QRect(90, 240, 151, 20));
        totalStudent->setFont(font);
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 171, 31));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        label->setFont(font6);
        clearStudentTextPushButton = new QPushButton(search);
        clearStudentTextPushButton->setObjectName("clearStudentTextPushButton");
        clearStudentTextPushButton->setGeometry(QRect(610, 40, 81, 31));
        clearStudentTextPushButton->setFont(font2);
        clearStudentTextPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchStudentPushButton = new QPushButton(search);
        searchStudentPushButton->setObjectName("searchStudentPushButton");
        searchStudentPushButton->setGeometry(QRect(700, 40, 81, 31));
        searchStudentPushButton->setFont(font3);
        searchStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchAllStudentButton = new QPushButton(search);
        searchAllStudentButton->setObjectName("searchAllStudentButton");
        searchAllStudentButton->setGeometry(QRect(790, 40, 81, 31));
        searchAllStudentButton->setFont(font3);
        searchAllStudentButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        tabWidget->addTab(search, QString());
        tabWidget->setTabText(tabWidget->indexOf(search), QString::fromUtf8("\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 "));
        addCourse = new QWidget();
        addCourse->setObjectName("addCourse");
        addCourseFrame = new QFrame(addCourse);
        addCourseFrame->setObjectName("addCourseFrame");
        addCourseFrame->setGeometry(QRect(50, 80, 821, 121));
        addCourseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addCourseFrame->setFrameShadow(QFrame::Shadow::Plain);
        addCourseFrame->setLineWidth(1);
        courseStudentIDText = new QLineEdit(addCourseFrame);
        courseStudentIDText->setObjectName("courseStudentIDText");
        courseStudentIDText->setGeometry(QRect(90, 20, 101, 31));
        courseStudentID = new QLabel(addCourseFrame);
        courseStudentID->setObjectName("courseStudentID");
        courseStudentID->setGeometry(QRect(50, 30, 31, 18));
        QFont font7;
        font7.setPointSize(12);
        courseStudentID->setFont(font7);
        courseYear = new QLabel(addCourseFrame);
        courseYear->setObjectName("courseYear");
        courseYear->setGeometry(QRect(520, 30, 31, 18));
        courseYear->setFont(font7);
        courseYearComboBox = new QComboBox(addCourseFrame);
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->setObjectName("courseYearComboBox");
        courseYearComboBox->setGeometry(QRect(560, 20, 101, 31));
        courseName = new QLabel(addCourseFrame);
        courseName->setObjectName("courseName");
        courseName->setGeometry(QRect(290, 30, 31, 18));
        courseName->setFont(font7);
        courseStudentNameText = new QLineEdit(addCourseFrame);
        courseStudentNameText->setObjectName("courseStudentNameText");
        courseStudentNameText->setGeometry(QRect(330, 20, 101, 31));
        courseCourseNameComboBox = new QComboBox(addCourseFrame);
        courseCourseNameComboBox->addItem(QString());
        courseCourseNameComboBox->setObjectName("courseCourseNameComboBox");
        courseCourseNameComboBox->setEnabled(true);
        courseCourseNameComboBox->setGeometry(QRect(330, 70, 101, 31));
        courseCourseName = new QLabel(addCourseFrame);
        courseCourseName->setObjectName("courseCourseName");
        courseCourseName->setGeometry(QRect(260, 80, 61, 20));
        courseCourseName->setFont(font7);
        courseMajor = new QLabel(addCourseFrame);
        courseMajor->setObjectName("courseMajor");
        courseMajor->setGeometry(QRect(50, 80, 31, 18));
        courseMajor->setFont(font7);
        courseMajorComboBox = new QComboBox(addCourseFrame);
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->setObjectName("courseMajorComboBox");
        courseMajorComboBox->setEnabled(true);
        courseMajorComboBox->setGeometry(QRect(90, 70, 101, 31));
        courseAddPushButton = new QPushButton(addCourseFrame);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(710, 30, 71, 51));
        courseAddPushButton->setFont(font3);
        courseAddPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        courseTable = new QTableWidget(addCourse);
        if (courseTable->columnCount() < 6)
            courseTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font3);
        courseTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font3);
        courseTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font3);
        courseTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font3);
        courseTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font3);
        courseTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font3);
        courseTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        courseTable->setObjectName("courseTable");
        courseTable->setGeometry(QRect(90, 280, 761, 291));
        courseTable->horizontalHeader()->setDefaultSectionSize(120);
        courseSearchPushButton = new QPushButton(addCourse);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(700, 40, 81, 31));
        courseSearchPushButton->setFont(font3);
        courseSearchPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        courseAllSearchPushButton = new QPushButton(addCourse);
        courseAllSearchPushButton->setObjectName("courseAllSearchPushButton");
        courseAllSearchPushButton->setGeometry(QRect(790, 40, 81, 31));
        courseAllSearchPushButton->setFont(font3);
        courseAllSearchPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        clearCourseTextPushButton = new QPushButton(addCourse);
        clearCourseTextPushButton->setObjectName("clearCourseTextPushButton");
        clearCourseTextPushButton->setGeometry(QRect(610, 40, 81, 31));
        clearCourseTextPushButton->setFont(font3);
        clearCourseTextPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        label_2 = new QLabel(addCourse);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 40, 231, 21));
        label_2->setFont(font6);
        deleteCoursePushButton = new QPushButton(addCourse);
        deleteCoursePushButton->setObjectName("deleteCoursePushButton");
        deleteCoursePushButton->setGeometry(QRect(770, 240, 81, 31));
        deleteCoursePushButton->setFont(font3);
        deleteCoursePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
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
        courseGradeComboBox->setGeometry(QRect(590, 240, 81, 31));
        courseGradeComboBox->setFont(font7);
        courseGradePushButton = new QPushButton(addCourse);
        courseGradePushButton->setObjectName("courseGradePushButton");
        courseGradePushButton->setGeometry(QRect(680, 240, 81, 31));
        courseGradePushButton->setFont(font3);
        courseGradePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        label_3 = new QLabel(addCourse);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 250, 31, 18));
        label_3->setFont(font7);
        tabWidget->addTab(addCourse, QString());
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(410, 20, 201, 41));
        QFont font8;
        font8.setPointSize(19);
        font8.setBold(true);
        label_9->setFont(font8);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 981, 21));
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
        searchSortComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\354\240\225\353\240\254 \352\270\260\354\244\200", nullptr));
        searchSortComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        searchSortComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        searchSortComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        searchSortComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\355\217\211\352\267\240 \355\225\231\354\240\220", nullptr));

        searchAscPushButton->setText(QCoreApplication::translate("MainWindow", " \342\206\221", nullptr));
        searchDescPushButton->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        deleteStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\202\255\354\240\234", nullptr));
        totalStudent->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 ", nullptr));
        clearStudentTextPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
        searchStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        searchAllStudentButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        courseStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        courseYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        courseYearComboBox->setItemText(0, QString());
        courseYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        courseYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        courseYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        courseYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        courseYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        courseYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        courseName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        courseCourseNameComboBox->setItemText(0, QString());

        courseCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        courseMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        courseMajorComboBox->setItemText(0, QString());
        courseMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        courseAddPushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200", nullptr));
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
        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        courseAllSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        clearCourseTextPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        deleteCoursePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        courseGradeComboBox->setItemText(0, QString());
        courseGradeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "A+", nullptr));
        courseGradeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "A", nullptr));
        courseGradeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "B+", nullptr));
        courseGradeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "B", nullptr));
        courseGradeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "C+", nullptr));
        courseGradeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "C", nullptr));
        courseGradeComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "F", nullptr));

        courseGradePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addCourse), QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \352\264\200\353\246\254 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
