

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Mar 16 22:36:37 2009
 */
/* Compiler settings for .\PhTranslateCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IPhTranslator,0x581A99EE,0x6C43,0x42F2,0x9A,0x48,0x0C,0xE5,0xEE,0x15,0xC4,0x69);


MIDL_DEFINE_GUID(IID, LIBID_PhTranslateCOMLib,0x1ABDE916,0x4C9A,0x4866,0x81,0x5F,0xB4,0xA2,0x6C,0xB7,0x34,0x7F);


MIDL_DEFINE_GUID(CLSID, CLSID_TeluguTranslator,0xA4E71D2A,0x480A,0x4CF0,0xA4,0xA8,0xDC,0xBF,0xB3,0xF9,0x9F,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_BengaliTranslator,0x5AA852E3,0x965D,0x4DCA,0x8B,0x15,0xCB,0x64,0x12,0x5B,0xE3,0xD6);


MIDL_DEFINE_GUID(CLSID, CLSID_HindiTranslator,0xDC5E7DD2,0x4565,0x4041,0xBE,0xAC,0x45,0xE3,0x69,0x2F,0x6A,0x61);


MIDL_DEFINE_GUID(CLSID, CLSID_GujaratiTranslator,0x8FE6872E,0xC45B,0x4C98,0xB6,0xF7,0x5B,0x6C,0x6F,0x13,0x7E,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_KannadaTranslator,0xE692A113,0xB73A,0x4896,0x8B,0xF5,0x6A,0x0D,0x3C,0x87,0xDB,0xC1);


MIDL_DEFINE_GUID(CLSID, CLSID_MalayalamTranslator,0xC46F00BB,0xFADD,0x404B,0x8E,0x78,0xED,0x29,0xCA,0x97,0x07,0xE3);


MIDL_DEFINE_GUID(CLSID, CLSID_PunjabiTranslator,0xB15CD237,0xA8A6,0x4C74,0x9D,0x98,0xD1,0x6C,0xE7,0x45,0x10,0x09);


MIDL_DEFINE_GUID(CLSID, CLSID_SanskritTranslator,0xF075931B,0x17FF,0x491A,0xA3,0xBB,0x7F,0xFF,0x6B,0x5A,0x31,0xB5);


MIDL_DEFINE_GUID(CLSID, CLSID_TamilTranslator,0xBA6D442F,0x3B70,0x42E4,0xAD,0xB0,0xB8,0x9C,0xFF,0x57,0xA1,0x88);


MIDL_DEFINE_GUID(CLSID, CLSID_OriyaTranslator,0xE05BF268,0x26FE,0x49F2,0xAD,0x1F,0x9C,0xFB,0x97,0xB7,0xF5,0xFA);


MIDL_DEFINE_GUID(CLSID, CLSID_CustomTranslator,0x5D6B9596,0x63F2,0x4989,0x9B,0x43,0xA8,0xB7,0x9C,0x28,0xC0,0xAF);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



