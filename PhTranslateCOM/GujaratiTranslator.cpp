// GujaratiTranslator.cpp : Implementation of CGujaratiTranslator

#include "stdafx.h"
#include "GujaratiTranslator.h"


// CGujaratiTranslator


STDMETHODIMP CGujaratiTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetGujaratiTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CGujaratiTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
