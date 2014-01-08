#ifndef CPTF_UI_DLLMAIN_H
#define CPTF_UI_DLLMAIN_H

#include "service/CptfDllModuleT.h"
using namespace cptf::core;

class CAppWindowModule : public CptfDllModuleT<CAppWindowModule>
{
public :
};

extern class CAppWindowModule g_module;

#endif