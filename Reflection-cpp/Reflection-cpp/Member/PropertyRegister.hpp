#pragma once
#include "../TypeInfo/TypeInfo.hpp"
#include "Property.hpp"
#include "PropertyInitializer.hpp"

template <typename TClass, typename T, typename TPtr, TPtr ptr>
class PropertyRegister
{
public:
	PropertyRegister(const char* name, TypeInfo& typeInfo)
	{
		if constexpr (std::is_member_pointer_v<TPtr>)
		{
			static PropertyHandler<TClass, T> handler(ptr);
			static PropertyInitializer initializer = {
				.Name = name,
				.Type = TypeInfo::GetStaticTypeInfo<T>(),
				.Handler = handler
			};
			static Property property(typeInfo, initializer);
		}
		else
		{

		}
	}
};