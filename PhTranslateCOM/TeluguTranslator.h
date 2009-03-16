// TeluguTranslator.h : Declaration of the CTeluguTranslator

#pragma once
#include "resource.h"       // main symbols

#include "PhTranslateCOM_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CTeluguTranslator

class ATL_NO_VTABLE CTeluguTranslator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTeluguTranslator, &CLSID_TeluguTranslator>,
	public IDispatchImpl<IPhTranslator, &IID_IPhTranslator, &LIBID_PhTranslateCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{

public:
	CTeluguTranslator();

DECLARE_REGISTRY_RESOURCEID(IDR_TELUGUTRANSLATOR)


BEGIN_COM_MAP(CTeluguTranslator)
	COM_INTERFACE_ENTRY(IPhTranslator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease();

public:

	STDMETHOD(Translate)(BSTR inPhoneticString, BSTR* pTranslatedString);
	STDMETHOD(SavePhoneticTable)(BSTR bstrPhTableFilePath);
	STDMETHOD(LoadPhoneticTable)(BSTR bstrPhTableFilePath);
};

OBJECT_ENTRY_AUTO(__uuidof(TeluguTranslator), CTeluguTranslator)
