/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created: Sun Mar 22 15:21:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../textedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextEdit[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      20,    9,    9,    9, 0x08,
      36,    9,   31,    9, 0x08,
      47,    9,   31,    9, 0x08,
      60,    9,    9,    9, 0x08,
      72,    9,    9,    9, 0x08,
      91,    9,    9,    9, 0x08,
     106,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,
     133,    9,    9,    9, 0x08,
     148,  146,    9,    9, 0x08,
     170,  168,    9,    9, 0x08,
     199,  188,    9,    9, 0x08,
     214,    9,    9,    9, 0x08,
     228,  226,    9,    9, 0x08,
     255,  248,    9,    9, 0x08,
     292,  285,    9,    9, 0x08,
     334,    9,    9,    9, 0x08,
     358,    9,    9,    9, 0x08,
     379,    9,    9,    9, 0x08,
     402,    9,    9,    9, 0x08,
     410,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TextEdit[] = {
    "TextEdit\0\0fileNew()\0fileOpen()\0bool\0"
    "fileSave()\0fileSaveAs()\0filePrint()\0"
    "filePrintPreview()\0filePrintPdf()\0"
    "textBold()\0textUnderline()\0textItalic()\0"
    "f\0textFamily(QString)\0p\0textSize(QString)\0"
    "styleIndex\0textStyle(int)\0textColor()\0"
    "a\0textAlign(QAction*)\0Option\0"
    "TranslationOptionChanged(int)\0format\0"
    "currentCharFormatChanged(QTextCharFormat)\0"
    "cursorPositionChanged()\0changeStyle(QString)\0"
    "clipboardDataChanged()\0about()\0"
    "printPreview(QPrinter*)\0"
};

const QMetaObject TextEdit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEdit,
      qt_meta_data_TextEdit, 0 }
};

const QMetaObject *TextEdit::metaObject() const
{
    return &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileNew(); break;
        case 1: fileOpen(); break;
        case 2: { bool _r = fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: filePrint(); break;
        case 5: filePrintPreview(); break;
        case 6: filePrintPdf(); break;
        case 7: textBold(); break;
        case 8: textUnderline(); break;
        case 9: textItalic(); break;
        case 10: textFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: textSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: textStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: textColor(); break;
        case 14: textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 15: TranslationOptionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 17: cursorPositionChanged(); break;
        case 18: changeStyle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: clipboardDataChanged(); break;
        case 20: about(); break;
        case 21: printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
