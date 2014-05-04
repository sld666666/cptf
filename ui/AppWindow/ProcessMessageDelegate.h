#pragma once
#include "include/cef_client.h"
#include "TypeDefine.h"
#include "service/IDispatch.h"

const wstring IProcessMsgImpl_IID = L"29aca551-d358-11e3-826c-bc305bacf447";
interfacecptf IProcessMsgImpl : public cptf::core::IDispatch 
{
	virtual bool excute(const CefRefPtr<CefBrowser>browser
		, const CefRefPtr<CefProcessMessage>& msg) const = 0;
	virtual string getName() const = 0;
};

class ProcessMessageDelegate : public CefBase
{
public:
	ProcessMessageDelegate();
	~ProcessMessageDelegate();

	virtual bool OnProcessMessageReceived(
		CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message);
private:
	void	init();
	void	excuteMsg(IProcessMsgImpl* processMsg
		, CefRefPtr<CefBrowser> browser
		, const CefRefPtr<CefProcessMessage>& msg);
	void	appendProcessMsgImpl(const wstring& csid);
private:
	vector<IProcessMsgImpl*>	processMsgImpls_;

	IMPLEMENT_REFCOUNTING(ProcessMessageDelegate);
};


