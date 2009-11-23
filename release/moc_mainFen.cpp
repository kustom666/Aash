/****************************************************************************
** Meta object code from reading C++ file 'mainFen.h'
**
** Created: Mon 23. Nov 17:22:30 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainFen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainFen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainFen[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      23,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      53,    8,    8,    8, 0x08,
      62,    8,    8,    8, 0x08,
      71,    8,    8,    8, 0x08,
      80,    8,    8,    8, 0x08,
      89,    8,    8,    8, 0x08,
     112,    8,    8,    8, 0x08,
     125,    8,    8,    8, 0x08,
     147,    8,    8,    8, 0x08,
     172,    8,    8,    8, 0x08,
     181,    8,    8,    8, 0x08,
     198,    8,    8,    8, 0x08,
     218,    8,    8,    8, 0x08,
     228,    8,    8,    8, 0x08,
     238,    8,    8,    8, 0x08,
     247,    8,    8,    8, 0x08,
     258,    8,    8,    8, 0x08,
     275,  269,    8,    8, 0x08,
     305,    8,  300,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mainFen[] = {
    "mainFen\0\0updateLigne()\0nouvelOnglet()\0"
    "fermerOnglet()\0couper()\0copier()\0"
    "coller()\0sauver()\0telechargerSourceWeb()\0"
    "sauverSous()\0changementOnglet(int)\0"
    "changementTitre(QString)\0ouvrir()\0"
    "croixFermer(int)\0changementColo(int)\0"
    "annuler()\0refaire()\0zoomer()\0dezoomer()\0"
    "compiler()\0event\0closeEvent(QCloseEvent*)\0"
    "bool\0nonSauve()\0"
};

const QMetaObject mainFen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainFen,
      qt_meta_data_mainFen, 0 }
};

const QMetaObject *mainFen::metaObject() const
{
    return &staticMetaObject;
}

void *mainFen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainFen))
        return static_cast<void*>(const_cast< mainFen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainFen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateLigne(); break;
        case 1: nouvelOnglet(); break;
        case 2: fermerOnglet(); break;
        case 3: couper(); break;
        case 4: copier(); break;
        case 5: coller(); break;
        case 6: sauver(); break;
        case 7: telechargerSourceWeb(); break;
        case 8: sauverSous(); break;
        case 9: changementOnglet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: changementTitre((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: ouvrir(); break;
        case 12: croixFermer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: changementColo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: annuler(); break;
        case 15: refaire(); break;
        case 16: zoomer(); break;
        case 17: dezoomer(); break;
        case 18: compiler(); break;
        case 19: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 20: { bool _r = nonSauve();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
