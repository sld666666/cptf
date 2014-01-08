#ifndef CPTF_UI_APPWINDOW
#define CPTF_UI_APPWINDOW

#include "service/CptfDllModuleT.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ThreadModel.h"
#include "service/ObjectRoot.h"
#include "TypeDefine.h"
#include "dllmain.h"
#include "IAppWindow.h"

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

