#ifndef CORE_SERVICE_SERVICECONTAINER_H
#define CORE_SERVICE_SERVICECONTAINER_H

#include "service/IService.h"
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
		//list<IService*> services_;
	};

	typedef shared_ptr<ServiceContainer> ServiceContainerPtr;

}
}

#endif
