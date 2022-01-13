#pragma once
#include <Bite/Core/Symbols.h>
namespace Bite
{
	/// <summary>
	/// Data volume for project versioning
	/// </summary>
	struct BITE_API ProjectVersion
	{
		/// <summary>
		/// Major index of the version
		/// </summary>
		unsigned int Major;

		/// <summary>
		/// Minor index of the version
		/// </summary>
		unsigned int Minor;
	};
}