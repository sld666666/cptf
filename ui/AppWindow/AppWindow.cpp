#include "StdAfx.h"
#include "AppWindow.h"
#include "WinMainWindowCreator.h"

AppWindow::AppWindow(void)
{
}

AppWindow::~AppWindow(void)
{
}

void AppWindow::init(const AppWindowParam& param)
{
	appWindowParam_ = param;
	CefProcess::intiCef();
}

bool AppWindow::show()
{
	bool rtn(false);
	WinMainWindowCreator creator(appWindowParam_.className);
	creator.initInstance(appWindowParam_.title);
	return rtn;
}

int AppWindow::run()
{
	return CefProcess::run();
}
