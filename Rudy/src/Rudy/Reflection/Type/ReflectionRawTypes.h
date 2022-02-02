#pragma once
#include <Rudy/Reflection/Type/ReflectionType.h>

#define GENERATE_RAW_REFLECTION_ACCESSOR(type)\
	class RUDY_API GET_RAW_NAME(type)_reflection_type_acccessor_\
	{\
	private:\
		static Rudy::ReflectionType* s_OwnerType;\
	public:\
		static Rudy::ReflectionType* GetOwnerType() { return s_OwnerType; }\
	}


GENERATE_RAW_REFLECTION_ACCESSOR(int);
GENERATE_RAW_REFLECTION_ACCESSOR(float);
GENERATE_RAW_REFLECTION_ACCESSOR(short);
GENERATE_RAW_REFLECTION_ACCESSOR(double);
GENERATE_RAW_REFLECTION_ACCESSOR(char);
GENERATE_RAW_REFLECTION_ACCESSOR(bool);