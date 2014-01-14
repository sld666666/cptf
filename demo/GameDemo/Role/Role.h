#pragma once
#include "TypeDefine.h"
#include "service/IDispatch.h"

const wstring Bundle_Role_IID = L"7f201611-7c1a-11e3-a2d2-bc305bacf447";

interfacecptf IRole{
	virtual	cptf::ulong	getHealth() = 0;
	virtual	cptf::ulong	getHurt() = 0;
	virtual wstring		getName() = 0;
};

const wstring IHero_IID = L"99f9dd8f-7c1a-11e3-9f9d-bc305bacf447";
const wstring Hero_CSID=  L"500851c0-7c2a-11e3-8c28-bc305bacf447";

interfacecptf IHero : public cptf::core::IDispatch
					, public IRole{
	virtual	cptf::ulong attack() = 0;
};


const wstring IOgre_IID = L"ba435561-7c36-11e3-89e5-bc305bacf447";
const wstring Wolf_CSID	= L"ae8b9bb0-7c36-11e3-99ea-bc305bacf447";
const wstring Tiger_CSID = L"58134430-7c37-11e3-af0a-bc305bacf447"; 
const wstring Dumesa_CSID = L"55635d11-7c50-11e3-8762-bc305bacf447"; 
interfacecptf IOgre : public cptf::core::IDispatch
					, public IRole{

};

const wstring IHumanOgre_IID = L"c8f36780-7c36-11e3-baf8-bc305bacf447";
interfacecptf IHumanOgre : public cptf::core::IDispatch{
	virtual wstring	getLanguage() = 0;
};