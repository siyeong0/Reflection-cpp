#pragma once
#include "../TypeInfo/MAKE_TYPE_INFO.h"
#include "../TypeInfo/TypeInfo.hpp"

class PropertyHandlerBase
{
	MAKE_TYPE_INFO(PropertyHandlerBase);
public:
	virtual ~PropertyHandlerBase() = default;
};

template <typename T>
class IPropertyHandler : public PropertyHandlerBase
{
	MAKE_TYPE_INFO(IPropertyHandler);
public:
	virtual T& Get(void* object) const = 0;
	virtual void Set(void* object, const T& value) const = 0;
};

template <typename TClass, typename T>
class PropertyHandler : public IPropertyHandler<T>
{
	MAKE_TYPE_INFO(PropertyHandler);
	using MemberPtrType = T TClass::*;
public:
	virtual T& Get(void* object) const override
	{
		return static_cast<TClass*>(object)->*mPtr;
	}

	virtual void Set(void* object, const T& value) const override
	{
		static_cast<TClass*>(object)->*mPtr = value;
	}

	explicit PropertyHandler(MemberPtrType ptr)
		: mPtr(ptr) 
	{
	}

private:
	MemberPtrType mPtr;
};