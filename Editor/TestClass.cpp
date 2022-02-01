#include "TestClass.h"
GENERATE_REFLECTABLE_TYPE(TestClass);

void abc()
{
	Rudy::ReflectableObjectDispatcher tipp((Rudy::ReflectableObjectGenerator)&Rudy::ReflectableObjectCreator::CreateReflectableObjectGenerator<TestClass>, TestClass::GetStaticType());
}