#pragma once
#include <type_traits>

namespace refl
{
	template <typename T, typename U = void>
	struct SuperClassTypeDeduction
	{
		using Type = void;
	};

	template <typename T>
	struct SuperClassTypeDeduction<T, std::void_t<typename T::ThisType>>
	{
		using Type = T::ThisType;
	};
}