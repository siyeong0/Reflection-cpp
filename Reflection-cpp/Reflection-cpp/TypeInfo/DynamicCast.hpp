#pragma once
#include <type_traits>

#include "TypeInfo.hpp"

// custom dynamic_cast
template <typename PtrTo, typename PtrFrom>
PtrTo DynamicCast(PtrFrom ptr)
{
	static_assert(std::is_pointer<PtrTo>::value);
	static_assert(std::is_pointer<PtrFrom>::value);
	using ToValueType = std::remove_pointer<PtrTo>::type;
	return ptr && ptr->GetTypeInfo().IsChildOf<ToValueType>() ? reinterpret_cast<PtrTo>(ptr) : nullptr;
}
