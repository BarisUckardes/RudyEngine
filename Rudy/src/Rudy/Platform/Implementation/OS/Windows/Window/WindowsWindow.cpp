#include "WindowsWindow.h"
#include <GLFW/glfw3.h>
#include <Rudy/Core/Assertion.h>
#include <Rudy/Application/Events/Window/WindowResizedEvent.h>
#include <Rudy/Application/Events/Window/WindowOffsetEvent.h>
#include <Rudy/Application/Events/Window/WindowClosedEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonDownEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonUpEvent.h>
#include <Rudy/Application/Events/Mouse/MousePositionChangedEvent.h>
#include <Rudy/Application/Events/Mouse/MouseScrolledEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardCharEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyReleasedEvent.h>
#include <Rudy/Application/Events/Window/WindowDropFileEvent.h>
#include <Rudy/Platform/Utility/PlatformError.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Core/Log.h>
namespace Rudy
{
	LRESULT WindowsMessageCallback(HWND, UINT, WPARAM, LPARAM)
	{
		return 0;
	}

	PlatformWindow::PlatformWindow(const String& title, const unsigned int offsetX, const unsigned int offsetY, const unsigned int sizeX, const unsigned int sizeY, HINSTANCE hInstance)
	{
		const wchar_t CLASS_NAME[] = L"WindowsWindowClass";

		/*
		* Create wnd class
		*/
		WNDCLASS wc = { 0 };
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hIcon = LoadIcon(0, IDI_WINLOGO);
		wc.lpszMenuName = 0;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc.hbrBackground = 0;
		wc.lpfnWndProc = WindowsMessageCallback;
		wc.hInstance = hInstance;
		wc.lpszClassName = CLASS_NAME;

		/*
		* Register class to windows
		*/
		RegisterClass(&wc);

		/*
		* Create window
		*/
		HWND windowHandle = CreateWindowEx(
			0,                              // Optional window styles.
			CLASS_NAME,                     // Window class
			L"WindowsWindowClass",    // Window text
			WS_OVERLAPPEDWINDOW,            // Window style

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			NULL,       // Parent window    
			NULL,       // Menu
			hInstance,  // Instance handle
			NULL        // Additional application data
		);

		/*
		* Validate window handle
		*/
		if (windowHandle == NULL)
		{
			MessageBoxA(windowHandle, *PlatformError::GetLastOSError(), "Title", 0);

			DebugBreak();
		}

		/*
		* Show window
		*/
		ShowWindow(windowHandle, SW_SHOW);
	}

	PlatformWindow::~PlatformWindow()
	{

	}

	Vector2i PlatformWindow::GetSize() const
	{
		return Vector2i();
	}

	Vector2i PlatformWindow::GetOffset() const
	{
		return Vector2i();
	}

	GraphicsDevice* PlatformWindow::GetGraphicsDevice() const
	{
		return nullptr;
	}

	bool PlatformWindow::HasCloseRequest() const
	{
		return false;
	}

	void PlatformWindow::PollBufferedEvents()
	{

	}

	void PlatformWindow::OnBroadcastEvent(Event* event)
	{

	}

	void PlatformWindow::SetGraphicsDevice(GraphicsDevice* device)
	{

	}

	Delegate<void, Event*>* PlatformWindow::GetWindowEventDelegate() const
	{
		return nullptr;
	}

	void PlatformWindow::OnWindowResizeEvent(const Vector2i& newSize)
	{

	}

	void PlatformWindow::OnWindowClosedEvent()
	{

	}

	void PlatformWindow::OnWindowOffsetChanged(const Vector2i& newOffset)
	{

	}

	void PlatformWindow::SetTitle(const String& title)
	{
		m_Title = title;
	}

	void PlatformWindow::RegisterCallBack(Delegate<void, Event*> functionPtr)
	{
		m_Callbacks.Add(functionPtr);
	}

	void PlatformWindow::RemoveCallBack(Delegate<void, Event*> functionPtr)
	{
		m_Callbacks.Remove(functionPtr);
	}

	//Rudy::PlatformWindow::PlatformWindow(const String& title, const unsigned int offsetX, const unsigned int offsetY, const unsigned int sizeX, const unsigned int sizeY,void* parameters)
	//{
	//	
	//	/*
	//	* Initialize glfw
	//	*/
	//	int glfwInitState = glfwInit();

	//	/*
	//	* Validate glfw initialization
	//	*/
	//	RUDY_ASSERT(glfwInitState == 1);

	//	/*
	//	* Set it as debug context
	//	*/
	//	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	//	/*
	//	* Create glfw window
	//	*/
	//	m_NativeWindow = glfwCreateWindow(sizeX, sizeY, *title,nullptr,nullptr);

	//	/*
	//	* Set user data pointer
	//	*/
	//	glfwSetWindowUserPointer(m_NativeWindow, &m_NativeWindowData);

	//	/*
	//	* Set window size callback
	//	*/
	//	glfwSetWindowSizeCallback(m_NativeWindow,
	//		[](GLFWwindow* window, int width, int height)
	//		{
	//			/*
	//			* Get user pointer data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Generate window resize event
	//			*/
	//			WindowResizedEvent* event = new WindowResizedEvent(Vector2i(width, height));

	//			/*
	//			* Broadcast event
	//			*/
	//			data.EventCallback->Invoke(event);
	//		}
	//		);

	//	/*
	//	* Set window offset callback
	//	*/
	//	glfwSetWindowPosCallback(m_NativeWindow,
	//		[](GLFWwindow* window, int offsetX, int offsetY)
	//		{
	//			/*
	//			* Get user pointer data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Generate window offset event
	//			*/
	//			WindowOffsetEvent* event = new WindowOffsetEvent(Vector2i(offsetX, offsetY));

	//			/*
	//			* Broad cast event
	//			*/
	//			data.EventCallback->Invoke(event);
	//		}
	//		);

	//	/*
	//	* Set window close callback
	//	*/
	//	glfwSetWindowCloseCallback(m_NativeWindow,
	//		[](GLFWwindow* window)
	//		{
	//			/*
	//			* Get set pointer data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Generate window closed event
	//			*/
	//			WindowClosedEvent* event = new WindowClosedEvent();

	//			/*
	//			* Broadcast event
	//			*/
	//			data.EventCallback->Invoke(event);
	//			printf("Window close callback\n");
	//		});

	//	/*
	//	* Set mouse button callback
	//	*/
	//	glfwSetMouseButtonCallback(m_NativeWindow,
	//		[](GLFWwindow* window, int button, int action, int mods)
	//		{
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			switch (action)
	//			{
	//				case GLFW_PRESS:
	//				{
	//					MouseButtonDownEvent* event = new MouseButtonDownEvent(button);
	//					data.EventCallback->Invoke(event);
	//					break;
	//				}
	//				case GLFW_RELEASE:
	//				{
	//					MouseButtonUpEvent* event = new MouseButtonUpEvent(button);
	//					data.EventCallback->Invoke(event);
	//					break;
	//				}
	//			}
	//		}
	//		);

	//	/*
	//	* Set mouse cursor position change callback
	//	*/
	//	glfwSetCursorPosCallback(m_NativeWindow,
	//		[](GLFWwindow* window, double x, double y)
	//		{
	//			/*
	//			* Get window data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Generate event data
	//			*/
	//			MousePositionChangedEvent* event = new MousePositionChangedEvent(Vector2i((int)x, (int)y));

	//			/*
	//			* Broadcast event
	//			*/
	//			data.EventCallback->Invoke(event);
	//		}
	//		);

	//	/*
	//	* Set mouse wheel scroll callback
	//	*/
	//	glfwSetScrollCallback(m_NativeWindow,
	//		[](GLFWwindow* window, double x,double y)
	//		{
	//			/*
	//			* Get window data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Generate scroll event
	//			*/
	//			MouseScrolledEvent* event = new MouseScrolledEvent(Vector2f((float)x,(float)y));

	//			/*
	//			* Broadcast event
	//			*/
	//			data.EventCallback->Invoke(event);
	//		}
	//		);

	//	/*
	//	* Set keyboard keyy callback
	//	*/
	//	glfwSetKeyCallback(m_NativeWindow,
	//		[](GLFWwindow* window, int key, int scanCode, int action, int mods)
	//	{
	//			/*
	//			* Get window data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			switch (action)
	//			{
	//				case GLFW_PRESS:
	//				{
	//					KeyboardKeyDownEvent* event = new KeyboardKeyDownEvent(key,0);
	//					data.EventCallback->Invoke(event);
	//					break;
	//				}
	//				case GLFW_RELEASE:
	//				{
	//					KeyboardKeyReleasedEvent* event = new KeyboardKeyReleasedEvent(key);
	//					data.EventCallback->Invoke(event);
	//					break;
	//				}
	//				case GLFW_REPEAT:
	//				{
	//					KeyboardKeyDownEvent* event = new KeyboardKeyDownEvent(key, 1);
	//					data.EventCallback->Invoke(event);
	//					break;
	//				}
	//			}
	//	});

	//	glfwSetCharCallback(m_NativeWindow, [](GLFWwindow* window, unsigned int keyCode)
	//		{
	//			/*
	//			* Get window data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Create char press event
	//			*/
	//			KeyboardCharEvent* event = new KeyboardCharEvent(keyCode);
	//			data.EventCallback->Invoke(event);
	//		});

	//	glfwSetDropCallback(m_NativeWindow,[](GLFWwindow* window, int dropCount, const char** dropPaths)
	//		{
	//			/*
	//			* Get window data
	//			*/
	//			GLFWWindowData& data = *(GLFWWindowData*)glfwGetWindowUserPointer(window);

	//			/*
	//			* Iterate and generate drop file data
	//			*/
	//			Array<String> dropPathsStrings;
	//			for (unsigned int i = 0; i < dropCount; i++)
	//			{
	//				/*
	//				* Get drop path
	//				*/
	//				const char* dropPath = dropPaths[i];

	//				/*
	//				* Register drop path
	//				*/
	//				dropPathsStrings.Add(dropPath);
	//			}

	//			/*
	//			* Create window file drop event
	//			*/
	//			WindowDropFileEvent* event = new WindowDropFileEvent(dropPathsStrings);
	//			data.EventCallback->Invoke(event);
	//		}
	//	);

	//	/*
	//	* Set event callback
	//	*/
	//	m_NativeWindowData.EventCallback = GetWindowEventDelegate();

	//	/*
	//	* Create graphics device for windows
	//	*/
	//	GraphicsDevice* device = GraphicsDevice::Create(this, Rudy::GraphicsAPIType::OpenGL);
	//	SetGraphicsDevice(device);
	//}

	//PlatformWindow::~PlatformWindow()
	//{

	//}

	//bool PlatformWindow::HasCloseRequest() const
	//{
	//	return glfwWindowShouldClose(m_NativeWindow) == GLFW_TRUE;
	//}

	//void PlatformWindow::PollBufferedEvents()
	//{
	//	glfwPollEvents();
	//}
	//
	//void PlatformWindow::SetTitle(const String& title)
	//{
	//	glfwSetWindowTitle(m_NativeWindow, *title);
	//}
}