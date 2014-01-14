#ifndef CORE_UTILS_CASTSUTILS_H
#define CORE_UTILS_CASTSUTILS_H
#include "StdLibInclude.h"

class CastUtils
{
public:
	template<typename Base, typename Child>
	static Child* parentToChild(Base* base)
	{
		Child* child = static_cast<Child*>(base);
		return child;
	}

	template<typename Base, typename Child>
	static list<Child*> parentsToChildren(const list<Base*>& parents)
	{
		static list<Child*> children;
		transform(parents.begin(), parents.end(), back_inserter(children)
			, bind(&CastUtils::parentToChild<Base, Child>, _1));

		return children;
	}
};
#endif