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
    QWidget *remove;
    QFrame *removeFrame;
    QLineEdit *searchStudentIDText;
    QPushButton *studentSearchButton;
    QPushButton *allStudentSearchButton;
    QComboBox *searchYearComboBox;
    QLabel *searchYear;
    QComboBox *searchMajorComboBox;
    QLabel *searchMajor;
    QLabel *searchCourseName;
    QComboBox *searchCourseNamecomboBox;
    QLabel *searchStudentID;
    QTableWidget *searchTable;
    QLabel *label;
    QLabel *label_2;
    QComboBox *sortComboBox;
    QToolButton *ascPushButton;
    QToolButton *descPushButton;
    QWidget *registration;
    QFrame *registrationFrame;
    QLineEdit *registrationStudentIDText;
    QLabel *registrationStudentID;
    QLineEdit *registrationNameText;
    QLabel *registrationMajor;
    QLabel *registrationYear;
    QComboBox *registrationYearComboBox;
    QComboBox *registrationMajorComboBox;
    QLabel *registrationName;
    QPushButton *registrationPushButton;
    QPushButton *deleteStudentPushButton;
    QTableWidget *registrationTable;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *addCourse;
    QFrame *addCourseFrame;
    QLineEdit *addDeleteCourseStudentIDText;
    QLabel *addDeleteCourseStudentID;
    QLabel *addDeleteCourseName;
    QComboBox *addDeleteCourseNameComboBox;
    QLabel *addDeleteDeleteCourseMajor;
    QComboBox *addDeleteCourseMajorComboBox;
    QLabel *addDeleteCourseYear;
    QComboBox *addDeleteYearComboBox;
    QPushButton *courseSearchPushButton;
    QPushButton *courseAddPushButton;
    QPushButton *courseDeletePushButton;
    QTableWidget *courseSearchTable;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_2;
    QFrame *updateGradeFrame;
    QLineEdit *updateStudentIDText;
    QLabel *updateStudentID;
    QLabel *updateCourseName;
    QComboBox *updateCourseNameComboBox;
    QLabel *updateMajor;
    QComboBox *updateMajorComboBox;
    QLabel *updateGrade;
    QComboBox *updateCourseGradeCombobox;
    QPushButton *updateSearchPushButton;
    QPushButton *updateRegistrationGradePushButton;
    QLabel *updateYear;
    QComboBox *updateYearComboBox;
    QTableWidget *gradeTable;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1069, 692);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(40, 80, 971, 511));
        remove = new QWidget();
        remove->setObjectName("remove");
        removeFrame = new QFrame(remove);
        removeFrame->setObjectName("removeFrame");
        removeFrame->setGeometry(QRect(60, 60, 851, 91));
        removeFrame->setFrameShape(QFrame::Shape::StyledPanel);
        removeFrame->setFrameShadow(QFrame::Shadow::Raised);
        searchStudentIDText = new QLineEdit(removeFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(70, 30, 91, 26));
        studentSearchButton = new QPushButton(removeFrame);
        studentSearchButton->setObjectName("studentSearchButton");
        studentSearchButton->setGeometry(QRect(730, 10, 93, 26));
        allStudentSearchButton = new QPushButton(removeFrame);
        allStudentSearchButton->setObjectName("allStudentSearchButton");
        allStudentSearchButton->setGeometry(QRect(730, 50, 93, 26));
        searchYearComboBox = new QComboBox(removeFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(230, 30, 91, 26));
        searchYear = new QLabel(removeFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(190, 30, 41, 18));
        searchMajorComboBox = new QComboBox(removeFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(400, 30, 91, 26));
        searchMajor = new QLabel(removeFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(360, 30, 41, 18));
        searchCourseName = new QLabel(removeFrame);
        searchCourseName->setObjectName("searchCourseName");
        searchCourseName->setGeometry(QRect(520, 30, 71, 18));
        searchCourseNamecomboBox = new QComboBox(removeFrame);
        searchCourseNamecomboBox->addItem(QString());
        searchCourseNamecomboBox->addItem(QString());
        searchCourseNamecomboBox->addItem(QString());
        searchCourseNamecomboBox->addItem(QString());
        searchCourseNamecomboBox->setObjectName("searchCourseNamecomboBox");
        searchCourseNamecomboBox->setGeometry(QRect(590, 30, 91, 26));
        searchStudentID = new QLabel(removeFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(30, 30, 41, 18));
        searchTable = new QTableWidget(remove);
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
        searchTable->setGeometry(QRect(120, 200, 721, 251));
        searchTable->horizontalHeader()->setDefaultSectionSize(140);
        label = new QLabel(remove);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 81, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(remove);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 170, 81, 18));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        label_2->setFont(font1);
        sortComboBox = new QComboBox(remove);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(220, 170, 111, 26));
        ascPushButton = new QToolButton(remove);
        ascPushButton->setObjectName("ascPushButton");
        ascPushButton->setGeometry(QRect(340, 170, 26, 25));
        descPushButton = new QToolButton(remove);
        descPushButton->setObjectName("descPushButton");
        descPushButton->setGeometry(QRect(370, 170, 26, 25));
        tabWidget->addTab(remove, QString());
        registration = new QWidget();
        registration->setObjectName("registration");
        registrationFrame = new QFrame(registration);
        registrationFrame->setObjectName("registrationFrame");
        registrationFrame->setGeometry(QRect(60, 60, 851, 91));
        registrationFrame->setFrameShape(QFrame::Shape::StyledPanel);
        registrationFrame->setFrameShadow(QFrame::Shadow::Raised);
        registrationStudentIDText = new QLineEdit(registrationFrame);
        registrationStudentIDText->setObjectName("registrationStudentIDText");
        registrationStudentIDText->setGeometry(QRect(70, 30, 91, 26));
        registrationStudentID = new QLabel(registrationFrame);
        registrationStudentID->setObjectName("registrationStudentID");
        registrationStudentID->setGeometry(QRect(30, 30, 41, 18));
        registrationNameText = new QLineEdit(registrationFrame);
        registrationNameText->setObjectName("registrationNameText");
        registrationNameText->setGeometry(QRect(230, 30, 91, 26));
        registrationMajor = new QLabel(registrationFrame);
        registrationMajor->setObjectName("registrationMajor");
        registrationMajor->setGeometry(QRect(540, 30, 31, 18));
        registrationYear = new QLabel(registrationFrame);
        registrationYear->setObjectName("registrationYear");
        registrationYear->setGeometry(QRect(360, 30, 31, 18));
        registrationYearComboBox = new QComboBox(registrationFrame);
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->setObjectName("registrationYearComboBox");
        registrationYearComboBox->setGeometry(QRect(400, 30, 91, 26));
        registrationMajorComboBox = new QComboBox(registrationFrame);
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->setObjectName("registrationMajorComboBox");
        registrationMajorComboBox->setGeometry(QRect(580, 30, 91, 26));
        registrationName = new QLabel(registrationFrame);
        registrationName->setObjectName("registrationName");
        registrationName->setGeometry(QRect(190, 30, 31, 18));
        registrationPushButton = new QPushButton(registrationFrame);
        registrationPushButton->setObjectName("registrationPushButton");
        registrationPushButton->setGeometry(QRect(730, 20, 91, 21));
        deleteStudentPushButton = new QPushButton(registrationFrame);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(730, 50, 91, 21));
        registrationTable = new QTableWidget(registration);
        if (registrationTable->columnCount() < 4)
            registrationTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        registrationTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        registrationTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        registrationTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        registrationTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        registrationTable->setObjectName("registrationTable");
        registrationTable->setGeometry(QRect(180, 200, 581, 231));
        registrationTable->horizontalHeader()->setDefaultSectionSize(140);
        label_3 = new QLabel(registration);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 20, 141, 31));
        label_3->setFont(font);
        label_4 = new QLabel(registration);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 170, 81, 18));
        label_4->setFont(font1);
        tabWidget->addTab(registration, QString());
        addCourse = new QWidget();
        addCourse->setObjectName("addCourse");
        addCourseFrame = new QFrame(addCourse);
        addCourseFrame->setObjectName("addCourseFrame");
        addCourseFrame->setGeometry(QRect(50, 60, 871, 101));
        addCourseFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addCourseFrame->setFrameShadow(QFrame::Shadow::Raised);
        addDeleteCourseStudentIDText = new QLineEdit(addCourseFrame);
        addDeleteCourseStudentIDText->setObjectName("addDeleteCourseStudentIDText");
        addDeleteCourseStudentIDText->setGeometry(QRect(70, 30, 101, 26));
        addDeleteCourseStudentID = new QLabel(addCourseFrame);
        addDeleteCourseStudentID->setObjectName("addDeleteCourseStudentID");
        addDeleteCourseStudentID->setGeometry(QRect(30, 30, 31, 18));
        addDeleteCourseName = new QLabel(addCourseFrame);
        addDeleteCourseName->setObjectName("addDeleteCourseName");
        addDeleteCourseName->setGeometry(QRect(570, 30, 61, 18));
        addDeleteCourseNameComboBox = new QComboBox(addCourseFrame);
        addDeleteCourseNameComboBox->addItem(QString());
        addDeleteCourseNameComboBox->setObjectName("addDeleteCourseNameComboBox");
        addDeleteCourseNameComboBox->setEnabled(true);
        addDeleteCourseNameComboBox->setGeometry(QRect(640, 30, 101, 26));
        addDeleteDeleteCourseMajor = new QLabel(addCourseFrame);
        addDeleteDeleteCourseMajor->setObjectName("addDeleteDeleteCourseMajor");
        addDeleteDeleteCourseMajor->setGeometry(QRect(390, 30, 31, 18));
        addDeleteCourseMajorComboBox = new QComboBox(addCourseFrame);
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->setObjectName("addDeleteCourseMajorComboBox");
        addDeleteCourseMajorComboBox->setEnabled(true);
        addDeleteCourseMajorComboBox->setGeometry(QRect(430, 30, 101, 26));
        addDeleteCourseYear = new QLabel(addCourseFrame);
        addDeleteCourseYear->setObjectName("addDeleteCourseYear");
        addDeleteCourseYear->setGeometry(QRect(210, 30, 31, 18));
        addDeleteYearComboBox = new QComboBox(addCourseFrame);
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->setObjectName("addDeleteYearComboBox");
        addDeleteYearComboBox->setGeometry(QRect(250, 30, 101, 26));
        courseSearchPushButton = new QPushButton(addCourseFrame);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(770, 10, 81, 21));
        courseAddPushButton = new QPushButton(addCourseFrame);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(770, 40, 81, 21));
        courseDeletePushButton = new QPushButton(addCourseFrame);
        courseDeletePushButton->setObjectName("courseDeletePushButton");
        courseDeletePushButton->setGeometry(QRect(770, 70, 81, 21));
        courseSearchTable = new QTableWidget(addCourse);
        if (courseSearchTable->columnCount() < 5)
            courseSearchTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        courseSearchTable->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        courseSearchTable->setObjectName("courseSearchTable");
        courseSearchTable->setGeometry(QRect(120, 210, 721, 241));
        courseSearchTable->horizontalHeader()->setDefaultSectionSize(140);
        label_5 = new QLabel(addCourse);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 20, 181, 31));
        label_5->setFont(font);
        label_6 = new QLabel(addCourse);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 180, 81, 18));
        label_6->setFont(font1);
        tabWidget->addTab(addCourse, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        updateGradeFrame = new QFrame(tab_2);
        updateGradeFrame->setObjectName("updateGradeFrame");
        updateGradeFrame->setGeometry(QRect(50, 60, 871, 101));
        updateGradeFrame->setFrameShape(QFrame::Shape::StyledPanel);
        updateGradeFrame->setFrameShadow(QFrame::Shadow::Raised);
        updateStudentIDText = new QLineEdit(updateGradeFrame);
        updateStudentIDText->setObjectName("updateStudentIDText");
        updateStudentIDText->setGeometry(QRect(110, 20, 101, 26));
        updateStudentID = new QLabel(updateGradeFrame);
        updateStudentID->setObjectName("updateStudentID");
        updateStudentID->setGeometry(QRect(60, 20, 41, 18));
        updateCourseName = new QLabel(updateGradeFrame);
        updateCourseName->setObjectName("updateCourseName");
        updateCourseName->setGeometry(QRect(40, 60, 71, 18));
        updateCourseNameComboBox = new QComboBox(updateGradeFrame);
        updateCourseNameComboBox->setObjectName("updateCourseNameComboBox");
        updateCourseNameComboBox->setEnabled(true);
        updateCourseNameComboBox->setGeometry(QRect(110, 60, 101, 26));
        updateMajor = new QLabel(updateGradeFrame);
        updateMajor->setObjectName("updateMajor");
        updateMajor->setGeometry(QRect(500, 20, 31, 18));
        updateMajorComboBox = new QComboBox(updateGradeFrame);
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->setObjectName("updateMajorComboBox");
        updateMajorComboBox->setEnabled(true);
        updateMajorComboBox->setGeometry(QRect(550, 20, 101, 26));
        updateGrade = new QLabel(updateGradeFrame);
        updateGrade->setObjectName("updateGrade");
        updateGrade->setGeometry(QRect(290, 60, 31, 18));
        updateCourseGradeCombobox = new QComboBox(updateGradeFrame);
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->setObjectName("updateCourseGradeCombobox");
        updateCourseGradeCombobox->setEnabled(true);
        updateCourseGradeCombobox->setGeometry(QRect(340, 60, 101, 26));
        updateSearchPushButton = new QPushButton(updateGradeFrame);
        updateSearchPushButton->setObjectName("updateSearchPushButton");
        updateSearchPushButton->setGeometry(QRect(720, 20, 81, 26));
        updateRegistrationGradePushButton = new QPushButton(updateGradeFrame);
        updateRegistrationGradePushButton->setObjectName("updateRegistrationGradePushButton");
        updateRegistrationGradePushButton->setGeometry(QRect(720, 60, 121, 26));
        updateYear = new QLabel(updateGradeFrame);
        updateYear->setObjectName("updateYear");
        updateYear->setGeometry(QRect(290, 20, 41, 18));
        updateYearComboBox = new QComboBox(updateGradeFrame);
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->setObjectName("updateYearComboBox");
        updateYearComboBox->setEnabled(true);
        updateYearComboBox->setGeometry(QRect(340, 20, 101, 26));
        gradeTable = new QTableWidget(tab_2);
        if (gradeTable->columnCount() < 6)
            gradeTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        gradeTable->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        gradeTable->setObjectName("gradeTable");
        gradeTable->setGeometry(QRect(80, 220, 801, 231));
        gradeTable->horizontalHeader()->setDefaultSectionSize(130);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 20, 171, 31));
        label_7->setFont(font);
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, 190, 81, 18));
        label_8->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(450, 20, 211, 41));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        label_9->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1069, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        studentSearchButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        allStudentSearchButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
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
        searchCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        searchCourseNamecomboBox->setItemText(0, QString());
        searchCourseNamecomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        searchCourseNamecomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        searchCourseNamecomboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        searchStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
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
        label->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\354\240\225\353\240\254 \352\270\260\354\244\200", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        sortComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        sortComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\355\217\211\352\267\240 \355\225\231\354\240\220", nullptr));

        ascPushButton->setText(QCoreApplication::translate("MainWindow", " \342\206\221", nullptr));
        descPushButton->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(remove), QCoreApplication::translate("MainWindow", " \355\225\231\354\203\235 \354\241\260\355\232\214", nullptr));
        registrationStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        registrationMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        registrationYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        registrationYearComboBox->setItemText(0, QString());
        registrationYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        registrationYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        registrationYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        registrationYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        registrationYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        registrationYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        registrationMajorComboBox->setItemText(0, QString());
        registrationMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        registrationMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        registrationMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        registrationName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        registrationPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235", nullptr));
        deleteStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = registrationTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = registrationTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = registrationTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = registrationTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235 \353\260\217 \354\202\255\354\240\234", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(registration), QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235 \353\260\217 \354\202\255\354\240\234", nullptr));
        addDeleteCourseStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        addDeleteCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        addDeleteCourseNameComboBox->setItemText(0, QString());

        addDeleteDeleteCourseMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        addDeleteCourseMajorComboBox->setItemText(0, QString());
        addDeleteCourseMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        addDeleteCourseMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        addDeleteCourseMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        addDeleteCourseYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        addDeleteYearComboBox->setItemText(0, QString());
        addDeleteYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        addDeleteYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        addDeleteYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        addDeleteYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        addDeleteYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        addDeleteYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        courseAddPushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200", nullptr));
        courseDeletePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = courseSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = courseSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = courseSearchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = courseSearchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = courseSearchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \354\266\224\352\260\200 \353\260\217 \354\202\255\354\240\234", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addCourse), QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \354\266\224\352\260\200 \353\260\217 \354\202\255\354\240\234", nullptr));
        updateStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        updateCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        updateMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        updateMajorComboBox->setItemText(0, QString());
        updateMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        updateMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        updateMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        updateGrade->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        updateCourseGradeCombobox->setItemText(0, QString());
        updateCourseGradeCombobox->setItemText(1, QCoreApplication::translate("MainWindow", "A+", nullptr));
        updateCourseGradeCombobox->setItemText(2, QCoreApplication::translate("MainWindow", "A", nullptr));
        updateCourseGradeCombobox->setItemText(3, QCoreApplication::translate("MainWindow", "B+", nullptr));
        updateCourseGradeCombobox->setItemText(4, QCoreApplication::translate("MainWindow", "B", nullptr));
        updateCourseGradeCombobox->setItemText(5, QCoreApplication::translate("MainWindow", "C+", nullptr));
        updateCourseGradeCombobox->setItemText(6, QCoreApplication::translate("MainWindow", "C", nullptr));
        updateCourseGradeCombobox->setItemText(7, QCoreApplication::translate("MainWindow", "F", nullptr));

        updateSearchPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        updateRegistrationGradePushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
        updateYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        updateYearComboBox->setItemText(0, QString());
        updateYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        updateYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        updateYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        updateYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        updateYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        updateYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        QTableWidgetItem *___qtablewidgetitem14 = gradeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = gradeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = gradeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = gradeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = gradeTable->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = gradeTable->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\355\225\231\354\240\220 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \352\264\200\353\246\254 \355\224\204\353\241\234\352\267\270\353\236\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
