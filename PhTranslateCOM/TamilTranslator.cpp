// TamilTranslator.cpp : Implementation of CTamilTranslator

#include "stdafx.h"
#include "TamilTranslator.h"


// CTamilTranslator


STDMETHODIMP CTamilTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetTamilTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CTamilTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
