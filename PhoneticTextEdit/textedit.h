/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QtGui/QMainWindow>
#include <QtGui/QKeyEvent>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QPointer>
#include <QtGui/QTextEdit>
#include <QtGui/QTextCursor>
#include <QtGui/QMessageBox>
#include <QtGui/QAction>
#include <Windows.h>

QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QFontComboBox)
QT_FORWARD_DECLARE_CLASS(QTextEdit)
QT_FORWARD_DECLARE_CLASS(QTextCharFormat)
QT_FORWARD_DECLARE_CLASS(QMenu)

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
        return str.toCaseFolded();
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
        OutputDebugString(L"\nsetPlainText: ");
        OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setPlainText(text);
    }
#ifndef QT_NO_TEXTHTMLPARSER
    void setHtml(const QString &text)
    {
        OutputDebugString(L"\nsetHtml: ");
        OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setHtml(text);
    }
#endif
    void setText(const QString &text)
    {
        OutputDebugString(L"\nsetText: ");
        OutputDebugString(text.toStdWString().c_str());
        QTextEdit::setText(text);
    }
#ifndef QT_NO_CLIPBOARD
    void paste()
    {
        OutputDebugString(L"\nPaste: ");
        QTextEdit::paste();
    }
#endif

    void insertPlainText(const QString &text)
    {
        OutputDebugString(L"\ninsertPlainText: ");
        OutputDebugString(text.toStdWString().c_str());
        QTextEdit::insertPlainText(text);
    }
#ifndef QT_NO_TEXTHTMLPARSER
    void insertHtml(const QString &text)
    {
        OutputDebugString(L"\ninsertHtml: ");
        OutputDebugString(text.toStdWString().c_str());
        QTextEdit::insertHtml(text);
    }
#endif // QT_NO_TEXTHTMLPARSER

    void append(const QString &text)
    {
        OutputDebugString(L"\nappend: ");
        OutputDebugString(text.toStdWString().c_str());
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
         QMessageBox msgBox;
         msgBox.setText("Translate Selected Text.");
         msgBox.exec();        
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

class TextEdit : public QMainWindow
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = 0);

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    void setupFileActions();
    void setupEditActions();
    void setupTextActions();
    bool load(const QString &f);
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);

private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void filePrint();
    void filePrintPreview();
    void filePrintPdf();

    void textBold();
    void textUnderline();
    void textItalic();
    void textFamily(const QString &f);
    void textSize(const QString &p);
    void textStyle(int styleIndex);
    void textColor();
    void textAlign(QAction *a);

    void currentCharFormatChanged(const QTextCharFormat &format);
    void cursorPositionChanged();

    void clipboardDataChanged();
    void about();
    void printPreview(QPrinter *);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);

    QAction *actionSave,
        *actionTextBold,
        *actionTextUnderline,
        *actionTextItalic,
        *actionTextColor,
        *actionAlignLeft,
        *actionAlignCenter,
        *actionAlignRight,
        *actionAlignJustify,
        *actionUndo,
        *actionRedo,
        *actionCut,
        *actionCopy,
        *actionPaste;

    QComboBox *comboStyle;
    QFontComboBox *comboFont;
    QComboBox *comboSize;

    QToolBar *tb;
    QString fileName;
    CPhoneticTextEdit *textEdit;
};

#endif
