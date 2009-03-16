// BengaliTranslator.cpp : Implementation of CBengaliTranslator

#include "stdafx.h"
#include "BengaliTranslator.h"


// CBengaliTranslator


STDMETHODIMP CBengaliTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetBengaliTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CBengaliTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
