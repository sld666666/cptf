#include "StdAfx.h"
#include "BattleMannager.h"
#include "utils/CastsUtils.h"
#include <iostream>
using namespace std;

BattleMannager::BattleMannager(void)
: hero_(NULL)
, serviceContainer_(&cptfModule_)
{
}

BattleMannager::~BattleMannager(void)
{
	if (hero_)hero_->release();
}

void BattleMannager::run()
{
	hero_ = static_cast<IHero*>(serviceContainer_.getService(Hero_CSID, IHero_IID));
	if (!hero_)return;
	printHero(hero_);

	list<IService*> services = serviceContainer_.getServices(IOgre_IID);
	list<IOgre*> ogres = CastUtils::parentsToChildren<IService, IOgre>(services);
	for_each(ogres.begin(), ogres.end(), bind(&BattleMannager::printOgre, _1));

	services = serviceContainer_.getServices(IHumanOgre_IID);
	list<IHumanOgre*> hummanOgres = CastUtils::parentsToChildren<IService, IHumanOgre>(services);
	for_each(hummanOgres.begin(), hummanOgres.end(), bind(&BattleMannager::printHumanOgre, _1));
}

void BattleMannager::printHero(IHero* hero)
{
	if (!hero)return;

	cptf::ulong  hurt = hero->attack();
	wstring name = hero->getName();
	cptf::ulong health = hero->getHealth();
	cout <<"hero-----------------------" <<endl;
	wcout << name << endl;
	cout << hurt << endl;
	cout << health << endl;
	cout <<"hero-----------------------" <<endl;
}

void BattleMannager::printOgre(IOgre* ogre)
{
	if (!ogre)return;

	wstring name = ogre->getName();
	cptf::ulong health = ogre->getHealth();
	cout <<"ogre-----------------------" <<endl;
	wcout << name << endl;
	cout << health << endl;
	cout <<"ogre-----------------------" <<endl;
}

void BattleMannager::printHumanOgre(IHumanOgre* humanOgre)
{
	if (!humanOgre)return;
	cout <<"humanOgre-----------------------" <<endl;
	wcout << humanOgre->getLanguage() << endl;
	cout <<"humanOgre-----------------------" <<endl;

}
