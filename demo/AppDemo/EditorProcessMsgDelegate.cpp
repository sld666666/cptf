#include "StdAfx.h"
#include "EditorProcessMsgDelegate.h"
#include "RunFileDialogCallback.h"
#include "utils/StringUtils.h"
static const string BindJsMessageName = "Editor";

EditorProcessMsgDelegate::EditorProcessMsgDelegate()
{
}

EditorProcessMsgDelegate::~EditorProcessMsgDelegate()
{
}

bool EditorProcessMsgDelegate::excute(const CefRefPtr<CefBrowser>browser
									  , const CefRefPtr<CefProcessMessage>& message) const
{
	vector<string> msgs =StringUtils<1>::splitLast(message->GetName(), ".");
	if(msgs.size() < 2)return false;

	string subMsg = msgs[1];
	if("FileOpen" == subMsg){
		std::vector<CefString> file_types;
		file_types.push_back("text/*");
		file_types.push_back(".log");
		file_types.push_back(".patch");

		browser->GetHost()->RunFileDialog(FILE_DIALOG_OPEN, "My Open Dialog",
			"test.txt", file_types, new RunFileDialogCallback());
	}
	

	return true;
}

string EditorProcessMsgDelegate::getName() const 
{
	return BindJsMessageName;
}