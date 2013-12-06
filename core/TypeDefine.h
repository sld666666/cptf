#ifndef CORE_TYPEDEFINE_H
#define CORE_TYPEDEFINE_H
#pragma warning(disable:4251) 
#include "StdLibInclude.h"

#ifdef CPTF_CORE_LIB
# define CPTF_EXPORT _declspec(dllexport)
#else
# define CPTF_EXPORT _declspec(dllimport)
#endif

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