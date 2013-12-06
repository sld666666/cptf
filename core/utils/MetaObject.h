#ifndef CORE_UTILS_METAOBJECT_H
#define CORE_UTILS_METAOBJECT_H
#include "StdLibInclude.h"
#include <boost/assign/list_of.hpp>

namespace cptf{
namespace core{

	typedef function<void(wstring)>	SetFunc;
	typedef function<wstring()> GetFunc;
	struct MetaDataPrivate{
		MetaDataPrivate(const wstring& name, SetFunc setFunc, GetFunc getFunc)
			: name_(name)
			, setFunc_(setFunc)
			, getFunc_(getFunc){

		}

		static bool	nameEqual(const shared_ptr<MetaDataPrivate> metaData, const wstring& name)
		{
			return metaData->name_ == name;
		}


		wstring		name_;
		SetFunc		setFunc_;
		GetFunc		getFunc_;
	};
	
	typedef shared_ptr<MetaDataPrivate>	MetaDataPrivatePtr;

	template<typename T>
	class MetaObject{
	public:
		MetaObject(){}
		~MetaObject(){}
	public:
		void		setProperty(const wstring& name,  const wstring& value);
		wstring		getProperty(const wstring& name);
	protected:
		void		invoke(const wstring& propertyName,GetFunc getFunc,  SetFunc setFunc);
	protected:
		vector<MetaDataPrivatePtr>		metaDatas_;
	};

	template<typename T>
	void MetaObject<T>::setProperty(const wstring& name
						,  const wstring& value)
	{
		vector<MetaDataPrivatePtr>::iterator iter = std::find_if(metaDatas_.begin(), metaDatas_.end()
			, bind(&MetaDataPrivate::nameEqual, _1, name));

		if (iter != metaDatas_.end()){
			(*iter)->setFunc_(value);
		}
	}

	template<typename T>
	wstring	MetaObject<T>::getProperty(const wstring& name)
	{
		wstring rtnValue;
		vector<MetaDataPrivatePtr> iter = std::find_if(metaDatas_.begin(), metaDatas_.end()
			, bind(&MetaDataPrivate::nameEqual, _1, name));
		if ( iter != metaDatas_.end()){
			rtnValue = (*iter)->getFunc_();
		}
		return rtnValue;
	}

	template<typename T>
	void MetaObject<T>::invoke(const wstring& propertyName
							, GetFunc getFunc
							,  SetFunc setFunc)
	{
		metaDatas_.push_back(MetaDataPrivatePtr(new MetaDataPrivate(
			propertyName, setFunc, getFunc)));
	}

	#define  INVOKE(name, setFun, getFun) invoke(name, bind(&setFun, this), bind(&getFun, this,_1))

}
}
#endif