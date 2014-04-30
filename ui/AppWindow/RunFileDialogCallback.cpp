#include "StdAfx.h"
#include "RunFileDialogCallback.h"

RunFileDialogCallback::RunFileDialogCallback(void)
{
}

RunFileDialogCallback::~RunFileDialogCallback(void)
{
}

void RunFileDialogCallback::OnFileDialogDismissed( CefRefPtr<CefBrowserHost> browser_host,
												 const std::vector<CefString>& file_paths)
{
	CefRefPtr<CefProcessMessage> message =
		CefProcessMessage::Create("binding_test");
	CefRefPtr<CefListValue> args = message->GetArgumentList();
	CefRefPtr<CefListValue> val = CefListValue::Create();
	for (int i = 0; i < static_cast<int>(file_paths.size()); ++i)
		val->SetString(i, file_paths[i]);
	args->SetList(0, val);

	// This will result in a call to the callback registered via JavaScript in
	// dialogs.html.
	browser_host->GetBrowser()->SendProcessMessage(PID_RENDERER, message);
}
