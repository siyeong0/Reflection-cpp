#pragma once
#include "Factory.h"

#include "SuperClassDeduction.hpp"
#include "TypeInfo.hpp"
#include "TypeInfoInitializer.hpp"

#include "Property.hpp"
#include "PropertyHandler.hpp"
#include "PropertyInitializer.hpp"
#include "PropertyRegister.hpp"

#include "Macro.h"

// custom dynamic_cast
template <typename PtrTo, typename PtrFrom>
PtrTo DynamicCast(PtrFrom ptr)
{
	static_assert(std::is_pointer<PtrTo>::value);
	static_assert(std::is_pointer<PtrFrom>::value);
	using ToValueType = std::remove_pointer<PtrTo>::type;
	return ptr && ptr->GetTypeInfo().IsChildOf<ToValueType>() ? reinterpret_cast<PtrTo>(ptr) : nullptr;
}