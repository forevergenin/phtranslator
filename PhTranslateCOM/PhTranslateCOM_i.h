

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __PhTranslateCOM_i_h__
#define __PhTranslateCOM_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPhTranslator_FWD_DEFINED__
#define __IPhTranslator_FWD_DEFINED__
typedef interface IPhTranslator IPhTranslator;
#endif 	/* __IPhTranslator_FWD_DEFINED__ */


#ifndef __TeluguTranslator_FWD_DEFINED__
#define __TeluguTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class TeluguTranslator TeluguTranslator;
#else
typedef struct TeluguTranslator TeluguTranslator;
#endif /* __cplusplus */

#endif 	/* __TeluguTranslator_FWD_DEFINED__ */


#ifndef __BengaliTranslator_FWD_DEFINED__
#define __BengaliTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class BengaliTranslator BengaliTranslator;
#else
typedef struct BengaliTranslator BengaliTranslator;
#endif /* __cplusplus */

#endif 	/* __BengaliTranslator_FWD_DEFINED__ */


#ifndef __HindiTranslator_FWD_DEFINED__
#define __HindiTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class HindiTranslator HindiTranslator;
#else
typedef struct HindiTranslator HindiTranslator;
#endif /* __cplusplus */

#endif 	/* __HindiTranslator_FWD_DEFINED__ */


#ifndef __GujaratiTranslator_FWD_DEFINED__
#define __GujaratiTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class GujaratiTranslator GujaratiTranslator;
#else
typedef struct GujaratiTranslator GujaratiTranslator;
#endif /* __cplusplus */

#endif 	/* __GujaratiTranslator_FWD_DEFINED__ */


#ifndef __KannadaTranslator_FWD_DEFINED__
#define __KannadaTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class KannadaTranslator KannadaTranslator;
#else
typedef struct KannadaTranslator KannadaTranslator;
#endif /* __cplusplus */

#endif 	/* __KannadaTranslator_FWD_DEFINED__ */


#ifndef __MalayalamTranslator_FWD_DEFINED__
#define __MalayalamTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class MalayalamTranslator MalayalamTranslator;
#else
typedef struct MalayalamTranslator MalayalamTranslator;
#endif /* __cplusplus */

#endif 	/* __MalayalamTranslator_FWD_DEFINED__ */


#ifndef __PunjabiTranslator_FWD_DEFINED__
#define __PunjabiTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class PunjabiTranslator PunjabiTranslator;
#else
typedef struct PunjabiTranslator PunjabiTranslator;
#endif /* __cplusplus */

#endif 	/* __PunjabiTranslator_FWD_DEFINED__ */


#ifndef __SanskritTranslator_FWD_DEFINED__
#define __SanskritTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class SanskritTranslator SanskritTranslator;
#else
typedef struct SanskritTranslator SanskritTranslator;
#endif /* __cplusplus */

#endif 	/* __SanskritTranslator_FWD_DEFINED__ */


#ifndef __TamilTranslator_FWD_DEFINED__
#define __TamilTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class TamilTranslator TamilTranslator;
#else
typedef struct TamilTranslator TamilTranslator;
#endif /* __cplusplus */

#endif 	/* __TamilTranslator_FWD_DEFINED__ */


#ifndef __OriyaTranslator_FWD_DEFINED__
#define __OriyaTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class OriyaTranslator OriyaTranslator;
#else
typedef struct OriyaTranslator OriyaTranslator;
#endif /* __cplusplus */

#endif 	/* __OriyaTranslator_FWD_DEFINED__ */


#ifndef __CustomTranslator_FWD_DEFINED__
#define __CustomTranslator_FWD_DEFINED__

#ifdef __cplusplus
typedef class CustomTranslator CustomTranslator;
#else
typedef struct CustomTranslator CustomTranslator;
#endif /* __cplusplus */

#endif 	/* __CustomTranslator_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IPhTranslator_INTERFACE_DEFINED__
#define __IPhTranslator_INTERFACE_DEFINED__

/* interface IPhTranslator */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPhTranslator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("581A99EE-6C43-42F2-9A48-0CE5EE15C469")
    IPhTranslator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Translate( 
            /* [in] */ BSTR inPhoneticString,
            /* [retval][out] */ BSTR *pTranslatedString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SavePhoneticTable( 
            /* [in] */ BSTR bstrPhTableFilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadPhoneticTable( 
            /* [in] */ BSTR bstrPhTableFilePath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhTranslatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhTranslator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhTranslator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhTranslator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPhTranslator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPhTranslator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPhTranslator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPhTranslator * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Translate )( 
            IPhTranslator * This,
            /* [in] */ BSTR inPhoneticString,
            /* [retval][out] */ BSTR *pTranslatedString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SavePhoneticTable )( 
            IPhTranslator * This,
            /* [in] */ BSTR bstrPhTableFilePath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadPhoneticTable )( 
            IPhTranslator * This,
            /* [in] */ BSTR bstrPhTableFilePath);
        
        END_INTERFACE
    } IPhTranslatorVtbl;

    interface IPhTranslator
    {
        CONST_VTBL struct IPhTranslatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhTranslator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhTranslator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhTranslator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhTranslator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPhTranslator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPhTranslator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPhTranslator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPhTranslator_Translate(This,inPhoneticString,pTranslatedString)	\
    ( (This)->lpVtbl -> Translate(This,inPhoneticString,pTranslatedString) ) 

#define IPhTranslator_SavePhoneticTable(This,bstrPhTableFilePath)	\
    ( (This)->lpVtbl -> SavePhoneticTable(This,bstrPhTableFilePath) ) 

#define IPhTranslator_LoadPhoneticTable(This,bstrPhTableFilePath)	\
    ( (This)->lpVtbl -> LoadPhoneticTable(This,bstrPhTableFilePath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhTranslator_INTERFACE_DEFINED__ */



#ifndef __PhTranslateCOMLib_LIBRARY_DEFINED__
#define __PhTranslateCOMLib_LIBRARY_DEFINED__

/* library PhTranslateCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PhTranslateCOMLib;

EXTERN_C const CLSID CLSID_TeluguTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("A4E71D2A-480A-4CF0-A4A8-DCBFB3F99F32")
TeluguTranslator;
#endif

EXTERN_C const CLSID CLSID_BengaliTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("5AA852E3-965D-4DCA-8B15-CB64125BE3D6")
BengaliTranslator;
#endif

EXTERN_C const CLSID CLSID_HindiTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("DC5E7DD2-4565-4041-BEAC-45E3692F6A61")
HindiTranslator;
#endif

EXTERN_C const CLSID CLSID_GujaratiTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("8FE6872E-C45B-4C98-B6F7-5B6C6F137E00")
GujaratiTranslator;
#endif

EXTERN_C const CLSID CLSID_KannadaTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("E692A113-B73A-4896-8BF5-6A0D3C87DBC1")
KannadaTranslator;
#endif

EXTERN_C const CLSID CLSID_MalayalamTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("C46F00BB-FADD-404B-8E78-ED29CA9707E3")
MalayalamTranslator;
#endif

EXTERN_C const CLSID CLSID_PunjabiTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("B15CD237-A8A6-4C74-9D98-D16CE7451009")
PunjabiTranslator;
#endif

EXTERN_C const CLSID CLSID_SanskritTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("F075931B-17FF-491A-A3BB-7FFF6B5A31B5")
SanskritTranslator;
#endif

EXTERN_C const CLSID CLSID_TamilTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("BA6D442F-3B70-42E4-ADB0-B89CFF57A188")
TamilTranslator;
#endif

EXTERN_C const CLSID CLSID_OriyaTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("E05BF268-26FE-49F2-AD1F-9CFB97B7F5FA")
OriyaTranslator;
#endif

EXTERN_C const CLSID CLSID_CustomTranslator;

#ifdef __cplusplus

class DECLSPEC_UUID("5D6B9596-63F2-4989-9B43-A8B79C28C0AF")
CustomTranslator;
#endif
#endif /* __PhTranslateCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


