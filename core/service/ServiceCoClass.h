#ifndef CORE_SERVICE_SERVICECOCLASS_H
#define CORE_SERVICE_SERVICECOCLASS_H
#include "service/ServiceCreator.h"
#include "service/ServiceObject.h"

namespace cptf{
namespace core{

	template<typename T>
	class ServiceCoClass{
	public:
		ServiceCoClass(){}
		~ServiceCoClass(){}

		static wstring	 clsid() {return T::clsid();}
	public:
		typedef  ServiceCreator< ServiceObject<T>> creatorClass_;
	};

}
}

#endif