#ifndef CORE_SERVICE_CPTFSERVICEMODEL_H
#define CORE_SERVICE_CPTFSERVICEMODEL_H
#include "IService.h"
#include "../utils/ApplicationPath.h"
#include "../StringDefine.h"

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
		return rtn;
	}
}
}



#endif