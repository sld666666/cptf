#ifndef CORE_SERVICE_SERVICECONFIG_H
#define CORE_SERVICE_SERVICECONFIG_H
#include "utils/MetaObject.h"
#include "utils/IXmlParser.h"

namespace cptf{
namespace core{
	class ServiceConfig : public MetaObject<ServiceConfig>
		,	public IXmlParser<ServiceConfig>{
	public:
		ServiceConfig(){
			INVOKE(L"bundle", ServiceConfig::bundle, ServiceConfig::setBundle);
			INVOKE(L"csid", ServiceConfig::csid, ServiceConfig::setCsid);
			INVOKE(L"description", ServiceConfig::description, ServiceConfig::setDescription);
			INVOKE(L"name", ServiceConfig::name, ServiceConfig::setName);
			INVOKE(L"serviceId", ServiceConfig::serviceId, ServiceConfig::setServiceId);
			INVOKE(L"serviceName", ServiceConfig::serviceName, ServiceConfig::setServiceName);
		}
		~ServiceConfig(){}

	public:
		wstring	csid(){return csid_;}
		void	setCsid(const wstring& val){csid_ = val;}

		wstring	bundle(){return bundle_;}
		void	setBundle(const wstring& val){bundle_ = val;}

		wstring description(){return description_;}
		void	setDescription(const wstring& val){description_ = val;}

		wstring	name(){return name_;}
		void	setName(const wstring& val){name_ = val;}

		wstring	serviceId(){return serviceId_;}
		void	setServiceId(const wstring& val){
			serviceId_ = val;
			serviceIds_ = StringUtils::splitLast(serviceId_, L";");
		}

		wstring	serviceName(){return serviceName_;}
		void	setServiceName(const wstring& val){serviceName_ = val;}

		vector<wstring>	serviceIds(){return serviceIds_;}
	protected:
		virtual wstring getNodeRelativePath(){return L"repository.services";}
	private:
		wstring csid_;
		wstring bundle_;
		wstring description_;
		wstring name_;
		wstring serviceId_;
		wstring serviceName_;
		vector<wstring>	serviceIds_;
	};
	
	typedef shared_ptr<ServiceConfig> ServiceConfigPtr;

	class ServiceConfigFunctors
	{
	public:
		static bool	matchedByService(const ServiceConfigPtr config
								, const wstring& serviceId)
		{
			if (!config.get())return false;
			vector<wstring>	serviceIds = config->serviceIds();
			return (find(serviceIds.begin(), serviceIds.end(), serviceId) !=  serviceIds.end());
		}

		static bool	matchedByCsid(const ServiceConfigPtr config
									, const wstring& csid)
		{
			bool rtn = (config.get() && csid == config->csid());
			return rtn;
		}


	};
}
}


#endif