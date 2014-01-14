#ifndef CORE_SERVICE_SERVICECONFIGS_H
#define CORE_SERVICE_SERVICECONFIGS_H
#include "StdLibInclude.h"
#include "StringDefine.h"
#include "service/ServiceConfig.h"
#include "utils/ApplicationPath.h"

namespace cptf{
namespace core{

	class CPTF_EXPORT ServiceConfigs 
	{
	public:
		ServiceConfigs(void);
		~ServiceConfigs(void);
	public:
		wstring		findBundlelName(const wstring& csid);
		wstring		getIId(const wstring& csid);
		vector<wstring> getCsids(const wstring& iid);
	private:
		bool	init();
	private:
		list<ServiceConfigPtr> serviceConfigs_;
	};

	typedef shared_ptr<ServiceConfigs> ServiceConfigsPtr;
}
}
#endif