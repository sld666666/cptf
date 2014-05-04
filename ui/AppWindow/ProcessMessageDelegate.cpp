#include "StdAfx.h"
#include "ProcessMessageDelegate.h"
#include "service/ServiceContainer.h"
#include "AppWindow.h"
#include <string>
using std::string;
using namespace cptf::core;

ProcessMessageDelegate::ProcessMessageDelegate(void)
{
	init();
}

ProcessMessageDelegate::~ProcessMessageDelegate(void)
{
}

void ProcessMessageDelegate::init()
{
	vector<wstring> processMsgDelegateIIds;
	processMsgDelegateIIds.push_back(L"30e78970-d358-11e3-a119-bc305bacf447");//BindJsProcessMsgDelegate_IID
	processMsgDelegateIIds.push_back(L"30178970-d358-11e3-a119-bc305bacf447");//DailogProcessMsgDelegate_IID

	for_each(processMsgDelegateIIds.begin(), processMsgDelegateIIds.end()
		,bind(&ProcessMessageDelegate::appendProcessMsgImpl, this, _1));
}

void ProcessMessageDelegate::appendProcessMsgImpl(const wstring& csid)
{
	ServiceContainer<CptfModule> container(&g_cptfModule);
	IProcessMsgImpl* processMsg = NULL;
	container.createService(csid, IProcessMsgImpl_IID, (void**)&processMsg);
	if(processMsg){
		processMsgImpls_.push_back(processMsg);
	}
}

bool ProcessMessageDelegate::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser
													  , CefProcessId source_process
													  ,CefRefPtr<CefProcessMessage> message)
{
	for_each(processMsgImpls_.begin(), processMsgImpls_.end()
		, bind(&ProcessMessageDelegate::excuteMsg, this, _1, browser, message));

	return true;

}

void ProcessMessageDelegate::excuteMsg(IProcessMsgImpl* processMsg
									   , const CefRefPtr<CefBrowser> browser
									   , const CefRefPtr<CefProcessMessage>& msg)
{
	if (!processMsg || !browser.get() || !msg.get())return;

	if(msg->GetName() != processMsg->getName())return;

	processMsg->excute(browser, msg);
}