#include "WindowsWindow.h"
#include <GLFW/glfw3.h>
#include <Rudy/Core/Assertion.h>
#include <Rudy/Events/Window/WindowResizedEvent.h>
namespace Rudy
{

	Rudy::WindowsWindow::WindowsWindow(const String& title, const unsigned int offsetX, const unsigned int offsetY, const unsigned int sizeX, const unsigned int sizeY)
		: Window(title,offsetX, offsetY,sizeX, sizeY)
	{
		/*
		* Initialize glfw
		*/
		int glfwInitState = glfwInit();

		/*
		* Validate glfw initialization
		*/
		RUDY_ASSERT(glfwInitState == 1);

		/*
		* Create glfw window
		*/
		m_NativeWindow = glfwCreateWindow(sizeX, sizeY, *title,nullptr,nullptr);

		/*
		* Set user data pointer
		*/
		glfwSetWindowUserPointer(m_NativeWindow, &m_NativeWindowData);

		/*
		* Set window size callback
		*/
		glfwSetWindowSizeCallback(m_NativeWindow,
			[](GLFWwindow* window, int width, int height)
			{
				/*
				* Get user pointer data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate window resize event
				*/
				WindowResizedEvent* event = new WindowResizedEvent(Vector2i(width, height));

				/*
				* Broadcast event
				*/
				data.EventCallback->Invoke(event);
			}
			);

		/*
		* Set window offset callback
		*/
		glfwSetWindowPosCallback(m_NativeWindow,
			[](GLFWwindow* window, int offsetX, int offsety)
			{
				/*
				* Get user pointer data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate window offset event
				*/

				/*
				* Broad cast event
				*/
				printf("Window moved\n");
			}
			);

		/*
		* Set event callback
		*/
		m_NativeWindowData.EventCallback = GetWindowEventDelegate();

		/*
		* Set alive
		*/
		SetAliveState(true);
	}

	WindowsWindow::~WindowsWindow()
	{
		SetAliveState(false);
	}

	void WindowsWindow::PollBufferedEvents()
	{
		glfwPollEvents();
	}
}