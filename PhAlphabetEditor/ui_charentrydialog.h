/********************************************************************************
** Form generated from reading UI file 'charentrydialog.ui'
**
** Created: Sat Jun 19 11:24:17 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARENTRYDIALOG_H
#define UI_CHARENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CharEntryDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QLabel *label_Char;
    QLabel *label_CharRelated;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_Vowel;
    QRadioButton *radioButton_DependantVowel;
    QRadioButton *radioButton_Consonant;
    QRadioButton *radioButton_Digit;
    QRadioButton *radioButton_SpecialSymbol;
    QRadioButton *radioButton_Virama;
    QRadioButton *radioButton_None;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout;
    QLabel *label_Vowel;
    QLineEdit *lineEdit_DepRefVowel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_PhoneticString;
    QPushButton *pushButton_Add;
    QListWidget *listWidget;
    QPushButton *pushButton_Remove;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_Ok;

    void setupUi(QDialog *CharEntryDialog)
    {
        if (CharEntryDialog->objectName().isEmpty())
            CharEntryDialog->setObjectName(QString::fromUtf8("CharEntryDialog"));
        CharEntryDialog->resize(767, 317);
        gridLayout = new QGridLayout(CharEntryDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(CharEntryDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(true);
        label_Char = new QLabel(groupBox_3);
        label_Char->setObjectName(QString::fromUtf8("label_Char"));
        label_Char->setGeometry(QRect(0, 30, 132, 61));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_Char->setFont(font);
        label_Char->setFrameShape(QFrame::NoFrame);
        label_CharRelated = new QLabel(groupBox_3);
        label_CharRelated->setObjectName(QString::fromUtf8("label_CharRelated"));
        label_CharRelated->setGeometry(QRect(0, 210, 132, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_CharRelated->setFont(font1);
        label_CharRelated->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox = new QGroupBox(CharEntryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radioButton_Vowel = new QRadioButton(groupBox);
        radioButton_Vowel->setObjectName(QString::fromUtf8("radioButton_Vowel"));

        gridLayout_2->addWidget(radioButton_Vowel, 0, 0, 1, 1);

        radioButton_DependantVowel = new QRadioButton(groupBox);
        radioButton_DependantVowel->setObjectName(QString::fromUtf8("radioButton_DependantVowel"));

        gridLayout_2->addWidget(radioButton_DependantVowel, 1, 0, 1, 1);

        radioButton_Consonant = new QRadioButton(groupBox);
        radioButton_Consonant->setObjectName(QString::fromUtf8("radioButton_Consonant"));

        gridLayout_2->addWidget(radioButton_Consonant, 2, 0, 1, 1);

        radioButton_Digit = new QRadioButton(groupBox);
        radioButton_Digit->setObjectName(QString::fromUtf8("radioButton_Digit"));

        gridLayout_2->addWidget(radioButton_Digit, 3, 0, 1, 1);

        radioButton_SpecialSymbol = new QRadioButton(groupBox);
        radioButton_SpecialSymbol->setObjectName(QString::fromUtf8("radioButton_SpecialSymbol"));

        gridLayout_2->addWidget(radioButton_SpecialSymbol, 4, 0, 1, 1);

        radioButton_Virama = new QRadioButton(groupBox);
        radioButton_Virama->setObjectName(QString::fromUtf8("radioButton_Virama"));

        gridLayout_2->addWidget(radioButton_Virama, 5, 0, 1, 1);

        radioButton_None = new QRadioButton(groupBox);
        radioButton_None->setObjectName(QString::fromUtf8("radioButton_None"));
        radioButton_None->setChecked(true);

        gridLayout_2->addWidget(radioButton_None, 6, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFlat(true);
        formLayout = new QFormLayout(groupBox_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(5, 7, -1, 0);
        label_Vowel = new QLabel(groupBox_4);
        label_Vowel->setObjectName(QString::fromUtf8("label_Vowel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Vowel);

        lineEdit_DepRefVowel = new QLineEdit(groupBox_4);
        lineEdit_DepRefVowel->setObjectName(QString::fromUtf8("lineEdit_DepRefVowel"));
        lineEdit_DepRefVowel->setMaxLength(4);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_DepRefVowel);


        gridLayout_2->addWidget(groupBox_4, 8, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 2);

        groupBox_2 = new QGroupBox(CharEntryDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_PhoneticString = new QLineEdit(groupBox_2);
        lineEdit_PhoneticString->setObjectName(QString::fromUtf8("lineEdit_PhoneticString"));

        gridLayout_3->addWidget(lineEdit_PhoneticString, 0, 0, 1, 1);

        pushButton_Add = new QPushButton(groupBox_2);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setEnabled(false);

        gridLayout_3->addWidget(pushButton_Add, 0, 1, 1, 1);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout_3->addWidget(listWidget, 1, 0, 1, 1);

        pushButton_Remove = new QPushButton(groupBox_2);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setEnabled(false);

        gridLayout_3->addWidget(pushButton_Remove, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 3, 1, 1);

        buttonBox = new QDialogButtonBox(CharEntryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        gridLayout->addWidget(buttonBox, 1, 2, 1, 1);

        pushButton_Ok = new QPushButton(CharEntryDialog);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        gridLayout->addWidget(pushButton_Ok, 1, 1, 1, 1);


        retranslateUi(CharEntryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CharEntryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CharEntryDialog, SLOT(reject()));
        QObject::connect(radioButton_DependantVowel, SIGNAL(clicked(bool)), lineEdit_DepRefVowel, SLOT(setShown(bool)));
        QObject::connect(radioButton_Vowel, SIGNAL(clicked(bool)), lineEdit_DepRefVowel, SLOT(setShown(bool)));
        QObject::connect(pushButton_Ok, SIGNAL(clicked()), CharEntryDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(CharEntryDialog);
    } // setupUi

    void retranslateUi(QDialog *CharEntryDialog)
    {
        CharEntryDialog->setWindowTitle(QApplication::translate("CharEntryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CharEntryDialog", "Preview", 0, QApplication::UnicodeUTF8));
        label_Char->setText(QString());
        label_CharRelated->setText(QString());
        groupBox->setTitle(QApplication::translate("CharEntryDialog", "Character Type", 0, QApplication::UnicodeUTF8));
        radioButton_Vowel->setText(QApplication::translate("CharEntryDialog", "Vowel", 0, QApplication::UnicodeUTF8));
        radioButton_DependantVowel->setText(QApplication::translate("CharEntryDialog", "Dependant Vowel", 0, QApplication::UnicodeUTF8));
        radioButton_Consonant->setText(QApplication::translate("CharEntryDialog", "Consonant", 0, QApplication::UnicodeUTF8));
        radioButton_Digit->setText(QApplication::translate("CharEntryDialog", "Digit", 0, QApplication::UnicodeUTF8));
        radioButton_SpecialSymbol->setText(QApplication::translate("CharEntryDialog", "Special Symbol", 0, QApplication::UnicodeUTF8));
        radioButton_Virama->setText(QApplication::translate("CharEntryDialog", "Virama / Halant", 0, QApplication::UnicodeUTF8));
        radioButton_None->setText(QApplication::translate("CharEntryDialog", "None", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        label_Vowel->setText(QApplication::translate("CharEntryDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_DepRefVowel->setToolTip(QApplication::translate("CharEntryDialog", "The corresponding dependant/independant form of the character (in Hex)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_DepRefVowel->setInputMask(QApplication::translate("CharEntryDialog", "hhhh; ", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CharEntryDialog", "Phonetic Strings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_PhoneticString->setToolTip(QApplication::translate("CharEntryDialog", "Enter Phonetic String here", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_Add->setText(QApplication::translate("CharEntryDialog", "&Add", 0, QApplication::UnicodeUTF8));
        pushButton_Remove->setText(QApplication::translate("CharEntryDialog", "&Remove", 0, QApplication::UnicodeUTF8));
        pushButton_Ok->setText(QApplication::translate("CharEntryDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CharEntryDialog: public Ui_CharEntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARENTRYDIALOG_H
