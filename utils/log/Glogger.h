#pragma once
#include "Logger.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ObjectRoot.h"
#include "service/ThreadModel.h"
#include "service/CpftBase.h"

using namespace cptf::core;

const wstring  Glogger_IID= L"30098970-d358-11e3-a119-bc305bacf447";
class Glogger :  public ILogger
				, public DefaultServiceImpl<Glogger>
{
public:
	Glogger();
	~Glogger();

	static wstring	 clsid() {return Glogger_IID;}

	virtual void	init();
	virtual void	log(int level, const string& msg);

	CPTF_BEGIN_SERVICE_MAP(Glogger)
		CPTF_SERVICE_INTERFACE_ENTRY(Glogger_IID, ILogger)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(Glogger)
