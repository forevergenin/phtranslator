#ifndef __PHTRANSLATOR___9EA8D480_6CC6_4b31_9C41_C8E2DE16EBBF__
#define __PHTRANSLATOR___9EA8D480_6CC6_4b31_9C41_C8E2DE16EBBF__

#include <vector>
#include <string>

namespace PhTranslation
{
    typedef wchar_t tUnicode;

    struct VowelDef
    {
        char phRep[8];   // The English Phonetic Representation of the Vowel
        tUnicode uCode; // The Unicode character of the Vowel when occuring Independently
        tUnicode dCode; // The Unicode character code of the Vowel when Dependant on preceding Consonant
    };

    struct ConsonantDef
    {
        char phRep[8]; // The English Phonetic Representation of the Consonant
        tUnicode uCode; // The Unicode character code of the Consonant
    };

    struct DigitDef
    {
        char phRep[1]; // The English Phonetic Represenation of the Digit
        tUnicode uCode; // The Unicode character code of the Digit
    };

    struct SpecialSymbolDef
    {
        char phRep[8]; // The English Representation of the Special Symbol
        tUnicode uCode; // The Unicode character code of the Special Symbol
    };


    class PhTranslator
    {
    public:
        enum {VecLength = 256};
    protected:
        typedef std::vector<VowelDef>           VecVowels;
        typedef std::vector<ConsonantDef>       VecConsonants;
        typedef std::vector<DigitDef>           VecDigits;
        typedef std::vector<SpecialSymbolDef>   VecSpecialSymbols;

        VecVowels               m_Vowels[VecLength];       // Indexed by English Alphabet [a-z] [A-Z]
        VecConsonants           m_Consonants[VecLength];   // Indexed by English Alphabet [a-z] [A-Z]
        VecDigits               m_Digits[VecLength];       // Indexed by English Digits [0-9]
        VecSpecialSymbols       m_SpecialSymbols[VecLength]; // Indexed by ASCII symbols
        tUnicode                m_Halant;

        // Returns if the given character is defined to a Vowel identifier
        inline bool IsVowel(char ch) const
        {
            return m_Vowels[ch].size() > 0;
        }

        unsigned int ExtractMatchingVowel(const char* sz, const VowelDef* &pRetVal) const;
        unsigned int ExtractMatchingConsonant(const char* sz, const ConsonantDef* &pRetVal) const;
        unsigned int ExtractMatchingDigit(const char* sz, const DigitDef* &pRetVal) const;
        unsigned int ExtractMatchingSpecialSymbol(const char* sz, const SpecialSymbolDef* &pRetVal) const;

        PhTranslator(void);
    public:
        ~PhTranslator(void);

        // Constructor
        // Inputs:
        //     pVowels: The Vowels Array
        //     nVSize: length of the pVowels Array (no. of elements)
        //     pConsonants: The Consonants Array
        //     nCSize: length of the pConsonants Array (no. of elements)
        //     pDigits: The Digits Array
        //     nVSize: length of the pVowels Array (no. of elements)
        //     pSpSymbols: The Special Symbols Array
        //     nSPSize: length of the pSpSymbols Array (no. of elements)
        //     Halant: The Unicode code that is to be used as 'Virama'/Halant. Supply 0 if none exists.
        PhTranslator(const VowelDef* pVowels, int nVSize,
                    const ConsonantDef* pConsonants, int nCSize,
                    const DigitDef* pDigits, int nDSize,
                    const SpecialSymbolDef* pSpSymbols, int nSPSize,
                    const tUnicode Halant);

        // Translates the given English string Phonetically
        // Inputs:
        //      sz: The String in Phonetic English
        // Outputs:
        //      retStr: The Unicode representation
        bool Translate(const char* sz, std::wstring& retStr) const;

        void PrintTables();
    };

} // namespace PhTranslation

#endif // __PHTRANSLATOR___9EA8D480_6CC6_4b31_9C41_C8E2DE16EBBF__