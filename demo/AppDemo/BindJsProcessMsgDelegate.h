#pragma once
#include "ProcessMessageDelegate.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ObjectRoot.h"
#include "service/ThreadModel.h"
#include "service/CpftBase.h"

using namespace cptf::core;

const wstring  BindJsProcessMsgDelegate_IID= L"30e78970-d358-11e3-a119-bc305bacf447";
class BindJsProcessMsgDelegate: public ServiceCoClass<BindJsProcessMsgDelegate>
							, public IDispatchImpl<IProcessMsgImpl>
							, public ObjectRoot<SingleThreadModel>
{
public:
	BindJsProcessMsgDelegate(void);
	~BindJsProcessMsgDelegate(void);

	static wstring	 clsid() {return BindJsProcessMsgDelegate_IID;}
	virtual bool excute(const CefRefPtr<CefBrowser>browser
		, const CefRefPtr<CefProcessMessage>& msg) const;
	virtual string getName()const;

	CPTF_BEGIN_SERVICE_MAP(BindJsProcessMsgDelegate)
		CPTF_SERVICE_INTERFACE_ENTRY(IProcessMsgImpl_IID, IProcessMsgImpl)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(BindJsProcessMsgDelegate)
