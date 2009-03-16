// KannadaTranslator.cpp : Implementation of CKannadaTranslator

#include "stdafx.h"
#include "KannadaTranslator.h"


// CKannadaTranslator


STDMETHODIMP CKannadaTranslator::SavePhoneticTable(BSTR bstrPhTableFilePath)
{
	return ::SavePhoneticTable(GetKannadaTranslator(), _bstr_t(bstrPhTableFilePath).operator const char *())
				? S_OK: E_FAIL;
}

STDMETHODIMP CKannadaTranslator::LoadPhoneticTable(BSTR bstrPhTableFilePath)
{
	return E_NOTIMPL;
}
