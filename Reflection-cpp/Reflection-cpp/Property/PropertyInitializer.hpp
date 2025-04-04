#pragma once
#include "PropertyHandler.hpp"

namespace refl
{
	struct PropertyInitializer
	{
		const char* Name;
		TypeInfo& Type;
		PropertyHandlerBase& Handler;
	};
}