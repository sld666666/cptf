#pragma once
#include "include/cef_app.h"
#include "include/cef_client.h"

class MainWindowClient : public CefClient
					   , public CefLifeSpanHandler
{
public:
	MainWindowClient(void);
	~MainWindowClient(void);

public:
	CefRefPtr<CefBrowser> getBrowser();
public://override
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler(){return this;}
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser);
public:
	IMPLEMENT_REFCOUNTING(MainWindowClient);
private:
	CefRefPtr<CefBrowser> browser_;
};
