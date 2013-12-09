#ifndef CORE_SERVICE_SERVICECONTAINER_H
#define CORE_SERVICE_SERVICECONTAINER_H

#include "service/ServiceConfig.h"
#include "StdLibInclude.h"

namespace cptf{
namespace core{

	class  ServiceContainer
	{
	public:
		ServiceContainer(void);
		~ServiceContainer(void);

	private:
		bool	init();

	private:
		list<ServiceConfigPtr> serviceConfigs_;
	};

	typedef shared_ptr<ServiceContainer> ServiceContainerPtr;

}
}

#endif
