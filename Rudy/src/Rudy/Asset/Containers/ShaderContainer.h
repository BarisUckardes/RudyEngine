#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Graphics/Shader/ShaderStage.h>
namespace Rudy
{
	/// <summary>
	/// Data volume for shader write load
	/// </summary>
	struct RUDY_API ShaderContainer
	{
		/// <summary>
		/// Stage of the shader
		/// </summary>
		ShaderStage Stage;

		/// <summary>
		/// Source text of the shader
		/// </summary>
		String SourceText;
	};
}