#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QLabel>
#include "CPhoneticTableItem.h"
#include "LanguageCodes.h"


namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum {ColumnHeight = 16};

private:
    Ui::MainWindowClass *ui;

    void setupTranslationActions();

    void* GetActiveTranslator(int Option);

    void AdjustHeaderSizes(const QFont& font);

    PhTranslation::PhTranslator* GetTranslator(QTableWidget* pTableWidget, QString& strFilePath=QString("")) const;
    
    QComboBox *comboTranslation;
    QLabel* labelTranslation;
    QComboBox *comboThemes;
    QLabel* labelThemes;
    QComboBox *sizeCombo;
    QFontComboBox *fontCombo;

    wchar_t m_nCodeStart, m_nCodeEnd;
    const PhTranslation::VowelDef* m_pVowels;
    const PhTranslation::ConsonantDef* m_pConsonants;
    const PhTranslation::SpecialSymbolDef* m_pSpecialSymbols;
    const PhTranslation::DigitDef* m_pDigits;
    wchar_t m_nVirama;
    int m_nVowelCount, m_nConsonantCount, m_nSpecialSymbolCount, m_nDigitCount;

    const PhTranslation::VowelDef* m_pCustomVowels;
    const PhTranslation::ConsonantDef* m_pCustomConsonants;
    const PhTranslation::SpecialSymbolDef* m_pCustomSpecialSymbols;
    const PhTranslation::DigitDef* m_pCustomDigits;
    wchar_t m_nCustomVirama;
    int m_nCustomVowelCount, m_nCustomConsonantCount, m_nCustomSpecialSymbolCount, m_nCustomDigitCount;
    wchar_t m_nCustomCodeStart, m_nCustomCodeEnd;

    void* m_pCustomTranslator;
    QString m_strCustomPhoneticTablePath;

    //RichDelegate    m_TableItemDelegate;

private slots:
    void DisplayTestDialog();
    void on_pushButtonDisplay_clicked();
    void TranslationOptionChanged(int Option);
    void LoadCustomPhTable();
    void SaveCustomPhTable();
    void findSizes(const QFont &font);
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void TableCellEntered(int , int);
    void InvokeCharEditorDialog(int, int);
    void FillTable();
    void fileSave();
    void fileOpen();
    void about();
};

#endif // MAINWINDOW_H
