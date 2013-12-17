#include "StringUtils.h"

namespace cptf{
namespace core{

	string StringUtils::wstrToStr(const wstring& wstr)
	{
		return std::string(wstr.begin(), wstr.end());
	}

	vector<wstring> StringUtils::splitLast(const wstring& wstr, const wstring& stuff)
	{
		vector<wstring> strList;
		int pos = wstr.rfind(stuff);
		if (-1 != pos){
			strList.push_back(wstr.substr(0,pos));
			strList.push_back(wstr.substr(pos+1, wstr.length()));

		}
		return strList;
	}
}
}

