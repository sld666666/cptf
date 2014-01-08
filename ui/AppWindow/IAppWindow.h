#ifndef CPTF_UI_IAPPWINDOW
#define CPTF_UI_IAPPWINDOW

#include "TypeDefine.h"
#include "service/IDispatch.h"
using namespace cptf::core;

struct AppWindowParam
{
	wstring className;
	wstring title;

	AppWindowParam(){}
	AppWindowParam(const wstring& _className, const wstring& _title)
		: className(_className) 
		, title(_title)
	{

	}
};

const wstring IAppWindow_IID = L"444444";
interfacecptf IAppWindow //: public cptf::core::IDispatch
{
	virtual cptf::IID getIID(){return IAppWindow_IID;}

	virtual void	init(const AppWindowParam& param) = 0;
	virtual bool	show() = 0;
	virtual int		run() = 0;

};

//const wstring BundleAppWindow_IID = L"2ff2ff21-7775-11e3-b50d-bc305bacf447";

#endif