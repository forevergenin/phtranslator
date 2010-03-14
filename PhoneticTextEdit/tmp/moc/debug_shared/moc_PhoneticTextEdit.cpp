/****************************************************************************
** Meta object code from reading C++ file 'PhTextEditor.h'
**
** Created: Sun Mar 22 15:21:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PhTextEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PhTextEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CPhoneticTextEdit[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      43,   18,   18,   18, 0x08,
      57,   18,   18,   18, 0x08,
      89,   81,   18,   18, 0x08,
     113,   18,   18,   18, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_CPhoneticTextEdit[] = {
    "CPhoneticTextEdit\0\0cursorPositionChanged()\0"
    "textChanged()\0TranslateSelectedText()\0"
    "bEnable\0TranslateOnTheFly(bool)\0"
    "TranslateOnTheFly()\0"
};

const QMetaObject CPhoneticTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_CPhoneticTextEdit,
      qt_meta_data_CPhoneticTextEdit, 0 }
};

const QMetaObject *CPhoneticTextEdit::metaObject() const
{
    return &staticMetaObject;
}

void *CPhoneticTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CPhoneticTextEdit))
        return static_cast<void*>(const_cast< CPhoneticTextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int CPhoneticTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cursorPositionChanged(); break;
        case 1: textChanged(); break;
        case 2: TranslateSelectedText(); break;
        case 3: TranslateOnTheFly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: TranslateOnTheFly(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
