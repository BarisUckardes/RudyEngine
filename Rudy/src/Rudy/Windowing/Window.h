#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Windowing/WindowCreateParameters.h>
#include <Rudy/Events/Event.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Core/Events.h>
#include <Rudy/Events/Delegate.h>
namespace Rudy
{
	/// <summary>
	/// Base class for all platform windows to implement
	/// </summary>
	class RUDY_API Window
	{
	public:
		/// <summary>
		/// Creates platform/os agnostic window
		/// </summary>
		/// <param name="createParameters"></param>
		/// <returns></returns>
		static Window* Create(const String& title,const unsigned int offsetX,const unsigned int offsetY,unsigned int sizeX,unsigned int sizeY);

		Window(const String& title, const unsigned int offsetX, const unsigned int offsetY, unsigned int sizeX, unsigned int sizeY);

		/// <summary>
		/// Returns the current width of this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetWidth() const;

		/// <summary>
		/// Returns the current height of this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetHeight() const;

		/// <summary>
		/// Returns the window title
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetTitle() const;

		/// <summary>
		/// Returns the window offset X
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetOffsetX() const;

		/// <summary>
		/// Returns the window offset Y
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetOffsetY() const;

		/// <summary>
		/// Returns whether this window is closes
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsAlive() const;

		/// <summary>
		/// Registers a function callback for this window to call when an event fired
		/// </summary>
		/// <param name="callbackFunction"></param>
		void RegisterCallBack(Delegate<void, Event&>* functionPtr);

		/// <summary>
		/// Removes a event callback from the registry
		/// </summary>
		/// <param name="callBackFunction"></param>
		void RemoveCallBack(Delegate<void, Event&>* functionPtr);
	protected:
		/// <summary>
		/// Called when received an event
		/// </summary>
		void OnEmitPlatformEvent(Event& event);

		virtual ~Window() = 0;
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
		Array<Delegate<void, Event&>*> m_Callbacks;
		String m_Title;
		unsigned int m_Width;
		unsigned int m_Height;
		unsigned int m_OffsetX;
		unsigned int m_OffsetY;
		bool m_WindowAlive;
	};

}
