#ifndef CORE_SERVICE_SERVICEOBJECT_H
#define CORE_SERVICE_SERVICEOBJECT_H

#include "../TypeDefine.h"

template <typename Base>
class ServiceObject : public Base{
public:
	ulong addRef();
	ulong release();

	void QueryInterface();


};
class 