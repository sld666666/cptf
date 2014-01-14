#pragma once
#include "service/CptfModule.h"
#include "service/ServiceContainer.h"
#include "../Role/Role.h"

using namespace cptf::core;
class BattleMannager
{
public:
	BattleMannager(void);
	~BattleMannager(void);

	void run();
private:
	static void printHero(IHero* hero);
	static void printOgre(IOgre* ogre);
	static void printHumanOgre(IHumanOgre* humanOgre);
private:
	CptfModule cptfModule_;
	ServiceContainer<CptfModule> serviceContainer_;
	IHero*	hero_;
};
