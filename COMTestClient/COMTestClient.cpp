// COMTestClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ComDef.h>
#include <Windows.h>
#include <AtlStr.h>

#include "PhTranslateCOM_i.h"

#define Error(x)    exit(fprintf(stderr, "%s", x));

int _tmain(int argc, _TCHAR* argv[])
{
    TCHAR szInput[32];

    printf("\nEnter some Phonetic Text to appear in Sanskrit: ");
    wscanf(L"%20s", szInput);

    TCHAR szCurDir[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, szCurDir);

    CString strManifest(szCurDir);
    strManifest += _T("\\COMTestClient.exe.manifest"); // Path of Activation Manifest

    CoInitialize(NULL);

    // Create an Activation Context structure
    ACTCTX actctx;
    ZeroMemory(&actctx, sizeof(actctx));
    actctx.cbSize = sizeof(actctx);
    actctx.lpSource = strManifest; // Give complete path to the Activation Manifest

    HANDLE pActCtx = CreateActCtx(&actctx);
    if(pActCtx == INVALID_HANDLE_VALUE)	{	Error(_T("CreateActCtx"));	return -1;	}

    ULONG_PTR lpCookie;
    if(!ActivateActCtx(pActCtx, &lpCookie))	{ Error(_T("ActivateActCtx")); return -1; }

    IPhTranslator* pTranslator = NULL;

    HRESULT hr = CoCreateInstance(__uuidof(SanskritTranslator), NULL, CLSCTX_ALL, IID_IPhTranslator, (LPVOID*)&pTranslator);
    if(FAILED(hr))
        printf("\nCoCreateInstance Failed with 0x%x", hr);
    else
    {
        _bstr_t bstrInput(szInput);

        BSTR bstrOutput;

        if(FAILED(hr = pTranslator->Translate(bstrInput, &bstrOutput)))
            printf("\nTranslation Failed with 0x%x", hr);
        else
        {
            MessageBox(NULL, bstrOutput, _T("Translated Text"), MB_OK);
            printf("\nRegistration Free COM worked fine !!\n");
        }        
    }

    CoUninitialize();   

    return 0;
}

