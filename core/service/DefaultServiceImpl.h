#ifndef CORE_SERVICE_DEFAULTSERVICEIMPL_H
#define CORE_SERVICE_DEFAULTSERVICEIMPL_H

#include "service/ServiceCoClass.h"
#include "service/ThreadModel.h"
#include "service/ObjectRoot.h"

namespace cptf{
namespace core{
	template<typename T, typename ThreadModel = SingleThreadModel>
	class DefaultServiceImpl : public ServiceCoClass<T>
							, public ObjectRoot<ThreadModel>{

	public:
		DefaultServiceImpl(){}
		~DefaultServiceImpl(){}
	};
}
}
#endif