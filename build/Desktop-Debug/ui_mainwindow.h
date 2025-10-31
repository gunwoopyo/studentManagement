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
    QPushButton *clearStudentFieldPushButton;
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
    QPushButton *courseSearchPushButton;
    QPushButton *courseAllSearchPushButton;
    QPushButton *clearCourseFieldPushButton;
    QLabel *label_2;
    QPushButton *deleteCoursePushButton;
    QComboBox *courseGradeComboBox;
    QPushButton *courseGradePushButton;
    QLabel *label_3;
    QTableWidget *courseTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1394, 736);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(40, 20, 1321, 661));
        tabWidget->setTabletTracking(false);
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        search = new QWidget();
        search->setObjectName("search");
        searchFrame = new QFrame(search);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setGeometry(QRect(100, 90, 1131, 111));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchFrame->sizePolicy().hasHeightForWidth());
        searchFrame->setSizePolicy(sizePolicy);
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Plain);
        searchStudentIDText = new QLineEdit(searchFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(130, 40, 131, 31));
        searchYearComboBox = new QComboBox(searchFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(590, 40, 131, 31));
        QFont font1;
        font1.setPointSize(11);
        searchYearComboBox->setFont(font1);
        searchYear = new QLabel(searchFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(550, 50, 31, 18));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(false);
        searchYear->setFont(font2);
        searchMajorComboBox = new QComboBox(searchFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(830, 40, 131, 31));
        sizePolicy.setHeightForWidth(searchMajorComboBox->sizePolicy().hasHeightForWidth());
        searchMajorComboBox->setSizePolicy(sizePolicy);
        searchMajorComboBox->setFont(font1);
        searchMajor = new QLabel(searchFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(790, 50, 31, 18));
        sizePolicy.setHeightForWidth(searchMajor->sizePolicy().hasHeightForWidth());
        searchMajor->setSizePolicy(sizePolicy);
        searchMajor->setFont(font2);
        searchStudentID = new QLabel(searchFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(90, 50, 31, 18));
        searchStudentID->setFont(font2);
        searchStudentNameText = new QLineEdit(searchFrame);
        searchStudentNameText->setObjectName("searchStudentNameText");
        searchStudentNameText->setGeometry(QRect(360, 40, 131, 31));
        searchStudentName = new QLabel(searchFrame);
        searchStudentName->setObjectName("searchStudentName");
        searchStudentName->setGeometry(QRect(320, 50, 31, 18));
        searchStudentName->setFont(font2);
        registrationStudentPushButton = new QPushButton(searchFrame);
        registrationStudentPushButton->setObjectName("registrationStudentPushButton");
        registrationStudentPushButton->setGeometry(QRect(1010, 30, 71, 51));
        sizePolicy.setHeightForWidth(registrationStudentPushButton->sizePolicy().hasHeightForWidth());
        registrationStudentPushButton->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        registrationStudentPushButton->setFont(font3);
        registrationStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchTable = new QTableWidget(search);
        if (searchTable->columnCount() < 5)
            searchTable->setColumnCount(5);
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font4);
        searchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        searchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        searchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font4);
        searchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font4);
        searchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        searchTable->setObjectName("searchTable");
        searchTable->setGeometry(QRect(210, 300, 916, 311));
        QFont font5;
        font5.setPointSize(12);
        searchTable->setFont(font5);
        searchTable->horizontalHeader()->setDefaultSectionSize(180);
        searchSortComboBox = new QComboBox(search);
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->setObjectName("searchSortComboBox");
        searchSortComboBox->setGeometry(QRect(840, 260, 101, 31));
        sizePolicy.setHeightForWidth(searchSortComboBox->sizePolicy().hasHeightForWidth());
        searchSortComboBox->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(false);
        searchSortComboBox->setFont(font6);
        searchAscPushButton = new QToolButton(search);
        searchAscPushButton->setObjectName("searchAscPushButton");
        searchAscPushButton->setGeometry(QRect(950, 260, 31, 31));
        sizePolicy.setHeightForWidth(searchAscPushButton->sizePolicy().hasHeightForWidth());
        searchAscPushButton->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        searchAscPushButton->setFont(font7);
        searchDescPushButton = new QToolButton(search);
        searchDescPushButton->setObjectName("searchDescPushButton");
        searchDescPushButton->setGeometry(QRect(990, 260, 31, 31));
        sizePolicy.setHeightForWidth(searchDescPushButton->sizePolicy().hasHeightForWidth());
        searchDescPushButton->setSizePolicy(sizePolicy);
        searchDescPushButton->setFont(font7);
        deleteStudentPushButton = new QPushButton(search);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(1030, 260, 91, 31));
        sizePolicy.setHeightForWidth(deleteStudentPushButton->sizePolicy().hasHeightForWidth());
        deleteStudentPushButton->setSizePolicy(sizePolicy);
        deleteStudentPushButton->setFont(font3);
        deleteStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        totalStudent = new QLabel(search);
        totalStudent->setObjectName("totalStudent");
        totalStudent->setGeometry(QRect(210, 270, 151, 20));
        totalStudent->setFont(font5);
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 40, 281, 41));
        QFont font8;
        font8.setPointSize(20);
        font8.setBold(true);
        label->setFont(font8);
        clearStudentFieldPushButton = new QPushButton(search);
        clearStudentFieldPushButton->setObjectName("clearStudentFieldPushButton");
        clearStudentFieldPushButton->setGeometry(QRect(940, 50, 91, 31));
        sizePolicy.setHeightForWidth(clearStudentFieldPushButton->sizePolicy().hasHeightForWidth());
        clearStudentFieldPushButton->setSizePolicy(sizePolicy);
        clearStudentFieldPushButton->setFont(font3);
        clearStudentFieldPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchStudentPushButton = new QPushButton(search);
        searchStudentPushButton->setObjectName("searchStudentPushButton");
        searchStudentPushButton->setGeometry(QRect(1040, 50, 91, 31));
        sizePolicy.setHeightForWidth(searchStudentPushButton->sizePolicy().hasHeightForWidth());
        searchStudentPushButton->setSizePolicy(sizePolicy);
        searchStudentPushButton->setFont(font5);
        searchStudentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        searchAllStudentButton = new QPushButton(search);
        searchAllStudentButton->setObjectName("searchAllStudentButton");
        searchAllStudentButton->setGeometry(QRect(1140, 50, 91, 31));
        sizePolicy.setHeightForWidth(searchAllStudentButton->sizePolicy().hasHeightForWidth());
        searchAllStudentButton->setSizePolicy(sizePolicy);
        searchAllStudentButton->setFont(font5);
        searchAllStudentButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        tabWidget->addTab(search, QString());
        tabWidget->setTabText(tabWidget->indexOf(search), QString::fromUtf8("\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 "));
        addCourse = new QWidget();
        addCourse->setObjectName("addCourse");
        addCourseFrame = new QFrame(addCourse);
        addCourseFrame->setObjectName("addCourseFrame");
        addCourseFrame->setGeometry(QRect(100, 90, 1131, 111));
        sizePolicy.setHeightForWidth(addCourseFrame->sizePolicy().hasHeightForWidth());
        addCourseFrame->setSizePolicy(sizePolicy);
        addCourseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addCourseFrame->setFrameShadow(QFrame::Shadow::Plain);
        addCourseFrame->setLineWidth(1);
        courseStudentIDText = new QLineEdit(addCourseFrame);
        courseStudentIDText->setObjectName("courseStudentIDText");
        courseStudentIDText->setGeometry(QRect(160, 20, 131, 31));
        courseStudentID = new QLabel(addCourseFrame);
        courseStudentID->setObjectName("courseStudentID");
        courseStudentID->setGeometry(QRect(120, 30, 31, 18));
        QFont font9;
        font9.setPointSize(13);
        courseStudentID->setFont(font9);
        courseYear = new QLabel(addCourseFrame);
        courseYear->setObjectName("courseYear");
        courseYear->setGeometry(QRect(790, 30, 31, 18));
        courseYear->setFont(font9);
        courseYearComboBox = new QComboBox(addCourseFrame);
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->setObjectName("courseYearComboBox");
        courseYearComboBox->setGeometry(QRect(830, 20, 121, 31));
        courseYearComboBox->setFont(font1);
        courseName = new QLabel(addCourseFrame);
        courseName->setObjectName("courseName");
        courseName->setGeometry(QRect(450, 30, 31, 18));
        courseName->setFont(font9);
        courseStudentNameText = new QLineEdit(addCourseFrame);
        courseStudentNameText->setObjectName("courseStudentNameText");
        courseStudentNameText->setGeometry(QRect(490, 20, 131, 31));
        courseCourseNameComboBox = new QComboBox(addCourseFrame);
        courseCourseNameComboBox->addItem(QString());
        courseCourseNameComboBox->setObjectName("courseCourseNameComboBox");
        courseCourseNameComboBox->setEnabled(true);
        courseCourseNameComboBox->setGeometry(QRect(490, 60, 131, 31));
        courseCourseNameComboBox->setFont(font1);
        courseCourseName = new QLabel(addCourseFrame);
        courseCourseName->setObjectName("courseCourseName");
        courseCourseName->setGeometry(QRect(420, 70, 71, 20));
        courseCourseName->setFont(font9);
        courseMajor = new QLabel(addCourseFrame);
        courseMajor->setObjectName("courseMajor");
        courseMajor->setGeometry(QRect(120, 70, 31, 18));
        courseMajor->setFont(font9);
        courseMajorComboBox = new QComboBox(addCourseFrame);
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->setObjectName("courseMajorComboBox");
        courseMajorComboBox->setEnabled(true);
        courseMajorComboBox->setGeometry(QRect(160, 60, 131, 31));
        courseMajorComboBox->setFont(font1);
        courseAddPushButton = new QPushButton(addCourseFrame);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(1010, 30, 71, 51));
        courseAddPushButton->setFont(font5);
        courseAddPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        courseSearchPushButton = new QPushButton(addCourse);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(1040, 50, 91, 31));
        courseSearchPushButton->setFont(font5);
        courseSearchPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        courseAllSearchPushButton = new QPushButton(addCourse);
        courseAllSearchPushButton->setObjectName("courseAllSearchPushButton");
        courseAllSearchPushButton->setGeometry(QRect(1140, 50, 91, 31));
        courseAllSearchPushButton->setFont(font5);
        courseAllSearchPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        clearCourseFieldPushButton = new QPushButton(addCourse);
        clearCourseFieldPushButton->setObjectName("clearCourseFieldPushButton");
        clearCourseFieldPushButton->setGeometry(QRect(940, 50, 91, 31));
        clearCourseFieldPushButton->setFont(font5);
        clearCourseFieldPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        label_2 = new QLabel(addCourse);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 40, 301, 41));
        label_2->setFont(font8);
        deleteCoursePushButton = new QPushButton(addCourse);
        deleteCoursePushButton->setObjectName("deleteCoursePushButton");
        deleteCoursePushButton->setGeometry(QRect(1060, 270, 91, 31));
        deleteCoursePushButton->setFont(font5);
        deleteCoursePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        courseGradeComboBox = new QComboBox(addCourse);
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString::fromUtf8("A+"));
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->addItem(QString());
        courseGradeComboBox->setObjectName("courseGradeComboBox");
        courseGradeComboBox->setGeometry(QRect(860, 270, 91, 31));
        courseGradeComboBox->setFont(font1);
        courseGradePushButton = new QPushButton(addCourse);
        courseGradePushButton->setObjectName("courseGradePushButton");
        courseGradePushButton->setGeometry(QRect(960, 270, 91, 31));
        courseGradePushButton->setFont(font5);
        courseGradePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"}"));
        label_3 = new QLabel(addCourse);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(820, 280, 31, 18));
        label_3->setFont(font9);
        courseTable = new QTableWidget(addCourse);
        if (courseTable->columnCount() < 6)
            courseTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        courseTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        courseTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font4);
        courseTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font4);
        courseTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font4);
        courseTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font4);
        courseTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        courseTable->setObjectName("courseTable");
        courseTable->setGeometry(QRect(180, 310, 975, 301));
        courseTable->setFont(font5);
        courseTable->horizontalHeader()->setDefaultSectionSize(160);
        tabWidget->addTab(addCourse, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 1394, 21));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
        clearStudentFieldPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
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
        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        courseAllSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        clearCourseFieldPushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\205\353\240\245 \354\264\210\352\270\260\355\231\224", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        deleteCoursePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        courseGradeComboBox->setItemText(0, QString());
        courseGradeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "A", nullptr));
        courseGradeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "B+", nullptr));
        courseGradeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "B", nullptr));
        courseGradeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "C+", nullptr));
        courseGradeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "C", nullptr));
        courseGradeComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "F", nullptr));

        courseGradePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(addCourse), QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
