#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Application/Events/Event.h>

namespace Rudy
{
	class ApplicationSession;
	/// <summary>
	/// Fundemental element of the application
	/// </summary>
	class RUDY_API ApplicationModule
	{
		friend class Application;
	public:
		ApplicationModule() = default;
		~ApplicationModule() = default;

		/// <summary>
		/// Called when module attached to application
		/// </summary>
		virtual void OnAttach() = 0;

		/// <summary>
		/// Called when module gets updated by the application
		/// </summary>
		virtual void OnUpdate() = 0;

		/// <summary>
		/// Called when module is detached from the application
		/// </summary>
		virtual void OnDetach() = 0;

		/// <summary>
		/// Called when an event broadcasted from the application
		/// </summary>
		/// <param name="event"></param>
		virtual void OnReceiveApplicationEvent(Event* event) = 0;
	protected:
		FORCEINLINE ApplicationSession* GetOwnerSession() const;
	private:
		/// <summary>
		/// Sets the owner session for this application module
		/// </summary>
		/// <param name="session"></param>
		void SetOwnerSession(ApplicationSession* session);
		ApplicationSession* m_OwnerSession;
	};
}