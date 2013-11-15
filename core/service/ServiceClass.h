#ifndef CORE_SERVICE_SERVICECLASS_H
#define CORE_SERVICE_SERVICECLASS_H

typename<class T>
class ServiceClass{
public:
	ServiceClass(){}
	~ServiceClass(){}

public:
	template <class Q>
	static bool CreateInstance(Q*p)
	{
		return T::CreatorClass::createInstance(Q*p);
	}
};

#endif