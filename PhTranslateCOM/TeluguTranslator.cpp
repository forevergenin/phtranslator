// TeluguTranslator.cpp : Implementation of CTeluguTranslator

#include "stdafx.h"
#include "TeluguTranslator.h"

// CTeluguTranslator
CTeluguTranslator::CTeluguTranslator()
{
}

void CTeluguTranslator::FinalRelease()
{
}

STDMETHODIMP CTeluguTranslator::Translate(BSTR inPhoneticString, BSTR* pTranslatedString)
{
	std::wstring strRet;

	::Translate(GetTeluguTranslator(), (wchar_t*)inPhoneticString, strRet);

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

STDMETHODIMP CTeluguTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetTeluguTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CTeluguTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
