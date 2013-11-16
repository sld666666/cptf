#ifndef CORE_SERVICE_SERVICEOBJECT_H
#define CORE_SERVICE_SERVICEOBJECT_H

#include "../TypeDefine.h"

template <typename Base>
class ServiceObject : public Base{
public:
	ulong addRef()
	{
		return internalAddRef();
	}
	ulong release()
	{
		ulong ref = internalReleaseRef();
		if (0 == ref){
			delete this;
			this = NULL;
		}

		return ref;
	}

	void QueryInterface();


};
class 