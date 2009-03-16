// HindiTranslator.cpp : Implementation of CHindiTranslator

#include "stdafx.h"
#include "HindiTranslator.h"


// CHindiTranslator


STDMETHODIMP CHindiTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetHindiTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CHindiTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
