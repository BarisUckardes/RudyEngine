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

		virtual void Execute() = 0;
	};
}