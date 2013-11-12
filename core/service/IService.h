#ifndef CORE_SERVICE_ISERVICE_H
#define CORE_SERVICE_ISERVICE_H
#include "../TypeDefine.h"
namespace core{

	class IService{

	public:
		IService(){}
		virtual ~IService(){}

	public:
		virtual	ulong addRef();
		virtual ulong releaseRef();
	};
}

#endif // CORE_SERVICE_ISERVICE_H
