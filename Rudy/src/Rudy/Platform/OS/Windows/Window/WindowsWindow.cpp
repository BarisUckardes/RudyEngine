#include "WindowsWindow.h"
#include <GLFW/glfw3.h>
#include <Rudy/Core/Assertion.h>
#include <Rudy/Events/Window/WindowResizedEvent.h>
#include <Rudy/Events/Window/WindowOffsetEvent.h>
#include <Rudy/Events/Window/WindowClosedEvent.h>
#include <Rudy/Events/Mouse/MouseButtonDownEvent.h>
#include <Rudy/Events/Mouse/MouseButtonUpEvent.h>
#include <Rudy/Events/Mouse/MousePositionChangedEvent.h>
#include <Rudy/Events/Mouse/MouseScrolledEvent.h>
#include <Rudy/Events/Keyboard/KeyboardCharEvent.h>
#include <Rudy/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Events/Keyboard/KeyboardKeyReleasedEvent.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
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
		* Set it as debug context
		*/
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

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
			[](GLFWwindow* window, int offsetX, int offsetY)
			{
				/*
				* Get user pointer data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate window offset event
				*/
				WindowOffsetEvent* event = new WindowOffsetEvent(Vector2i(offsetX, offsetY));

				/*
				* Broad cast event
				*/
				data.EventCallback->Invoke(event);
			}
			);

		/*
		* Set window close callback
		*/
		glfwSetWindowCloseCallback(m_NativeWindow,
			[](GLFWwindow* window)
			{
				/*
				* Get set pointer data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate window closed event
				*/
				WindowClosedEvent* event = new WindowClosedEvent();

				/*
				* Broadcast event
				*/
				data.EventCallback->Invoke(event);
			});

		/*
		* Set mouse button callback
		*/
		glfwSetMouseButtonCallback(m_NativeWindow,
			[](GLFWwindow* window, int button, int action, int mods)
			{
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonDownEvent* event = new MouseButtonDownEvent(button);
						data.EventCallback->Invoke(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonUpEvent* event = new MouseButtonUpEvent(button);
						data.EventCallback->Invoke(event);
						break;
					}
				}
			}
			);

		/*
		* Set mouse cursor position change callback
		*/
		glfwSetCursorPosCallback(m_NativeWindow,
			[](GLFWwindow* window, double x, double y)
			{
				/*
				* Get window data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate event data
				*/
				MousePositionChangedEvent* event = new MousePositionChangedEvent(Vector2i((int)x, (int)y));

				/*
				* Broadcast event
				*/
				data.EventCallback->Invoke(event);
			}
			);

		/*
		* Set mouse wheel scroll callback
		*/
		glfwSetScrollCallback(m_NativeWindow,
			[](GLFWwindow* window, double x,double y)
			{
				/*
				* Get window data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Generate scroll event
				*/
				MouseScrolledEvent* event = new MouseScrolledEvent(Vector2f((float)x,(float)y));

				/*
				* Broadcast event
				*/
				data.EventCallback->Invoke(event);
			}
			);

		/*
		* Set keyboard keyy callback
		*/
		glfwSetKeyCallback(m_NativeWindow,
			[](GLFWwindow* window, int key, int scanCode, int action, int mods)
		{
				/*
				* Get window data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyboardKeyDownEvent* event = new KeyboardKeyDownEvent(key,0);
						data.EventCallback->Invoke(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyboardKeyReleasedEvent* event = new KeyboardKeyReleasedEvent(key);
						data.EventCallback->Invoke(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyboardKeyDownEvent* event = new KeyboardKeyDownEvent(key, 1);
						data.EventCallback->Invoke(event);
						break;
					}
				}
		});

		glfwSetCharCallback(m_NativeWindow, [](GLFWwindow* window, unsigned int keyCode)
			{
				/*
				* Get window data
				*/
				GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

				/*
				* Create char press event
				*/
				KeyboardCharEvent* event = new KeyboardCharEvent(keyCode);
				data.EventCallback->Invoke(event);
			});

		/*
		* Set event callback
		*/
		m_NativeWindowData.EventCallback = GetWindowEventDelegate();

		/*
		* Create graphics device for windows
		*/
		GraphicsDevice* device = GraphicsDevice::Create(this, Rudy::GraphicsAPIType::OpenGL);
		SetGraphicsDevice(device);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	bool WindowsWindow::HasCloseRequest() const
	{
		return glfwWindowShouldClose(m_NativeWindow) == GLFW_FALSE;
	}

	void WindowsWindow::PollBufferedEvents()
	{
		glfwPollEvents();
	}
	void* WindowsWindow::GetNativePtr() const
	{
		return m_NativeWindow;
	}
}