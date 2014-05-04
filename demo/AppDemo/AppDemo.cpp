// AppDemo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "AppDemo.h"
#include "IAppWindow.h"
#include "AppWindow.h"


cptf::core::CptfModule g_cptfModule;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	shared_ptr<IAppWindow> appWindow(new AppWindow());
	if (appWindow){
		appWindow->init(AppWindowParam(_T("11111"), _T("22222")));
		appWindow->show();
		appWindow->run();
	}

}
