#ifndef CORE_SERVICE_SERVICECLASSFACTORY_H
#define CORE_SERVICE_SERVICECLASSFACTORY_H
#include "TypeDefine.h"
#include "StringDefine.h"
#include "service/ServiceContainer.h"
#include "service/SystemOperation.h"
#include "service/WinDllCreator.h"

namespace cptf{
namespace core{
	
	template <typename T>
	class ServiceClassFactory {
	public:
		ServiceClassFactory(){}
		~ServiceClassFactory(){}

	public:
		bool createInstance(const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
	private:
		bool ServiceClassFactory::getClassObject(const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
		bool bundleCreateInstance(const wstring& bundleName, const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
	private:
		ServiceContainer	serviceContainer_;
	};

	template <typename T>
	bool ServiceClassFactory<T>::createInstance(const cptf::IID& csid
											, const cptf::IID& iid
											, void** rntObj)
	{
		bool rtn(false);
		wstring bundleName = serviceContainer_.findBundlelName(csid);
		if (!bundleName.empty()){
			if (MAINAPP == bundleName){
				rtn = getClassObject(csid, iid, rntObj);
			}else{
				rtn = bundleCreateInstance(bundleName, csid, iid, rntObj);
			}
		}
		return rtn;
	}

	template <typename T>
	bool ServiceClassFactory<T>::bundleCreateInstance(const wstring& bundleName
												, const cptf::IID& csid
												, const cptf::IID& iid
												, void** rntObj)
	{
		bool rtn(false);
		rtn = SystemOperation<WinDllCreator>::createObjectFromDll(
			bundleName, csid, iid, rntObj);
		return rtn;
	}

	template <typename T>
	bool ServiceClassFactory<T>::getClassObject(const cptf::IID& csid
										, const cptf::IID& iid
										, void** rntObj)
	{
		return cptfModuleGetClassObject(static_cast<T*>(this), csid, iid, rntObj); 
	}
}
}

#endif