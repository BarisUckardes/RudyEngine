#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	/// <summary>
	/// Encapsulates the immediate gui layout commands
	/// </summary>
	class RUDY_API ImGuiLayoutCommands
	{
	public:
		ImGuiLayoutCommands() = default;
		~ImGuiLayoutCommands() = default;

	    void StayHere() const;
	    void SetCursorPosition(const Vector2f& position) const;
	    void SetNextWindowSize(const Vector2f& size) const;
	    void SetNextWindowPosition(const Vector2f& position) const;
	    void SetCurrentWindowFontScale(float scale) const;
	    Vector2f GetViewportSize() const;
	    Vector2f GetViewportPosition() const;
	    Vector2f GetAvailableSpace() const;
	    Vector2f GetCursorPosition() const;
	};


}