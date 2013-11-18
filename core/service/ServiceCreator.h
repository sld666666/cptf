#ifndef CORE_SERVICE_SERVICECREATOR_H
#define CORE_SERVICE_SERVICECREATOR_H
#include "../TypeDefine.h"
namespace cptf{
namespace core{

	template <typename T>
	class ServiceCreator{

	public:
		ServiceCreator(){}
		virtual ~ServiceCreator(){}

	public:
		static bool	createInstance(IID iid, T* rtnObj);
	};

	template <typename T>
	bool ServiceCreator<T>::createInstance(IID iid
										, T* rtnObj)
	{
		bool rtn(false);
		
		return rtn;
	}	 

}
}


#endif // CORE_SERVICE_SERVICECREATOR_H