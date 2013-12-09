#ifndef CORE_SERVICE_AUTOOBJECT_H
#define CORE_SERVICE_AUTOOBJECT_H
#include "TypeDefine.h"

typedef bool (WINAPI CREATORFUNC)(cptf::CPTF_IID, void**);

struct AutoObjectEntry
{
	const cptf::CPTF_IID	iid;
	CREATORFUNC* crateFunc;

};

#pragma section("CPTF$__a", read, shared)
#pragma section("CPTF$__z", read, shared)
#pragma section("CPTF$__m", read, shared)
extern "C"
{
	__declspec(selectany) __declspec(allocate("CPTF$__a")) AutoObjectEntry* g_objEntryFirst = NULL;
	__declspec(selectany) __declspec(allocate("CPTF$__z")) AutoObjectEntry* g_objEntryLast = NULL;
}

#define _CPTF_DECL_ALLOCATE_SECTION_M __declspec(allocate("CPTF$__m"))

#if !defined(_M_IA64)
#pragma comment(linker, "/merge:CPTF=.rdata")
#endif

#if defined(_M_IX86)
#define CPTF_OBJECT_ENTRY_PRAGMA(class) __pragma(comment(linker, "/include:___pobjMap_" #class));
#elif defined(_M_IA64)
#define CPTF_OBJECT_ENTRY_PRAGMA(class) __pragma(comment(linker, "/include:__pobjMap_" #class));
#elif defined(_M_AMD64)
#define CPTF_OBJECT_ENTRY_PRAGMA(class) __pragma(comment(linker, "/include:__pobjMap_" #class));
#else
#error Unknown Platform. define CPTF_OBJECT_ENTRY_PRAGMA
#endif

#define CPTF_OBJECT_ENTRY_AUTO(clsid, class) \
	__declspec(selectany) AutoObjectEntry __objMap_##class = {clsid, class::creatorClass_::createInstance}; \
	extern "C" __declspec(allocate("CPTF$__m")) __declspec(selectany) AutoObjectEntry* const __pobjMap_##class = &__objMap_##class; \
	CPTF_OBJECT_ENTRY_PRAGMA(class)




#endif // AutoObject_h