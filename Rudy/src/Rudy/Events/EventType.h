#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Supported event types
	/// </summary>
	enum class RUDY_API EventType
	{
		/// <summary>
		/// The event type is undefined
		/// </summary>
		Undefined = 0,

		/// <summary>
		/// The event type is a keyboard key down
		/// </summary>
		KeyboardKeyDown = 1,

		/// <summary>
		/// The event type is a keyboard key up
		/// </summary>
		KeyboardKeyUp = 2,

		/// <summary>
		/// Represents the window resize event
		/// </summary>
		WindowResized = 3,

		/// <summary>
		/// Represents the window close event
		/// </summary>
		WindowClosed = 4
	};
}