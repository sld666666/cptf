#ifndef CORE_SERVICE_DispatchImpl_H
#define CORE_SERVICE_DispatchImpl_H

//impl 表示具体实现着
template <typename T>
class DispatchImpl : public T{

public:
	DispatchImpl(){}
	~DispatchImpl(){}
};

#endif