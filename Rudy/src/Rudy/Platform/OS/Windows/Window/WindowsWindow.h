#pragma once
#include <Rudy/Windowing/Window.h>
#include <Rudy/Mathematics/Vector2i.h>

struct GLFWwindow;
namespace Rudy
{
	class RUDY_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const String& title,const unsigned int offsetX,const unsigned int offsetY,const unsigned int sizeX,const unsigned int sizeY);
		virtual ~WindowsWindow() override;

		virtual bool HasCloseRequest() const override;
		virtual void PollBufferedEvents() override;
		virtual void* GetNativePtr() const override;
	private:
		struct GLFWWindowData
		{
			String Title;
			unsigned int Width, Height;
			bool VSync;
			Delegate<void,Event*>* EventCallback;

		};
	private:
		GLFWwindow* m_NativeWindow;
		GLFWWindowData m_NativeWindowData;
	};


}