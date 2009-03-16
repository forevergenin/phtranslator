// OriyaTranslator.cpp : Implementation of COriyaTranslator

#include "stdafx.h"
#include "OriyaTranslator.h"


// COriyaTranslator


STDMETHODIMP COriyaTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetOriyaTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP COriyaTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
