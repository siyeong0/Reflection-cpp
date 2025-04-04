#pragma once
#include <concepts>

namespace refl
{
	// forward declaration
	class TypeInfo;

	template <typename T> // (T::Super�� ����) and (T::Super�� voidŸ���� �ƴ�)
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