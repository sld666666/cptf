#ifndef CORE_UTILS_APPLICATIONPATH_H
#define CORE_UTILS_APPLICATIONPATH_H
#include "../StdLibInclude.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

class ApplicaitonPath{
public:
	static wstring		getCurAppPath();
	static wstring		getDirSeparator();
};

wstring ApplicaitonPath::getCurAppPath()
{
	wstring curPath = boost::filesystem::current_path<boost::filesystem::wpath>().string();
	return curPath;
}

wstring ApplicaitonPath::getDirSeparator()
{
// 	boost::filesystem::wpath slash(L"/");
// 	return slash.make_preferred().native();
	return L"/";
}
#endif