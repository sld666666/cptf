#pragma once
#include "include/cef_browser.h"

class RunFileDialogCallback : public  CefRunFileDialogCallback
{
public:
	RunFileDialogCallback(void);
	~RunFileDialogCallback(void);

	virtual void OnFileDialogDismissed(
		CefRefPtr<CefBrowserHost> browser_host,
		const std::vector<CefString>& file_paths);

	IMPLEMENT_REFCOUNTING(CefRunFileDialogCallback)
};
