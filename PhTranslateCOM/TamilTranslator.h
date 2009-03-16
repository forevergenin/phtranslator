// TamilTranslator.h : Declaration of the CTamilTranslator

#pragma once
#include "resource.h"       // main symbols

#include "PhTranslateCOM_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CTamilTranslator

class ATL_NO_VTABLE CTamilTranslator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTamilTranslator, &CLSID_TamilTranslator>,
	public IDispatchImpl<IPhTranslator, &IID_IPhTranslator, &LIBID_PhTranslateCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTamilTranslator()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_TAMILTRANSLATOR)


	BEGIN_COM_MAP(CTamilTranslator)
		COM_INTERFACE_ENTRY(IPhTranslator)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:


	// IPhTranslator Methods
public:
	STDMETHOD(Translate)( BSTR inPhoneticString,  BSTR * pTranslatedString)
	{
		std::wstring strRet;

		::Translate(GetTamilTranslator(), (wchar_t*)inPhoneticString, strRet);

		try
		{
			*pTranslatedString = SysAllocString(strRet.c_str());	// Caller should free this using SysFreeString
		}
		catch(...)
		{
			return E_OUTOFMEMORY;
		}

		return S_OK;
	}
	STDMETHOD(SavePhoneticTable)(BSTR bstrPhTableFilePath);
	STDMETHOD(LoadPhoneticTable)(BSTR bstrPhTableFilePath);
};

OBJECT_ENTRY_AUTO(__uuidof(TamilTranslator), CTamilTranslator)
