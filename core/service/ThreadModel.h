#ifndef CORE_SERVICE_THREAD_MODEL_H
#define CORE_SERVICE_THREAD_MODEL_H
#include "TypeDefine.h"

namespace cptf{
namespace core{
	class SingleThreadModel
	{
	public:
		SingleThreadModel(){}
		~SingleThreadModel();

		static ulong WINAPI increment(ulong* p)  {return ++(*p);}
		static ulong WINAPI decrement(ulong* p)  {return --(*p);}
	};
}
}

#endif