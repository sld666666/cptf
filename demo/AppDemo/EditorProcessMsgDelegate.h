#pragma once
#include "ProcessMessageDelegate.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ObjectRoot.h"
#include "service/ThreadModel.h"
#include "service/CpftBase.h"

using namespace cptf::core;

const wstring  EditorProcessMsgDelegate_IID= L"30078970-d358-11e3-a119-bc305bacf447";
class EditorProcessMsgDelegate: public ServiceCoClass<EditorProcessMsgDelegate>
							, public IDispatchImpl<IProcessMsgImpl>
							, public ObjectRoot<SingleThreadModel>
{
public:
	EditorProcessMsgDelegate(void);
	~EditorProcessMsgDelegate(void);

	static wstring	 clsid() {return EditorProcessMsgDelegate_IID;}
	virtual bool excute(const CefRefPtr<CefBrowser>browser
		, const CefRefPtr<CefProcessMessage>& msg) const;
	virtual string getName()const;

	CPTF_BEGIN_SERVICE_MAP(EditorProcessMsgDelegate)
		CPTF_SERVICE_INTERFACE_ENTRY(IProcessMsgImpl_IID, IProcessMsgImpl)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(EditorProcessMsgDelegate)
