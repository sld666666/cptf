#ifndef CORE_SERVICE_SERVICEOBJECT_H
#define CORE_SERVICE_SERVICEOBJECT_H

#include "TypeDefine.h"

namespace cptf{
namespace core{
	template <typename Base>
	class ServiceObject : public Base{
	public:
		virtual ulong addRef()
		{
			return internalAddRef();
		}

		virtual ulong release()
		{
			ulong ref = internalReleaseRef();
			if (0 == ref){
				delete this;
			}
			return ref;
		}

		virtual bool queryInterface(const cptf::IID& iid, void**rntObj){
			return internalQueryInterface(iid, rntObj);
		}
	};
}
}

#endif

 