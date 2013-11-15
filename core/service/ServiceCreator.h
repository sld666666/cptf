#ifndef CORE_SERVICE_SERVICECREATOR_H
#define CORE_SERVICE_SERVICECREATOR_H
#include "../TypeDefine.h"
namespace cptf{
namespace core{

	class ServiceCreator{

	public:
		ServiceCreator(){}
		virtual ~ServiceCreator(){}

	public:
		bool	createInstance();
	};
}
}


#endif // CORE_SERVICE_SERVICECREATOR_H