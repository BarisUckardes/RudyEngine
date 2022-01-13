#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>

namespace Bite
{
	/// <summary>
	/// Data volume for project properties
	/// </summary>
	struct BITE_API ProjectProperties
	{
		/// <summary>
		/// Name of the project
		/// </summary>
		Rudy::String Name;

		/// <summary>
		/// Major version of the version
		/// </summary>
		unsigned int MajorVersion;

		/// <summary>
		/// Minor version of the project
		/// </summary>
		unsigned int MinorVersion;

		/// <summary>
		/// Unique id of the project
		/// </summary>
		Rudy::Guid ID;
	};

}