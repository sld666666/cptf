#ifndef CORE_UTILS_APPLICATIONPATH_H
#define CORE_UTILS_APPLICATIONPATH_H
#include "StdLibInclude.h"
#include "TypeDefine.h"
#include "OS.h"
#include "StringUtils.h"
#include<stdio.h>
#include<direct.h>

// #include <boost/filesystem.hpp>
// #include <boost/filesystem/operations.hpp>
namespace cptf{
namespace core{
	template <typename Os = Windows>
	class ApplicaitonPath{
	public:
		static wstring		getCurAppPath();
		static wstring		getDirSeparator();
	};

	template <typename Os>
	wstring ApplicaitonPath<Os>::getCurAppPath()
	{
		const int MAXPATH = 2000;
		char buffer[MAXPATH];
		_getcwd(buffer, MAXPATH);

		return  StringUtils<>::strToWstr(string(buffer));
	}

	template <typename Os>
	wstring ApplicaitonPath<Os>::getDirSeparator()
	{
		// 	boost::filesystem::wpath slash(L"/");
		// 	return slash.make_preferred().native();
		return L"/";
	}
}
}
#endif