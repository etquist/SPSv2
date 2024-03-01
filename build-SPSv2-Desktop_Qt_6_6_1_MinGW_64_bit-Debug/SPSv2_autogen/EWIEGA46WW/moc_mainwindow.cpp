/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SPSv2/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "updateActions_catalogNetwork",
    "",
    "updateActions_catalogConst",
    "updateActions_compList",
    "updateActions_netCompList",
    "on_pushButton_clicked",
    "newDatabaseEntryButton",
    "insertCatalogEntry",
    "nameInpt",
    "typeInpt",
    "uniqueIDInpt",
    "insertCatalogLabel",
    "QModelIndex",
    "name",
    "promptForPath",
    "initialization",
    "on_catalogView_doubleClicked",
    "index",
    "newCatalogLabel_connector",
    "updatePropertiesEditorLabel_input",
    "on_catalogView_1_clicked",
    "launchGitHub",
    "databaseNetworkHelpButton",
    "databaseConstructorHelpButton",
    "importDatabase",
    "on_catalogView_1_doubleClicked",
    "deleteCatalogEntry",
    "on_pushButton_9_clicked",
    "on_pushButton_10_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[11];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[23];
    char stringdata5[26];
    char stringdata6[22];
    char stringdata7[23];
    char stringdata8[19];
    char stringdata9[9];
    char stringdata10[9];
    char stringdata11[13];
    char stringdata12[19];
    char stringdata13[12];
    char stringdata14[5];
    char stringdata15[14];
    char stringdata16[15];
    char stringdata17[29];
    char stringdata18[6];
    char stringdata19[26];
    char stringdata20[34];
    char stringdata21[25];
    char stringdata22[13];
    char stringdata23[26];
    char stringdata24[30];
    char stringdata25[15];
    char stringdata26[31];
    char stringdata27[19];
    char stringdata28[24];
    char stringdata29[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 28),  // "updateActions_catalogNetwork"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 26),  // "updateActions_catalogConst"
        QT_MOC_LITERAL(68, 22),  // "updateActions_compList"
        QT_MOC_LITERAL(91, 25),  // "updateActions_netCompList"
        QT_MOC_LITERAL(117, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(139, 22),  // "newDatabaseEntryButton"
        QT_MOC_LITERAL(162, 18),  // "insertCatalogEntry"
        QT_MOC_LITERAL(181, 8),  // "nameInpt"
        QT_MOC_LITERAL(190, 8),  // "typeInpt"
        QT_MOC_LITERAL(199, 12),  // "uniqueIDInpt"
        QT_MOC_LITERAL(212, 18),  // "insertCatalogLabel"
        QT_MOC_LITERAL(231, 11),  // "QModelIndex"
        QT_MOC_LITERAL(243, 4),  // "name"
        QT_MOC_LITERAL(248, 13),  // "promptForPath"
        QT_MOC_LITERAL(262, 14),  // "initialization"
        QT_MOC_LITERAL(277, 28),  // "on_catalogView_doubleClicked"
        QT_MOC_LITERAL(306, 5),  // "index"
        QT_MOC_LITERAL(312, 25),  // "newCatalogLabel_connector"
        QT_MOC_LITERAL(338, 33),  // "updatePropertiesEditorLabel_i..."
        QT_MOC_LITERAL(372, 24),  // "on_catalogView_1_clicked"
        QT_MOC_LITERAL(397, 12),  // "launchGitHub"
        QT_MOC_LITERAL(410, 25),  // "databaseNetworkHelpButton"
        QT_MOC_LITERAL(436, 29),  // "databaseConstructorHelpButton"
        QT_MOC_LITERAL(466, 14),  // "importDatabase"
        QT_MOC_LITERAL(481, 30),  // "on_catalogView_1_doubleClicked"
        QT_MOC_LITERAL(512, 18),  // "deleteCatalogEntry"
        QT_MOC_LITERAL(531, 23),  // "on_pushButton_9_clicked"
        QT_MOC_LITERAL(555, 24)   // "on_pushButton_10_clicked"
    },
    "MainWindow",
    "updateActions_catalogNetwork",
    "",
    "updateActions_catalogConst",
    "updateActions_compList",
    "updateActions_netCompList",
    "on_pushButton_clicked",
    "newDatabaseEntryButton",
    "insertCatalogEntry",
    "nameInpt",
    "typeInpt",
    "uniqueIDInpt",
    "insertCatalogLabel",
    "QModelIndex",
    "name",
    "promptForPath",
    "initialization",
    "on_catalogView_doubleClicked",
    "index",
    "newCatalogLabel_connector",
    "updatePropertiesEditorLabel_input",
    "on_catalogView_1_clicked",
    "launchGitHub",
    "databaseNetworkHelpButton",
    "databaseConstructorHelpButton",
    "importDatabase",
    "on_catalogView_1_doubleClicked",
    "deleteCatalogEntry",
    "on_pushButton_9_clicked",
    "on_pushButton_10_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  176,    2, 0x0a,    1 /* Public */,
       3,    0,  177,    2, 0x0a,    2 /* Public */,
       4,    0,  178,    2, 0x0a,    3 /* Public */,
       5,    0,  179,    2, 0x0a,    4 /* Public */,
       6,    0,  180,    2, 0x08,    5 /* Private */,
       7,    0,  181,    2, 0x08,    6 /* Private */,
       8,    3,  182,    2, 0x08,    7 /* Private */,
       8,    2,  189,    2, 0x28,   11 /* Private | MethodCloned */,
       8,    1,  194,    2, 0x28,   14 /* Private | MethodCloned */,
       8,    0,  197,    2, 0x28,   16 /* Private | MethodCloned */,
      12,    3,  198,    2, 0x08,   17 /* Private */,
      12,    2,  205,    2, 0x28,   21 /* Private | MethodCloned */,
      12,    1,  210,    2, 0x28,   24 /* Private | MethodCloned */,
      12,    0,  213,    2, 0x28,   26 /* Private | MethodCloned */,
      17,    1,  214,    2, 0x08,   27 /* Private */,
      19,    0,  217,    2, 0x08,   29 /* Private */,
      20,    1,  218,    2, 0x08,   30 /* Private */,
      20,    0,  221,    2, 0x28,   32 /* Private | MethodCloned */,
      21,    1,  222,    2, 0x08,   33 /* Private */,
      22,    0,  225,    2, 0x08,   35 /* Private */,
      23,    0,  226,    2, 0x08,   36 /* Private */,
      24,    0,  227,    2, 0x08,   37 /* Private */,
      25,    0,  228,    2, 0x08,   38 /* Private */,
      26,    1,  229,    2, 0x08,   39 /* Private */,
      27,    0,  232,    2, 0x08,   41 /* Private */,
      28,    0,  233,    2, 0x08,   42 /* Private */,
      29,    0,  234,    2, 0x08,   43 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    0x80000000 | 13, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   14,   15,   16,
    0x80000000 | 13, QMetaType::QString, QMetaType::Bool,   14,   15,
    0x80000000 | 13, QMetaType::QString,   14,
    0x80000000 | 13,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'updateActions_catalogNetwork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateActions_catalogConst'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateActions_compList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateActions_netCompList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'newDatabaseEntryButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insertCatalogEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'insertCatalogEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'insertCatalogEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'insertCatalogEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insertCatalogLabel'
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'insertCatalogLabel'
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'insertCatalogLabel'
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'insertCatalogLabel'
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        // method 'on_catalogView_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'newCatalogLabel_connector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updatePropertiesEditorLabel_input'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updatePropertiesEditorLabel_input'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_catalogView_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'launchGitHub'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'databaseNetworkHelpButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'databaseConstructorHelpButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_catalogView_1_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'deleteCatalogEntry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_10_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateActions_catalogNetwork(); break;
        case 1: _t->updateActions_catalogConst(); break;
        case 2: _t->updateActions_compList(); break;
        case 3: _t->updateActions_netCompList(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->newDatabaseEntryButton(); break;
        case 6: _t->insertCatalogEntry((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->insertCatalogEntry((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->insertCatalogEntry((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->insertCatalogEntry(); break;
        case 10: { QModelIndex _r = _t->insertCatalogLabel((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 11: { QModelIndex _r = _t->insertCatalogLabel((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 12: { QModelIndex _r = _t->insertCatalogLabel((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 13: { QModelIndex _r = _t->insertCatalogLabel();
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->on_catalogView_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 15: _t->newCatalogLabel_connector(); break;
        case 16: _t->updatePropertiesEditorLabel_input((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->updatePropertiesEditorLabel_input(); break;
        case 18: _t->on_catalogView_1_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 19: _t->launchGitHub(); break;
        case 20: _t->databaseNetworkHelpButton(); break;
        case 21: _t->databaseConstructorHelpButton(); break;
        case 22: _t->importDatabase(); break;
        case 23: _t->on_catalogView_1_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 24: _t->deleteCatalogEntry(); break;
        case 25: _t->on_pushButton_9_clicked(); break;
        case 26: _t->on_pushButton_10_clicked(); break;
        default: ;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
