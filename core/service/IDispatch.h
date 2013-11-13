#ifndef CORE_SERVICE_IDISPATCH_H
#define CORE_SERVICE_IDISPATCH_H
#include "../TypeDefine.h"

namespace cptf{
namespace core{

	class IDispatch{

	public:
		IDispatch(){}
		virtual ~IDispatch(){}
	
	public:
		virtual uint getTypeInfoCount() = 0;
		virtual bool invoke()=0;

	};
}
}


#endif // CORE_SERVICE_IDISPATCH_H
