#ifndef CORE_SERVICE_CPTFBASE_H
#define CORE_SERVICE_CPTFBASE_H
#include "TypeDefine.h"
#include "AutoObject.h"
#include "StdLibInclude.h"

namespace cptf{
namespace core{

	struct CptfServiceEntities 
	{
		AutoObjectEntry** autoObjMapFirst_;
		AutoObjectEntry** autoObjMapLast_;
	};

	typedef shared_ptr<CptfServiceEntities>  CptfServiceEntitiesPtr;


	inline bool CptfModuleGetClassObject(const CptfServiceEntities* cpfgModel
										, const CPTF_IID& iid
										, void** rtnObj)
	{
		bool rtn(false);
		assert(cpfgModel);
		for (AutoObjectEntry** entity = cpfgModel->autoObjMapFirst_
			; entity != cpfgModel->autoObjMapLast_; ++entity)
		{
			AutoObjectEntry* obj = *entity;
			if (obj == NULL) continue;
			if (obj->crateFunc != NULL && iid == obj->iid){
				rtn  = obj->crateFunc(iid, rtnObj);
			}
		}

		return rtn;
	}

}
}

#endif