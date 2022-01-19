#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
namespace Rudy
{
	/// <summary>
	/// API agnostic imgui implementation
	/// </summary>
	class RUDY_API ImGuiGraphicsAPIImplementation
	{
	public:
		// <summary>
		/// Creates imgui api
		/// </summary>
		static void CreateAPICore(GraphicsAPIType apiType);

		/// <summary>
		/// Creates anew api sessions
		/// </summary>
		static void NewFrameCore(GraphicsAPIType apiType);

		/// <summary>
		/// Renders the draw data
		/// </summary>
		static void RenderDrawDataCore(GraphicsAPIType apiType);
	};
}
