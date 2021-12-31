#include "ReflectionType.h"
#include <stdio.h>
namespace Rudy
{
	ReflectionType::ReflectionType(const String& typeName, unsigned int typeSize)
	{
		m_TypeName = typeName;
		m_TypeSize = typeSize;
		printf("New reflectable object: %s\n", *typeName);
	}
}