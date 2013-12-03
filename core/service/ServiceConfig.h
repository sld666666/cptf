#ifndef CORE_SERVICE_SERVICECONFIG_H
#define CORE_SERVICE_SERVICECONFIG_H
#include "utils/MetaObject.h"
#include "utils/IXmlParser.h"

namespace cptf{
namespace core{
	class ServiceConfig : public MetaObject<ServiceConfig>
		,	public IXmlParser<ServiceConfig>{
	public:
		ServiceConfig(){}
		~ServiceConfig(){}

	public:
		virtual

	protected:
		virtual wstring getNodeRelativePath(){return L"repository.service";};

	};

	vector<MetaDataPrivatePtr>::ServiceConfig metaDatas_(boost::assign::list_of
		(shared_ptr<MetaDataPrivatePtr>(new MetaDataPrivate(propertyName, setFunc, getFunc))
		)
}
}


#endif