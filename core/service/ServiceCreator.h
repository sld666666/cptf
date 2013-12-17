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
		static bool	WINAPI createInstance(cptf::IID iid, void** rtnObj);
	};

	template <typename T>
	bool ServiceCreator<T>::createInstance(cptf::IID iid, void** rtnObj)
	{
		bool rtn(false);
		T* serviceObj(new T());
		if (serviceObj){
			rtn = true;
			serviceObj->queryInterface(iid, rtnObj);
		}
		return rtn;
	}	 

}
}


#endif // CORE_SERVICE_SERVICECREATOR_H