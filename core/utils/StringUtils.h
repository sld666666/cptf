#ifndef CORE_UTILS_STRINGUTILS_H
#define CORE_UTILS_STRINGUTILS_H
#include <string>
#include "TypeDefine.h"
using std::string;
using std::wstring;

namespace cptf{
namespace core{

	class CPTF_EXPORT StringUtils{
	public:
		static string wstrToStr(const wstring& wstr);
	};
}
}


#endif