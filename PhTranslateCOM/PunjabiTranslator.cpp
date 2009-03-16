// PunjabiTranslator.cpp : Implementation of CPunjabiTranslator

#include "stdafx.h"
#include "PunjabiTranslator.h"


// CPunjabiTranslator


STDMETHODIMP CPunjabiTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetPunjabiTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CPunjabiTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
