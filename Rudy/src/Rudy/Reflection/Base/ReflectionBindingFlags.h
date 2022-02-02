#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Flags for reflection bind properties
	/// </summary>
	enum RUDY_API ReflectionBindingFlags 
	{
		ReflectionBindingFlags_None = 0,

		/// <summary>
		/// Represents a public bindable
		/// </summary>
		ReflectionBindingFlags_Public = 1 << 0,

		/// <summary>
		/// Represents a private bindable
		/// </summary>
		ReflectionBindingFlags_Private = 1 << 1,

		/// <summary>
		/// Represents a protected bindable
		/// </summary>
		ReflectionBindingFlags_Protected = 1 << 2,

		/// <summary>
		/// Represents a member bindable
		/// </summary>
		ReflectionBindingFlags_Instance = 1 << 3,

		/// <summary>
		/// Represents a static bindable
		/// </summary>
		ReflectionBindingFlags_Static = 1 << 4,

		/// <summary>
		/// Represents a function
		/// </summary>
		ReflectionBindingFlags_Function = 1 << 5,

		/// <summary>
		/// Represents a read-only bindable
		/// </summary>
		ReflectionBindingFlags_Const = 1 << 6,

		/// <summary>
		/// Represents a reference bindable
		/// </summary>
		ReflectionBindingFlags_Reference = 1 << 7,

		/// <summary>
		/// Represents a pointer bindable
		/// </summary>
		ReflectionBindingFlags_Pointer = 1 << 8,

		/// <summary>
		/// Represents a value bindable
		/// </summary>
		ReflectionBindingFlags_Value = 1 << 9,

		/// <summary>
		/// Represents a virtual bindable
		/// </summary>
		ReflectionBindingFlags_Virtual = 1 << 10,

		/// <summary>
		/// Represents a pure virtual bindable
		/// </summary>
		ReflectionBindingFlags_PureVirtual = 1 << 11
	};
}