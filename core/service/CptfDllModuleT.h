#ifndef CORE_SERVICE_CPTFDLLMODELT_H
#define CORE_SERVICE_CPTFDLLMODELT_H
#include "service/CptfModuleT.h"

namespace cptf{
namespace core{
	template <typename T>
	class CptfDllModuleT : public CptfModuleT<CptfDllModuleT<T>>{
	public:
		CptfDllModuleT(){}
		~CptfDllModuleT(){}

		bool	dllGetClassObject(const cptf::IID& csid, const cptf::IID& iid, void** rntObj);

	};

	template<typename T>
	bool CptfDllModuleT<T>::dllGetClassObject(const cptf::IID& csid
										, const cptf::IID& iid
										, void** rntObj)
	{
		return cptfModuleGetClassObject(static_cast<T*>(this), csid, iid, rntObj);
	}
}
}

#endif