#pragma once
#include <Rudy/Reflection/Object/ReflectableObject.h>
#include <Rudy/Reflection/Field/ReflectionTypeField.h>

class TestSubClass : public Rudy::ReflectableObject
{
public:
	GENERATE_REFLECTABLE_OBJECT(TestSubClass);
	TestSubClass(const Rudy::String& name);
	~TestSubClass() = default;

	Rudy::String GetName() const { return m_Name; }
private:
	Rudy::String m_Name;
};
GENERATE_REFLECTION_ACCESSOR(TestSubClass);



