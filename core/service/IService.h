#ifndef CORE_SERVICE_ISERVICE_H
#define CORE_SERVICE_ISERVICE_H
#include "../TypeDefine.h"
namespace cptf{
namespace core{
	class IService{

	public:
		IService(){}
		virtual ~IService(){}

	public:
		virtual	void*	queryInterface(ulong iid)=0;
		virtual	ulong	addRef()=0;
		virtual ulong	releaseRef()=0;
	};
}
}


#endif // CORE_SERVICE_ISERVICE_H
