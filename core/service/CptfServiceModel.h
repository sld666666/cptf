#ifndef CORE_SERVICE_CPTFSERVICEMODEL_H
#define CORE_SERVICE_CPTFSERVICEMODEL_H
#include "IService.h"
#include "../utils/ApplicationPath.h"
#include "../StringDefine.h"
#include "utils/MetaObject.h"
#include "service/ServiceConfig.h"

namespace cptf{
namespace core{
	class CptfServiceModel{
	public:
		CptfServiceModel(){

		}

		~CptfServiceModel(){

		}

	public:
		bool	init();

	private:
		list<IService*> services_;
	};

	bool CptfServiceModel::init()
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



#endif