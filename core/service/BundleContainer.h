#ifndef CORE_SERVICE_BUNDLECONTAINER_H
#define CORE_SERVICE_BUNDLECONTAINER_H

#include "utils/ApplicationPath.h"
#include "service/BundleConfig.h"

namespace cptf{
namespace core{
	class BundleContainer
	{
	public: 
		BundleContainer(){init();}
		~BundleContainer(){}

	public:

	private:
		bool	init();
	private:
		list<BundleConfigPtr> bundleConfigs_;
	};


	bool BundleContainer::init()
	{
		bool rtn(false);
		wstring curAppPath = ApplicaitonPath::getCurAppPath();
		wstring serviceXmlPath = curAppPath+ ApplicaitonPath::getDirSeparator()
			+ BUNDLE_XML_NAME;

		bundleConfigs_ = BundleConfig().read(serviceXmlPath);
		return rtn;
	}
}
}

#endif