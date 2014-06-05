#pragma once
class Wolf : public DefaultServiceImpl<Wolf>
					, public IOgre{
public:
	static wstring	 clsid() {return Wolf_CSID;}
	Wolf(){}
	~Wolf(){}

	virtual	cptf::ulong	getHealth(){return 10;}
	virtual	cptf::ulong	getHurt() {return 1;}
	virtual wstring		getName() {return L"I am Wolf";}

	CPTF_BEGIN_SERVICE_MAP(Wolf)
		CPTF_SERVICE_INTERFACE_ENTRY(IOgre_IID, IOgre)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(Wolf)