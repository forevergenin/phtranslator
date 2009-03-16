// dllmain.h : Declaration of module class.

class CPhTranslateCOMModule : public CAtlDllModuleT< CPhTranslateCOMModule >
{
public :
	DECLARE_LIBID(LIBID_PhTranslateCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_PHTRANSLATECOM, "{BFAA0A5F-9391-423C-8D41-A587E98692A9}")
};

extern class CPhTranslateCOMModule _AtlModule;
