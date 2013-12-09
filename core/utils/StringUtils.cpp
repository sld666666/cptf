#include "StringUtils.h"

namespace cptf{
namespace core{

	string StringUtils::wstrToStr(const wstring& wstr)
	{
		return std::string(wstr.begin(), wstr.end());
	}
}
}

