#ifndef CORE_UTILS_STRINGUTILS_H
#define CORE_UTILS_STRINGUTILS_H
#include <string>
using std::string;
using std::wstring;

namespace cptf{
namespace core{

	class StringUtils{
	public:
		static string wstrToStr(const wstring& wstr);
	};


	string StringUtils::wstrToStr(const wstring& wstr)
	{
		return std::string(wstr.begin(), wstr.end());
	}
}
}


#endif