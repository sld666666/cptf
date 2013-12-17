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

		serviceConfigs_ = ServiceConfig().read(serviceXmlPath);
		return rtn;
	}

	wstring	ServiceContainer::findBundlelName(const wstring& iid)
	{
		wstring bundelName;
		list<ServiceConfigPtr>::iterator iter = find_if(serviceConfigs_.begin()
			, serviceConfigs_.end(), bind(&ServiceConfigFunctors::matchedById, _1, iid));
		bundelName = (iter != serviceConfigs_.end())?(*iter)->bundle():L"";
		return bundelName;
	}
}
}


