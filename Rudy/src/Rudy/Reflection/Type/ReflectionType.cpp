#include "ReflectionType.h"

namespace Rudy
{
	ReflectionType::ReflectionType(const String& typeName, unsigned int typeSize)
	{
		m_TypeName = typeName;
		m_TypeSize = typeSize;
	}
}