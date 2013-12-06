#ifndef CORE_UTILS_IXMLPARSER_H
#define CORE_UTILS_IXMLPARSER_H
#include "utils/StringUtils.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using boost::property_tree::ptree;
using namespace boost::property_tree;
namespace cptf{
namespace core{
	template<class T>

	class IXmlParser{
	public:
		IXmlParser(){};
		~IXmlParser(){};
	public:
		list<shared_ptr<T>>	read(const wstring& filePath);
		bool	write(const wstring& filePath);
	protected:
		virtual wstring getNodeRelativePath() = 0;
		virtual wstring getNodeName() = 0;
	};


	template<class T>
	list<shared_ptr<T>> IXmlParser<T>::read(const wstring& filePath)
	{
		list<shared_ptr<T>> rtnList;

		wptree tree;
		string path = StringUtils::wstrToStr(filePath);
		xml_parser::read_xml(path, tree);
		foreach(wptree::value_type& val, tree.get_child(getNodeRelativePath())){
			shared_ptr<T> obj(new T());
			wptree child = val.second;
			wstring path = getNodeRelativePath()+L"."+getNodeName();
			foreach(wptree::value_type& childval, tree.get_child(path)){
				wstring first = val.first;
				wstring secode = val.second.data();
				obj->setProperty(first, secode);
			}
			rtnList.push_back(obj);
		}

		return rtnList;
	}

	template<class T>
	bool IXmlParser<T>::write(const wstring& filePath)
	{
		bool rtn(false);

		return rtn;
	}
}
}




#endif