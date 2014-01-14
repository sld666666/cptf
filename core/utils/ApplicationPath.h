#ifndef CORE_UTILS_APPLICATIONPATH_H
#define CORE_UTILS_APPLICATIONPATH_H
#include "StdLibInclude.h"
#include "TypeDefine.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

class CPTF_EXPORT ApplicaitonPath{
public:
	static wstring		getCurAppPath();
	static wstring		getDirSeparator();
};

#endif