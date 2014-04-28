#ifndef CORE_SERVICE_SERVICECONFIGS_H
#define CORE_SERVICE_SERVICECONFIGS_H
#include "StdLibInclude.h"
#include "StringDefine.h"
#include "service/ServiceConfig.h"
#include "utils/ApplicationPath.h"

namespace cptf{
namespace core{

	class ServiceConfigs 
	{
	public:
		ServiceConfigs(void);
		~ServiceConfigs(void);
	public:
		wstring		findBundlelName(const wstring& csid);
		wstring		getIId(const wstring& csid);
		vector<wstring> getCsids(const wstring& iid);
	private:
		bool	init();
	private:
		list<ServiceConfigPtr> serviceConfigs_;
	};

	typedef shared_ptr<ServiceConfigs> ServiceConfigsPtr;

	ServiceConfigs::ServiceConfigs(void)
	{
		init();
	}

	ServiceConfigs::~ServiceConfigs(void)
	{

	}

	bool ServiceConfigs::init()
	{
		bool rtn(false);
		wstring curAppPath = ApplicaitonPath<>::getCurAppPath();
		wstring serviceXmlPath = curAppPath+ ApplicaitonPath<>::getDirSeparator()
			+ SERVICE_XML_NAME;

		serviceConfigs_ = ServiceConfig().read(serviceXmlPath);
		return rtn;
	}

	wstring	ServiceConfigs::findBundlelName(const wstring& csid)
	{
		wstring bundelName;
		list<ServiceConfigPtr>::iterator iter = find_if(serviceConfigs_.begin()
			, serviceConfigs_.end(), bind(&ServiceConfigFunctors::matchedByCsid, _1, csid));
		bundelName = (iter != serviceConfigs_.end())?(*iter)->bundle():L"";
		return bundelName;
	}

	wstring	ServiceConfigs::getIId(const wstring& csid)
	{
		wstring iid;
		list<ServiceConfigPtr>::iterator iter = find_if(serviceConfigs_.begin()
			, serviceConfigs_.end(), bind(&ServiceConfigFunctors::matchedByCsid, _1, csid));
		iid = (iter != serviceConfigs_.end())?(*iter)->serviceId():L"";
		return iid;
	}

	vector<wstring> ServiceConfigs::getCsids(const wstring& iid)
	{
		vector<wstring> csids;
		foreach(ServiceConfigPtr config, serviceConfigs_){
			if (ServiceConfigFunctors::matchedByService(config, iid)){
				csids.push_back(config->csid());
			}
		}
		return csids;
	}
}
}
#endif