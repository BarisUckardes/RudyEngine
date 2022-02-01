#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Reflection/Base/ReflectionBase.h>
#include <Rudy/Memory/Array.h>

namespace Rudy
{
	/// <summary>
	/// Represents the collection of the reflection data per dll
	/// </summary>
	class RUDY_API ReflectionAssembly
	{
	public:
		ReflectionAssembly();
		~ReflectionAssembly() = default;

		/// <summary>
		/// Registers anew raw type
		/// </summary>
		/// <param name="type"></param>
		void RegisterRawType(ReflectionType* type);

		/// <summary>
		/// Regsters anew type
		/// </summary>
		/// <param name="type"></param>
		void RegisterType(ReflectionType* type);

	private:
		Array<ReflectionType*> m_Types;
		Array<ReflectionType*> m_RawTypes;
	};


}