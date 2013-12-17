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
	#define interfacecptf		struct 
	typedef wstring				IID;

	typedef	unsigned long		ulong;
}

#endif