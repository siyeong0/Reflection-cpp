#pragma once
#include <memory>
#include <unordered_map>

#define BUILD_FACTORY(BASECLASS)	\
class BASECLASS ## Factory	\
{	\
public:	\
	using CreatorFunc = std::unique_ptr<BASECLASS>(*)();	\
\
	static std::unique_ptr<BASECLASS> Create(const char* name)	\
	{	\
		auto it = getRegistry().find(name);	\
		if (it != getRegistry().end())	\
		{	\
			return it->second();	\
		}	\
		return nullptr;	\
	}	\
\
	static void _registerClass(const char* name, CreatorFunc func)	\
	{	\
		getRegistry()[name] = func;	\
	}	\
private:	\
	static std::unordered_map<std::string, CreatorFunc>& getRegistry()	\
	{	\
		static std::unordered_map<std::string, CreatorFunc> registry;	\
		return registry;	\
	}	\
};	

#define FACTORY_REGISTER(BASECLASS, CLASSNAME) \
inline static bool _registered_##CLASSNAME = []	\
	{	\
		BASECLASS ## Factory::_registerClass(#CLASSNAME, []()->std::unique_ptr<BASECLASS> { return std::make_unique<CLASSNAME>(); }); \
		return true; \
	}();	