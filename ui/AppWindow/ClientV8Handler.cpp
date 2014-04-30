#include "StdAfx.h"
#include "ClientV8Handler.h"

ClientV8Handler::ClientV8Handler(CefRefPtr<ClientApp> clientApp)
:clientApp_(clientApp)
{
}

ClientV8Handler::~ClientV8Handler(void)
{
}

bool ClientV8Handler::Execute(const CefString& name,
							 CefRefPtr<CefV8Value> object,
							 const CefV8ValueList& arguments,
							 CefRefPtr<CefV8Value>& retval,
							 CefString& exception) 
{
	bool handled = false;

	if (name == "sendMessage") {
	 // Send a message to the browser process.
	 if ((arguments.size() == 1 || arguments.size() == 2) &&
		 arguments[0]->IsString()) {
			 CefRefPtr<CefBrowser> browser =
				 CefV8Context::GetCurrentContext()->GetBrowser();

			 CefString name = arguments[0]->GetStringValue();
			 if (!name.empty()) {
				 CefRefPtr<CefProcessMessage> message =
					 CefProcessMessage::Create(name);

				 // Translate the arguments, if any.
				 if (arguments.size() == 2 && arguments[1]->IsArray())
					 V8ListSetter::SetList(arguments[1], message->GetArgumentList());

				 browser->SendProcessMessage(PID_BROWSER, message);
				 handled = true;
			 }
	 }
	} else if (name == "setMessageCallback") {
	 // Set a message callback.
	 if (arguments.size() == 2 && arguments[0]->IsString() &&
		 arguments[1]->IsFunction()) {
			 std::string name = arguments[0]->GetStringValue();
			 CefRefPtr<CefV8Context> context = CefV8Context::GetCurrentContext();
			 int browser_id = context->GetBrowser()->GetIdentifier();
			 clientApp_->SetMessageCallback(name, browser_id, context,
				 arguments[1]);
			 handled = true;
	 }
	}  else if (name == "removeMessageCallback") {
	 // Remove a message callback.
	 if (arguments.size() == 1 && arguments[0]->IsString()) {
		 std::string name = arguments[0]->GetStringValue();
		 CefRefPtr<CefV8Context> context = CefV8Context::GetCurrentContext();
		 int browser_id = context->GetBrowser()->GetIdentifier();
		 bool removed = clientApp_->RemoveMessageCallback(name, browser_id);
		 retval = CefV8Value::CreateBool(removed);
		 handled = true;
	 }
	}

	if (!handled)
	 exception = "Invalid method arguments";

	return true;
}
