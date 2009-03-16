// MalayalamTranslator.cpp : Implementation of CMalayalamTranslator

#include "stdafx.h"
#include "MalayalamTranslator.h"


// CMalayalamTranslator


STDMETHODIMP CMalayalamTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetMalayalamTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CMalayalamTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
