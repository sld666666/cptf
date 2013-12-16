#ifndef CORE_SERVICE_SERVICEOBJECT_H
#define CORE_SERVICE_SERVICEOBJECT_H

#include "TypeDefine.h"

namespace cptf{
namespace core{
	template <typename Base>
	class ServiceObject : public Base{
	public:
		ulong addRef()
		{
			return internalAddRef();
		}
		ulong release()
		{
			ulong ref = internalReleaseRef();
			if (0 == ref){
				delete this;
				this = NULL;
			}

			return ref;
		}

		bool queryInterface(const CPTF_IID& iid, void**rntObj){
			return internalQueryInterface(iid, rntObj);
		}
	};
}
}

#endif

 