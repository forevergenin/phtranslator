/********************************************************************************
** Form generated from reading UI file 'testdialog.ui'
**
** Created: Sat Jun 19 10:42:19 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIALOG_H
#define UI_TESTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TestDialog
{
public:
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_Output;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Input;
    QPushButton *pushButton_Translate;

    void setupUi(QDialog *TestDialog)
    {
        if (TestDialog->objectName().isEmpty())
            TestDialog->setObjectName(QString::fromUtf8("TestDialog"));
        TestDialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TestDialog->sizePolicy().hasHeightForWidth());
        TestDialog->setSizePolicy(sizePolicy);
        TestDialog->setModal(false);
        gridLayout_2 = new QGridLayout(TestDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit_Output = new QTextEdit(TestDialog);
        textEdit_Output->setObjectName(QString::fromUtf8("textEdit_Output"));

        gridLayout_2->addWidget(textEdit_Output, 0, 0, 1, 1);

        groupBox = new QGroupBox(TestDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_Input = new QLineEdit(groupBox);
        lineEdit_Input->setObjectName(QString::fromUtf8("lineEdit_Input"));

        gridLayout->addWidget(lineEdit_Input, 0, 0, 1, 1);

        pushButton_Translate = new QPushButton(groupBox);
        pushButton_Translate->setObjectName(QString::fromUtf8("pushButton_Translate"));

        gridLayout->addWidget(pushButton_Translate, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_Input, pushButton_Translate);
        QWidget::setTabOrder(pushButton_Translate, textEdit_Output);

        retranslateUi(TestDialog);
        QObject::connect(pushButton_Translate, SIGNAL(clicked()), TestDialog, SLOT(TranslateInputText()));
        QObject::connect(lineEdit_Input, SIGNAL(textChanged(QString)), pushButton_Translate, SLOT(click()));

        QMetaObject::connectSlotsByName(TestDialog);
    } // setupUi

    void retranslateUi(QDialog *TestDialog)
    {
        TestDialog->setWindowTitle(QApplication::translate("TestDialog", "Try your Character Mappings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("TestDialog", "GroupBox", 0, QApplication::UnicodeUTF8));
        lineEdit_Input->setText(QApplication::translate("TestDialog", "Type here ", 0, QApplication::UnicodeUTF8));
        pushButton_Translate->setText(QApplication::translate("TestDialog", "&Translate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestDialog: public Ui_TestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIALOG_H
