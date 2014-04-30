#pragma once
#include "include/cef_app.h"
#include "SetList.h"

class ClientApp : public CefApp
				, public CefRenderProcessHandler
{
public:
	ClientApp(void);
	~ClientApp(void);

	void SetMessageCallback(const std::string& message_name,
		int browser_id,
		CefRefPtr<CefV8Context> context,
		CefRefPtr<CefV8Value> function);

	bool RemoveMessageCallback(const std::string& message_name,
		int browser_id);

	virtual void OnWebKitInitialized();

	virtual bool OnProcessMessageReceived(
		CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message);

 private:
	 virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler(){ return this; }

private:
	typedef std::map<std::pair<std::string, int>,
		std::pair<CefRefPtr<CefV8Context>, CefRefPtr<CefV8Value> > >
		CallbackMap;
	CallbackMap callback_map_;

IMPLEMENT_REFCOUNTING(ClientApp);
};
