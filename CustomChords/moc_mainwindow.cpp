/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Apr 28 17:06:47 2011
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     270,   11,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     363,   11,   11,   11, 0x08,
     393,   11,   11,   11, 0x08,
     422,   11,   11,   11, 0x08,
     455,   11,   11,   11, 0x08,
     493,  487,   11,   11, 0x08,
     527,  487,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_suggestions_currentIndexChanged(QString)\0"
    "on_chord_tab_field_editingFinished()\0"
    "on_chord_tab_field_textEdited(QString)\0"
    "on_chord_tab_field_textChanged(QString)\0"
    "on_chord_cancel_button_clicked()\0"
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
        case 0: on_suggestions_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_chord_tab_field_editingFinished(); break;
        case 2: on_chord_tab_field_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_chord_tab_field_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: on_chord_cancel_button_clicked(); break;
        case 5: on_inst_cancel_button_clicked(); break;
        case 6: on_chord_create_button_clicked(); break;
        case 7: on_inst_create_button_clicked(); break;
        case 8: on_chord_save_button_clicked(); break;
        case 9: on_inst_save_button_clicked(); break;
        case 10: on_del_chord_button_clicked(); break;
        case 11: on_del_inst_button_clicked(); break;
        case 12: on_chord_folder_button_clicked(); break;
        case 13: on_inst_folder_button_clicked(); break;
        case 14: on_ChordTree_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 15: on_InstrumentTree_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
