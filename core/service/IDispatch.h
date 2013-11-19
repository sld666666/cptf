#ifndef CORE_SERVICE_IDISPATCH_H
#define CORE_SERVICE_IDISPATCH_H
#include "../TypeDefine.h"
#include "IService.h"

namespace cptf{
namespace core{

	interfacecptf IDispatch :public IService{

// 		virtual uint getTypeInfoCount() = 0;
// 		virtual bool invoke()=0;
		virtual cptf::IID getIID() = 0;

	};
}
}


#endif // CORE_SERVICE_IDISPATCH_H
