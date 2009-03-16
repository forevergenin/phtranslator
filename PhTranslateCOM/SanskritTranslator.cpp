// SanskritTranslator.cpp : Implementation of CSanskritTranslator

#include "stdafx.h"
#include "SanskritTranslator.h"


// CSanskritTranslator


STDMETHODIMP CSanskritTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetSanskritTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CSanskritTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
