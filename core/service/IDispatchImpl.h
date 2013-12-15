#ifndef CORE_SERVICE_IDISPATCHIMPL_H
#define CORE_SERVICE_IDISPATCHIMPL_H

//impl 表示具体实现着
namespace cptf{
namespace core{
	template <typename T>
	class IDispatchImpl : public T{
	public:
		IDispatchImpl(){}
		~IDispatchImpl(){}
	};
}
}
#endif