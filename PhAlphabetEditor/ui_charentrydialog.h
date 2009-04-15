/********************************************************************************
** Form generated from reading ui file 'charentrydialog.ui'
**
** Created: Mon Apr 6 22:53:50 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
    QLabel *label_Char;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QRadioButton *radioButton_Vowel;
    QRadioButton *radioButton_DependantVowel;
    QRadioButton *radioButton_Consonant;
    QRadioButton *radioButton_Digit;
    QRadioButton *radioButton_SpecialSymbol;
    QRadioButton *radioButton_Virama;
    QLabel *label_Vowel;
    QLineEdit *lineEdit_DepRefVowel;
    QRadioButton *radioButton_None;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLineEdit *lineEdit_PhoneticString;
    QPushButton *pushButton_Add;
    QListWidget *listWidget;
    QPushButton *pushButton_Remove;
    QDialogButtonBox *buttonBox;
    QLabel *label_CharRelated;
    QPushButton *pushButton_Ok;

    void setupUi(QDialog *CharEntryDialog)
    {
        if (CharEntryDialog->objectName().isEmpty())
            CharEntryDialog->setObjectName(QString::fromUtf8("CharEntryDialog"));
        CharEntryDialog->resize(775, 317);
        label_Char = new QLabel(CharEntryDialog);
        label_Char->setObjectName(QString::fromUtf8("label_Char"));
        label_Char->setGeometry(QRect(9, 9, 132, 61));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_Char->setFont(font);
        groupBox = new QGroupBox(CharEntryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(147, 9, 241, 261));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        radioButton_Vowel = new QRadioButton(groupBox);
        radioButton_Vowel->setObjectName(QString::fromUtf8("radioButton_Vowel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton_Vowel);

        radioButton_DependantVowel = new QRadioButton(groupBox);
        radioButton_DependantVowel->setObjectName(QString::fromUtf8("radioButton_DependantVowel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton_DependantVowel);

        radioButton_Consonant = new QRadioButton(groupBox);
        radioButton_Consonant->setObjectName(QString::fromUtf8("radioButton_Consonant"));

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton_Consonant);

        radioButton_Digit = new QRadioButton(groupBox);
        radioButton_Digit->setObjectName(QString::fromUtf8("radioButton_Digit"));

        formLayout->setWidget(3, QFormLayout::LabelRole, radioButton_Digit);

        radioButton_SpecialSymbol = new QRadioButton(groupBox);
        radioButton_SpecialSymbol->setObjectName(QString::fromUtf8("radioButton_SpecialSymbol"));

        formLayout->setWidget(4, QFormLayout::LabelRole, radioButton_SpecialSymbol);

        radioButton_Virama = new QRadioButton(groupBox);
        radioButton_Virama->setObjectName(QString::fromUtf8("radioButton_Virama"));

        formLayout->setWidget(5, QFormLayout::LabelRole, radioButton_Virama);

        label_Vowel = new QLabel(groupBox);
        label_Vowel->setObjectName(QString::fromUtf8("label_Vowel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_Vowel);

        lineEdit_DepRefVowel = new QLineEdit(groupBox);
        lineEdit_DepRefVowel->setObjectName(QString::fromUtf8("lineEdit_DepRefVowel"));
        lineEdit_DepRefVowel->setMaxLength(4);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_DepRefVowel);

        radioButton_None = new QRadioButton(groupBox);
        radioButton_None->setObjectName(QString::fromUtf8("radioButton_None"));
        radioButton_None->setChecked(true);

        formLayout->setWidget(6, QFormLayout::LabelRole, radioButton_None);

        groupBox_2 = new QGroupBox(CharEntryDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 10, 361, 266));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lineEdit_PhoneticString = new QLineEdit(groupBox_2);
        lineEdit_PhoneticString->setObjectName(QString::fromUtf8("lineEdit_PhoneticString"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEdit_PhoneticString);

        pushButton_Add = new QPushButton(groupBox_2);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButton_Add);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, listWidget);

        pushButton_Remove = new QPushButton(groupBox_2);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));
        pushButton_Remove->setEnabled(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pushButton_Remove);

        buttonBox = new QDialogButtonBox(CharEntryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(230, 280, 160, 29));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        label_CharRelated = new QLabel(CharEntryDialog);
        label_CharRelated->setObjectName(QString::fromUtf8("label_CharRelated"));
        label_CharRelated->setGeometry(QRect(10, 210, 132, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_CharRelated->setFont(font1);
        pushButton_Ok = new QPushButton(CharEntryDialog);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setGeometry(QRect(230, 280, 75, 27));

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
        label_Char->setText(QString());
        groupBox->setTitle(QApplication::translate("CharEntryDialog", "Character Type", 0, QApplication::UnicodeUTF8));
        radioButton_Vowel->setText(QApplication::translate("CharEntryDialog", "Vowel", 0, QApplication::UnicodeUTF8));
        radioButton_DependantVowel->setText(QApplication::translate("CharEntryDialog", "Dependant Vowel", 0, QApplication::UnicodeUTF8));
        radioButton_Consonant->setText(QApplication::translate("CharEntryDialog", "Consonant", 0, QApplication::UnicodeUTF8));
        radioButton_Digit->setText(QApplication::translate("CharEntryDialog", "Digit", 0, QApplication::UnicodeUTF8));
        radioButton_SpecialSymbol->setText(QApplication::translate("CharEntryDialog", "Special Symbol", 0, QApplication::UnicodeUTF8));
        radioButton_Virama->setText(QApplication::translate("CharEntryDialog", "Virama / Halant", 0, QApplication::UnicodeUTF8));
        label_Vowel->setText(QApplication::translate("CharEntryDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_DepRefVowel->setToolTip(QApplication::translate("CharEntryDialog", "The corresponding dependant/independant form of the character (in Hex)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_DepRefVowel->setInputMask(QApplication::translate("CharEntryDialog", "hhhh; ", 0, QApplication::UnicodeUTF8));
        radioButton_None->setText(QApplication::translate("CharEntryDialog", "None", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CharEntryDialog", "Phonetic Strings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_PhoneticString->setToolTip(QApplication::translate("CharEntryDialog", "Enter Phonetic String here", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_Add->setText(QApplication::translate("CharEntryDialog", "&Add", 0, QApplication::UnicodeUTF8));
        pushButton_Remove->setText(QApplication::translate("CharEntryDialog", "&Remove", 0, QApplication::UnicodeUTF8));
        label_CharRelated->setText(QString());
        pushButton_Ok->setText(QApplication::translate("CharEntryDialog", "Ok", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CharEntryDialog);
    } // retranslateUi

};

namespace Ui {
    class CharEntryDialog: public Ui_CharEntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARENTRYDIALOG_H
