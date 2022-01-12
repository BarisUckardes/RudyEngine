#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	class RUDY_API ImGuiLayoutCommands
	{
	public:
		ImGuiLayoutCommands() = delete;
		~ImGuiLayoutCommands() = delete;

		static void SetNextWindowSize(const Vector2f& size);
		static void SetNextWindowPosition(const Vector2f& position);
		static void SetCurrentWindowFontScale(float scale);
		static Vector2f GetViewportSize();
		static Vector2f GetViewportPosition();
	};


}