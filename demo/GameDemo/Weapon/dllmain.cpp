// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ThreadModel.h"
#include "service/ObjectRoot.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return TRUE;
}


extern "C" __declspec(dllexport) bool dllGetClassObject(cptf::IID csid
														, cptf::IID iid
														, void** rntObj)
{
	return true;
	//return g_module.dllGetClassObject(csid, iid, rntObj);
}

