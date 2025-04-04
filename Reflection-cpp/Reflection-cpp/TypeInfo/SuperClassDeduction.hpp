#pragma once
#include <type_traits>

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
