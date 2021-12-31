#pragma once
#include <Rudy/Memory/String.h>


namespace Rudy
{
	/// <summary>
	/// A reflection type
	/// </summary>
	class RUDY_API ReflectionType
	{
	public:
		ReflectionType(const String& typeName,unsigned int typeSize);
		~ReflectionType() = default;

	private:
		String m_TypeName;
		unsigned int m_TypeSize;
	};
}