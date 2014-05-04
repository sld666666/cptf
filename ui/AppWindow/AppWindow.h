#ifndef CPTF_UI_APPWINDOW
#define CPTF_UI_APPWINDOW

#include "service/CptfModule.h"

#include "TypeDefine.h"
#include "dllmain.h"
#include "IAppWindow.h"

extern cptf::core::CptfModule g_cptfModule;

class AppWindow : public IAppWindow{
public:
	AppWindow();
	~AppWindow();
public:
	virtual void	init(const AppWindowParam& param);
	virtual bool	show();
	virtual int		run();

private:
	AppWindowParam		appWindowParam_;
};

#endif

