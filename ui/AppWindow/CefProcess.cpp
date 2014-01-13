#include "StdAfx.h"
#include "CefProcess.h"


CefProcess::CefProcess(void)
{
}

CefProcess::~CefProcess(void)
{
}

void CefProcess::intiCef()
{
	CefMainArgs main_args(NULL);
	int exit_code = CefExecuteProcess(main_args, NULL);
	if (exit_code >= 0) {
		return ;
	}
	CefSettings settings;
	CefInitialize(main_args, settings, NULL);
}

int CefProcess::run()
{
	CefRunMessageLoop();
	CefShutdown();
	return 0;
}

void CefProcess::createBrowser(HWND hWnd
							   , CefClient* client)
{
	if (!client)return;

	CefBrowserSettings settings;
	CefWindowInfo info;
	RECT rect;
	GetClientRect(hWnd, &rect);
	info.SetAsChild(hWnd, rect);
	CefBrowserHost::CreateBrowser(info, client
		, "file:///E:/cptftestor/test.html", settings); 
}

