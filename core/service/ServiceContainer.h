#ifndef CORE_SERVICE_SERVICECONTAINER_H
#define CORE_SERVICE_SERVICECONTAINER_H

#include "service/ServiceConfig.h"
#include "StdLibInclude.h"

namespace cptf{
namespace core{

	class CPTF_EXPORT ServiceContainer
	{
	public:
		ServiceContainer(void);
		~ServiceContainer(void);
	public:
		wstring	findBundlelName(const wstring& iid);

	private:
		bool	init();
	private:
		list<ServiceConfigPtr> serviceConfigs_;
	};

	typedef shared_ptr<ServiceContainer> ServiceContainerPtr;

}
}

#endif
