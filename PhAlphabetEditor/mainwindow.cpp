#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <QtGui/QWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTableWidgetItem>
#include <QtCore/QString>
#include <QtGui/QMouseEvent>
#include <QtGui/QToolTip>
#include <Stdio.h>
#include "charentrydialog.h"
#include <QtGui/QAbstractItemView>
#include "testdialog.h"
#include <QtGui/QKeySequence>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass),
    m_nCodeStart(0), m_nCodeEnd(0), 
    m_pCustomVowels(0),
    m_pCustomConsonants(0),
    m_pCustomSpecialSymbols(0),
    m_pCustomDigits(0),
    m_nCustomVirama(0),
    m_nCustomVowelCount(0),
    m_nCustomConsonantCount(0),
    m_nCustomSpecialSymbolCount(0),
    m_nCustomDigitCount(0)
{
    ui->setupUi(this);
    setupTranslationActions();

    //ui->tableWidget->setItemDelegate(&m_TableItemDelegate);

    // Connect for tool tip - make sure the MouseTracking is enabled for Tablewidget for this to work
    connect(ui->tableWidget, SIGNAL(cellEntered(int, int )), this,     SLOT(TableCellEntered(int , int)));

    // Connect the Double-click of table item to CharEditor dialog
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(InvokeCharEditorDialog(int, int)));

    // Disable default editing when double-clicked. We will display our own dialog box.
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete m_pCustomVowels;
    delete m_pCustomConsonants;
    delete m_pCustomSpecialSymbols;
    delete m_pCustomDigits;
    delete ui;
}

void MainWindow::setupTranslationActions()
{
    // All these pionters allocated with this parameter will
    // be deleted automatically by Qt qhen this object goes away.
    // this object takes their ownership created with this as parameter in new.
    QToolBar* tb = new QToolBar(this);
    tb->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    tb->setWindowTitle(tr("Tables Toolbar"));
	//addToolBarBreak(Qt::TopToolBarArea);	
    addToolBar(tb);    

    labelTranslation = new QLabel(tr("&Table: "), tb);
    tb->addWidget(labelTranslation);

    comboTranslation = new QComboBox(tb);
    tb->addWidget(comboTranslation);
    comboTranslation->addItem("Bengali");
    comboTranslation->addItem("Gujarati");
    comboTranslation->addItem("Hindi");
    comboTranslation->addItem("Kannada");
    comboTranslation->addItem("Malayalam");
    comboTranslation->addItem("Oriya");
    comboTranslation->addItem("Punjabi");
    comboTranslation->addItem("Sanskrit");
    comboTranslation->addItem("Tamil");
    comboTranslation->addItem("Telugu");
    comboTranslation->addItem("Custom");
    connect(comboTranslation, SIGNAL(currentIndexChanged(int)), this, SLOT(TranslationOptionChanged(int)));

    labelTranslation->setBuddy(comboTranslation);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(fileOpen()));
    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT(fileSave()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    /////////////////////////////////////////////
    /// Setup Fonts and Sizes Combos
    QLabel *fontLabel = new QLabel(tr(" Font: "));
    fontCombo = new QFontComboBox;
    QLabel *sizeLabel = new QLabel(tr(" Size: "));
    sizeCombo = new QComboBox;

    fontLabel->setBuddy(fontCombo);
    sizeLabel->setBuddy(sizeCombo);

    tb->addSeparator();
    tb->addWidget(fontLabel);
    tb->addWidget(fontCombo);
    tb->addWidget(sizeLabel);
    tb->addWidget(sizeCombo);

    findSizes(fontCombo->currentFont());

    connect(fontCombo, SIGNAL(currentFontChanged(const QFont &)),
            this, SLOT(findSizes(const QFont &)));
    connect(fontCombo, SIGNAL(currentFontChanged(const QFont &)),
            this, SLOT(updateFont(const QFont &)));
    connect(sizeCombo, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(updateSize(const QString &)));


    //ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    //ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    // Initial Settings
    TranslationOptionChanged(0);
}


//! [8]


void MainWindow::findSizes(const QFont &font)
{
    QFontDatabase fontDatabase;
    QString currentSize = sizeCombo->currentText();
    sizeCombo->blockSignals(true);
    sizeCombo->clear();

    int size;
    if(fontDatabase.isSmoothlyScalable(font.family(), fontDatabase.styleString(font))) {
        foreach(size, QFontDatabase::standardSizes()) {
            sizeCombo->addItem(QVariant(size).toString());
            sizeCombo->setEditable(true);
        }

    } else {
        foreach(size, fontDatabase.smoothSizes(font.family(), fontDatabase.styleString(font))) {
            sizeCombo->addItem(QVariant(size).toString());
            sizeCombo->setEditable(false);
        }
    }

    sizeCombo->blockSignals(false);

    int sizeIndex = sizeCombo->findText(currentSize);

    if(sizeIndex == -1)
        sizeCombo->setCurrentIndex(qMax(0, sizeCombo->count() / 3));
    else
        sizeCombo->setCurrentIndex(sizeIndex);
}

void MainWindow::updateFont(const QFont &font)
{
    QFont newFont(font);    

    QTableWidgetItem* pItem = ui->tableWidget->item(0, 0);
    if(pItem)
    {
        pItem->setFont(newFont);
        updateSize(sizeCombo->currentText());
    }
    //newFont.setPointSize(sizeCombo->currentText().toInt());

    //ui->tableWidget->setUpdatesEnabled(false);

    //for(int i=0, nMax = ui->tableWidget->rowCount(); i < nMax; ++i)
    //    for(int j=0, jMax = ui->tableWidget->columnCount(); j < jMax; ++j)
    //    {
    //     QTableWidgetItem* pItem =   ui->tableWidget->item(i, j);
    //     pItem->setFont(newFont);
    //    }

    //ui->tableWidget->setUpdatesEnabled(true);
}
//! [1]

void MainWindow::AdjustHeaderSizes(const QFont& font)
{
    QFontMetrics fm(font);
    int nFontWidth = fm.maxWidth()/* + fm.averageCharWidth()*/;
    int nFontHeight = fm.height();

    int squareSize = qMax(32, qMax(nFontWidth, nFontHeight));

    int nRowCount = ui->tableWidget->rowCount();
    int nColCount = ui->tableWidget->columnCount();

    QStringList vertList;
    for(int i=0; i < nRowCount; ++i)
    {
        ui->tableWidget->verticalHeader()->resizeSection(i, squareSize);

        char sz[16]; sprintf(sz, "%X", i);
        vertList.append(QString::fromAscii(sz));
    }
    ui->tableWidget->setVerticalHeaderLabels(vertList);

    QStringList horizList;
    for(int j=0 ; j < nColCount; ++j)
    {
        ui->tableWidget->horizontalHeader()->resizeSection(j, squareSize);

        char sz[16]; sprintf(sz, "%03X", ((m_nCodeStart + (j*ColumnHeight))>>4) );
        horizList.append(QString::fromAscii(sz));
    }
    ui->tableWidget->setHorizontalHeaderLabels(horizList);   

}

//! [2]
void MainWindow::updateSize(const QString &fontSize)
{            
    QTableWidgetItem* pItem =   ui->tableWidget->item(0, 0);
    if(pItem)
    {
        QFont newFont(pItem->font());
        newFont.setPointSize(fontSize.toInt());
    
        ui->tableWidget->setUpdatesEnabled(false);

        AdjustHeaderSizes(newFont);

        // Update the item fonts
        for(int i=0, nMax = ui->tableWidget->rowCount(); i < nMax; ++i)
            for(int j=0, jMax = ui->tableWidget->columnCount(); j < jMax; ++j)
            {
             CPhoneticTableItem* pItem =   (CPhoneticTableItem *)ui->tableWidget->item(i, j);
             if(pItem)
                 pItem->setFont(newFont);
            }

        ui->tableWidget->setUpdatesEnabled(true);
    }

    //displayFont.setPointSize(fontSize.toInt());
    //squareSize = qMax(24, QFontMetrics(displayFont).xHeight() * 3);
    //adjustSize();
    //update();
}

#define CUSTOMTABLE_OPTION 11

void* MainWindow::GetActiveTranslator(int Option)
{
	switch(Option)
	{
	case 0: return NULL;
	//case 1: return GetBengaliTranslator();
	//case 2: return GetGujaratiTranslator();
	//case 3: return GetHindiTranslator();
	//case 4: return GetKannadaTranslator();
	//case 5: return GetMalayalamTranslator(); 
	//case 6: return GetOriyaTranslator();
	//case 7: return GetPunjabiTranslator(); 
	//case 8: return GetSanskritTranslator();
	//case 9: return GetTamilTranslator();
	//case 10: return GetTeluguTranslator();
    //case CUSTOMTABLE_OPTION: return m_pCustomTranslator;
    }
    return NULL;
}

template<typename T>
void SetupVowelStrings(T* Array, int nCount, QTableWidget* pTable, int nCodeStart)
{
    QStringList Reps;
    for(int nVowel=0; nVowel < nCount; nVowel++)
    {
        // Map the Independent Vowels
        int nRow = (Array[nVowel].uCode - nCodeStart)%MainWindow::ColumnHeight;
        int nCol = (Array[nVowel].uCode - nCodeStart)/MainWindow::ColumnHeight;

        int nDepRow = (Array[nVowel].dCode - nCodeStart)%MainWindow::ColumnHeight;
        int nDepCol = (Array[nVowel].dCode - nCodeStart)/MainWindow::ColumnHeight;

        CPhoneticTableItem* pItem = (CPhoneticTableItem*) pTable->item(nRow, nCol);
        if(pItem && pItem->m_uCode == Array[nVowel].uCode)
        {
            pItem->AddPhoneticString(QString::fromAscii(Array[nVowel].phRep));
            pItem->SetType(CPhoneticTableItem::Vowel);
            pItem->m_dRefCode = Array[nVowel].uCode;
        }

        if(Array[nVowel].dCode == 0) pItem->m_dRefCode = 0;
        else if(Array[nVowel].dCode != Array[nVowel].uCode)
        {
            // Map the Dependant Vowels
            CPhoneticTableItem* pDependantItem = (CPhoneticTableItem*) pTable->item(nDepRow, nDepCol);
            if(pDependantItem && pDependantItem->m_uCode == Array[nVowel].dCode)
            {
                pDependantItem->AddPhoneticString(QString::fromAscii(Array[nVowel].phRep));
                pDependantItem->SetType(CPhoneticTableItem::DependantVowel);
                pDependantItem->m_dRefCode = Array[nVowel].uCode;
                if(pItem) pItem->m_dRefCode = Array[nVowel].dCode;
            }
        }
    }
}

template<typename T>
void SetupStrings(T* Array, int nCount, QTableWidget* pTable, int nCodeStart, CPhoneticTableItem::ItemType type)
{
    QStringList Reps;
    for(int nVowel=0; nVowel < nCount; nVowel++)
    {
        // Map the Symbols
        int nRow = (Array[nVowel].uCode - nCodeStart)%MainWindow::ColumnHeight;
        int nCol = (Array[nVowel].uCode - nCodeStart)/MainWindow::ColumnHeight;

        CPhoneticTableItem* pItem = (CPhoneticTableItem*) pTable->item(nRow, nCol);
        //if(pItem == NULL)
        //{
        //    pItem = new CPhoneticTableItem((wchar_t)Array[nVowel].uCode, pTable->item(0,0)->font());
        //    pTable->setItem(nRow, nCol, pItem);
        //}
        if(pItem && pItem->m_uCode == Array[nVowel].uCode)
        {
            pItem->AddPhoneticString(QString::fromAscii(Array[nVowel].phRep));
            pItem->SetType(type);
        }
    }
}

void MainWindow::FillTable()
{
    this->cursor().setShape(Qt::CursorShape::BusyCursor);
    
    ui->tableWidget->clear();

    ui->tableWidget->setRowCount(ColumnHeight);
    ui->tableWidget->setColumnCount(((m_nCodeEnd - m_nCodeStart) + ColumnHeight-1)/ColumnHeight);

    QFont newFont(this->fontCombo->currentText());
    newFont.setPointSize(this->sizeCombo->currentText().toInt());

    // Create and associate Phonetic Items to the Table
    // Later we will set their PhoneticStrings
    for(int i=m_nCodeStart; i <= m_nCodeEnd ; ++i)
    {
        int nRow = (i - m_nCodeStart)%ColumnHeight;
        int nCol = (i - m_nCodeStart)/ColumnHeight;

        CPhoneticTableItem* pItem = new CPhoneticTableItem((wchar_t)i, newFont);
            
        ui->tableWidget->setItem(nRow, nCol, pItem);
    }

     // Set the Phonetic Strings to the Table Items
    SetupVowelStrings(m_pVowels, m_nVowelCount, ui->tableWidget, m_nCodeStart);
    SetupStrings(m_pConsonants, m_nConsonantCount, ui->tableWidget, m_nCodeStart, CPhoneticTableItem::Consonant);
    SetupStrings(m_pSpecialSymbols, m_nSpecialSymbolCount, ui->tableWidget, m_nCodeStart, CPhoneticTableItem::SpecialSymbol);
    SetupStrings(m_pDigits, m_nDigitCount, ui->tableWidget, m_nCodeStart, CPhoneticTableItem::Digit);

    // Setup Virama
    {        
        int nRow = (m_nVirama - m_nCodeStart)%MainWindow::ColumnHeight;
        int nCol = (m_nVirama - m_nCodeStart)/MainWindow::ColumnHeight;

        CPhoneticTableItem* pItem = (CPhoneticTableItem*) ui->tableWidget->item(nRow, nCol);
        if(pItem && pItem->m_uCode == m_nVirama)
        {
            pItem->SetType(CPhoneticTableItem::Halant);
        }
    }   
   
    // Modify the Header sizes based on the font
    AdjustHeaderSizes(newFont);

    // Update the text boxes to reflect the current progression
    ui->lineEditFrom->setText(QString::fromLatin1("%1").arg(m_nCodeStart, 4, 16, QLatin1Char('0')));
    ui->lineEditTo->setText(QString::fromLatin1("%1").arg(m_nCodeEnd, 4, 16, QLatin1Char('0')));

    this->cursor().setShape(Qt::CursorShape::ArrowCursor);
}

void MainWindow::TranslationOptionChanged(int Option)
{
    switch(Option)
    {
    case 0:
        {
            m_nCodeStart = 0x0980; m_nCodeEnd = 0x09FF; 
            m_pVowels = PhTranslation::Bengali::Vowels; m_nVowelCount = _countof(PhTranslation::Bengali::Vowels);
            m_pConsonants = PhTranslation::Bengali::Consonants; m_nConsonantCount = _countof(PhTranslation::Bengali::Consonants);
            m_pSpecialSymbols = PhTranslation::Bengali::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Bengali::SpecialSymbols);
            m_pDigits = PhTranslation::Bengali::Digits; m_nDigitCount = _countof(PhTranslation::Bengali::Digits);
            m_nVirama = PhTranslation::Bengali::uHalant;
            break;
        }
    case 1:
        {
            m_nCodeStart = 0x0A80; m_nCodeEnd = 0x0AFF;
            m_pVowels = PhTranslation::Gujarati::Vowels; m_nVowelCount = _countof(PhTranslation::Gujarati::Vowels);
            m_pConsonants = PhTranslation::Gujarati::Consonants; m_nConsonantCount = _countof(PhTranslation::Gujarati::Consonants);
            m_pSpecialSymbols = PhTranslation::Gujarati::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Gujarati::SpecialSymbols);
            m_pDigits = PhTranslation::Gujarati::Digits; m_nDigitCount = _countof(PhTranslation::Gujarati::Digits);
            m_nVirama = PhTranslation::Gujarati::uHalant;
            break;
        }
    case 2:
        {
            m_nCodeStart = 0x0900; m_nCodeEnd = 0x097F; 
            m_pVowels = PhTranslation::Hindi::Vowels; m_nVowelCount = _countof(PhTranslation::Hindi::Vowels);
            m_pConsonants = PhTranslation::Hindi::Consonants; m_nConsonantCount = _countof(PhTranslation::Hindi::Consonants);
            m_pSpecialSymbols = PhTranslation::Hindi::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Hindi::SpecialSymbols);
            m_pDigits = PhTranslation::Hindi::Digits; m_nDigitCount = _countof(PhTranslation::Hindi::Digits);
            m_nVirama = PhTranslation::Hindi::uHalant;
            break;
        }
    case 3:
        {        
           m_nCodeStart = 0x0C80; m_nCodeEnd = 0x0CFF; 
            m_pVowels = PhTranslation::Kannada::Vowels; m_nVowelCount = _countof(PhTranslation::Kannada::Vowels);
            m_pConsonants = PhTranslation::Kannada::Consonants; m_nConsonantCount = _countof(PhTranslation::Kannada::Consonants);
            m_pSpecialSymbols = PhTranslation::Kannada::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Kannada::SpecialSymbols);
            m_pDigits = PhTranslation::Kannada::Digits; m_nDigitCount = _countof(PhTranslation::Kannada::Digits);
            m_nVirama = PhTranslation::Kannada::uHalant;
            break;
        }
    case 4:
        {
            m_nCodeStart = 0x0D00; m_nCodeEnd = 0x0D7F; 
            m_pVowels = PhTranslation::Malayalam::Vowels; m_nVowelCount = _countof(PhTranslation::Malayalam::Vowels);
            m_pConsonants = PhTranslation::Malayalam::Consonants; m_nConsonantCount = _countof(PhTranslation::Malayalam::Consonants);
            m_pSpecialSymbols = PhTranslation::Malayalam::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Malayalam::SpecialSymbols);
            m_pDigits = PhTranslation::Malayalam::Digits; m_nDigitCount = _countof(PhTranslation::Malayalam::Digits);
            m_nVirama = PhTranslation::Malayalam::uHalant;
            break;
        }
    case 5:
        {
            m_nCodeStart = 0x0B00; m_nCodeEnd = 0x0B7F; 
            m_pVowels = PhTranslation::Oriya::Vowels; m_nVowelCount = _countof(PhTranslation::Oriya::Vowels);
            m_pConsonants = PhTranslation::Oriya::Consonants; m_nConsonantCount = _countof(PhTranslation::Oriya::Consonants);
            m_pSpecialSymbols = PhTranslation::Oriya::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Oriya::SpecialSymbols);
            m_pDigits = PhTranslation::Oriya::Digits; m_nDigitCount = _countof(PhTranslation::Oriya::Digits);
            m_nVirama = PhTranslation::Oriya::uHalant;
            break;
        }
    case 6:
        {
            m_nCodeStart = 0x0A00; m_nCodeEnd = 0x0A7F; 
            m_pVowels = PhTranslation::Punjabi::Vowels; m_nVowelCount = _countof(PhTranslation::Punjabi::Vowels);
            m_pConsonants = PhTranslation::Punjabi::Consonants; m_nConsonantCount = _countof(PhTranslation::Punjabi::Consonants);
            m_pSpecialSymbols = PhTranslation::Punjabi::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Punjabi::SpecialSymbols);
            m_pDigits = PhTranslation::Punjabi::Digits; m_nDigitCount = _countof(PhTranslation::Punjabi::Digits);
            m_nVirama = PhTranslation::Punjabi::uHalant;
            break;
        }
    case 7:
        {
            m_nCodeStart = 0x0900; m_nCodeEnd = 0x097F; 
            m_pVowels = PhTranslation::Sanskrit::Vowels; m_nVowelCount = _countof(PhTranslation::Sanskrit::Vowels);
            m_pConsonants = PhTranslation::Sanskrit::Consonants; m_nConsonantCount = _countof(PhTranslation::Sanskrit::Consonants);
            m_pSpecialSymbols = PhTranslation::Sanskrit::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Sanskrit::SpecialSymbols);
            m_pDigits = PhTranslation::Sanskrit::Digits; m_nDigitCount = _countof(PhTranslation::Sanskrit::Digits);
            m_nVirama = PhTranslation::Sanskrit::uHalant;
            break;
        }
    case 8:
        {
            m_nCodeStart = 0x0B80; m_nCodeEnd = 0x0BFF; 
            m_pVowels = PhTranslation::Tamil::Vowels; m_nVowelCount = _countof(PhTranslation::Tamil::Vowels);
            m_pConsonants = PhTranslation::Tamil::Consonants; m_nConsonantCount = _countof(PhTranslation::Tamil::Consonants);
            m_pSpecialSymbols = PhTranslation::Tamil::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Tamil::SpecialSymbols);
            m_pDigits = PhTranslation::Tamil::Digits; m_nDigitCount = _countof(PhTranslation::Tamil::Digits);
            m_nVirama = PhTranslation::Tamil::uHalant;
            break;
        }
    case 9:
        {
            m_nCodeStart = 0x0C00; m_nCodeEnd = 0x0C7F; 
            m_pVowels = PhTranslation::Telugu::Vowels; m_nVowelCount = _countof(PhTranslation::Telugu::Vowels);
            m_pConsonants = PhTranslation::Telugu::Consonants; m_nConsonantCount = _countof(PhTranslation::Telugu::Consonants);
            m_pSpecialSymbols = PhTranslation::Telugu::SpecialSymbols; m_nSpecialSymbolCount = _countof(PhTranslation::Telugu::SpecialSymbols);
            m_pDigits = PhTranslation::Telugu::Digits; m_nDigitCount = _countof(PhTranslation::Telugu::Digits);
            m_nVirama = PhTranslation::Telugu::uHalant;
            break;
        }
    default:
        {
            if(m_pCustomVowels == NULL)
                LoadCustomPhTable();
            m_nCodeStart = m_nCustomCodeStart; m_nCodeEnd = m_nCustomCodeEnd;
            m_pVowels = m_pCustomVowels; m_nVowelCount = m_nCustomVowelCount;
            m_pConsonants = m_pCustomConsonants; m_nConsonantCount = m_nCustomConsonantCount;
            m_pSpecialSymbols = m_pCustomSpecialSymbols; m_nSpecialSymbolCount = m_nCustomSpecialSymbolCount;
            m_pDigits = m_pCustomDigits; m_nDigitCount = m_nCustomDigitCount;
            m_nVirama = m_nCustomVirama;
            break;
        }
    }
    
    // Fill the table based on the selected values
    FillTable();
}


void MainWindow::TableCellEntered(int nRow, int nCol)
{
    CPhoneticTableItem* pItem = (CPhoneticTableItem*)ui->tableWidget->item(nRow, nCol);    
    if(pItem)        
    {
        QRect rect = ui->tableWidget->visualItemRect(pItem);        
        QToolTip::showText(QCursor::pos(), pItem->GetTipText(), this);
    }

    //QPoint widgetPosition = mapFromGlobal(event->globalPos());
}

void MainWindow::LoadCustomPhTable()
{
    QStringList filters; 
    filters << "PhoneticTable Files (*.PhTable)"         
         << "Any files (*)";

    QFileDialog OpenFileDlg;

    OpenFileDlg.setFilters(filters);
    OpenFileDlg.setFileMode(QFileDialog::ExistingFile);

    if(OpenFileDlg.exec())
    {
        QString strSelectedfileName = OpenFileDlg.selectedFiles()[0];

        {
		    FILE* fp = fopen(strSelectedfileName.toStdString().c_str(), "r");
		    if(fp != NULL)
		    {
			    char szHeader[16];

			    fscanf(fp, "%13s %u %u %u %u %u", szHeader, &m_nCustomVowelCount, &m_nCustomConsonantCount, &m_nCustomDigitCount, &m_nCustomSpecialSymbolCount, &m_nCustomVirama);
    			
			    if(strcmp(szHeader, "PhTranslation")) goto ReportError;

                if(m_nCustomVowelCount) { delete m_pCustomVowels; m_pCustomVowels = new PhTranslation::VowelDef[m_nCustomVowelCount]; }
                if(m_nCustomConsonantCount) { delete m_pCustomConsonants; m_pCustomConsonants = new PhTranslation::ConsonantDef[m_nCustomConsonantCount]; }
                if(m_nCustomDigitCount)		{ delete m_pCustomDigits;	m_pCustomDigits = new PhTranslation::DigitDef[m_nCustomDigitCount]; }
                if(m_nCustomSpecialSymbolCount) { delete m_pCustomSpecialSymbols;	m_pCustomSpecialSymbols = new PhTranslation::SpecialSymbolDef[m_nCustomSpecialSymbolCount]; }

                m_nCustomCodeStart = 0xFFFF, m_nCustomCodeEnd = 0;

			    {
				    for(int i=0; i < m_nCustomVowelCount; ++i)
                    {
					    fscanf(fp, "%8s %hu %hu", m_pCustomVowels[i].phRep, &m_pCustomVowels[i].uCode, &m_pCustomVowels[i].dCode);
                        if(m_pCustomVowels[i].uCode < m_nCustomCodeStart) m_nCustomCodeStart = m_pCustomVowels[i].uCode;
                        if(m_pCustomVowels[i].uCode > m_nCustomCodeEnd) m_nCustomCodeEnd = m_pCustomVowels[i].uCode;
                        if(m_pCustomVowels[i].dCode > m_nCustomCodeEnd) m_nCustomCodeEnd = m_pCustomVowels[i].dCode;                       
                    }

				    for(int i=0; i < m_nCustomConsonantCount; ++i)
                    {
					    fscanf(fp, "%8s %hu", m_pCustomConsonants[i].phRep, &m_pCustomConsonants[i].uCode);
                        if(m_pCustomConsonants[i].uCode < m_nCustomCodeStart) m_nCustomCodeStart = m_pCustomConsonants[i].uCode;
                        if(m_pCustomConsonants[i].uCode > m_nCustomCodeEnd) m_nCustomCodeEnd = m_pCustomConsonants[i].uCode;
                    }

				    for(int i=0; i < m_nCustomDigitCount; ++i)
                    {
					    fscanf(fp, "%8s %hu", m_pCustomDigits[i].phRep, &m_pCustomDigits[i].uCode);
                        if(m_pCustomDigits[i].uCode < m_nCustomCodeStart) m_nCustomCodeStart = m_pCustomDigits[i].uCode;
                        if(m_pCustomDigits[i].uCode > m_nCustomCodeEnd) m_nCustomCodeEnd = m_pCustomDigits[i].uCode;
                    }

				    for(int i=0; i < m_nCustomSpecialSymbolCount; ++i)
                    {
					    fscanf(fp, "%8s %hu", m_pCustomSpecialSymbols[i].phRep, &m_pCustomSpecialSymbols[i].uCode);
                        if(m_pCustomSpecialSymbols[i].uCode < m_nCustomCodeStart) m_nCustomCodeStart = m_pCustomSpecialSymbols[i].uCode;
                        if(m_pCustomSpecialSymbols[i].uCode > m_nCustomCodeEnd) m_nCustomCodeEnd = m_pCustomSpecialSymbols[i].uCode;
                    }

				    fclose(fp);
			    }
            }

            m_nCustomCodeStart = (m_nCustomCodeStart & 0xFFF0); // Align on Boundary
            m_nCustomCodeEnd = (m_nCustomCodeEnd | 0x000F);
        }

        if(m_pCustomVowels)
        {
            if(this->comboTranslation->currentIndex() != comboTranslation->findText("Custom")) 
                this->comboTranslation->setCurrentIndex(comboTranslation->findText("Custom"));

            this->m_strCustomPhoneticTablePath = strSelectedfileName;
        }
        else
        {
ReportError:
             QMessageBox msgBox;
             msgBox.setText("Unable to Load PhoneticTable");
             msgBox.setInformativeText(strSelectedfileName);
             msgBox.setStandardButtons(QMessageBox::Ok);
             msgBox.setIcon(QMessageBox::Critical);
             msgBox.exec();
        }
    }
}

void MainWindow::SaveCustomPhTable()
{     
    void* pTranslator = GetActiveTranslator(this->comboTranslation->currentIndex());

    if(pTranslator == NULL)
    {
         QMessageBox msgBox;
         msgBox.setText(tr("No Active Custom Phonetic Table Found."));
         msgBox.setInformativeText(tr("Tip: First Load a custom table using the <i>Load Custom Table</i> Menu Options."));
         msgBox.setStandardButtons(QMessageBox::Ok);
         msgBox.setIcon(QMessageBox::Warning);
         msgBox.exec();
        return;
    }
     
    QString fileName = QFileDialog::getSaveFileName(this,
                                 tr("Save File"),
                                 ".",
                                 tr("PhoneticTable Files (*.PhTable)"));
    if(!fileName.isEmpty())
    {

        if(false == NULL)
        {
             QMessageBox msgBox;
             msgBox.setText("Unable to Save PhoneticTable");
             msgBox.setInformativeText(fileName);
             msgBox.setStandardButtons(QMessageBox::Ok);             
             msgBox.setIcon(QMessageBox::Critical);
             msgBox.exec();
        }
    }
}


void MainWindow::InvokeCharEditorDialog(int nRow, int nCol)
{
    CPhoneticTableItem* pItem = (CPhoneticTableItem*)ui->tableWidget->item(nRow, nCol);
    if(pItem != NULL)
    {
        CharEntryDialog dlg(ui->tableWidget, nRow, nCol);
        if(dlg.exec() == QDialog::Accepted)
        {
            pItem->SetPhoneticStrings(dlg.m_AcceptedItem.m_phReps);
            pItem->m_dRefCode = dlg.m_AcceptedItem.m_dRefCode;
            pItem->SetType(dlg.m_AcceptedItem.m_type);

            // Make sure only one Halant is active
            if(pItem->m_type == CPhoneticTableItem::Halant)
            {
                if(this->m_nVirama != 0)
                {
                    int nRow = (m_nVirama - m_nCodeStart)%MainWindow::ColumnHeight;
                    int nCol = (m_nVirama - m_nCodeStart)/MainWindow::ColumnHeight;

                    CPhoneticTableItem* pViramaItem = (CPhoneticTableItem*)ui->tableWidget->item(nRow, nCol);
                    if(pViramaItem != NULL)
                        pViramaItem->SetType(CPhoneticTableItem::Invalid);
                }
                this->m_nVirama = pItem->m_uCode;
            }
        }
    }
}

void MainWindow::on_pushButtonDisplay_clicked()
{
    bool bOk = false;

    unsigned short nStart  = ui->lineEditFrom->text().toUShort(&bOk, 16);
    if(!bOk) return;
    unsigned short nEnd = ui->lineEditTo->text().toUShort(&bOk, 16);
    if(!bOk) return;

    m_nCodeStart = nStart; m_nCodeEnd = nEnd;

    m_nCodeStart = (m_nCodeStart & 0xFFF0); // Align on Boundary
    m_nCodeEnd = (m_nCodeEnd | 0x000F);

    FillTable();
}

template<typename T>
QString DumpVector(const T* inputArr, int nInputSize)
{
    QString strRet("");
    char sz[128];

    // For each entry in the definition
    int i=0, nCellCount = 0;

    while(i < nInputSize)
    {
        if(!(nCellCount%5))
            strRet += "<tr>";

        const T& defObj = inputArr[i];

        strRet += "<td class='ucStyle'>";
        sprintf(sz, "&#%hu;", defObj.uCode);
        strRet += sz;
        strRet += "</td> <td>";

        strRet += defObj.phRep;

        int j=i+1;
        while(j < nInputSize && inputArr[j].uCode == defObj.uCode)
        {
            strRet += ", ";
            strRet += inputArr[j].phRep;

            ++j;
        }

        strRet += "</td>";
        
        nCellCount++;

        if(!(nCellCount%5))
            strRet += "</tr>";


        i = j;
    }
        
    if((nCellCount%5)) strRet += "</tr>";


    return strRet;
}

const QString szTableCSS("<style type=\"text/css\">\nbody {    background-color: white;    color: black;    font-family: \"Times New Roman\", serif;    border: none;}\n h1, h2, h3, h4 {    font-family: Verdana, Arial, Helvetica, sans-serif;    font-weight: bold;}\n h1 {    font-size: 200%;    text-align: center;}\n h2 {    font-size: 130%;    text-align: center;}\n h3 {    font-size: 120%;}\n h4 {    font-size: 80%;}\n p {    font-size: 100%;}\n p.small {    font-size: 70%;    text-align: center;}\n p.important {    background-color:inherit;    color: red;}\n ul {    float:left;    width:100%;    padding:0;    margin:0;    list-style-type: none;    list-style-position: inside;}\n li.inline {    display:inline;}\n table {    table-layout: fixed;  /* Speeds up table layout */    width: 100%; height: 150px;}\n th {    background-color: #BDF;    color: inherit;}\n td {  margin-left: 5px;  margin-top: 5px;  text-align: center;  vertical-align: top;}\n table.sub {    border: 2px solid #888888  /* Speeds up table layout */}\n .ucStyle {    font-size: 1.5em;    text-align: center;    background-color: #FFBC79;    color: inherit;}\n a {    color: blue;    background-color: transparent;}\n a.language {    text-decoration: none;    font-size: 20px;}\n a:visited {    color: inherit;    background-color:inherit;}\n a:hover {    color: red;    background-color: inherit;}\n textarea {    width: 100%;    font-size: 15px;}\n </style>");

QString GetHtmlForTable(
    PhTranslation::VowelDef* pVowels, int nVowels, 
    PhTranslation::ConsonantDef* pConsonants,int nConsonants, 
    PhTranslation::DigitDef* pDigits,int nDigits, 
    PhTranslation::SpecialSymbolDef* pSpecialSymbols, int nSpecialSymbols)  
{ 
   QString strTables = "<html> <head><meta http-equiv='Content-Type' content='text/html; charset=utf-8' />" + szTableCSS + "</head><body>";

    strTables += "<table>";
    strTables += "<tr>";
    {
        strTables += "<td>";
        strTables += "<table>";
        {
            strTables += "<tr><td>";
            strTables += "<table border='1'><tr><th colspan='10'>Vowels</th></tr>";
            strTables += DumpVector(pVowels, nVowels);
            strTables += "</table>";            
            strTables += "</td></tr>";

            strTables += "<tr><td>";
            strTables += "<table border='1'><tr><th colspan='10'>Digits</th></tr>";
            strTables += DumpVector(pDigits, nDigits);
            strTables += "</table>";
            strTables += "</td></tr>";
        }
        strTables += "</table>";
        strTables += "</td>";

        strTables += "<td>";
        strTables += "<table border='1'><tr><th colspan='10'>Consonants</th></tr>";
        strTables += DumpVector(pConsonants, nConsonants);
        strTables += "</table>";
        strTables += "</td>";
    }
    strTables += "</tr>";

    strTables += "<tr>";
    {
        strTables += "<td>";
        strTables += "<table border='1'><tr><th colspan='10'>Special Symbols</th></tr>";
        strTables += DumpVector(pSpecialSymbols, nSpecialSymbols);
        strTables += "</table>";
        strTables += "</td>";
    }        
    strTables += "</tr>";

    strTables += "</table>";

    strTables += "</body></html>";

    return strTables;
}

template<typename T>
void GetExtraStrings(const T* Array, const int nCount, const int nCodeStart, QTableWidget* pTable, T* OutputArray, int& outputCount)
{
    QStringList Reps;
    for(int i=0; i < nCount; i++)
    {
        // Map the Symbols
        int nRow = (Array[i].uCode - nCodeStart)%MainWindow::ColumnHeight;
        int nCol = (Array[i].uCode - nCodeStart)/MainWindow::ColumnHeight;

        CPhoneticTableItem* pItem = (CPhoneticTableItem*) pTable->item(nRow, nCol);
        if(pItem == NULL)   // this item was not represented in the Table - so lets add it manually here
        {
            OutputArray[outputCount].uCode = Array[i].uCode;
            strcpy(OutputArray[outputCount].phRep, Array[i].phRep);
            outputCount++;
        }
    }
}

// Saves the Html tables and returns a Translator object
PhTranslation::PhTranslator* MainWindow::GetTranslator(QTableWidget* pTableWidget, QString& strFilePath/*=QString("")*/) const
{
    const int nItemCount = pTableWidget->rowCount() * pTableWidget->columnCount() * 2;  // Extra space for any symbols not present in the Tables but present in the Loaded Arrays
    PhTranslation::VowelDef* pVowels = new PhTranslation::VowelDef[nItemCount];
    PhTranslation::ConsonantDef* pConsonants = new PhTranslation::ConsonantDef[nItemCount];
    PhTranslation::SpecialSymbolDef* pSpecialSymbols = new PhTranslation::SpecialSymbolDef[nItemCount];
    PhTranslation::DigitDef* pDigits = new PhTranslation::DigitDef[nItemCount];

    int nVowels=0, nConsonants=0, nSpecialSymbols=0, nDigits=0;
    wchar_t nVirama=0;

    // Load the Table Items
    for(int nRow=0, nRowMax = pTableWidget->rowCount(); nRow < nRowMax; ++nRow)
        for(int nCol=0, nColMax = pTableWidget->columnCount(); nCol < nColMax; ++nCol)
        {
            CPhoneticTableItem* pItem = (CPhoneticTableItem *) pTableWidget->item(nRow, nCol);
            if(pItem != NULL)
            {
                if(pItem->m_type == CPhoneticTableItem::Halant)
                {
                     nVirama = pItem->m_uCode;
                     continue;
                }
                for(int nString=0, nStringMax = pItem->m_phReps.count(); nString < nStringMax; ++nString)
                {
                    switch(pItem->m_type)
                    {
                    case CPhoneticTableItem::Vowel:
                        {
                            pVowels[nVowels].uCode = pItem->m_uCode;
                            pVowels[nVowels].dCode = pItem->m_dRefCode;
                            strncpy(pVowels[nVowels].phRep, pItem->m_phReps[nString].toStdString().c_str(),_countof(pVowels[nVowels].phRep)-1);
                            pVowels[nVowels].phRep[_countof(pVowels[nVowels].phRep)-1] = 0;
                            nVowels++;
                            break;
                        }
                    case CPhoneticTableItem::Consonant:
                        {
                            pConsonants[nConsonants].uCode = pItem->m_uCode;
                            strncpy(pConsonants[nConsonants].phRep, pItem->m_phReps[nString].toStdString().c_str(),_countof(pConsonants[nConsonants].phRep)-1);
                            pConsonants[nVowels].phRep[_countof(pConsonants[nConsonants].phRep)-1] = 0;
                            nConsonants++;
                            break;
                        }
                    case CPhoneticTableItem::SpecialSymbol:
                        {
                            pSpecialSymbols[nSpecialSymbols].uCode = pItem->m_uCode;
                            strncpy(pSpecialSymbols[nSpecialSymbols].phRep, pItem->m_phReps[nString].toStdString().c_str(),_countof(pSpecialSymbols[nSpecialSymbols].phRep)-1);
                            pSpecialSymbols[nVowels].phRep[_countof(pSpecialSymbols[nSpecialSymbols].phRep)-1] = 0;
                            nSpecialSymbols++;
                            break;
                        }
                    case CPhoneticTableItem::Digit:
                        {
                            pDigits[nDigits].uCode = pItem->m_uCode;
                            strncpy(pDigits[nDigits].phRep, pItem->m_phReps[nString].toStdString().c_str(),_countof(pDigits[nDigits].phRep)-1);
                            pDigits[nVowels].phRep[_countof(pDigits[nDigits].phRep)-1] = 0;
                            nDigits++;
                            break;
                        }
                    }
                }
            }
        }

        // Some characters might not have been added to the table - add them to output arrays here manually
        GetExtraStrings(m_pConsonants, m_nConsonantCount, m_nCodeStart, ui->tableWidget, pConsonants, nConsonants);
        GetExtraStrings(m_pDigits, m_nDigitCount, m_nCodeStart, ui->tableWidget, pDigits, nDigits);
        GetExtraStrings(m_pSpecialSymbols, m_nSpecialSymbolCount, m_nCodeStart, ui->tableWidget, pSpecialSymbols, nSpecialSymbols);

        // Save to Html File
        if(strFilePath.isEmpty() == false)
        {
            QString strHtmlFilePath = strFilePath.mid(0, strFilePath.lastIndexOf('.')) + ".html";
            QString strTables = GetHtmlForTable(pVowels, nVowels, pConsonants, nConsonants, pDigits, nDigits, pSpecialSymbols, nSpecialSymbols);
            FILE* fp = fopen(strHtmlFilePath.toAscii(), "w");
            fprintf(fp, "%s", strTables.toStdString().c_str());
            fclose(fp);
        }

        PhTranslation::PhTranslator* pTranslator = new PhTranslation::PhTranslator(pVowels, nVowels,
            pConsonants, nConsonants, pDigits, nDigits, pSpecialSymbols, nSpecialSymbols, nVirama);

        delete pVowels; delete pConsonants; delete pDigits; delete pSpecialSymbols;

        return pTranslator;
}

void MainWindow::DisplayTestDialog()
{
    PhTranslation::PhTranslator* pTranslator = GetTranslator(ui->tableWidget);

    QFont newFont(this->fontCombo->currentText());
    newFont.setPointSize(this->sizeCombo->currentText().toInt());

    TestDialog dlg(this, pTranslator, newFont);

    dlg.exec();

    delete pTranslator;

    //PhTranslator Translator (this->m_pVowels, this->m_nvo,
    //                Tamil::Consonants, __countof(Tamil::Consonants),
    //                Tamil::Digits, __countof(Tamil::Digits),
				//	Tamil::SpecialSymbols, __countof(Tamil::SpecialSymbols),
    //                Tamil::uHalant);


}

void MainWindow::fileOpen()
{
    LoadCustomPhTable();

    int nCustomIndex = this->comboTranslation->findText("Custom");

    if(nCustomIndex == this->comboTranslation->currentIndex()) 
        this->TranslationOptionChanged(nCustomIndex); // if Custom is already selected, call the slot manually
    else
        this->comboTranslation->setCurrentIndex(nCustomIndex);
}

void MainWindow::fileSave()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                 tr("Save File"),
                                 ".",
                                 tr("PhoneticTable Files (*.PhTable)"));
    if(!fileName.isEmpty())
    {
        PhTranslation::PhTranslator* pTranslator = GetTranslator(ui->tableWidget, fileName);

        if(false == pTranslator->SavePhoneticTable(fileName.toStdString().c_str()))
        {
             QMessageBox msgBox;
             msgBox.setText("Unable to Save PhoneticTable");
             msgBox.setInformativeText(fileName);
             msgBox.setStandardButtons(QMessageBox::Ok);             
             msgBox.setIcon(QMessageBox::Critical);
             msgBox.exec();
        }
    
        delete pTranslator;
    }
}

void MainWindow::about()
{
    QString str = "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" /><title>Alphabet Mapping Editor for Phonetic Translation</title><style type=\"text/css\"> p, li { white-space: pre-wrap; } </style></head><body style=\" font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\"> <p align=\"center\" style=\" -qt-block-indent:0; font-family: 'Times New Roman', Times, serif; font-size: 14pt; font-weight: bold;\">PhAlphabetEditor</p> <p align=\"justify\" > <span style=\" font-size:11pt; font-family: 'Times New Roman', Times, serif;\">PhAlphabetEditor allows you to map English phonetic strings to Unicode characters of Indic Languages. <br> You can save the mapping as PhTable file and load it as a Custom Phonetic Table with PhWordPad application or use it from PhTranslation Library.</span></p></body></html>";
    QMessageBox::about(this, tr("About"), str);
}