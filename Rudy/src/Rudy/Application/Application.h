#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Events/Event.h>
#include <Rudy/Windowing/WindowCreateParameters.h>
#include <Rudy/Events/Delegate.h>
#include <Rudy/Memory/Array.h>

namespace Rudy
{
	class Window;
	class ApplicationModule;
	class ApplicationSession;
	/// <summary>
	/// Base class for appllcations
	/// </summary>
	class RUDY_API Application
	{
	public:
		Application(const String& executablePath,const WindowCreateParameters& createParameters);
		virtual ~Application() = default;

		/// <summary>
		/// Returns the window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Window* GetWindow() const;

		/// <summary>
		/// Returns the executable path for this application
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetApplicationExecutablePath() const;
	protected:
		/// <summary>
		/// Registers anew module to the application
		/// </summary>
		/// <typeparam name="TModule"></typeparam>
		template<typename TModule, typename ...TParameters>
		void RegisterModule(TParameters... parameters);

		/// <summary>
		/// Run loop of the application
		/// </summary>
		void Run();

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
		void OnEventReceived(Event* event);
	private:
		Array<ApplicationModule*> m_PendingModules;
		Array<ApplicationModule*> m_Modules;
		Array<Event*> m_BufferedEvents;
		Delegate<void, Event*> m_ApplicationWindowEventDelegate;
		ApplicationSession* m_Session;
		Window* m_Window;
		String m_ExecutablePath;
	};

	template<typename TModule,typename ...TParameters>
	void Application::RegisterModule(TParameters... parameters)
	{
		/*
		* Create new module
		*/
		TModule* newModule = new TModule(parameters...);

		/*
		* Register to the pending list
		*/
		m_PendingModules.Add(newModule);
	}
}