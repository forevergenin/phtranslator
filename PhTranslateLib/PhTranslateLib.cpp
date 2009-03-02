// PhTranslateLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PhTranslateLib.h"

#include "LanguageCodes.h"
using namespace PhTranslation;

#ifndef __countof
#define __countof(x)    (sizeof(x) /  sizeof(x[0]))
#endif 

extern "C"
{
    // Creates a Telugu Translator.
    // The output of this method must be sent as input to the Translate Method.
    PHTRANSLATELIB_API void* CreateTeluguTranslator()
    {            
        PhTranslator* pTranslator =  new 
            PhTranslator(Telugu::Vowels, __countof(Telugu::Vowels),
                        Telugu::Consonants, __countof(Telugu::Consonants),
                        Telugu::Digits, __countof(Telugu::Digits),
                        NULL, 0,
                        Telugu::uHalant);

        return pTranslator;
    }

    // Releases a Translator previously created with one of CreateXYZTranslator() methods
    PHTRANSLATELIB_API void ReleaseTranslator(void* Translator)
    {
        PhTranslator* pTranslator = (PhTranslator*) Translator;
        if(pTranslator)
            delete pTranslator;
    }

    // Translates the given Phonetic English string.
    // Parameters:
    //  [in]  Translator: This must be a value returned by one of the CreateXYZTranslator() methods
    //  [in]  szInput: The Phonetic English String that is to be translated
    //  [out] szOutput: The Translated String in Unicode representation
    //  [in]  nLen: Maximum number of wide characters to be filled in szOutput
    PHTRANSLATELIB_API int Translate(void* Translator, const char* szInput, 
                                      wchar_t* szOutput, const int nLen)
    {
        std::wstring retStr;
        Translate(Translator, szInput, retStr);
        if(szOutput != NULL && nLen > 0)
        {
            // Copy the generated Unicode string to the output buffer
            wcsncpy(szOutput, retStr.c_str(), nLen-1);

            szOutput[nLen-1] = L'\0';
        }

        return retStr.length();
    }

}   // extern "C"

PHTRANSLATELIB_API void Translate(void* Translator, const char* szInput, std::wstring& retStr)
{
    PhTranslator* pTranslator = (PhTranslator*) Translator;
    if(pTranslator != NULL && szInput != NULL)
    {
        // Do the Translation using the Translator
        pTranslator->Translate(szInput, retStr);
    }
}