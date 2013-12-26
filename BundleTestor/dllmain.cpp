// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "service/CptfDllModuleT.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ThreadModel.h"
#include "service/ObjectRoot.h"
#include "dllmain.h"
#include "BundleTestor.h"


CHelloAtlModule g_module;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return true;
}


extern "C" __declspec(dllexport) bool dllGetClassObject(cptf::IID csid
												 , cptf::IID iid
												, void** rntObj)
{
	return g_module.dllGetClassObject(csid, iid, rntObj);
}

class BundleTestor1 : public ServiceCoClass<BundleTestor1>
	, public ObjectRoot<SingleThreadModel>
	, public cptf::core::IDispatchImpl<IBundleTestor1>{
public:
	BundleTestor1()
	{
		int i (0);
	}
	~BundleTestor1()
	{
		int i (0);
	}
	virtual bool test(){
		int i(0);
		return true;
	};


	CPTF_BEGIN_SERVICE_MAP(BundleTestor1)
		CPTF_SERVICE_INTERFACE_ENTRY(IBundleTestor1_IID, IBundleTestor1)
	CPTF_END_SERVICE_MAP()
};



CPTF_OBJECT_ENTRY_AUTO(BundleTestor1_IID, BundleTestor1)
