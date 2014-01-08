#ifndef CORE_SERVICE_ISERVICE_H
#define CORE_SERVICE_ISERVICE_H
#include "TypeDefine.h"

namespace cptf{
namespace core{
	interfacecptf IService{
		virtual	cptf::ulong addRef() = 0;
		virtual cptf::ulong release() = 0;
		virtual bool queryInterface(const cptf::IID& iid, void**rntObj) = 0;
	};
}
}


#endif // CORE_SERVICE_ISERVICE_H
