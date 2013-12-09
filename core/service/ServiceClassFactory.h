#ifndef CORE_SERVICE_SERVICECLASSFACTORY_H
#define CORE_SERVICE_SERVICECLASSFACTORY_H
#include "../TypeDefine.h"
#include "IService.h"

namespace fptf{
namespace core{
	
	class ServiceClassFactory{
	public:
		ServiceClassFactory(){}
		~ServiceClassFactory(){}

	public:
		bool createInstance(CPTF_IID iid, IService* service);
	};

	bool ServiceClassFactory::createInstance(CPTF_IID iid, IService* service)
	{
		bool rtn(false);
		
		return rtn;
	}
}
}

#endif