#include "StdAfx.h"
#include "DailogProcessMsgDelegate.h"
#include "RunFileDialogCallback.h"

static const string BindJsMessageName = "DialogTest";

DailogProcessMsgDelegate::DailogProcessMsgDelegate()
{
}

DailogProcessMsgDelegate::~DailogProcessMsgDelegate()
{
}

bool DailogProcessMsgDelegate::excute(const CefRefPtr<CefBrowser>browser
									  , const CefRefPtr<CefProcessMessage>& message) const
{
	std::vector<CefString> file_types;
    file_types.push_back("text/*");
    file_types.push_back(".log");
    file_types.push_back(".patch");

	browser->GetHost()->RunFileDialog(FILE_DIALOG_OPEN, "My Open Dialog",
		"test.txt", file_types, new RunFileDialogCallback());

	return true;
}

string DailogProcessMsgDelegate::getName() const 
{
	return BindJsMessageName;
}