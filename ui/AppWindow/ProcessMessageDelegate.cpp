#include "StdAfx.h"
#include "ProcessMessageDelegate.h"
#include "RunFileDialogCallback.h"
#include <string>
using std::string;

ProcessMessageDelegate::ProcessMessageDelegate(void)
{
}

ProcessMessageDelegate::~ProcessMessageDelegate(void)
{
}

bool ProcessMessageDelegate::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser
													  , CefProcessId source_process
													  ,CefRefPtr<CefProcessMessage> message)
{
	const string kMessageName = "binding_test";
	bool rtn(false);
	std::string message_name = message->GetName();
	if(kMessageName == message_name)
	{
		std::string result;
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		if (args->GetSize() > 0 && args->GetType(0) == VTYPE_STRING) {
			result = args->GetString(0);
		} else {
			result = "Invalid request";
		}
		
		result += "1234";
		CefRefPtr<CefProcessMessage> response =
			CefProcessMessage::Create(kMessageName);
		response->GetArgumentList()->SetString(0, result);
		browser->SendProcessMessage(PID_RENDERER, response);

		rtn = true;
	}

	std::vector<CefString> file_types;
    file_types.push_back("text/*");
    file_types.push_back(".log");
    file_types.push_back(".patch");

	browser->GetHost()->RunFileDialog(FILE_DIALOG_OPEN, "My Open Dialog",
		"test.txt", file_types, new RunFileDialogCallback());
	return true;

	return rtn;
}