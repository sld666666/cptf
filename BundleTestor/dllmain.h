// dllmain.h : 模块类的声明。
#include "service/CptfDllModuleT.h"
using namespace cptf::core;

class CHelloAtlModule : public CptfDllModuleT<CHelloAtlModule>
{
public :
};

extern class CHelloAtlModule g_module;
