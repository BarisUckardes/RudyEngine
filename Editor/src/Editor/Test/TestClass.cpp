#include "TestClass.h"
GENERATE_REFLECTABLE_TYPE(TestClass,typeof(int));
GENERATE_TYPE_FIELD(TestClass, a,uint,Rudy::ReflectionBindingFlags_Public & Rudy::ReflectionBindingFlags_Instance);
GENERATE_TYPE_FIELD(TestClass, s_Static, uint, Rudy::ReflectionBindingFlags_Static | Rudy::ReflectionBindingFlags_Public | Rudy::ReflectionBindingFlags_Instance);
