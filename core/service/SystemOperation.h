/** 
* @file         SystemOperation.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef CORE_SERVICE_SYSTEMOERATION_H
#define CORE_SERVICE_SYSTEMOERATION_H

namespace cptf{
namespace core{

	template<class creation>
	class SystemOperation
	{
	public:
		static bool createObjectFromDll( const wstring& bundleName
										, const cptf::IID& csid
										, const cptf::IID& iid
										, void** rntObj)
		{
			return creation::createObjectFromDll(bundleName, csid, iid, rntObj);
		}
	};

}
}


#endif