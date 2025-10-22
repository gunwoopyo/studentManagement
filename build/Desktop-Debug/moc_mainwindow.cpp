/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "showWarningAndClear",
        "",
        "title",
        "message",
        "showInformingAndClear",
        "onMajorChanged",
        "major",
        "onTabChanged",
        "index",
        "on_searchStudentIDTextEntered",
        "on_searchNameTextEntered",
        "on_clearStudentDataPushButton_clicked",
        "on_searchStudentPushButton_clicked",
        "on_searchAllStudentButton_clicked",
        "on_registrationStudentPushButton_clicked",
        "on_deleteStudentTable_cellClicked",
        "row",
        "on_deleteStudentPushButton_clicked",
        "searchClear",
        "searchTable",
        "Student*",
        "headPointer",
        "searchStudentTable",
        "stnID",
        "name",
        "year",
        "applySearchTableRow",
        "QTableWidget*",
        "studentTable",
        "currentStudent",
        "applySearchTableRowColors",
        "totalStudentCount",
        "setSearchStudentInfo",
        "int&",
        "studentID",
        "QString&",
        "applyCourseTableRowColors",
        "courseTable",
        "on_courseStudentIDTextEntered",
        "on_courseNameTextEntered",
        "on_clearCourseDataPushButton_clicked",
        "on_courseSearchPushButton_clicked",
        "on_courseAllSearchPushButton_clicked",
        "on_courseAddPushButton_clicked",
        "on_courseTable_cellClicked",
        "on_deleteCoursePushButton_clicked",
        "on_courseGradePushButton_clicked",
        "stn",
        "courseSearchTable",
        "courseName",
        "insertCourseTable",
        "student",
        "Course*",
        "course",
        "courseClear",
        "on_searchAscPushButton_clicked",
        "on_searchDescPushButton_clicked",
        "bubbleSortTable",
        "table",
        "column",
        "ascending",
        "clearAllStudents",
        "saveDataBeforeClose"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'showWarningAndClear'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Slot 'showInformingAndClear'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Slot 'onMajorChanged'
        QtMocHelpers::SlotData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'onTabChanged'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'on_searchStudentIDTextEntered'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchNameTextEntered'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_clearStudentDataPushButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchAllStudentButton_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_registrationStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_deleteStudentTable_cellClicked'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'on_deleteStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'searchClear'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'searchTable'
        QtMocHelpers::SlotData<void(Student *)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'searchStudentTable'
        QtMocHelpers::SlotData<void(int, QString, QString, QString)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 }, { QMetaType::QString, 25 }, { QMetaType::QString, 26 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'applySearchTableRow'
        QtMocHelpers::SlotData<void(QTableWidget *, int, Student *)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 }, { QMetaType::Int, 17 }, { 0x80000000 | 21, 30 },
        }}),
        // Slot 'applySearchTableRowColors'
        QtMocHelpers::SlotData<void(QTableWidget *)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'totalStudentCount'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSearchStudentInfo'
        QtMocHelpers::SlotData<void(int &, QString &, QString &, QString &)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 35 }, { 0x80000000 | 36, 25 }, { 0x80000000 | 36, 26 }, { 0x80000000 | 36, 7 },
        }}),
        // Slot 'applyCourseTableRowColors'
        QtMocHelpers::SlotData<void(QTableWidget *)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 38 },
        }}),
        // Slot 'on_courseStudentIDTextEntered'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseNameTextEntered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_clearCourseDataPushButton_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseSearchPushButton_clicked'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseAllSearchPushButton_clicked'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseAddPushButton_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseTable_cellClicked'
        QtMocHelpers::SlotData<void(int)>(45, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'on_deleteCoursePushButton_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseGradePushButton_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'courseTable'
        QtMocHelpers::SlotData<void(Student *)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 48 },
        }}),
        // Slot 'courseSearchTable'
        QtMocHelpers::SlotData<void(int, QString, QString, QString, QString)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 }, { QMetaType::QString, 25 }, { QMetaType::QString, 26 }, { QMetaType::QString, 7 },
            { QMetaType::QString, 50 },
        }}),
        // Slot 'insertCourseTable'
        QtMocHelpers::SlotData<void(int, Student *, Course *)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 }, { 0x80000000 | 21, 52 }, { 0x80000000 | 53, 54 },
        }}),
        // Slot 'courseClear'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchAscPushButton_clicked'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchDescPushButton_clicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'bubbleSortTable'
        QtMocHelpers::SlotData<void(QTableWidget *, int, bool)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 59 }, { QMetaType::Int, 60 }, { QMetaType::Bool, 61 },
        }}),
        // Slot 'bubbleSortTable'
        QtMocHelpers::SlotData<void(QTableWidget *, int)>(58, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 28, 59 }, { QMetaType::Int, 60 },
        }}),
        // Slot 'clearAllStudents'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveDataBeforeClose'
        QtMocHelpers::SlotData<void()>(63, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->showWarningAndClear((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->showInformingAndClear((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->onMajorChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onTabChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_searchStudentIDTextEntered(); break;
        case 5: _t->on_searchNameTextEntered(); break;
        case 6: _t->on_clearStudentDataPushButton_clicked(); break;
        case 7: _t->on_searchStudentPushButton_clicked(); break;
        case 8: _t->on_searchAllStudentButton_clicked(); break;
        case 9: _t->on_registrationStudentPushButton_clicked(); break;
        case 10: _t->on_deleteStudentTable_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_deleteStudentPushButton_clicked(); break;
        case 12: _t->searchClear(); break;
        case 13: _t->searchTable((*reinterpret_cast<std::add_pointer_t<Student*>>(_a[1]))); break;
        case 14: _t->searchStudentTable((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 15: _t->applySearchTableRow((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<Student*>>(_a[3]))); break;
        case 16: _t->applySearchTableRowColors((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1]))); break;
        case 17: _t->totalStudentCount(); break;
        case 18: _t->setSearchStudentInfo((*reinterpret_cast<std::add_pointer_t<int&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[4]))); break;
        case 19: _t->applyCourseTableRowColors((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1]))); break;
        case 20: _t->on_courseStudentIDTextEntered(); break;
        case 21: _t->on_courseNameTextEntered(); break;
        case 22: _t->on_clearCourseDataPushButton_clicked(); break;
        case 23: _t->on_courseSearchPushButton_clicked(); break;
        case 24: _t->on_courseAllSearchPushButton_clicked(); break;
        case 25: _t->on_courseAddPushButton_clicked(); break;
        case 26: _t->on_courseTable_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_deleteCoursePushButton_clicked(); break;
        case 28: _t->on_courseGradePushButton_clicked(); break;
        case 29: _t->courseTable((*reinterpret_cast<std::add_pointer_t<Student*>>(_a[1]))); break;
        case 30: _t->courseSearchTable((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        case 31: _t->insertCourseTable((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Student*>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<Course*>>(_a[3]))); break;
        case 32: _t->courseClear(); break;
        case 33: _t->on_searchAscPushButton_clicked(); break;
        case 34: _t->on_searchDescPushButton_clicked(); break;
        case 35: _t->bubbleSortTable((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3]))); break;
        case 36: _t->bubbleSortTable((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 37: _t->clearAllStudents(); break;
        case 38: _t->saveDataBeforeClose(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_WARNING_POP
