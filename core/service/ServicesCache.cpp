#include "ServicesCache.h"

namespace cptf{
namespace core{

	ServicesCache::ServicesCache(void)
	{
	}

	ServicesCache::~ServicesCache(void)
	{
	}

	bool ServicesCache::contains(const cptf::IID& csid
								, const cptf::IID& iid)
	{
		bool rtn(false);
		rtn = (find_if(objectConfiges_.begin(), objectConfiges_.end()
					, bind(&ServiceObjectConfig::matched, _1, csid, iid)) != objectConfiges_.end());
		return rtn;
	}

	void ServicesCache::add(const cptf::IID& csid
							, const cptf::IID& iid
							, IService* service)
	{
		ServiceObjectConfigPtr object(new ServiceObjectConfig(csid, iid, service));
		objectConfiges_.push_back(object);
	}

	IService* ServicesCache::get(const cptf::IID& csid
								, const cptf::IID& iid)
	{
		list<ServiceObjectConfigPtr>::iterator iter = find_if(objectConfiges_.begin()
			, objectConfiges_.end(), bind(&ServiceObjectConfig::matched, _1, csid, iid));
		return (iter == objectConfiges_.end())?NULL:(*iter)->service;
	}

	void ServicesCache::release(IService* service)
	{
		list<ServiceObjectConfigPtr>::iterator iter = find_if(objectConfiges_.begin()
			, objectConfiges_.end(), bind(&ServiceObjectConfig::matched, _1, service));
		if (iter != objectConfiges_.end()){
			objectConfiges_.erase(iter);
			(*iter)->service->release();
		}
	}
}
}
