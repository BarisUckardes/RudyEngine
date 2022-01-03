#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Events/Event.h>
#include <Rudy/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Events/Keyboard/KeyboardKeyReleasedEvent.h>
#include <Rudy/Events/Keyboard/KeyboardCharEvent.h>
#include <Rudy/Events/Mouse/MouseButtonDownEvent.h>
#include <Rudy/Events/Mouse/MouseButtonUpEvent.h>
#include <Rudy/Events/Mouse/MousePositionChangedEvent.h>
#include <Rudy/Events/Mouse/MouseScrolledEvent.h>
#include <Rudy/Events/Window/WindowResizedEvent.h>
#include <Rudy/Platform/Graphics/GraphicsAPIType.h>
namespace Rudy
{
	class RUDY_API ImGuiRenderer
	{
	public:
		ImGuiRenderer(const Vector2i& initialWindowSize,GraphicsAPIType apiType);
		~ImGuiRenderer();

		void Begin();
		void End();

		void OnEventReceived(Event& event);
	private:
		bool OnMouseButtonPressed(MouseButtonDownEvent& event);
		bool OnMouseButtonUp(MouseButtonUpEvent& event);
		bool OnMouseMoved(MousePositionChangedEvent& event);
		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnKeyDown(KeyboardKeyDownEvent& event);
		bool OnKeyUp(KeyboardKeyReleasedEvent& event);
		bool OnKeyChar(KeyboardCharEvent& event);
		bool OnWindowResized(WindowResizedEvent& event);
	private:
		GraphicsAPIType m_ApiType;
		Vector2i m_WindowSize;
		float m_Time;
	};
}