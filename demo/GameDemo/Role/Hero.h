#pragma once

#include "Role.h"
#include "service/DefaultServiceImpl.h"
using namespace cptf::core;

class Hero : public DefaultServiceImpl<Hero>
			, public IHero{
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