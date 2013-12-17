#ifndef CORE_SERVICE_CPTFMODULE_H
#define CORE_SERVICE_CPTFMODULE_H

#include "service/CptfModuleT.h"
#include "service/ServiceClassFactory.h"

namespace cptf{
namespace core{

	class CptfModule : public CptfModuleT<CptfModule>
					, public  ServiceClassFactory<CptfModule>{
	public:
		CptfModule(){}
		~CptfModule(){}

	};
}
}


#endif