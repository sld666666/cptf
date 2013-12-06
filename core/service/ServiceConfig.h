#ifndef CORE_SERVICE_SERVICECONFIG_H
#define CORE_SERVICE_SERVICECONFIG_H
#include "utils/MetaObject.h"
#include "utils/IXmlParser.h"

namespace cptf{
namespace core{

	class ServiceConfig : public MetaObject<ServiceConfig>
		,	public IXmlParser<ServiceConfig>{
	public:
		ServiceConfig(){
			INVOKE(L"iid", ServiceConfig::iid, ServiceConfig::setIid);
			INVOKE(L"bundle", ServiceConfig::bundle, ServiceConfig::setBundle);
		}
		~ServiceConfig(){}

	public:
		wstring iid(){return iid_;}
		void setIid(const wstring& val){iid_ = val;}

		wstring bundle(){return bundle_;}
		void setBundle(const wstring& val){bundle_ = val;}

	protected:
		virtual wstring getNodeRelativePath(){return L"repository.services";};
		virtual wstring getNodeName(){return L"service";}
	private:
		wstring iid_;
		wstring bundle_;

	};

// 	vector<MetaDataPrivatePtr> ServiceConfig::metaDatas_(boost::assign::list_of
// 		(MetaDataPrivatePtr(new MetaDataPrivate(L"iid", bind(&ServiceConfig::iid, this)
// 		, bind(&ServiceConfig::setIid, this,_1)))
// 		)
}
}


#endif