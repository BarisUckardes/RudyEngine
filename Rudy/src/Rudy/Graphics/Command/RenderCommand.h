#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Base class for all render commands
	/// </summary>
	class RUDY_API RenderCommand
	{
	public:
		RenderCommand() = default;
		~RenderCommand() = default;

		/// <summary>
		/// Executes the render command implementation
		/// </summary>
		virtual void Execute() = 0;
	};
}