#pragma once
class Dumesa : public ServiceCoClass<Dumesa>
					, public ObjectRoot<SingleThreadModel>
					, IOgre
					, IHumanOgre{
public:
	static wstring	 clsid() {return Dumesa_CSID;}
	Dumesa(){}
	~Dumesa(){}

	virtual	cptf::ulong	getHealth(){return 10;}
	virtual	cptf::ulong	getHurt() {return 1;}
	virtual wstring		getName() {return L"I am Dumesa";}
	virtual wstring		getLanguage(){return L"En";}

	CPTF_BEGIN_SERVICE_MAP(Dumesa)
		CPTF_SERVICE_INTERFACE_ENTRY(IOgre_IID, IOgre)
		CPTF_SERVICE_INTERFACE_ENTRY(IHumanOgre_IID, IHumanOgre)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(Dumesa)