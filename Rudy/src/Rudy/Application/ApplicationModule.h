#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Events/Event.h>

namespace Rudy
{
	/// <summary>
	/// Fundemental element of the application
	/// </summary>
	class RUDY_API ApplicationModule
	{
	public:
		ApplicationModule() = default;
		virtual ~ApplicationModule() = default;


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
		virtual void OnReceiveApplicationEvent(Event& event) = 0;
	};
}