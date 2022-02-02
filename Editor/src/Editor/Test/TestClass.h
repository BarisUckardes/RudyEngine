#pragma once
#include <Rudy/Reflection/Object/ReflectableObject.h>
#include <Rudy/Reflection/Field/ReflectionTypeField.h>
class TestClass : public Rudy::ReflectableObject
{
public:
	GENERATE_REFLECTABLE_OBJECT(TestClass);

	unsigned int s_Static;
	unsigned int a;
	unsigned int b;
};
GENERATE_REFLECTION_ACCESSOR(TestClass);
