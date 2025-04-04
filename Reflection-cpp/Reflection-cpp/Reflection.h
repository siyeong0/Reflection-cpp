#pragma once
#include "Factory.h"

#include "TypeInfo/SuperClassDeduction.hpp"
#include "TypeInfo/TypeInfo.hpp"
#include "TypeInfo/TypeInfoInitializer.hpp"

#include "Property/Property.hpp"
#include "Property/PropertyHandler.hpp"
#include "Property/PropertyInitializer.hpp"
#include "Property/PropertyRegister.hpp"

#include "Macro.h"

namespace refl
{
	// custom dynamic_cast
	template <typename PtrTo, typename PtrFrom>
	PtrTo DynamicCast(PtrFrom ptr)
	{
		static_assert(std::is_pointer<PtrTo>::value);
		static_assert(std::is_pointer<PtrFrom>::value);
		using ToValueType = std::remove_pointer<PtrTo>::type;
		return ptr && ptr->GetTypeInfo().IsChildOf<ToValueType>() ? reinterpret_cast<PtrTo>(ptr) : nullptr;
	}
}