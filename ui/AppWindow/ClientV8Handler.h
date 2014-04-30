#pragma once
#include "ClientApp.h"


class ClientV8Handler : public CefV8Handler
{
public:
	ClientV8Handler(CefRefPtr<ClientApp> clientApp);
	~ClientV8Handler(void);

	virtual bool Execute(const CefString& name,
		CefRefPtr<CefV8Value> object,
		const CefV8ValueList& arguments,
		CefRefPtr<CefV8Value>& retval,
		CefString& exception);
private:
	 CefRefPtr<ClientApp> clientApp_;

	 IMPLEMENT_REFCOUNTING(ClientV8Handler);
};
