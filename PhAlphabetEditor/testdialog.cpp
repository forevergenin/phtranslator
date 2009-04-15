#include "testdialog.h"
#include "ui_testdialog.h"

#include <string>

TestDialog::TestDialog(QWidget *parent, PhTranslation::PhTranslator* pTranslator, QFont& font) :
    QDialog(parent),
    m_ui(new Ui::TestDialog), m_pTranslator(pTranslator)
{
    m_ui->setupUi(this);

    m_ui->textEdit_Output->setFont(font);
}

TestDialog::~TestDialog()
{
    delete m_ui;
}

void TestDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void TestDialog::TranslateInputText()
{
    QString strInput = m_ui->lineEdit_Input->text();

    std::wstring strRet;

    this->m_pTranslator->Translate(strInput.toStdWString().c_str(), strRet);

    m_ui->textEdit_Output->setText(QString::fromStdWString(strRet));
}
