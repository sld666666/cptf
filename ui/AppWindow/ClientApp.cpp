#include "StdAfx.h"
#include "ClientApp.h"
#include "ClientV8Handler.h"

ClientApp::ClientApp(void)
{
}

ClientApp::~ClientApp(void)
{
}

void ClientApp::SetMessageCallback(const std::string& message_name,
								   int browser_id,
								   CefRefPtr<CefV8Context> context,
								   CefRefPtr<CefV8Value> function) 
{
   callback_map_.insert(std::make_pair(std::make_pair(message_name, browser_id)
	   , std::make_pair(context, function)));
}

bool ClientApp::RemoveMessageCallback(const std::string& message_name,
									  int browser_id) 
{

	  CallbackMap::iterator it =
		  callback_map_.find(std::make_pair(message_name, browser_id));
	  if (it != callback_map_.end()) {
		  callback_map_.erase(it);
		  return true;
	  }

	  return false;
}

void ClientApp::OnWebKitInitialized() {
	// Register the client_app extension.
	std::string app_code =
		"var app;"
		"if (!app)"
		"  app = {};"
		"(function() {"
		"  app.sendMessage = function(name, arguments) {"
		"    native function sendMessage();"
		"    return sendMessage(name, arguments);"
		"  };"
		"  app.setMessageCallback = function(name, callback) {"
		"    native function setMessageCallback();"
		"    return setMessageCallback(name, callback);"
		"  };"
		"  app.removeMessageCallback = function(name) {"
		"    native function removeMessageCallback();"
		"    return removeMessageCallback(name);"
		"  };"
		"})();";
	CefRegisterExtension("v8/app", app_code,
		new ClientV8Handler(this));
}

bool ClientApp::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
										CefProcessId source_process,
										CefRefPtr<CefProcessMessage> message) 
{
	bool handled = false;

	// Execute the registered JavaScript callback if any.
	if (!callback_map_.empty()) {
		CefString message_name = message->GetName();
		CallbackMap::const_iterator it = callback_map_.find(
			std::make_pair(message_name.ToString(),
			browser->GetIdentifier()));
		if (it != callback_map_.end()) {
			// Keep a local reference to the objects. The callback may remove itself
			// from the callback map.
			CefRefPtr<CefV8Context> context = it->second.first;
			CefRefPtr<CefV8Value> callback = it->second.second;

			// Enter the context.
			context->Enter();

			CefV8ValueList arguments;

			// First argument is the message name.
			arguments.push_back(CefV8Value::CreateString(message_name));

			// Second argument is the list of message arguments.
			CefRefPtr<CefListValue> list = message->GetArgumentList();
			CefRefPtr<CefV8Value> args =
				CefV8Value::CreateArray(static_cast<int>(list->GetSize()));
			V8ListSetter::SetList(list, args);
			arguments.push_back(args);

			// Execute the callback.
			CefRefPtr<CefV8Value> retval = callback->ExecuteFunction(NULL, arguments);
			if (retval.get()) {
				if (retval->IsBool())
					handled = retval->GetBoolValue();
			}

			// Exit the context.
			context->Exit();
		}
	}

	return handled;
}