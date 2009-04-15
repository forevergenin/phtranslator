#ifndef __PhoneticTextEdit_H__1844AAF9_3353_47cf_99E0_F7AA4BC61E24__
#define __PhoneticTextEdit_H__1844AAF9_3353_47cf_99E0_F7AA4BC61E24__

#include <QtGui/QTextEdit>
#include <QtGui/QTextCursor>
#include <QtGui/QMessageBox>
#include <QtGui/QAction>
#include <QtGui/QTextDocumentFragment>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>

#include <Windows.h>

class CPhoneticTextEdit : public QTextEdit
{        
    Q_OBJECT

protected:
    int         m_nCurEditingWordStartPos;  // TextChangedEvent keeps track of this
    int         m_nCurInputWordStartPos;    // KeyPressEvent keeps track of this
    bool        m_bInsideTranslation;      // Useful for preventing recursion
    QAction*    m_pTranslateAction;
    // Overloaded to get a peek at the Keyboard event
    inline virtual void keyPressEvent(QKeyEvent *e)
    {
        m_nCurInputWordStartPos = GetCurrentWordStartPos();
        ////OutputDebugString(L"\nKeyPress at ");
        ////Print(m_nCurInputWordStartPos);
        ////switch(e->key())
        ////{
        ////case Qt::Key_Enter:
        ////case Qt::Key_Tab:
        ////case Qt::Key_Space:
        ////case Qt::Key_Period:
        ////    m_bWordComplete = true;
        ////    OutputDebugString(L"  wordcomplete");
        ////default: break;
        ////}
        QTextEdit::keyPressEvent(e);
    }
    void Print(int num)
    {
        QString qstr;
        qstr.setNum(num, 10);
        std::wstring str = qstr.toStdWString();
        OutputDebugString(str.c_str());
    }

    /////////////////////////////////////////////////
    /// Helper methods to get the word under the cursor
    inline QString TextUnderCursor() const
    {
        QTextCursor tc = textCursor();
        tc.select(QTextCursor::WordUnderCursor);
        return tc.selectedText();
    }
    inline QString Replace(QString str) const
    {
        return "x_" + str.toCaseFolded();
    }
    inline int GetCurrentWordStartPos() const
    {
        QTextCursor tc = textCursor();
        tc.movePosition(QTextCursor::StartOfWord);
        return tc.position();
    }
    ///////////////////////////////////////////

public:
    //////////////////////////////////////////
    /// Overloads
    void setPlainText(const QString &text)
    {
        //OutputDebugString(L"\nsetPlainText: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setPlainText(text);
    }
#ifndef QT_NO_TEXTHTMLPARSER
    void setHtml(const QString &text)
    {
        //OutputDebugString(L"\nsetHtml: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setHtml(text);
    }
#endif
    void setText(const QString &text)
    {
        //OutputDebugString(L"\nsetText: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setText(text);
    }
#ifndef QT_NO_CLIPBOARD
    void paste()
    {
        //OutputDebugString(L"\nPaste: ");
        QTextEdit::paste();
    }
#endif

    void insertPlainText(const QString &text)
    {
        //OutputDebugString(L"\ninsertPlainText: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::insertPlainText(text);
    }
#ifndef QT_NO_TEXTHTMLPARSER
    void insertHtml(const QString &text)
    {
        //OutputDebugString(L"\ninsertHtml: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::insertHtml(text);
    }
#endif // QT_NO_TEXTHTMLPARSER

    void append(const QString &text)
    {
        //OutputDebugString(L"\nappend: ");
        //OutputDebugString(text.toStdWString().c_str());
        QTextEdit::append(text);
    }
protected:
    // Phonetically Translates the word at the given position
    void TranslateWordAt(int Pos)
    {
        m_bInsideTranslation = true;
            QTextCursor tc = textCursor();
            tc.setPosition(Pos);

            tc.select(QTextCursor::WordUnderCursor);
            QString str = Replace(tc.selectedText()); 
            QTextCharFormat tcf = tc.charFormat();
            tc.deleteChar();
            tc.insertText(str, tcf);
            //setTextCursor(tc); //<<-- is this required?
        m_bInsideTranslation = false;
    }
private slots:
    // Used for handling the CursorPositionChanged event raised by QTextEdit.
    // Raised for all mouse and keyboard events that cause the cursor position change.
    // Subscribed in the Constructor
    void cursorPositionChanged()
    {
        if(m_bInsideTranslation == true) return;

        int nCurWordPos = (m_nCurEditingWordStartPos >=0) ? GetCurrentWordStartPos() : -1;
        if(nCurWordPos != m_nCurEditingWordStartPos)
        {
            ///////////////////////////////////////////////////
            ///
            ////OutputDebugString(L"\nCursorPosChanged from word ");
            ////Print(m_nCurEditingWordStartPos);
            ////OutputDebugString(L" to word ");
            ////Print(nCurWordPos);
            ///
            ////////////////////////////////////////////////////
            TranslateWordAt(m_nCurEditingWordStartPos);

            m_nCurEditingWordStartPos = -1;
        }
    }

    // This event is raised by QTextEdit whenever text changes. It could 
    // be as a result of textEdit or text Format change. This is raised *after*
    // the cursorChanged event.
    void textChanged()
    {
        // If the text has changed as a result of our own replace operation, ignore it
        if(m_bInsideTranslation == true) return;

        // Get the location where the text seems to have changed
        m_nCurEditingWordStartPos = GetCurrentWordStartPos();

        /////////////////////////////////////////////
        //// 
        ////QString qstr;
        ////qstr.setNum(textCursor().position(), 10);            
        ////qstr += TextUnderCursor();
        ////
        ////std::wstring str = L"\nTextChanged:" + qstr.toStdWString();
        ////
        ////OutputDebugString(str.c_str());
        /////////////////////////////////////////////////

        // If the text change is not because of key input, ignore it
        if(m_nCurInputWordStartPos != m_nCurEditingWordStartPos)
            m_nCurEditingWordStartPos = -1;        
    }
    void TranslateSelectedText()
    {
        QTextCursor tc = textCursor();
        OutputDebugString(tc.selection().toHtml().toStdWString().c_str());

        QDomDocument selDoc;
        if(!selDoc.setContent(tc.selection().toHtml()))
        {
            OutputDebugString(L"\nUnable to Set Content !!");
            return;
        }
        
        QString str;
        QDomNodeList selNodeList = selDoc.elementsByTagName("span");
        for(int i=0, nMax = selNodeList.count(); i < nMax; ++i)
        {
            QDomNode& selNode = selNodeList.at(i);
            //str += "\nName:"+selNodeList.at(i).childNodes().at(0).nodeName() +" Value:"+selNodeList.at(i).childNodes().at(0).nodeValue();
            for(int nChild=0, nChildMax = selNode.childNodes().count(); nChild < nChildMax; ++nChild)
            {
                QDomNode& textNode = selNode.childNodes().at(nChild);
                textNode.setNodeValue(Replace(textNode.nodeValue()));
            }
        }

        OutputDebugString(L"\n");
        OutputDebugString(selDoc.toString().toStdWString().c_str());

        tc.deleteChar();
        tc.insertHtml(selDoc.toString(-1));        
    }
    void TranslateOnTheFly(bool bEnable = true)
    {
        OutputDebugString(L"\nTranslateOnTheFly");
    }
private:
    // Called from Constructor to initialize
    void Init()
    {
        QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(cursorPositionChanged()));
        QObject::connect(this, SIGNAL(textChanged()), this, SLOT(textChanged()));

        m_pTranslateAction = new QAction(this);
        m_pTranslateAction->setShortcut(Qt::CTRL + Qt::Key_T);
        QObject::connect(m_pTranslateAction, SIGNAL(triggered()), this, SLOT(TranslateSelectedText()));

        this->addAction(m_pTranslateAction);
    }
public:
    inline explicit CPhoneticTextEdit(QWidget *parent = 0) 
        : QTextEdit(parent) ,  
        m_nCurEditingWordStartPos(-1), 
        m_nCurInputWordStartPos(-1), 
        m_bInsideTranslation(false),
        m_pTranslateAction(0)
    {
        Init();
    }

    inline explicit CPhoneticTextEdit(const QString &text, QWidget *parent = 0) 
        : QTextEdit(text, parent) ,  
        m_nCurEditingWordStartPos(-1),
        m_nCurInputWordStartPos(-1), 
        m_bInsideTranslation(false),
        m_pTranslateAction(0)
    { 
        Init();
    }

    inline virtual ~CPhoneticTextEdit() 
    { 
        if(m_pTranslateAction)
        {
            delete m_pTranslateAction;
            m_pTranslateAction = NULL;
        }
    }
};


#endif // __PhoneticTextEdit_H__1844AAF9_3353_47cf_99E0_F7AA4BC61E24__