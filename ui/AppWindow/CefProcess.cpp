#include "StdAfx.h"
#include "CefProcess.h"
#include "utils/ApplicationPath.h"


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
	wstring resource = cptf::core::ApplicaitonPath<>::getCurAppPath();
	wstring indexPath = L"file:///" 
		+ resource 
		+ cptf::core::ApplicaitonPath<>::getDirSeparator()
		+ L"resource"
		+ cptf::core::ApplicaitonPath<>::getDirSeparator()
		+ L"index.html";
	CefBrowserHost::CreateBrowser(info, client
		, indexPath, settings); 
}

