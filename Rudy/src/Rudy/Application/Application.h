#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	class Window;

	/// <summary>
	/// Base class for appllcations
	/// </summary>
	class RUDY_API Application
	{
	public:
		Application(const String& applicationName,unsigned int offsetX,unsigned int offsetY,unsigned int sizeX,unsigned int sizeY);

		virtual void Run() = 0;
		virtual void Shuwdown() = 0;
	protected:
		virtual ~Application() = 0;
	private:
		Window* m_Window;
	};
}