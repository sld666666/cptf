// AlloyTimer.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "AlloyTimer.h"
#include "IAppWindow.h"
#include "AppWindow.h"
#include "service/CptfModule.h"

CptfModule g_cptfModule;

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	shared_ptr<IAppWindow> appWindow(new AppWindow());
	if (appWindow){
		appWindow->init(AppWindowParam(_T("AloyTimer"), _T("AloyTimer")));
		appWindow->show();
		appWindow->run();
	}

}
