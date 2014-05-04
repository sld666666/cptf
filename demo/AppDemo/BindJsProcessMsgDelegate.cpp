#include "StdAfx.h"
#include "BindJsProcessMsgDelegate.h"

static const string BindJsMessageName = "binding_test";

BindJsProcessMsgDelegate::BindJsProcessMsgDelegate()
{
}

BindJsProcessMsgDelegate::~BindJsProcessMsgDelegate()
{
}

bool BindJsProcessMsgDelegate::excute(const CefRefPtr<CefBrowser>browser
									  , const CefRefPtr<CefProcessMessage>& message) const
{
	bool rtn = false;

	std::string result;
	CefRefPtr<CefListValue> args = message->GetArgumentList();
	if (args->GetSize() > 0 && args->GetType(0) == VTYPE_STRING) {
		result = args->GetString(0);
		rtn = true;
	} else {
		result = "Invalid request";
	}

	result += "1234";
	CefRefPtr<CefProcessMessage> response =
		CefProcessMessage::Create(BindJsMessageName);
	response->GetArgumentList()->SetString(0, result);
	browser->SendProcessMessage(PID_RENDERER, response);

	return rtn;
}

string BindJsProcessMsgDelegate::getName() const 
{
	return BindJsMessageName;
}