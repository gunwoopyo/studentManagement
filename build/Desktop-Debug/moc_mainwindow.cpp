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
        "showMessegeAndClear",
        "",
        "title",
        "message",
        "onMajorChanged",
        "major",
        "onTabChanged",
        "index",
        "totalStudentCount",
        "setCourseInfo",
        "int&",
        "studentID",
        "QString&",
        "name",
        "year",
        "courseName",
        "setStudentInfo",
        "on_searchStudentIDTextEntered",
        "on_searchNameTextEntered",
        "on_clearStudentTextPushButton_clicked",
        "on_searchStudentPushButton_clicked",
        "on_searchAllStudentButton_clicked",
        "on_registrationStudentPushButton_clicked",
        "on_studentTable_cellClicked",
        "row",
        "on_deleteStudentPushButton_clicked",
        "clearStudentField",
        "studentTable",
        "Student*",
        "student",
        "searchStudent",
        "stnID",
        "applyStudentTableRow",
        "QTableWidget*",
        "currentStudent",
        "applyStudentTableRowColors",
        "courseTable",
        "searchAllStudent",
        "applyCourseTableRowColors",
        "on_courseStudentIDTextEntered",
        "on_courseNameTextEntered",
        "on_clearCourseTextPushButton_clicked",
        "on_courseSearchPushButton_clicked",
        "on_courseAllSearchPushButton_clicked",
        "on_courseAddPushButton_clicked",
        "on_courseTable_cellClicked",
        "on_deleteCoursePushButton_clicked",
        "on_courseGradePushButton_clicked",
        "clearCourseField",
        "setCourseFieldEnabled",
        "enabled",
        "on_ascPushButton_clicked",
        "on_descPushButton_clicked",
        "bubbleSort",
        "table",
        "column",
        "ascending",
        "clearAllStudentsObjects",
        "saveStudentDataBeforeClose"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'showMessegeAndClear'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Slot 'onMajorChanged'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'onTabChanged'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'totalStudentCount'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCourseInfo'
        QtMocHelpers::SlotData<void(int &, QString &, QString &, QString &, QString &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 }, { 0x80000000 | 13, 14 }, { 0x80000000 | 13, 15 }, { 0x80000000 | 13, 6 },
            { 0x80000000 | 13, 16 },
        }}),
        // Slot 'setStudentInfo'
        QtMocHelpers::SlotData<void(int &, QString &, QString &, QString &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 }, { 0x80000000 | 13, 14 }, { 0x80000000 | 13, 15 }, { 0x80000000 | 13, 6 },
        }}),
        // Slot 'on_searchStudentIDTextEntered'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchNameTextEntered'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_clearStudentTextPushButton_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_searchAllStudentButton_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_registrationStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_studentTable_cellClicked'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
        // Slot 'on_deleteStudentPushButton_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearStudentField'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'studentTable'
        QtMocHelpers::SlotData<void(Student *)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 29, 30 },
        }}),
        // Slot 'searchStudent'
        QtMocHelpers::SlotData<void(int, QString, QString, QString)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 32 }, { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 6 },
        }}),
        // Slot 'applyStudentTableRow'
        QtMocHelpers::SlotData<void(QTableWidget *, int, Student *)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 28 }, { QMetaType::Int, 25 }, { 0x80000000 | 29, 35 },
        }}),
        // Slot 'applyStudentTableRowColors'
        QtMocHelpers::SlotData<void(QTableWidget *)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 28 },
        }}),
        // Slot 'courseTable'
        QtMocHelpers::SlotData<void(Student *)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 29, 30 },
        }}),
        // Slot 'searchStudent'
        QtMocHelpers::SlotData<void(int, QString, QString, QString, QString)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 32 }, { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 6 },
            { QMetaType::QString, 16 },
        }}),
        // Slot 'searchAllStudent'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'applyCourseTableRowColors'
        QtMocHelpers::SlotData<void(QTableWidget *)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 37 },
        }}),
        // Slot 'on_courseStudentIDTextEntered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseNameTextEntered'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_clearCourseTextPushButton_clicked'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseSearchPushButton_clicked'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseAllSearchPushButton_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseAddPushButton_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseTable_cellClicked'
        QtMocHelpers::SlotData<void(int)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
        // Slot 'on_deleteCoursePushButton_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_courseGradePushButton_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearCourseField'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCourseFieldEnabled'
        QtMocHelpers::SlotData<void(bool)>(50, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 51 },
        }}),
        // Slot 'on_ascPushButton_clicked'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_descPushButton_clicked'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'bubbleSort'
        QtMocHelpers::SlotData<void(QTableWidget *, int, bool)>(54, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 55 }, { QMetaType::Int, 56 }, { QMetaType::Bool, 57 },
        }}),
        // Slot 'bubbleSort'
        QtMocHelpers::SlotData<void(QTableWidget *, int)>(54, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 34, 55 }, { QMetaType::Int, 56 },
        }}),
        // Slot 'clearAllStudentsObjects'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveStudentDataBeforeClose'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPublic, QMetaType::Void),
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
        case 0: _t->showMessegeAndClear((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->onMajorChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onTabChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->totalStudentCount(); break;
        case 4: _t->setCourseInfo((*reinterpret_cast<std::add_pointer_t<int&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[5]))); break;
        case 5: _t->setStudentInfo((*reinterpret_cast<std::add_pointer_t<int&>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString&>>(_a[4]))); break;
        case 6: _t->on_searchStudentIDTextEntered(); break;
        case 7: _t->on_searchNameTextEntered(); break;
        case 8: _t->on_clearStudentTextPushButton_clicked(); break;
        case 9: _t->on_searchStudentPushButton_clicked(); break;
        case 10: _t->on_searchAllStudentButton_clicked(); break;
        case 11: _t->on_registrationStudentPushButton_clicked(); break;
        case 12: _t->on_studentTable_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_deleteStudentPushButton_clicked(); break;
        case 14: _t->clearStudentField(); break;
        case 15: _t->studentTable((*reinterpret_cast<std::add_pointer_t<Student*>>(_a[1]))); break;
        case 16: _t->searchStudent((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 17: _t->applyStudentTableRow((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<Student*>>(_a[3]))); break;
        case 18: _t->applyStudentTableRowColors((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1]))); break;
        case 19: _t->courseTable((*reinterpret_cast<std::add_pointer_t<Student*>>(_a[1]))); break;
        case 20: _t->searchStudent((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        case 21: _t->searchAllStudent(); break;
        case 22: _t->applyCourseTableRowColors((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1]))); break;
        case 23: _t->on_courseStudentIDTextEntered(); break;
        case 24: _t->on_courseNameTextEntered(); break;
        case 25: _t->on_clearCourseTextPushButton_clicked(); break;
        case 26: _t->on_courseSearchPushButton_clicked(); break;
        case 27: _t->on_courseAllSearchPushButton_clicked(); break;
        case 28: _t->on_courseAddPushButton_clicked(); break;
        case 29: _t->on_courseTable_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_deleteCoursePushButton_clicked(); break;
        case 31: _t->on_courseGradePushButton_clicked(); break;
        case 32: _t->clearCourseField(); break;
        case 33: _t->setCourseFieldEnabled((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 34: _t->on_ascPushButton_clicked(); break;
        case 35: _t->on_descPushButton_clicked(); break;
        case 36: _t->bubbleSort((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3]))); break;
        case 37: _t->bubbleSort((*reinterpret_cast<std::add_pointer_t<QTableWidget*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 38: _t->clearAllStudentsObjects(); break;
        case 39: _t->saveStudentDataBeforeClose(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableWidget* >(); break;
            }
            break;
        case 22:
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
        case 37:
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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    return _id;
}
QT_WARNING_POP
