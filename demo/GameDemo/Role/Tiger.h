#pragma once
class Tiger : public ServiceCoClass<Tiger>
					, public ObjectRoot<SingleThreadModel>
					, public cptf::core::IDispatchImpl<IOgre>{
public:
	static wstring	 clsid() {return Tiger_CSID;}
	Tiger(){}
	~Tiger(){}

	virtual	cptf::ulong	getHealth(){return 10;}
	virtual	cptf::ulong	getHurt() {return 1;}
	virtual wstring		getName() {return L"I am Tiger";}

	CPTF_BEGIN_SERVICE_MAP(Tiger)
		CPTF_SERVICE_INTERFACE_ENTRY(IOgre_IID, IOgre)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(Tiger)