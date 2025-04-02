#pragma once
#include "PropertyHandler.hpp"

struct PropertyInitializer
{
	const char* Name;
	TypeInfo& Type;
	PropertyHandlerBase& Handler;
};