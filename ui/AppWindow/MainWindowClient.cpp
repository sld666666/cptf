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

