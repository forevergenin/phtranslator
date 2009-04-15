#include "charentrydialog.h"
#include "ui_charentrydialog.h"
#include <QtGui/QListWidgetItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTableWidgetItem>

CharEntryDialog::CharEntryDialog(QWidget *parent, int nRow, int nCol) :
    QDialog(parent),
    m_ui(new Ui::CharEntryDialog),
    m_nRow(nRow),
    m_nCol(nCol)
{
    m_ui->setupUi(this);
    m_ui->label_Vowel->setShown(false);
    m_ui->lineEdit_DepRefVowel->setShown(false);
    m_ui->label_CharRelated->setShown(false);

    // Setup the character related settings in the UI
    QTableWidget* pTable = (QTableWidget*) parent;
    CPhoneticTableItem* pItem = (CPhoneticTableItem*)pTable->item(nRow, nCol);

    this->setWindowTitle(QString("Character: ") + QChar(pItem->m_uCode) + QString::fromLatin1("  %1").arg(pItem->m_uCode, 4, 16, QLatin1Char('0')) + "  (" + QString::number(pItem->m_uCode) + ")" );

    m_ui->label_Char->setText(QString("") + QChar(pItem->m_uCode));
    m_ui->lineEdit_DepRefVowel->setText(QString::fromLatin1("%1").arg(pItem->m_dRefCode, 4, 16, QLatin1Char('0')));

    switch(pItem->m_type)
    {
    case CPhoneticTableItem::Vowel:
        {
            m_ui->radioButton_Vowel->setChecked(true); 
            break;
        }
    case CPhoneticTableItem::DependantVowel:
        {
            m_ui->radioButton_DependantVowel->setChecked(true); 
            break;
        }
    case CPhoneticTableItem::Consonant:
        {
            m_ui->radioButton_Consonant->setChecked(true);
            break;
        }
    case CPhoneticTableItem::Digit:
        {
            m_ui->radioButton_Digit->setChecked(true);
            break;
        }
    case CPhoneticTableItem::SpecialSymbol:
        {
            m_ui->radioButton_SpecialSymbol->setChecked(true);
            break;
        }
    case CPhoneticTableItem::Halant:
        {
            m_ui->radioButton_Virama->setChecked(true);
            break;
        }
    default: break;
    }

    // Fill the Phonetic Strings in the ListBox
    m_ui->listWidget->addItems(pItem->m_phReps);

    this->m_AcceptedItem.m_uCode = pItem->m_uCode;
    this->m_AcceptedItem.m_type = pItem->m_type;
}

CharEntryDialog::~CharEntryDialog()
{
    delete m_ui;
}

void CharEntryDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CharEntryDialog::on_radioButton_Vowel_toggled(bool checked)
{
    m_ui->label_Vowel->setShown(checked);
    m_ui->lineEdit_DepRefVowel->setShown(checked);
    m_ui->label_CharRelated->setShown(checked);
    if(checked)
    {
        m_ui->label_Vowel->setText("Dependant form: ");
        this->m_AcceptedItem.m_type = CPhoneticTableItem::Vowel;
    }
}

void CharEntryDialog::on_radioButton_DependantVowel_toggled(bool checked)
{
    m_ui->label_Vowel->setShown(checked);
    m_ui->lineEdit_DepRefVowel->setShown(checked);
     m_ui->label_CharRelated->setShown(checked);
   if(checked)
    {
        m_ui->label_Vowel->setText("Vowel form: ");
        this->m_AcceptedItem.m_type = CPhoneticTableItem::DependantVowel;
    }
}

void CharEntryDialog::on_radioButton_SpecialSymbol_toggled(bool checked)
{
     m_ui->label_Vowel->setShown(!checked);
    m_ui->lineEdit_DepRefVowel->setShown(!checked);
     m_ui->label_CharRelated->setShown(!checked);
     if(checked) this->m_AcceptedItem.m_type = CPhoneticTableItem::SpecialSymbol;
}

void CharEntryDialog::on_radioButton_Virama_toggled(bool checked)
{
     m_ui->label_Vowel->setShown(!checked);
    m_ui->lineEdit_DepRefVowel->setShown(!checked);
     m_ui->label_CharRelated->setShown(!checked);
     if(checked) this->m_AcceptedItem.m_type = CPhoneticTableItem::Halant;
}

void CharEntryDialog::on_radioButton_Consonant_toggled(bool checked)
{
       m_ui->label_Vowel->setShown(!checked);
    m_ui->lineEdit_DepRefVowel->setShown(!checked);
     m_ui->label_CharRelated->setShown(!checked);
     if(checked) this->m_AcceptedItem.m_type = CPhoneticTableItem::Consonant;

}

void CharEntryDialog::on_radioButton_Digit_toggled(bool checked)
{
    m_ui->label_Vowel->setShown(!checked);
    m_ui->lineEdit_DepRefVowel->setShown(!checked);
     m_ui->label_CharRelated->setShown(!checked);
     if(checked) this->m_AcceptedItem.m_type = CPhoneticTableItem::Digit;
}

void CharEntryDialog::on_lineEdit_DepRefVowel_textChanged(QString str)
{
    //if(str.isEmpty())
    //    m_ui->label_CharRelated->setText("");
    //else
    {
        bool bOk = true;
        wchar_t uCode = str.toUShort(&bOk, 16);
        if(bOk)
            m_ui->label_CharRelated->setText(QString("") + QChar(uCode));
        else
            m_ui->label_CharRelated->setText("");

    }
}

void CharEntryDialog::on_lineEdit_PhoneticString_textChanged(QString str)
{
    m_ui->pushButton_Add->setEnabled(str.isEmpty() == false && m_ui->listWidget->findItems(str, Qt::MatchFixedString | Qt::MatchCaseSensitive).empty());
}

void CharEntryDialog::on_listWidget_itemSelectionChanged()
{
    m_ui->pushButton_Remove->setEnabled(m_ui->listWidget->selectedItems().empty() == false);
}

void CharEntryDialog::on_pushButton_Add_clicked()
{
    QString strPhonetic = m_ui->lineEdit_PhoneticString->text();

    m_ui->listWidget->addItem(strPhonetic);

    m_ui->lineEdit_PhoneticString->setText("");
}

void CharEntryDialog::on_pushButton_Remove_clicked()
{
   QListWidgetItem* pListItem =  m_ui->listWidget->takeItem(m_ui->listWidget->row(m_ui->listWidget->currentItem()));
   delete pListItem;
}



void CharEntryDialog::on_radioButton_None_toggled(bool checked)
{
      m_ui->label_Vowel->setShown(!checked);
    m_ui->lineEdit_DepRefVowel->setShown(!checked);
     m_ui->label_CharRelated->setShown(!checked);
     if(checked) this->m_AcceptedItem.m_type = CPhoneticTableItem::Invalid;
}

void CharEntryDialog::on_pushButton_Ok_clicked()
{
       for(int i=0; i < m_ui->listWidget->count(); ++i)
    {
        this->m_AcceptedItem.m_phReps.append(m_ui->listWidget->item(i)->text());
    }
    if(this->m_AcceptedItem.m_type == CPhoneticTableItem::Vowel ||
       this->m_AcceptedItem.m_type == CPhoneticTableItem::DependantVowel)
    {
        bool bOk = false;
       this->m_AcceptedItem.m_dRefCode = (wchar_t)m_ui->lineEdit_DepRefVowel->text().toUShort(&bOk, 16);
    }
}
