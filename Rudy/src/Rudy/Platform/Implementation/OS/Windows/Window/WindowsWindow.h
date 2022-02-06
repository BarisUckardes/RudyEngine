#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Platform/Window/WindowCreateParameters.h>
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Core/Events.h>
#include <Rudy/Application/Events/Delegate.h>
#include <Rudy/Mathematics/Vector2i.h>
#include <Windows.h>

struct GLFWwindow;
namespace Rudy
{
	class GraphicsDevice;
	/// <summary>
	/// Base class for all platform windows to implement
	/// </summary>
	class RUDY_API PlatformWindow
	{
		friend class ApplicationSession;
	protected:
		using WindowEventCallback = std::function<void(Event&)>;
	public:
		PlatformWindow(const String& title,
			const unsigned int offsetX, const unsigned int offsetY,
			unsigned int sizeX, unsigned int sizeY, HINSTANCE parameters);
		~PlatformWindow();
		/// <summary>
		/// Returns the size of this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2i GetSize() const;

		/// <summary>
		/// Returns the client offset of this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector2i GetOffset() const;

		/// <summary>
		/// Returns the assinged graphics device for this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetGraphicsDevice() const;

		/// <summary>
		/// Sets the title of this window
		/// </summary>
		/// <param name="title"></param>
		void SetTitle(const String& title);

		/// <summary>
		/// Registers a function callback for this window to call when an event fired
		/// </summary>
		/// <param name="callbackFunction"></param>
		void RegisterCallBack(Delegate<void, Event*> functionPtr);

		/// <summary>
		/// Removes a event callback from the registry
		/// </summary>
		/// <param name="callBackFunction"></param>
		void RemoveCallBack(Delegate<void, Event*> functionPtr);

		/// <summary>
		/// returns whether this window should close
		/// </summary>
		/// <returns></returns>
		bool HasCloseRequest() const;

		/// <summary>
		/// Records buffered events and broadcasts them to the application
		/// </summary>
		void PollBufferedEvents();
	protected:
		/// <summary>
		/// Called when received an event
		/// </summary>
		void OnBroadcastEvent(Event* event);

		/// <summary>
		/// Sets the graphics device for this window
		/// </summary>
		/// <param name="device"></param>
		void SetGraphicsDevice(GraphicsDevice* device);

		/// <summary>
		/// Returns the window event delegate of this window
		/// </summary>
		/// <returns></returns>
		Delegate<void, Event*>* GetWindowEventDelegate() const;
	private:
		/// <summary>
		/// Called when window is resized
		/// </summary>
		/// <param name="newSize"></param>
		void OnWindowResizeEvent(const Vector2i& newSize);

		/// <summary>
		/// Called when window closed
		/// </summary>
		void OnWindowClosedEvent();

		/// <summary>
		/// Called when windows offset changed
		/// </summary>
		/// <param name="newOffset"></param>
		void OnWindowOffsetChanged(const Vector2i& newOffset);
	private:
		Array<Delegate<void, Event*>> m_Callbacks;
		GraphicsDevice* m_GraphicsDevice;
		Delegate<void, Event*>* m_WindowEventCallback;
		String m_Title;
		Vector2i m_Size;
		Vector2i m_Offset;
	};
}