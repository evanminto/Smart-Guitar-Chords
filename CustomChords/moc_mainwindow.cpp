/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Mar 25 09:19:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     233,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     333,  327,   11,   11, 0x08,
     367,  327,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_chord_cancel_button_clicked()\0"
    "on_inst_cancel_button_clicked()\0"
    "on_chord_create_button_clicked()\0"
    "on_inst_create_button_clicked()\0"
    "on_chord_save_button_clicked()\0"
    "on_inst_save_button_clicked()\0"
    "on_del_chord_button_clicked()\0"
    "on_del_inst_button_clicked()\0"
    "on_chord_folder_button_clicked()\0"
    "on_inst_folder_button_clicked()\0index\0"
    "on_ChordTree_clicked(QModelIndex)\0"
    "on_InstrumentTree_clicked(QModelIndex)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_chord_cancel_button_clicked(); break;
        case 1: on_inst_cancel_button_clicked(); break;
        case 2: on_chord_create_button_clicked(); break;
        case 3: on_inst_create_button_clicked(); break;
        case 4: on_chord_save_button_clicked(); break;
        case 5: on_inst_save_button_clicked(); break;
        case 6: on_del_chord_button_clicked(); break;
        case 7: on_del_inst_button_clicked(); break;
        case 8: on_chord_folder_button_clicked(); break;
        case 9: on_inst_folder_button_clicked(); break;
        case 10: on_ChordTree_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 11: on_InstrumentTree_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
