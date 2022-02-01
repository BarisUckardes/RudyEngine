#pragma once
#include <Rudy/Reflection/Object/ReflectableObject.h>
class TestClass : public Rudy::ReflectableObject
{
public:
	GENERATE_REFLECTABLE_OBJECT(TestClass);
};

