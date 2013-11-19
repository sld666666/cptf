#ifndef CORE_TYPEDEFINE_H
#define CORE_TYPEDEFINE_H

#include "StdLibInclude.h"

namespace cptf{

	#define interfacecptf struct 

 	typedef shared_ptr<uuid> IID;

	inline  IID GENERATEIID(const std::wstring& str){
		boost::uuids::string_generator gen;
		IID rtnIID(new uuid(gen(str)));
		return rtnIID;
	} 	
}

#endif