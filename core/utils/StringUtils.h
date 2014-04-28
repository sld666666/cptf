#ifndef CORE_UTILS_STRINGUTILS_H
#define CORE_UTILS_STRINGUTILS_H
#include <string>
#include "TypeDefine.h"
using std::string;
using std::wstring;

namespace cptf{
namespace core{

	template<int inst = 0>
	class StringUtils{
	public:
		static string wstrToStr(const wstring& wstr);

		static wstring strToWstr(const string& str);

		static vector<wstring> splitLast(const wstring& wstr, const wstring& stuff);
	};

	template<int inst>
	string StringUtils<inst>::wstrToStr(const wstring& wstr)
	{
		return std::string(wstr.begin(), wstr.end());
	}

	template<int inst>
	wstring StringUtils<inst>::strToWstr(const string& str)
	{
		return std::wstring(str.begin(), str.end());
	}

	template<int inst>
	vector<wstring> StringUtils<inst>::splitLast(const wstring& wstr
												, const wstring& stuff)
	{
		vector<wstring> strList;
		int pos = wstr.rfind(stuff);
		if (-1 != pos){
			strList.push_back(wstr.substr(0,pos));
			strList.push_back(wstr.substr(pos+1, wstr.length()));

		}
		strList.push_back(wstr);
		return strList;
	}
}
}


#endif