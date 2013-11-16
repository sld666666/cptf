#ifndef CORE_SERVICE_IUNKOWN_H
#define CORE_SERVICE_IUNKOWN_H

#include "../TypeDefine.h"

namespace cptf{
namespace core{
	interface IUnknown
	{
		virtual	void*	queryInterface(ulong iid)=0;
		virtual	ulong	addRef()=0;
		virtual ulong	releaseRef()=0;
	};

}
}

#endif