#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Windowing/WindowCreateParameters.h>

namespace Rudy
{
	/// <summary>
	/// Base class for all platform windows to implement
	/// </summary>
	class RUDY_API Window
	{
	public:
		Window(const WindowCreateParameters& createParameters);

		FORCEINLINE unsigned int GetWidth() const;
		FORCEINLINE unsigned int GetHeight() const;

	protected:
		virtual ~Window() = 0;
		virtual void OnEmitPlatformEvent() = 0;

		unsigned int m_Width;
		unsigned int m_Height;
	};

}
