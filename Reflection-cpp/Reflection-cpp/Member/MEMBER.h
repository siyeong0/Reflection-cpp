#pragma once
#include "Property.hpp"
#include "PropertyHandler.hpp"
#include "PropertyInitializer.hpp"
#include "PropertyRegister.hpp"

#define MEMBER(NAME)	\
inline static struct _registProperty##NAME	\
{	\
	_registProperty##NAME()	\
	{	\
		static PropertyRegister	\
			<ThisType, decltype(m##NAME), decltype(&ThisType::m##NAME), &ThisType::m##NAME>	\
			propertyRegisterNAME(#NAME, ThisType::StaticTypeInfo());	\
	}	\
} registName;	