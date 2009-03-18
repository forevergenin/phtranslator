// PrintTablesToHtml.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <AtlStr.h>
#include "LanguageCodes.h"

template<typename T>
std::string DumpVector(const T* inputArr, int nInputSize)
{
    std::string strRet("");
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

#define GetHtmlForTable(NS, strTables)  \
{   \
\
    strTables += "<html> <head><meta http-equiv='Content-Type' content='text/html; charset=utf-8' /> <link rel='stylesheet' type='text/css' href='Tables.css' /> </head><body>";\
\
    strTables += "<table>";\
    strTables += "<tr>";\
    {\
        strTables += "<td>";\
        strTables += "<table>";\
        {\
            strTables += "<tr><td>";\
            strTables += "<table border='1'><tr><th colspan='10'>Vowels</th></tr>";\
            strTables += DumpVector(NS::Vowels, _countof(NS::Vowels));\
            strTables += "</table>";            \
            strTables += "</td></tr>";\
\
            strTables += "<tr><td>";\
            strTables += "<table border='1'><tr><th colspan='10'>Digits</th></tr>";\
            strTables += DumpVector(NS::Digits, _countof(NS::Digits));\
            strTables += "</table>";\
            strTables += "</td></tr>";\
        }\
        strTables += "</table>";\
        strTables += "</td>";\
\
        strTables += "<td>";\
        strTables += "<table border='1'><tr><th colspan='10'>Consonants</th></tr>";\
        strTables += DumpVector(NS::Consonants, _countof(NS::Consonants));\
        strTables += "</table>";\
        strTables += "</td>";\
    }\
    strTables += "</tr>";\
\
    strTables += "<tr>";\
    {\
        strTables += "<td>";\
        strTables += "<table border='1'><tr><th colspan='10'>Special Symbols</th></tr>";\
        strTables += DumpVector(NS::SpecialSymbols, _countof(NS::SpecialSymbols));\
        strTables += "</table>";\
        strTables += "</td>";\
    }        \
    strTables += "</tr>";\
\
    strTables += "</table>";\
\
    strTables += "</body></html>";\
}\

void SaveToFile(const std::string& str, const char* lpszFilePath)
{
    FILE* fp = fopen(lpszFilePath, "w");
    fprintf(fp, "%s", str.c_str());
    fclose(fp);
}

int _tmain(int argc, _TCHAR* argv[])
{
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Bengali, strTables);
        SaveToFile(strTables, "BengaliTable.html");
    }
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Gujarati, strTables);
        SaveToFile(strTables, "GujaratiTable.html");
    }
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Hindi, strTables);
        SaveToFile(strTables, "HindiTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Kannada, strTables);
        SaveToFile(strTables, "KannadaTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Malayalam, strTables);
        SaveToFile(strTables, "MalayalamTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Oriya, strTables);
        SaveToFile(strTables, "OriyaTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Punjabi, strTables);
        SaveToFile(strTables, "PunjabiTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Sanskrit, strTables);
        SaveToFile(strTables, "SanskritTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Tamil, strTables);
        SaveToFile(strTables, "TamilTable.html");
    }        
    {
        std::string strTables;
        GetHtmlForTable(PhTranslation::Telugu, strTables);
        SaveToFile(strTables, "TeluguTable.html");
    }

	return 0;
}

