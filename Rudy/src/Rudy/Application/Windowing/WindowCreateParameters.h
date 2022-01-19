#pragma once
#include <Rudy/Mathematics/Vector2i.h>
#include <Rudy/Memory/String.h>
namespace Rudy
{
	/// <summary>
	/// Contains required parameters for window creation
	/// </summary>
	struct RUDY_API WindowCreateParameters
	{
	public:
		WindowCreateParameters(const String& title,const Vector2i& offset,const Vector2i& size) : Title(title),Offset(offset),Size(size) {}
		~WindowCreateParameters() = default;

		/// <summary>
		/// The title of the window
		/// </summary>
		String Title;

		/// <summary>
		/// The offset of the window position on the screen
		/// </summary>
		Vector2i Offset;

		/// <summary>
		/// The size of the window
		/// </summary>
		Vector2i Size;
	};
}