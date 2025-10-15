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
    QTableWidget *searchTable;
    QLabel *label;
    QComboBox *searchSortComboBox;
    QToolButton *searchAscPushButton;
    QToolButton *searchDescPushButton;
    QPushButton *searchDeletePushButton;
    QPushButton *searchStudentSearchButton;
    QPushButton *searchStudentAllSearchButton;
    QPushButton *searchRegistrationPushButton;
    QPushButton *searchUpdatePushButton;
    QLabel *label_7;
    QWidget *addCourse;
    QFrame *addCourseFrame;
    QLineEdit *courseStudentIDText;
    QLabel *courseStudentID;
    QLabel *courseCourseName;
    QComboBox *courseCourseNameComboBox;
    QLabel *courseMajor;
    QComboBox *courseMajorComboBox;
    QLabel *courseYear;
    QComboBox *courseYearComboBox;
    QLabel *courseName;
    QLineEdit *courseNameText;
    QTableWidget *courseSearchTable;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *courseSearchPushButton;
    QPushButton *courseAddPushButton;
    QPushButton *courseDeletePushButton;
    QPushButton *courseAllSearchPushButton;
    QPushButton *courseGradePushButton;
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
        tabWidget->setGeometry(QRect(30, 50, 931, 621));
        search = new QWidget();
        search->setObjectName("search");
        searchFrame = new QFrame(search);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setGeometry(QRect(30, 70, 851, 71));
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Raised);
        searchStudentIDText = new QLineEdit(searchFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(90, 20, 91, 26));
        searchYearComboBox = new QComboBox(searchFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(490, 20, 91, 26));
        searchYear = new QLabel(searchFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(440, 20, 31, 18));
        searchMajorComboBox = new QComboBox(searchFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(690, 20, 91, 26));
        searchMajor = new QLabel(searchFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(640, 20, 31, 18));
        searchStudentID = new QLabel(searchFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(50, 20, 31, 18));
        searchStudentNameText = new QLineEdit(searchFrame);
        searchStudentNameText->setObjectName("searchStudentNameText");
        searchStudentNameText->setGeometry(QRect(280, 20, 91, 26));
        searchStudentName = new QLabel(searchFrame);
        searchStudentName->setObjectName("searchStudentName");
        searchStudentName->setGeometry(QRect(240, 20, 31, 18));
        searchTable = new QTableWidget(search);
        if (searchTable->columnCount() < 5)
            searchTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        searchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        searchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        searchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        searchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        searchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        searchTable->setObjectName("searchTable");
        searchTable->setGeometry(QRect(110, 240, 721, 301));
        searchTable->horizontalHeader()->setDefaultSectionSize(140);
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 210, 81, 18));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        label->setFont(font1);
        searchSortComboBox = new QComboBox(search);
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->addItem(QString());
        searchSortComboBox->setObjectName("searchSortComboBox");
        searchSortComboBox->setGeometry(QRect(210, 210, 101, 26));
        searchAscPushButton = new QToolButton(search);
        searchAscPushButton->setObjectName("searchAscPushButton");
        searchAscPushButton->setGeometry(QRect(330, 210, 26, 25));
        searchDescPushButton = new QToolButton(search);
        searchDescPushButton->setObjectName("searchDescPushButton");
        searchDescPushButton->setGeometry(QRect(370, 210, 26, 25));
        searchDeletePushButton = new QPushButton(search);
        searchDeletePushButton->setObjectName("searchDeletePushButton");
        searchDeletePushButton->setGeometry(QRect(760, 210, 71, 26));
        searchDeletePushButton->setFont(font);
        searchStudentSearchButton = new QPushButton(search);
        searchStudentSearchButton->setObjectName("searchStudentSearchButton");
        searchStudentSearchButton->setGeometry(QRect(570, 30, 71, 26));
        searchStudentSearchButton->setFont(font);
        searchStudentAllSearchButton = new QPushButton(search);
        searchStudentAllSearchButton->setObjectName("searchStudentAllSearchButton");
        searchStudentAllSearchButton->setGeometry(QRect(650, 30, 71, 26));
        searchStudentAllSearchButton->setFont(font);
        searchRegistrationPushButton = new QPushButton(search);
        searchRegistrationPushButton->setObjectName("searchRegistrationPushButton");
        searchRegistrationPushButton->setGeometry(QRect(730, 30, 71, 26));
        searchRegistrationPushButton->setFont(font);
        searchUpdatePushButton = new QPushButton(search);
        searchUpdatePushButton->setObjectName("searchUpdatePushButton");
        searchUpdatePushButton->setGeometry(QRect(810, 30, 71, 26));
        searchUpdatePushButton->setFont(font);
        label_7 = new QLabel(search);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 20, 231, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_7->setFont(font2);
        tabWidget->addTab(search, QString());
        addCourse = new QWidget();
        addCourse->setObjectName("addCourse");
        addCourseFrame = new QFrame(addCourse);
        addCourseFrame->setObjectName("addCourseFrame");
        addCourseFrame->setGeometry(QRect(40, 70, 851, 81));
        addCourseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addCourseFrame->setFrameShadow(QFrame::Shadow::Raised);
        courseStudentIDText = new QLineEdit(addCourseFrame);
        courseStudentIDText->setObjectName("courseStudentIDText");
        courseStudentIDText->setGeometry(QRect(70, 30, 81, 26));
        courseStudentID = new QLabel(addCourseFrame);
        courseStudentID->setObjectName("courseStudentID");
        courseStudentID->setGeometry(QRect(30, 30, 31, 18));
        courseCourseName = new QLabel(addCourseFrame);
        courseCourseName->setObjectName("courseCourseName");
        courseCourseName->setGeometry(QRect(670, 30, 61, 18));
        courseCourseNameComboBox = new QComboBox(addCourseFrame);
        courseCourseNameComboBox->addItem(QString());
        courseCourseNameComboBox->setObjectName("courseCourseNameComboBox");
        courseCourseNameComboBox->setEnabled(true);
        courseCourseNameComboBox->setGeometry(QRect(730, 30, 81, 26));
        courseMajor = new QLabel(addCourseFrame);
        courseMajor->setObjectName("courseMajor");
        courseMajor->setGeometry(QRect(510, 30, 31, 18));
        courseMajorComboBox = new QComboBox(addCourseFrame);
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->addItem(QString());
        courseMajorComboBox->setObjectName("courseMajorComboBox");
        courseMajorComboBox->setEnabled(true);
        courseMajorComboBox->setGeometry(QRect(550, 30, 81, 26));
        courseYear = new QLabel(addCourseFrame);
        courseYear->setObjectName("courseYear");
        courseYear->setGeometry(QRect(350, 30, 31, 18));
        courseYearComboBox = new QComboBox(addCourseFrame);
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->addItem(QString());
        courseYearComboBox->setObjectName("courseYearComboBox");
        courseYearComboBox->setGeometry(QRect(390, 30, 81, 26));
        courseName = new QLabel(addCourseFrame);
        courseName->setObjectName("courseName");
        courseName->setGeometry(QRect(190, 30, 31, 18));
        courseNameText = new QLineEdit(addCourseFrame);
        courseNameText->setObjectName("courseNameText");
        courseNameText->setGeometry(QRect(230, 30, 81, 26));
        courseSearchTable = new QTableWidget(addCourse);
        if (courseSearchTable->columnCount() < 6)
            courseSearchTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        courseSearchTable->setObjectName("courseSearchTable");
        courseSearchTable->setGeometry(QRect(60, 250, 801, 271));
        courseSearchTable->horizontalHeader()->setDefaultSectionSize(130);
        label_5 = new QLabel(addCourse);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 20, 231, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(addCourse);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 220, 81, 18));
        label_6->setFont(font1);
        courseSearchPushButton = new QPushButton(addCourse);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(580, 40, 71, 21));
        courseSearchPushButton->setFont(font);
        courseAddPushButton = new QPushButton(addCourse);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(740, 40, 71, 21));
        courseDeletePushButton = new QPushButton(addCourse);
        courseDeletePushButton->setObjectName("courseDeletePushButton");
        courseDeletePushButton->setGeometry(QRect(820, 40, 71, 21));
        courseAllSearchPushButton = new QPushButton(addCourse);
        courseAllSearchPushButton->setObjectName("courseAllSearchPushButton");
        courseAllSearchPushButton->setGeometry(QRect(660, 40, 71, 21));
        courseGradePushButton = new QPushButton(addCourse);
        courseGradePushButton->setObjectName("courseGradePushButton");
        courseGradePushButton->setGeometry(QRect(790, 220, 71, 21));
        tabWidget->addTab(addCourse, QString());
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(450, 10, 211, 41));
        QFont font3;
        font3.setPointSize(19);
        font3.setBold(true);
        label_9->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 979, 21));
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
        searchDeletePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\202\255\354\240\234", nullptr));
        searchStudentSearchButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        searchStudentAllSearchButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        searchRegistrationPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235", nullptr));
        searchUpdatePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\210\230\354\240\225", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 \354\210\230\354\240\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(search), QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214 \353\223\261\353\241\235 \354\202\255\354\240\234 \354\210\230\354\240\225", nullptr));
        courseStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        courseCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        courseCourseNameComboBox->setItemText(0, QString());

        courseMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        courseMajorComboBox->setItemText(0, QString());
        courseMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        courseMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        courseYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        courseYearComboBox->setItemText(0, QString());
        courseYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        courseYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        courseYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        courseYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        courseYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        courseYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        courseName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = courseSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = courseSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = courseSearchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = courseSearchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = courseSearchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = courseSearchTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \353\260\217 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        courseAddPushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200", nullptr));
        courseDeletePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        courseAllSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        courseGradePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addCourse), QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200 \354\202\255\354\240\234  \353\260\217 \355\225\231\354\240\220 \353\223\261\353\241\235", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \352\264\200\353\246\254 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
