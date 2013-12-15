#ifndef CORE_SERVICE_ISERVICE_H
#define CORE_SERVICE_ISERVICE_H
#include "TypeDefine.h"

namespace cptf{
namespace core{
	interfacecptf IService{
		virtual cptf::CPTF_IID getIID() = 0;
	};
}
}


#endif // CORE_SERVICE_ISERVICE_H
