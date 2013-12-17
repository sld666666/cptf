/** 
* @file         WinDllCreator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef CORE_SERVICE_WIN_DLL_CREATOR_H
#define CORE_SERVICE_WIN_DLL_CREATOR_H
#include <windows.h>
#include "StdLibInclude.h"
#include "utils/StringUtils.h"

typedef bool (DLLPROC)(cptf::IID, cptf::IID, void**);

namespace cptf{
namespace core{

	class WinDllCreator
	{
	public:
		static bool createObjectFromDll(const wstring& bundleName
										, const cptf::IID& csid
										, const cptf::IID& iid
										, void** rntObj)
		{
			DLLPROC* pFunc = NULL;
			vector<wstring> splits = StringUtils::splitLast(bundleName, L"\\");
			if (splits.size()<2)return false;

			wstring path = splits[0];
			wstring name = splits[1];

			HMODULE hMod = GetModuleHandle(name.c_str());
			if (0 == hMod){
				try{
					hMod = LoadLibrary( bundleName.c_str() );
				}
				catch( ... ){
					hMod = NULL;
					return NULL;
				}
			}

			try{
				pFunc = ( DLLPROC* ) GetProcAddress(hMod, "dllGetClassObject"); 
			}
			catch(...)
			{
				pFunc = NULL;
			}

			if ( pFunc == NULL ){
				return NULL;
			}	
			return ((*pFunc)(csid, iid, rntObj));
		}
	};
}
}


#endif