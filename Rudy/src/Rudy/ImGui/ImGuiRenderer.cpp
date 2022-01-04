#include "ImGuiRenderer.h"
#include <IMGUI/imgui.h>
#include <Rudy/Input/Keys.h>
#include <Rudy/ImGui/ImGuiGraphicsAPIImplementation.h>
namespace Rudy
{
	ImGuiRenderer::ImGuiRenderer(const Vector2i& initialWindowSize,GraphicsAPIType apiType)
	{
		/*
		* Set api
		*/
		m_ApiType = apiType;

		/*
		* Set time
		*/
		m_Time = 0;

		/*
		* Create imgui context
		*/
		ImGui::SetCurrentContext(ImGui::CreateContext());
		ImGui::StyleColorsDark();

		/*
		* Set io flags
		*/
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		/*
		* Set key mappings
		*/
		io.KeyMap[ImGuiKey_Tab] = RUDY_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = RUDY_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = RUDY_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = RUDY_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = RUDY_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = RUDY_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = RUDY_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = RUDY_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = RUDY_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = RUDY_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = RUDY_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = RUDY_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = RUDY_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = RUDY_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = RUDY_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = RUDY_KEY_A;
		io.KeyMap[ImGuiKey_C] = RUDY_KEY_C;
		io.KeyMap[ImGuiKey_V] = RUDY_KEY_V;
		io.KeyMap[ImGuiKey_X] = RUDY_KEY_X;
		io.KeyMap[ImGuiKey_Y] = RUDY_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = RUDY_KEY_Z;

		/*
		* Create platform agnostic imgui implementation
		*/
		ImGuiGraphicsAPIImplementation::CreateAPICore(m_ApiType);
		m_WindowSize = initialWindowSize;
	}

	ImGuiRenderer::~ImGuiRenderer()
	{

	}

	void ImGuiRenderer::Begin()
	{
		/*
		* Get current time
		*/
		float time = 16;

		/*
		* Get imgui io
		*/
		ImGuiIO& io = ImGui::GetIO();

		/*
		* Set display size
		*/
		unsigned int width = m_WindowSize.X;
		unsigned int height = m_WindowSize.Y;
		io.DisplaySize = ImVec2(width, height);
		io.DeltaTime = 1.0f / 60.0f;

		/*
		* Create new frame
		*/
		ImGuiGraphicsAPIImplementation::NewFrameCore(m_ApiType);
		ImGui::NewFrame();
	}
	void ImGuiRenderer::End()
	{
		ImGui::Render();
		ImGuiGraphicsAPIImplementation::RenderDrawDataCore(m_ApiType);
	}

	void ImGuiRenderer::OnEventReceived(Event* event)
	{
		/*
		* Get event type
		*/
		EventType eventType = event->GetEventType();

		/*
		* Catch event type
		*/
		switch (eventType)
		{
		case Rudy::EventType::Undefined:
			break;
		case Rudy::EventType::KeyboardKeyDown:
			OnKeyDown((KeyboardKeyDownEvent*)event);
			break;
		case Rudy::EventType::KeyboardKeyUp:
			OnKeyUp((KeyboardKeyReleasedEvent*)event);
			break;
		case Rudy::EventType::KeyboardChar:
			OnKeyChar((KeyboardCharEvent*)event);
			break;
		case Rudy::EventType::WindowResized:
			OnWindowResized((WindowResizedEvent*)event);
			break;
		case Rudy::EventType::WindowClosed:
			break;
		case Rudy::EventType::WindowOffsetChanged:
			break;
		case Rudy::EventType::MouseButtonDown:
			OnMouseButtonPressed((MouseButtonDownEvent*)event);
			break;
		case Rudy::EventType::MouseButtonUp:
			OnMouseButtonUp((MouseButtonUpEvent*)event);
			break;
		case Rudy::EventType::MouseScrolled:
			OnMouseScrolled((MouseScrolledEvent*)event);
			break;
		case Rudy::EventType::MousePositionChanged:
			OnMouseMoved((MousePositionChangedEvent*)event);
			break;
		default:
			break;
		}
	}

	bool ImGuiRenderer::OnMouseButtonPressed(MouseButtonDownEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event->GetButton()] = true;
		return false;
	}

	bool ImGuiRenderer::OnMouseButtonUp(MouseButtonUpEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event->GetButton()] = false;
		return false;
	}

	bool ImGuiRenderer::OnMouseMoved(MousePositionChangedEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		const Vector2i& position = event->GetPosition();
		io.MousePos = ImVec2(position.X, position.Y);
		return false;
	}

	bool ImGuiRenderer::OnMouseScrolled(MouseScrolledEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		const Vector2f& amount = event->GetAmount();
		io.MouseWheel += amount.Y;
		io.MouseWheelH += amount.X;
		return false;
	}

	bool ImGuiRenderer::OnKeyDown(KeyboardKeyDownEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event->GetRelatedKey()] = true;

		io.KeyCtrl = io.KeysDown[RUDY_KEY_LEFT_CONTROL] || io.KeysDown[RUDY_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[RUDY_KEY_LEFT_SHIFT] || io.KeysDown[RUDY_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[RUDY_KEY_LEFT_ALT] || io.KeysDown[RUDY_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[RUDY_KEY_LEFT_SUPER] || io.KeysDown[RUDY_KEY_RIGHT_SUPER];
		return false;
	}

	bool ImGuiRenderer::OnKeyUp(KeyboardKeyReleasedEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event->GetRelatedKey()] = false;
		return false;
	}

	bool ImGuiRenderer::OnKeyChar(KeyboardCharEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keyCode = event->GetRelatedKey();
		if (keyCode > 0 && keyCode < 0x10000)
			io.AddInputCharacter((unsigned short)keyCode);
		return false;
	}

	bool ImGuiRenderer::OnWindowResized(WindowResizedEvent* event)
	{
		ImGuiIO& io = ImGui::GetIO();
		const Vector2i& size = event->GetSize();
		io.DisplaySize = ImVec2(size.X,size.Y);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		m_WindowSize = size;
		return false;
	}
	
}