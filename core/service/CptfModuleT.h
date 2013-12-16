#ifndef CORE_SERVICE_CPTFMODULET_H
#define CORE_SERVICE_CPTFMODULET_H
#include "StdLibInclude.h"
#include "CpftBase.h"

namespace cptf{
namespace core{

	template <typename T>
	class CptfModuleT : public CptfServiceEntities{
	public:
		CptfModuleT()
		{
			autoObjMapFirst_ = &g_objEntryFirst + 1;
			autoObjMapLast_ = &g_objEntryLast;
		}
		~CptfModuleT(){}

	public:
		void	initLibId(const wstring& libId);
		bool	getClassObject(const CPTF_IID& csid, const CPTF_IID& iid, void** rntObj);
	private:
		wstring		libId_;
	};


	template<typename T>
	void CptfModuleT<T>::initLibId(const wstring& libId)
	{
		libId_ = libId;
	}

	template<typename T>
	bool CptfModuleT<T>::getClassObject(const CPTF_IID& csid
										, const CPTF_IID& iid
										, void** rntObj)
	{
		return CptfModuleGetClassObject(this, csid, iid, rntObj); 
	}
}
}

#endif