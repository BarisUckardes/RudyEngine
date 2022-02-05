#pragma once
#include "TestSubClass.h"

class TestClass : public TestSubClass
{
public:
	TestClass();
	GENERATE_REFLECTABLE_OBJECT(TestClass);

	unsigned int s_Static;
	unsigned int a;
	unsigned int b;

	void MyReflectionMethod(int a, int b);
};
GENERATE_REFLECTION_ACCESSOR(TestClass);

