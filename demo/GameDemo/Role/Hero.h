#pragma once
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ThreadModel.h"
#include "service/ObjectRoot.h"
#include "Role.h"
using namespace cptf::core;

class Hero : public ServiceCoClass<Hero>
			, public ObjectRoot<SingleThreadModel>
			, public cptf::core::IDispatchImpl<IHero>{
public:
	static wstring	 clsid() {return Hero_CSID;}
	Hero(){}
	~Hero(){}

	virtual	cptf::ulong	getHealth(){return 100;}
	virtual	cptf::ulong	getHurt() {return 10;}
	virtual wstring		getName() {return L"I am Hero";}

	cptf::ulong attack(){return 10;}

	CPTF_BEGIN_SERVICE_MAP(Hero)
		CPTF_SERVICE_INTERFACE_ENTRY(IHero_IID, IHero)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(Hero)