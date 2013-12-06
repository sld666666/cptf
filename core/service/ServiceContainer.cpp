#include "ServiceContainer.h"
#include "utils/ApplicationPath.h"
#include "service/ServiceConfig.h"
#include "StringDefine.h"

namespace cptf{
namespace core{

	ServiceContainer::ServiceContainer(void)
	{
		init();
	}

	ServiceContainer::~ServiceContainer(void)
	{
	}

	bool ServiceContainer::init()
	{
		bool rtn(false);
		wstring curAppPath = ApplicaitonPath::getCurAppPath();
		wstring serviceXmlPath = curAppPath+ ApplicaitonPath::getDirSeparator()
			+ SERVICE_XML_NAME;

		ServiceConfig config;
		config.read(serviceXmlPath);
		return rtn;
	}
}
}


