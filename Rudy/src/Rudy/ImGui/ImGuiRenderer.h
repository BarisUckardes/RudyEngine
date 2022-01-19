#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyReleasedEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardCharEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonDownEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonUpEvent.h>
#include <Rudy/Application/Events/Mouse/MousePositionChangedEvent.h>
#include <Rudy/Application/Events/Mouse/MouseScrolledEvent.h>
#include <Rudy/Application/Events/Window/WindowResizedEvent.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
#include <Rudy/ImGui/Flags/GUIConfigFlags.h>
#include <Rudy/ImGui/Flags/GUIBackendFlags.h>
namespace Rudy
{
	/// <summary>
	/// A renderer for imgui libraray
	/// </summary>
	class RUDY_API ImGuiRenderer
	{
	public:
		ImGuiRenderer(const Vector2i& initialWindowSize,GraphicsAPIType apiType,GUIBackendFlags backendFlags,GUIConfigFlags configFlags);
		~ImGuiRenderer();

		/// <summary>
		/// Starts the rendering session
		/// </summary>
		void Begin();

		/// <summary>
		/// Ends the rendering session
		/// </summary>
		void End();

		/// <summary>
		/// Received an event from the application
		/// </summary>
		/// <param name="event"></param>
		void OnEventReceived(Event* event);
	private:
		/// <summary>
		/// Called when mouse button pressed
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnMouseButtonPressed(MouseButtonDownEvent* event);

		/// <summary>
		/// Called when mouse button released
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnMouseButtonUp(MouseButtonUpEvent* event);

		/// <summary>
		/// Called when mouse cursor moved
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnMouseMoved(MousePositionChangedEvent* event);

		/// <summary>
		/// Called when mouse scrolled
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnMouseScrolled(MouseScrolledEvent* event);

		/// <summary>
		/// Called when keyboard key is down
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnKeyDown(KeyboardKeyDownEvent* event);

		/// <summary>
		/// Called when keyboard key is up
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnKeyUp(KeyboardKeyReleasedEvent* event);

		/// <summary>
		/// Called when keyboard char key pressed
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnKeyChar(KeyboardCharEvent* event);

		/// <summary>
		/// Called when window resized
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool OnWindowResized(WindowResizedEvent* event);
	private:
		GraphicsAPIType m_ApiType;
		Vector2i m_WindowSize;
		float m_Time;
	};
}