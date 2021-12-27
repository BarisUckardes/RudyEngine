#pragma once
#include <Rudy/Windowing/Window.h>
#include <Rudy/Mathematics/Vector2i.h>
namespace Rudy
{
	class RUDY_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const String& title,const unsigned int offsetX,const unsigned int offsetY,const unsigned int sizeX,const unsigned int sizeY);
		virtual ~WindowsWindow() override;
	};


}