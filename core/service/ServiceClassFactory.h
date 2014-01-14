#ifndef CORE_SERVICE_SERVICECLASSFACTORY_H
#define CORE_SERVICE_SERVICECLASSFACTORY_H
#include "TypeDefine.h"
#include "StringDefine.h"
#include "service/SystemOperation.h"
#include "service/WinDllCreator.h"
#include "service/CpftBase.h"

namespace cptf{
namespace core{
	
	template <typename T>
	class ServiceClassFactory {
	public:
		ServiceClassFactory(){}
		~ServiceClassFactory(){}

	public:
		bool appClassObject(const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
		bool bundleCreateInstance(const wstring& bundleName, const cptf::IID& csid, const cptf::IID& iid, void** rntObj);
	};


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
	bool ServiceClassFactory<T>::appClassObject(const cptf::IID& csid
										, const cptf::IID& iid
										, void** rntObj)
	{
		return cptfModuleGetClassObject(static_cast<T*>(this), csid, iid, rntObj); 
	}
}
}

#endif