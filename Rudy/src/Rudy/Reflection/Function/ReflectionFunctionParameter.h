#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include<initializer_list>
namespace Rudy
{
	class ReflectionType;

	/// <summary>
	/// The meta-data for the reflection function parameter
	/// </summary>
	struct RUDY_API ReflectionFunctionParameter
	{
		ReflectionFunctionParameter(const String& name, ReflectionType* type)
		{
			Name = name;
			Type = type;
		}
		ReflectionFunctionParameter() = default;

		/// <summary>
		/// The name of the parameter
		/// </summary>
		String Name;

		/// <summary>
		/// The type of the parameter
		/// </summary>
		ReflectionType* Type;
	};
}