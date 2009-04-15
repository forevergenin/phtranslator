#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QtGui/QDialog>
#include "LanguageCodes.h"

namespace Ui {
    class TestDialog;
}

class TestDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(TestDialog)
public:
    explicit TestDialog(QWidget *parent , PhTranslation::PhTranslator*, QFont&);
    virtual ~TestDialog();

    PhTranslation::PhTranslator* m_pTranslator;

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::TestDialog *m_ui;

private slots:
    void TranslateInputText();

};

#endif // TESTDIALOG_H
