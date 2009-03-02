// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PHTRANSLATELIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PHTRANSLATELIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PHTRANSLATELIB_EXPORTS
#define PHTRANSLATELIB_API __declspec(dllexport)
#else
#define PHTRANSLATELIB_API __declspec(dllimport)
#endif

#include <string>

extern "C"
{
    // Creates a Telugu Translator.
    // The output of this method must be sent as input to the Translate Method.
    PHTRANSLATELIB_API void* CreateTeluguTranslator();

    // Releases a Translator previously created with one of CreateXYZTranslator() methods
    PHTRANSLATELIB_API void ReleaseTranslator(void* Translator);

    // Translates the given Phonetic English string.
    // Parameters:
    //  [in]  Translator: This must be a value returned by one of the CreateXYZTranslator() methods
    //  [in]  szInput: The Phonetic English String that is to be translated
    //  [out] szOutput: The Translated String in Unicode representation
    //  [in]  nLen: Max no.of wide chars to be filled. szOutput[nLen-1] will be '\0' if the buffer is small.
    //  [return] Returns the length of the full converted string. szOutput might be holding only a fraction of it, if nLen is small.
    //  Remarks: Send szInput as NULL and to get the required length of the buffer.
    PHTRANSLATELIB_API int Translate(void* Translator, const char* szInput, 
                                      wchar_t* szOutput, const int nLen);

    //// 
    //PHTRANSLATELIB_API int GetTranslatedBufferLength(void* Translator, const char* szInput, void** pHint);

    //PHTRANSLATELIB_API void GetTranslatedBuffer(wchar_t* szOutput, const int nLen, void* pHint);

} // extern "C"

// Translates the given Phonetic English string.
// Parameters:
//  [in]  Translator: This must be a value returned by one of the CreateXYZTranslator() methods
//  [in]  szInput: The Phonetic English String that is to be translated
//  [out] retStr: The Translated String in Unicode representation
PHTRANSLATELIB_API void Translate(void* Translator, const char* szInput, std::wstring& retStr);


