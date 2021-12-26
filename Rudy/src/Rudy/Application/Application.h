#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	/// <summary>
	/// Base class for appllcations
	/// </summary>
	class RUDY_API Application
	{
	public:
		Application(const String& applicationName,unsigned int offsetX,unsigned int offsetY,unsigned int sizeX,unsigned int sizeY);
		void Run();
	protected:
		virtual ~Application() = 0;
	};
}