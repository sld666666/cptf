#ifndef CORE_SERVICE_OBJECTROOT_H
#define CORE_SERVICE_OBJECTROOT_H

#include "TypeDefine.h"
namespace cptf{
namespace core{
	template<typename ThreadModel>
	class ObjectRoot{

	public:
		ObjectRoot(): ref_(0){}
		~ObjectRoot(){}

		ulong internalAddRef()
		{
			return ThreadModel::increment(&ref_);
		}

		ulong internalReleaseRef()
		{
			return ThreadModel::decrement(&ref_);
		}

	private:
		ulong ref_;
	};
}
}
#endif