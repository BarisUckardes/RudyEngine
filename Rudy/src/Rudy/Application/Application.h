#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Events/Event.h>
#include <Rudy/Windowing/WindowCreateParameters.h>
#include <Rudy/Events/Delegate.h>
namespace Rudy
{
	class Window;

	/// <summary>
	/// Base class for appllcations
	/// </summary>
	class RUDY_API Application
	{
	public:
		//Application(const WindowCreateParameters& createParameters);
		virtual ~Application() = default;

		/// <summary>
		/// Run loop of the application
		/// </summary>
		virtual void Run() = 0;

		/// <summary>
		/// Frees all the resources
		/// </summary>
		virtual void Shuwdown() = 0;

		/// <summary>
		/// Returns the window
		/// </summary>
		/// <returns></returns>
		Window* GetWindow() const;
	protected:
		/// <summary>
		/// Sets a window for this application
		/// </summary>
		/// <param name="window"></param>
		void SubmitWindow(Window* window);
	private:
		/// <summary>
		/// Called when this application receives an event
		/// </summary>
		/// <param name="event"></param>
		virtual void OnEventReceived(Event& event) = 0;
	private:
		Delegate<void, Event&>* m_WindowEventDelegate;
		Window* m_Window;
	};
}