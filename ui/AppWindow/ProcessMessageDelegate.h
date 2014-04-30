#pragma once
#include "include/cef_client.h"

class ProcessMessageDelegate : public CefBase
{
public:
	ProcessMessageDelegate();
	~ProcessMessageDelegate();

	virtual bool OnProcessMessageReceived(
		CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message);

	IMPLEMENT_REFCOUNTING(ProcessMessageDelegate);
};
