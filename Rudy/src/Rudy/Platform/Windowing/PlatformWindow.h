#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Windowing/PlatformWindowCreateParameters.h>

namespace Rudy
{
	/// <summary>
	/// Base class for all platform windows to implement
	/// </summary>
	class RUDY_API PlatformWindow
	{
	public:
		PlatformWindow(const PlatformWindowCreateParameters& createParameters);

		FORCEINLINE unsigned int GetWidth() const;
		FORCEINLINE unsigned int GetHeight() const;

	protected:
		virtual ~PlatformWindow() = 0;
		virtual void OnEmitPlatformEvent() = 0;

		unsigned int m_Width;
		unsigned int m_Height;
	};

}
