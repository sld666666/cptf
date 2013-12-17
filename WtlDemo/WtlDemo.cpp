// WtlDemo.cpp : main source file for WtlDemo.exe
//

#include "stdafx.h"

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include "resource.h"

#include "aboutdlg.h"
#include "MainDlg.h"

CAppModule _Module;

#include "service/IDispatch.h"
#include "TypeDefine.h"
#include "service/CptfServiceModel.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "BundleTestor.h"
#include "utils/Log.h"
#include <boost/assign/list_of.hpp>


using namespace cptf::core;

CptfModule g_cptfModule;

const wstring IMath_IID = L"111111";
interfacecptf IMath : public cptf::core::IDispatch{
	virtual cptf::IID getIID(){
		return IMath_IID;
	}

	virtual bool test() = 0;

};

const wstring IMath1_IID = L"22222";
interfacecptf IMath1 : public cptf::core::IDispatch{
	virtual cptf::IID getIID(){
		return IMath1_IID;
	}

	virtual bool test1() = 0;

};

class MyMath : public ServiceCoClass<MyMath>
	, public cptf::core::IDispatchImpl<IMath>
	, public IMath1{
public:
	MyMath()
	{
		int i (0);
	}
	virtual bool test(){
		int i(0);
		return true;
	};

	virtual bool test1(){
		int i(0);
		return true;
	}

	CPTF_BEGIN_SERVICE_MAP(MyMath)
		CPTF_SERVICE_INTERFACE_ENTRY(IMath_IID, IMath)
		CPTF_SERVICE_INTERFACE_ENTRY(IMath1_IID, IMath1)
	CPTF_END_SERVICE_MAP()
};

const wstring MyMath_IID = L"114003cf-505f-11e3-9ce6-00269e3e5da0";

CPTF_OBJECT_ENTRY_AUTO(MyMath_IID, MyMath)



class testor{
	public:
	static vector<int> aStatic_;
};

vector<int>  testor::aStatic_(boost::assign::list_of(4)(17)(20));


int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
	IMath* math = NULL;
	g_cptfModule.createInstance(MyMath_IID, IMath_IID, (void**)&math);
	if (math){
		math->test();
	}

	IMath1* math1(NULL);
	g_cptfModule.createInstance(MyMath_IID, IMath1_IID,(void**)&math1);
	if(math1){
		math1->test1();
	}

	IBundleTestor1* bundleTestor1(NULL);
	g_cptfModule.createInstance(BundleTestor1_IID, IBundleTestor1_IID,(void**)&bundleTestor1);
	if(bundleTestor1){
		bundleTestor1->test();
	}

	g_cptfModule.createInstance(BundleTestor1_IID, IBundleTestor1_IID,(void**)&bundleTestor1);
	if(bundleTestor1){
		bundleTestor1->test();
	}


	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainDlg dlgMain;

	if(dlgMain.Create(NULL) == NULL)
	{
		ATLTRACE(_T("Main dialog creation failed!\n"));
		return 0;
	}
	CptfServiceModel model;

	dlgMain.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	initLog();
	LOG(INFO) << "22 " << " cookies";
	LOG(ERROR) <<"ERROR";
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
