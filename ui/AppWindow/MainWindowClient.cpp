#include "StdAfx.h"
#include "MainWindowClient.h"

MainWindowClient::MainWindowClient(void)
{
}

MainWindowClient::~MainWindowClient(void)
{
}

CefRefPtr<CefBrowser> MainWindowClient::getBrowser()
{
	return browser_;
}

void MainWindowClient::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	browser_ = browser;
}


bool MainWindowClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
											 CefProcessId source_process,
											 CefRefPtr<CefProcessMessage> message)
{
	bool rtn(false);
	processMessageDelegate_.OnProcessMessageReceived(
		  browser
		, source_process
		, message);
	return rtn;
}
