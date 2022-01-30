#include "ImGuiRenderer.h"
#include <IMGUI/imgui.h>
#include <Rudy/Input/Keys.h>
#include <Rudy/ImGui/ImGuiGraphicsAPIImplementation.h>
#include <stdio.h>
namespace Rudy
{
	void SetupDefaultTheme()
	{
		/*ImGuiStyle* style = &ImGui::GetStyle();
		ImVec4* colors = style->Colors;

		colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
		colors[ImGuiCol_Border] = ImVec4(0.266f, 0.266f, 0.266f, 1.000f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
		colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
		colors[ImGuiCol_Header] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
		colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_DockingPreview] = ImVec4(1.000f, 0.391f, 0.000f, 0.781f);
		colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

		style->ChildRounding = 4.0f;
		style->FrameBorderSize = 1.0f;
		style->FrameRounding = 2.0f;
		style->GrabMinSize = 7.0f;
		style->PopupRounding = 2.0f;
		style->ScrollbarRounding = 12.0f;
		style->ScrollbarSize = 13.0f;
		style->TabBorderSize = 1.0f;
		style->TabRounding = 0.0f;
		style->WindowRounding = 4.0f;*/

	    ImGui::GetStyle().FrameRounding = 4.0f;
		ImGui::GetStyle().GrabRounding = 4.0f;

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	}
	void SetupBackedFlags(GUIBackendFlags flags)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags = (int)flags;
	}
	void SetupConfigFlags(GUIConfigFlags flags)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags = (int)flags;
	}
	ImGuiRenderer::ImGuiRenderer(const Vector2i& initialWindowSize,GraphicsAPIType apiType, GUIBackendFlags backendFlags, GUIConfigFlags configFlags)
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
		io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;

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

		/*
		* Set backend and config flag
		*/
		SetupBackedFlags(backendFlags);
		SetupConfigFlags(configFlags);

		/*
		* Enable default theme
		*/
		SetupDefaultTheme();
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
		printf("Imgui key down...\n");
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