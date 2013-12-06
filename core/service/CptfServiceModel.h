#ifndef CORE_SERVICE_CPTFSERVICEMODEL_H
#define CORE_SERVICE_CPTFSERVICEMODEL_H
#include "service/ServiceContainer.h"
namespace cptf{
namespace core{
	class CPTF_EXPORT CptfServiceModel{
	public:
	
		CptfServiceModel();
		~CptfServiceModel();
	public:
		

	private:
		ServiceContainerPtr	serviceContainer_;
	};


}
}



#endif