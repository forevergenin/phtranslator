// CustomTranslator.h : Declaration of the CCustomTranslator

#pragma once
#include "resource.h"       // main symbols

#include "PhTranslateCOM_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CCustomTranslator

class ATL_NO_VTABLE CCustomTranslator :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCustomTranslator, &CLSID_CustomTranslator>,
	public IDispatchImpl<IPhTranslator, &IID_IPhTranslator, &LIBID_PhTranslateCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	void* m_pCustomTranslator;
public:
	CCustomTranslator(): m_pCustomTranslator(0)
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_CUSTOMTRANSLATOR)


	BEGIN_COM_MAP(CCustomTranslator)
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
		::ReleaseCustomTranslator(m_pCustomTranslator);
	}

public:


	// IPhTranslator Methods
public:
	STDMETHOD(Translate)( BSTR inPhoneticString,  BSTR * pTranslatedString)
	{
		if(m_pCustomTranslator == NULL) return E_FAIL;

		std::wstring strRet;

		::Translate(m_pCustomTranslator, (wchar_t*)inPhoneticString, strRet);

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
	STDMETHOD(SavePhoneticTable)( BSTR bstrPhTableFilePath)
	{	
		return ::SavePhoneticTable(m_pCustomTranslator, _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
	}
	STDMETHOD(LoadPhoneticTable)( BSTR bstrPhTableFilePath)
	{
		::ReleaseCustomTranslator(m_pCustomTranslator);
		
		m_pCustomTranslator = NULL;
		
		m_pCustomTranslator = ::CreateCustomTranslator(_bstr_t(bstrPhTableFilePath).operator const char *());

		return m_pCustomTranslator ? S_OK : E_FAIL;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(CustomTranslator), CCustomTranslator)
