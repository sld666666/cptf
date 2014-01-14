#ifndef CORE_SERVICE_BUNDLECONFIG_H
#define CORE_SERVICE_BUNDLECONFIG_H

#include "utils/MetaObject.h"
#include "utils/IXmlParser.h"

namespace cptf{
namespace core{

	class BundleConfig : MetaObject<BundleConfig>
		, public IXmlParser<BundleConfig>
	{
		BundleConfig(){
			INVOKE(L"name", BundleConfig::name, BundleConfig::setName);
			INVOKE(L"description", BundleConfig::description, BundleConfig::setDescription);
			INVOKE(L"iid", BundleConfig::iid, BundleConfig::setIid);

		}
		~BundleConfig(){}

	public:
		wstring iid(){return iid_;}
		void setIid(const wstring& val){iid_ = val;}

		wstring name(){return name_;}
		void setName(const wstring& val){name_ = val;}

	protected:
		virtual wstring getNodeRelativePath(){return L"repository.bundles";}
	private:
		wstring iid_;
		wstring name_;
	};

	typedef shared_ptr<BundleConfig>	BundleConfigPtr;

}
}
#endif