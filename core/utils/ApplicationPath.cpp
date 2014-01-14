#include "ApplicationPath.h"

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