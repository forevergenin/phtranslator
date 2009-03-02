#ifndef _LANGUAGECODES_H__195ADDC0_CF4A_44c0_AC65_8247CD83E6AA__
#define _LANGUAGECODES_H__195ADDC0_CF4A_44c0_AC65_8247CD83E6AA__

#include "PhTranslator.h"

namespace PhTranslation
{
    namespace Telugu
    {
        const VowelDef Vowels[] =
        {
            "a",    3077, 0,    // అ
            "aa",   3078, 3134, // ఆ
            "A",    3078, 3134, // ఆ
            "i",    3079, 3135, // ఇ
            "ee",   3080, 3136, // ఈ
            "I",    3080, 3136, // ఈ
            "u",    3081, 3137, // ఉ
            "oo",   3082, 3138, // ఊ
            "U",    3082, 3138, // ఊ
            "zr",   3083, 3139, // ఋ
            "zl",   3084, 3170, // 
            "e",    3086, 3142, // ఎ
            "ae",   3087, 3143, // ఏ
            "E",    3087, 3143, // ఏ
            "ai",   3088, 3144, // ఐ
            "o",    3090, 3146, // ఒ
            "oa",   3091, 3147, // ఓ
            "O",    3091, 3147, // ఓ
            "au",   3092, 3148, // ఔ
            "zR",   3168, 3140, // ౠ
            "zL",   3169, 3171, // 
            "AO",   3073, 3073, // ఁ
            "M",    3074, 3074, // ం
            "H",    3075, 3075, // ః
        };

        const ConsonantDef Consonants[] = 
        {
            "k",    3093,
            "K",    3093,
            "kh",    3094,
            "Kh",    3094,
            "g",    3095,
            "gh",    3096,
            "G",    3097,
            "ch",    3098,
            "Ch",    3099,
            "j",    3100,
            "jh",    3101,
            "J",    3101,
            "Jh",    3101,
            "nY",    3102,
            "T",    3103,
            "Th",    3104,
            "d",    3105,
            "dh",    3106,
            "N",    3107,
            "t",    3108,
            "th",    3109,
            "D",    3110,
            "Dh",    3111,
            "n",    3112,
            "p",    3114,
            "ph",    3115,
            "b",    3116,
            "B",    3117,
            "bh",    3117,
            "Bh",    3117,
            "m",    3118,
            "y",    3119,
            "r",    3120,
            "R",    3121,
            "l",    3122,
            "L",    3123,
            "v",    3125,
            "sh",    3126,
            "Sh",    3127,
            "s",    3128,
            "h",    3129,
        };

        const unsigned int uHalant = 0x0C4D;   // The Unicode character code for Virama (Halant)

        const DigitDef Digits[] = 
        {
            '0',    0x0C66,
            '1',    0x0C67,
            '2',    0x0C68,
            '3',    0x0C69,
            '4',    0x0C6A,
            '5',    0x0C6B,
            '6',    0x0C6C,
            '7',    0x0C6D,
            '8',    0x0C6E,
            '9',    0x0C6F,
        };

        // const SpecialSymbolDef SpecialSymbols[] = { };

    } // namespace Telugu

} // namespace PhTranslation

#endif // _LANGUAGECODES_H__195ADDC0_CF4A_44c0_AC65_8247CD83E6AA__