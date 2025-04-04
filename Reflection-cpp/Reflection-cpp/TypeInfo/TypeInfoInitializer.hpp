#pragma once
#include <concepts>

namespace refl
{
	// forward declaration
	class TypeInfo;

	template <typename T> // (T::Super가 존재) and (T::Super가 void타입이 아님)
	concept HasSuper = requires { typename T::Super; } && !std::same_as<typename T::Super, void>;

	template <typename T>
	struct TypeInfoInitializer
	{
		const char* Name;
		const TypeInfo* Super;

		TypeInfoInitializer(const char* name)
			: Name(name)
			, Super(nullptr)
		{
			if constexpr (HasSuper<T>)
			{
				Super = &(GetStaticTypeInfo<T::Super>());
			}
		}
	};
}