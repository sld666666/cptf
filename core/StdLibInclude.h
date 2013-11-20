#ifndef CORE_SERVICE_STDLIBINCLUDE_H
#define CORE_SERVICE_STDLIBINCLUDE_H
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/shared_ptr.hpp>
#include <boost/cstdint.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using boost::shared_ptr;
using boost::uuids::uuid;
using boost::function;
using boost::bind;

#include <string>
#include <list>
#include <vector>
#include <algorithm>

using std::wstring;
using std::list;
using std::vector;
#endif