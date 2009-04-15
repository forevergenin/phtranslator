
====================================================
        How to use Registration-Free-COM
====================================================

Side-by-Side manifests should reside in the same sub-directory structure as that of the DLL they refer to.

1.	Create an external manifest with similar schema as below

<?xml version="1.0" encoding="UTF-8"?>
<assembly xsi:schemaLocation="urn:schemas-microsoft-com:asm.v1 assembly.adaptive.xsd" manifestVersion="1.0" xmlns:asmv1="urn:schemas-microsoft-com:asm.v1" xmlns:asmv2="urn:schemas-microsoft-com:asm.v2" xmlns:dsig="http://www.w3.org/2000/09/xmldsig#" xmlns="urn:schemas-microsoft-com:asm.v1" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
            <assemblyIdentity name="Your Application Name.exe" version="1.0.0.0" type="win32"/>
            <file name="Your COM DLL Name.dll">
            <typelib tlbid="{80FC5F54-FAA3-46B7-BFC7-586313D4428A}" version="1.0" helpdir="" resourceid="0" flags="HASDISKIMAGE"/>    
                        <comClass clsid="{8CA0C09D-6F21-44DE-9442-7A0A96FFBD6D}" threadingModel="Apartment" tlbid="{80FC5F54-FAA3-46B7-BFC7-586313D4428A}" progid="COMTESTLib.Math.1" description="COMTest Class"/>
            </file>
            <comInterfaceExternalProxyStub name="IMath" iid="{C1AC6E0E-84F7-444A-9453-CB053028D2F8}" proxyStubClsid32="{00020424-0000-0000-C000-000000000046}" baseInterface="{00000000-0000-0000-C000-000000000046}" tlbid="{80FC5F54-FAA3-46B7-BFC7-586313D4428A}"/>
</assembly>

In the above, you should substitute the red parts with your own appropriate values.
2.	Save the created manifest file in the same directory as the COM DLL it refers to. That is, the created manifest file and the COM DLL both should reside in the same directory (anywhere on the system). You can either put both of them in the WinSxS directory or any other directory in the system.
3.	In your application code, before calling the CoCreateInstance() on the COM component, use the following code to set the activation context (so that the manifest we have created is used to resolve the COM DLL).
	
// Create an Activation Context structure
	ACTCTX actctx;
	ZeroMemory(&actctx, sizeof(actctx));
	actctx.cbSize = sizeof(actctx);
	actctx.lpSource = “Complete Path of the external manifest”; // For Example, “c:\\myapp\\Sample.Manifest”

	HANDLE pActCtx = CreateActCtx(&actctx);
	if(pActCtx == INVALID_HANDLE_VALUE)	{	Error(_T("CreateActCtx"));	return;	}

	ULONG_PTR lpCookie;
	if(!ActivateActCtx(pActCtx, &lpCookie))	{ Error(_T("ActivateActCtx")); return; }

	hr = CoCreateInstance(…);	// would return success
4.	Once you have used your COM component you can reset the activation context, if you wish, using the below code:

		DeactivateActCtx(0, lpCookie);

	The lpCookie value is the same as the value obtained in the afore mentioned ActivateActCtx() call.

========================================================================================================
//////////////////////////////////////////////////////////////////////////////////////////////////
/// Observations:
To make reg-free com work with a native COM component:

2. Use an external manifest file. Specify its path in the activation context API while creating the ActCtx structure. The manifest and the COM Dll has to be in the same directory. This manifest should have the following schema:
-------------------------------------------------------------------------------------------------------------------------------
<?xml version="1.0" encoding="UTF-8"?>
<assembly xsi:schemaLocation="urn:schemas-microsoft-com:asm.v1 assembly.adaptive.xsd" manifestVersion="1.0" xmlns:asmv1="urn:schemas-microsoft-com:asm.v1" xmlns:asmv2="urn:schemas-microsoft-com:asm.v2" xmlns:dsig="http://www.w3.org/2000/09/xmldsig#" xmlns="urn:schemas-microsoft-com:asm.v1" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
	<assemblyIdentity name="SxSActivationContext.exe" version="1.0.0.0" type="win32"/>
	<file name="COMApp.dll">
    <typelib tlbid="{5E72C4CA-997C-4914-BB05-DBDB882DCCFC}" version="1.0" helpdir="" resourceid="0" flags="HASDISKIMAGE"/>    
		<comClass clsid="{4FA2C0B5-CFA1-40FB-BD37-88F6E1166EB9}" threadingModel="Apartment" tlbid="{5E72C4CA-997C-4914-BB05-DBDB882DCCFC}" progid="ComApp.SxSNativeComObject.1" description="SxSNativeComObject Class"/>
	</file>
	<comInterfaceExternalProxyStub name="ISxSNativeComObject" iid="{7E00CAFF-7180-41CD-AEDC-FC3FD2767FB9}" proxyStubClsid32="{00020424-0000-0000-C000-000000000046}" baseInterface="{00000000-0000-0000-C000-000000000046}" tlbid="{5E72C4CA-997C-4914-BB05-DBDB882DCCFC}"/>
</assembly>
-------------------------------------------------------------------------------------------------------------------------------

This way, when the COM DLL is shipped along with an external manifest that descibes the COMClasses exposed the COMDLL, and when the Exe uses Activation context API to refer to the manifest, CoCreateInstance() is working fine without requiring to register the COMDLL.


To make reg-free COM Interop work with .NET assembly that exposes COM classes,

1. Embed a dependency manifest in the native application exe. The manifest is of the following schema
----------------------------------------------------------------------------------------------------------------------------------------------------
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <dependency>
    <dependentAssembly>
      <assemblyIdentity type="win32" 
                    name="DotNetApp" 
                    version="1.0.0.0" 
      />
    </dependentAssembly>
  </dependency>
</assembly>
----------------------------------------------------------------------------------------------------------------------------------------------------
2. Create A .Net assembly that exposes a COM object and embedded a manifest that describes the ClrClasses inside it. The embedded manifest should have the following schema:
----------------------------------------------------------------------------------------------------------------------------------------------------
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity type="win32"
               name="DotNetApp"
               version="1.0.0.0" />
  <clrClass
               clsid="{4FA2C0B5-CFA1-40FB-BD37-88F6E1166EB9}"
               progid="DotNetApp.Class1"
               threadingModel="Both"
               name="DotNetApp.Class1"
               runtimeVersion="v2.0.50727">
  </clrClass>
  <file name="DotNetApp.dll">
  </file>
</assembly>
----------------------------------------------------------------------------------------------------------------------------------------------------

This way, when the native exe uses a dependency manifest that refers to an assembly DLL (which in turn has an embedded manifest that describes the ClrClasses exposed by the assembly), CoCreateInstance() is working fine without requiring to register the assembly or without requiring to use activation context API.

To make Reg-Free COM Interop work with .NET assembly with activation context API (so as to avoid embedding the manifests in the exe and assembly dll).

Remove the embedded dependency manifest from the exe. Also remove the embedded manifest from the .NET assembly. 
Create an external manifest for the .net assembly describing the CLRClasses exposed by it. The schema is as below:
--------------------------------------------------------------------------------------------------------------------
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity type="win32"
               name="DotNetApp"
               version="1.0.0.0" />
  <clrClass
               clsid="{4FA2C0B5-CFA1-40FB-BD37-88F6E1166EB9}"
               progid="DotNetApp.Class1"
               threadingModel="Both"
               name="DotNetApp.Class1"
               runtimeVersion="v2.0.50727">
  </clrClass>
  <file name="DotNetApp.dll">
  </file>
</assembly>
--------------------------------------------------------------------------------------------------------------------
Now when this external manifest path is set in the ACTCTX structure of the activation context API, the CoCreateInstance() on the .Net exposed COM object succeeded. Make sure the exe, the assembly and the DLL are all in the same directory.

I am able to successfully use the .Net exposed COM objects using the Activation Context API, without requiring to register the assembly or to embed any manifests in the exe or assembly.


========================================================================================================

To Use Isolated-Com option in the C++ build settings:
 1. Use this Isolate COM option for the COM component. Select its type library and its own output dll name in the fields. (Do not use absolute paths. Only use relative paths).
 2. IsolateCOM option embeds a manifest file into the COM dll. But the generated manifest will not have any Assembly Identity tag in it. So, we need to create an additional manifest with Assembly Identity name and specify it as additional manifest to be merged with the automatically generated manifest.
 3. For the client executable, we need to add a dependency tag in the Exe's manifest specifying the assembly identify of the COM dll.
 4. If any SxS syntax error occurs, add the <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
----
Or
----
 To configure the "Isolated COM", go to the C++ project settings and select the "Manifest Tool":
     + For the "Isolated COM | Type library File" entry, specify the below value:
          $(TargetDir)$(ProjectName).tlb
       Or optionally you can specify the below also (make sure MIDL is generating TLB file):
          $(IntDir)/$(ProjectName).tlb
     + For the "Isolated COM| Component File Name" entry, specify the below value:
          $(ProjectName).dll
     + For the "General | Assembly Identiy" specify the below value:
          $(ProjectName), type=win32, version=1.0.0.0
 Then for the client executable, add a dependency tag in the Exe's manifest specifying the assembly identify of theCOM dll.
