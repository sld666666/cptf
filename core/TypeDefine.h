#ifndef CORE_TYPEDEFINE_H
#define CORE_TYPEDEFINE_H

#include "StdLibInclude.h"

namespace cptf{

	#define struct interface

	#define const shared_ptr<boost::uuids::uuid> IID

	inline  IID GENERATE_IID(const std::wstring& str){
		using boost::uuids::uuid;
		shared_ptr<uuid> rtnIID(new uuid(boost::uuids::string_generator(str.c_str())));
		return rtnIID;
	} 	
}

#endif