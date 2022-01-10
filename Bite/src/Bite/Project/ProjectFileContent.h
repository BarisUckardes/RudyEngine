#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
namespace Bite
{
	/// <summary>
	/// Data volume for project file loading/writing
	/// </summary>
	struct BITE_API ProjectFileContent
	{
		ProjectFileContent() = default;
		~ProjectFileContent() = default;

		/// <summary>
		/// The name of the project.(max 20 chars)
		/// </summary>
		char Name[20];

		/// <summary>
		/// The major version
		/// </summary>
		unsigned int VersionMajor;

		/// <summary>
		/// The minor version
		/// </summary>
		unsigned int VersionMinor;

		/// <summary>
		/// The unique id of this project
		/// </summary>
		Rudy::Guid ProjectID;

		/// <summary>
		/// The id of the last world
		/// </summary>
		Rudy::Guid WorldID;
	};
}