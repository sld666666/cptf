#ifndef CORE_SERVICE_SERVICECONTAINER_H
#define CORE_SERVICE_SERVICECONTAINER_H

#include "service/ServicesCache.h"

namespace cptf{
namespace core{

	template<typename Creator>
	class ServiceContainer 
	{
	public:
		ServiceContainer(Creator* creator) {creator_ = creator;}
		~ServiceContainer(void){};
	public:
		IService*	getService(const cptf::IID& csid, const cptf::IID& iid);
		list<IService*> getServices(const cptf::IID& iid);
		bool		createService(const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
	private:
		Creator*					creator_;
		ServicesCache				servicesCache_;
		ServiceConfigs				serviceConfigs_;
	};

	template <typename Creator>
	IService* ServiceContainer<Creator>::getService(const cptf::IID& csid
													, const cptf::IID& iid)
	{
		IService* service(NULL);
		if (servicesCache_.contains(csid, iid)){
			service = servicesCache_.get(csid, iid);;
		}
		else{
			createService(csid, iid, (void**)&service);
			servicesCache_.add(csid, iid, service);
		}
		return service;
	}

	template <typename Creator>
	list<IService*> ServiceContainer<Creator>::getServices(const cptf::IID& iid)
	{
		list<IService*> services;
		vector<wstring> csids = serviceConfigs_.getCsids(iid);
		transform(csids.begin(), csids.end(), back_inserter(services)
			, bind(&ServiceContainer<Creator>::getService, this, _1, iid));
		return services;
	}

	template <typename Creator>
	bool ServiceContainer<Creator>::createService(const cptf::IID& csid
												, const cptf::IID& iid
												, void** rntObj)
	{
		bool rtn(false);
		if (!creator_)return rtn;

		wstring bundleName = serviceConfigs_.findBundlelName(csid);
		bundleName = ApplicaitonPath::getCurAppPath() + ApplicaitonPath::getDirSeparator()
			+ bundleName;
		if (!bundleName.empty()){
			if (MAINAPP == bundleName){
				rtn = creator_->appClassObject(csid, iid, rntObj);
			}else{
				rtn = creator_->bundleCreateInstance(bundleName, csid, iid, rntObj);
			}
		}
		return rtn;
	}
}
}

#endif
