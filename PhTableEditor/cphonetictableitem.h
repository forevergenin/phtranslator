#ifndef CPHONETICTABLEITEM_H_0E5D0634_D258_4970_B4D9_91847750CE05__
#define CPHONETICTABLEITEM_H_0E5D0634_D258_4970_B4D9_91847750CE05__

#include <QtGui/QTableWidgetItem>
#include <QtCore/QStringList>
#include <QtGui/QItemDelegate>
#include <QtGui/QTextDocument>
#include <QtGui/QTextLayout>
#include <QtGui/QTextBlock>
#include <QtGui/QPainter>
#include <QtGui/QStyleOptionViewItem>
#include <QtCore/QModelIndex>
#include <QtGui/QAbstractTextDocumentLayout>
#include <QtGui/QTableWidget>
#include <QtGui/QFontMetrics>
#include <QtCore/QSize>
#include <QtGui/QBrush>
#include <QtGui/QColor>

class RichDelegate : public QItemDelegate
{
public:
  void paint ( QPainter * painter,
               const QStyleOptionViewItem & option,
               const QModelIndex & index           ) const
  {
    //// stripped down to the minimum sufficient to reproduce the crash
    //QString text = "<b>Test</b> text";
    //QTextDocument textDocument;
    //textDocument.setHtml(text);
    //QTextLayout textLayout(textDocument.begin());
    //textLayout.beginLayout();
    ////QTextLine line = textLayout.createLine(); // UNCOMMENT THIS TO CRASH
    //textLayout.endLayout();

    painter->save();
    QTextDocument doc;
    doc.setHtml(index.data().toString());
    QAbstractTextDocumentLayout::PaintContext context;
    doc.setPageSize(option.rect.size());
    painter->translate(option.rect.x(), option.rect.y());
    doc.documentLayout()->draw(painter, context);
    painter->restore();
  }
};


class CPhoneticTableItem : public QTableWidgetItem
{
public:
    enum ItemType {Invalid=0, Vowel, DependantVowel, Consonant, SpecialSymbol, Digit, Halant};

    wchar_t         m_uCode;   // Unicode representation of the character
    QStringList     m_phReps;   // Phonetic Strings for the character
    ItemType        m_type;    // Type of the character
    QString         m_strChar;
    QString         m_strPhStrings;
    wchar_t         m_dRefCode;    // When type == DependantVowel, this points to the original Independent Character
public:
    inline CPhoneticTableItem()
          : QTableWidgetItem(QTableWidgetItem::UserType),
              m_uCode(0), m_type(Invalid), m_dRefCode(0)
    {
        QTableWidgetItem::setTextAlignment(Qt::AlignCenter);
    }
    inline CPhoneticTableItem(wchar_t uCode, const QFont& font)
        : QTableWidgetItem(QTableWidgetItem::UserType),
              m_uCode(uCode), m_type(Invalid), m_dRefCode(uCode)
    {
        wchar_t szText[8] = L"";
        szText[0] = (wchar_t)m_uCode;
        szText[1] = L'\0';

        m_strChar = QString::fromWCharArray(szText);  

        QTableWidgetItem::setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        QTableWidgetItem::setText(m_strChar);
        QTableWidgetItem::setFont(font);
    }

    inline QString GetTypeString() const
    {
        switch(m_type)
        {
        case Vowel: return "Vowel" +                       
                        QString(" (Dependent form: " + ((m_dRefCode == 0) ? QString("None") : QString("")+QChar(m_dRefCode)) + ")");
        case DependantVowel: return QString::fromLatin1("Dependant Vowel for ") + QChar(m_dRefCode);
        case Consonant: return "Consonant";
        case SpecialSymbol: return "Special Symbol";
        case Digit: return "Digit";
        case Halant: return "Halant / Virama";
        default: return "";
        }
    }

    inline void SetType(ItemType type)
    {
        m_type = type;
        switch(m_type)
        {
        case Vowel: QTableWidgetItem::setBackground(QBrush(QColor(220,255,255), Qt::SolidPattern)); return;
        case DependantVowel: QTableWidgetItem::setBackground(QBrush(QColor(196,255,255), Qt::SolidPattern)); return;
        case Consonant: QTableWidgetItem::setBackground(QBrush(QColor(255,220,255), Qt::SolidPattern)); return ;
        case SpecialSymbol: QTableWidgetItem::setBackground(QBrush(QColor(255,255,220), Qt::SolidPattern)); return ;
        case Digit: QTableWidgetItem::setBackground(QBrush(QColor(220,220,255), Qt::SolidPattern)); return ;
        case Halant: QTableWidgetItem::setBackground(QBrush(QColor(220,255,220), Qt::SolidPattern)); return ;
        default: QTableWidgetItem::setBackground(QBrush(QColor(250,250,250), Qt::SolidPattern)); return ;
        }
    }

    inline QString GetTipText() const
    {
        QString str;

        const QFont& dispFont = QTableWidgetItem::font();

        str = QString::fromLatin1("<p align=\"center\"> <span style=\"font-size: %1pt;").arg(qMax(16, dispFont.pointSize()+4))
               +  QString::fromLatin1(" font-family: %1\">").arg(dispFont.family())
               + QChar(m_uCode)
               + QString::fromLatin1("</span><p align=\"center\">0x")
               + QString::fromLatin1("%1").arg(m_uCode, 4, 16, QLatin1Char('0')) //::number(m_uCode, 16)
               + "  (" + QString::number(m_uCode) + ")"
               + "</p>";

        str += "<p align=\"center\">" + m_strPhStrings + "</p>";
        str += "<p align=\"center\">" + GetTypeString() + "</p>";

        return str;
    }

    inline void SetPhoneticStrings(const QStringList& strList)
    {
        //QString str = m_strChar;
        
        //str += "<br>{";
        m_phReps = strList;

        int nLen = m_phReps.length();
        if(nLen > 0)
        {
            m_strPhStrings = "{ ";

            m_strPhStrings += m_phReps[0];
        
            for(int i=1; i < nLen; ++i)
                m_strPhStrings += ((", ") + m_phReps[i]);

            m_strPhStrings += " }";
        }

        QTableWidgetItem::setText(m_strChar + "    " + m_strPhStrings);
    }

    inline void AddPhoneticString(const QString& str)
    {
        m_phReps.append(str);

        SetPhoneticStrings(m_phReps);
    }

    inline const QString& GetPhoneticStringsText() const
    {
        return m_strPhStrings;
    }
};

#endif // CPHONETICTABLEITEM_H_0E5D0634_D258_4970_B4D9_91847750CE05__
