#include "StdAfx.h"
#include "PhTranslator.h"

#include <algorithm>

namespace PhTranslation
{
    PhTranslator::PhTranslator(void)
    {
    }

    PhTranslator::~PhTranslator(void)
    {
    }

    // Return if the first element is greater than the second
    template<typename T>
    bool phRepComparator(const T& input1, const T& input2)
    {
        return strlen(input1.phRep) > strlen(input2.phRep);
    }

    template<typename T>
    void LoadVector(std::vector<T> vec[], const T* inputArr, int nInputSize)
    {
        // For each entry in the definition
        for(int i=0; i < nInputSize; ++i)
        {
            // Find the First character of its phonetic representation
            const T& defObj = inputArr[i];
            const char chIndex = defObj.phRep[0];
            // Store the definition, indexed at its first character 
            vec[chIndex].push_back(defObj);
        }

        // Sort each vector such that longer strings come first
        for(int i=0, nMax = PhTranslator::VecLength; i < nMax; ++i)
        {
            std::sort(vec[i].begin(), vec[i].end(), phRepComparator<T>);
        }
    }

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
    PhTranslator::PhTranslator(const VowelDef* pVowels, int nVSize,
                const ConsonantDef* pConsonants, int nCSize,
                const DigitDef* pDigits, int nDSize,
                const SpecialSymbolDef* pSpSymbols, int nSPSize,
                const tUnicode Halant /*= 0*/)                
    {
        // Load the input Arrays into internal structures
        if(pVowels != NULL &&  nVSize != 0)
            LoadVector(this->m_Vowels, pVowels, nVSize);

        if(pConsonants != NULL &&  nCSize != 0)
            LoadVector(this->m_Consonants, pConsonants, nCSize);

        if(pDigits != NULL &&  nDSize != 0)
            LoadVector(this->m_Digits, pDigits, nDSize);

        if(pSpSymbols != NULL &&  nSPSize != 0)
            LoadVector(this->m_SpecialSymbols, pSpSymbols, nSPSize);

        m_Halant = Halant;
    }

    template<typename T>
    void Print(const std::vector<T> vec[])
    {
        for(int i=0, iMax = PhTranslator::VecLength; i < iMax; ++i)
        {
            for(int j=0, jMax = vec[i].size(); j < jMax; ++j)                
                printf(" %s %d,", vec[i][j].phRep, vec[i][j].uCode);
            if(vec[i].size()) printf("\n");
        }
    }

    void PhTranslator::PrintTables()
    {
        printf("\nVowels");
        Print(this->m_Vowels);
        printf("\nConsonants");
        Print(this->m_Consonants);
        printf("\nDigits");
        Print(this->m_Digits);
        printf("\nSpecialSymbols");
        Print(this->m_SpecialSymbols);
    }


    // Checks if the given prefix string is complete present in the string.
    // Return value would be same as the length of the prefix string, if successful.
    // Return value would be zero, in case the prefix string is not present completely.
    inline unsigned int IsPrefixMatching(const char* sz, const char* pfx)
    {
        unsigned int nMatched = 0;
        
        while(*sz && *pfx && *sz == *pfx) 
        {
            sz++;
            pfx++;
            nMatched++;
        }
        
        return (*pfx == NULL) ? nMatched : 0;
    }

    // Searches the vectors to find the best prefix that matches the sequence of
    // characters pointed by sz.
    template<typename T>
    inline unsigned int ExtractMatchingObject(const std::vector<T> vec[], const char* sz, const T* &retVal)
    {
        const char chIndex =  sz[0];

        const std::vector<T>& vecObjects = vec[chIndex];

        unsigned int nMatched = 0;

        for(int i=0, nMax = vecObjects.size(); i <  nMax; ++i)
        {
            retVal = &vecObjects[i];

            if((nMatched = IsPrefixMatching(sz, retVal->phRep)) > 0)
                return nMatched;
        }

        retVal = NULL;

        return 0;
    }

    unsigned int PhTranslator::ExtractMatchingVowel(const char* sz, const VowelDef* &retVal) const
    {
        return ExtractMatchingObject(this->m_Vowels, sz, retVal);
    }

    unsigned int PhTranslator::ExtractMatchingConsonant(const char* sz, const ConsonantDef* &retVal) const
    {
        return ExtractMatchingObject(this->m_Consonants, sz, retVal);
    }

    unsigned int PhTranslator::ExtractMatchingDigit(const char* sz, const DigitDef* &retVal) const
    {
        return ExtractMatchingObject(this->m_Digits, sz, retVal);
    }

    unsigned int PhTranslator::ExtractMatchingSpecialSymbol(const char* sz, const SpecialSymbolDef* &retVal) const
    {
        return ExtractMatchingObject(this->m_SpecialSymbols, sz, retVal);
    }

    inline bool IsASCIIAlphabet(const char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    inline void AppendUCODE(std::wstring& Str, tUnicode uCode)
    {
        if(uCode != 0)
            Str += uCode;
    }

    bool PhTranslator::Translate(const char* sz, std::wstring& retStr) const
    {
        if(sz == NULL) return false;

        const char* psz = sz;

        const VowelDef* pVowel = NULL;
        const ConsonantDef* pConsonant = NULL;
        const DigitDef* pDigit = NULL;
        const SpecialSymbolDef* pSpecialSymbol = NULL;

        bool bFollowingConsonant = false;

        unsigned int nMatched = 0;

        do
        {
            // Try Vowels
            {   
                nMatched = ExtractMatchingVowel(psz, pVowel);
                if(nMatched > 0)
                {
                    // if this vowel is following a consontant then use it as a dependant character
                    // otherwise output as an independent vowel
                    AppendUCODE(retStr, (bFollowingConsonant ? pVowel->dCode : pVowel->uCode));
                    psz += nMatched;
                    bFollowingConsonant = false;

                    continue;
                }
            }

            // If this character is classified as Vowel, but reached here
            // then it is a false positive. In such case, we might have missed
            // inserting the Halant for the preceding consonant (thinking that this would be a vowel).
            // Now that it is confirmed as not a vowel, lets insert it now (if valid).
            if(bFollowingConsonant && IsVowel(*psz))
                AppendUCODE(retStr, this->m_Halant);

            // Try Consonants
            {   
                nMatched = ExtractMatchingConsonant(psz, pConsonant);
                if(nMatched > 0)
                {
                    AppendUCODE(retStr, pConsonant->uCode);
                    psz += nMatched;
                    bFollowingConsonant = true;

                    // if the next character is not vowel, insert the Virama/Halant (if valid)
                    if(*psz != NULL && IsVowel(*psz) == false)
                        AppendUCODE(retStr, this->m_Halant);

                    if(*psz == NULL)
                        AppendUCODE(retStr, this->m_Halant);

                    continue;
                }
            }

            // Try Digits
            {   
                nMatched = ExtractMatchingDigit(psz, pDigit);
                if(nMatched > 0)
                {
                    AppendUCODE(retStr, pDigit->uCode);
                    psz += nMatched;
                    bFollowingConsonant = false;

                    continue;
                }
            }

            // Try Special Symbols
            {   
                nMatched = ExtractMatchingSpecialSymbol(psz, pSpecialSymbol);
                if(nMatched > 0)
                {
                    AppendUCODE(retStr, pSpecialSymbol->uCode);
                    psz += nMatched;
                    bFollowingConsonant = false;

                    continue;
                }
            }

            // This character, what ever it is, did not match anything. 
            // Insert it as is.
            {
                retStr += *psz++;
                bFollowingConsonant = false;
            }

        }while(*psz != NULL);

        return true;
    }

} // namespace PhTranslation


