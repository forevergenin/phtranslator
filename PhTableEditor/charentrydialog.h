#ifndef CHARENTRYDIALOG_H
#define CHARENTRYDIALOG_H

#include <QtGui/QDialog>
#include "cphonetictableitem.h"

namespace Ui {
    class CharEntryDialog;
}

class CharEntryDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(CharEntryDialog)
public:
    explicit CharEntryDialog(QWidget *parent, int nRow, int nCol);
    virtual ~CharEntryDialog();

    CPhoneticTableItem m_AcceptedItem;

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::CharEntryDialog *m_ui;

    // Parent Table Column and Row being edited
    int m_nRow;
    int m_nCol;

private slots:
    void on_pushButton_Ok_clicked();
    void on_radioButton_None_toggled(bool checked);
    void on_pushButton_Remove_clicked();
    void on_pushButton_Add_clicked();
    void on_listWidget_itemSelectionChanged();
    void on_lineEdit_PhoneticString_textChanged(QString );
    void on_lineEdit_DepRefVowel_textChanged(QString );
    void on_radioButton_Digit_toggled(bool checked);
    void on_radioButton_Consonant_toggled(bool checked);
    void on_radioButton_Virama_toggled(bool checked);
    void on_radioButton_SpecialSymbol_toggled(bool checked);
    void on_radioButton_DependantVowel_toggled(bool checked);
    void on_radioButton_Vowel_toggled(bool checked);
};

    #endif // CHARENTRYDIALOG_H
