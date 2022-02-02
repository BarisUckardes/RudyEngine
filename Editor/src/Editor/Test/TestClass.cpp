#include "TestClass.h"
#include <Rudy/Reflection/Function/ReflectionFunction.h>

GENERATE_REFLECTABLE_TYPE(TestClass,typeof(int));
GENERATE_TYPE_FIELD(TestClass, a,uint,Rudy::ReflectionBindingFlags_Public & Rudy::ReflectionBindingFlags_Instance);
GENERATE_TYPE_FIELD(TestClass, s_Static, uint, Rudy::ReflectionBindingFlags_Static | Rudy::ReflectionBindingFlags_Public | Rudy::ReflectionBindingFlags_Instance);
GENERATE_MEMBER_FUNCTION(TestClass, MyReflectionMethod, void,0);
GENERATE_MEMBER_FUNCTION_PARAMETER(TestClass,MyReflectionMethod, int,a);
GENERATE_MEMBER_FUNCTION_PARAMETER(TestClass, MyReflectionMethod, int, b);

void TestClass::MyReflectionMethod(int a, int b)
{

}
