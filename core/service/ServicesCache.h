#ifndef CORE_SERVICE_SERVICESCACHE
#define CORE_SERVICE_SERVICESCACHE

#include "StdLibInclude.h"
#include "TypeDefine.h"
#include "service/IService.h"
#include "service/ServiceConfigs.h"

namespace cptf{
namespace core{

	//csid+ iid 确定一个service
	struct ServiceObjectConfig
	{
		IService* service;
		cptf::IID csid;
		cptf::IID iid;

		ServiceObjectConfig(const cptf::IID& _csid, const cptf::IID& _iid, IService* _service)
			: service(_service)
			, csid(_csid)
			, iid(_iid)
		{

		}

		static bool matched(shared_ptr<ServiceObjectConfig>  config
							, const cptf::IID& csid
							, const cptf::IID& iid)
		{
			return (config.get() 
					&& (csid == config->csid)
					&& (iid == config->iid));
		}

		static bool matched(shared_ptr<ServiceObjectConfig>  config
			, IService* service)
		{
			return (config.get() 
				&& (service == config->service));
		}
	};
	typedef shared_ptr<ServiceObjectConfig> ServiceObjectConfigPtr;

	class CPTF_EXPORT ServicesCache
	{
	public:
		ServicesCache();
		~ServicesCache();

		void		add(const cptf::IID& csid, const cptf::IID& iid, IService* service);
		IService*	get(const cptf::IID& csid, const cptf::IID& iid);
		void		release(IService* service);
		bool		contains(const cptf::IID& csid, const cptf::IID& iid);
	private:
		list<ServiceObjectConfigPtr> objectConfiges_;
	};

}
}



#endif
