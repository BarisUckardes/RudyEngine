#include "ImGuiGraphicsAPIImplementation.h"
#include <IMGUI/imgui_impl_opengl3.h>
#include <IMGUI/imgui.h>
#include <Rudy/Platform/Graphics/SupportedGraphicsApiDetection.h>
namespace Rudy
{
	void ImGuiGraphicsAPIImplementation::CreateAPICore(GraphicsAPIType apiType)
	{
		switch (apiType)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
				ImGui_ImplOpenGL3_Init("#version 450");
				break;
			case Rudy::GraphicsAPIType::DÝrectx9:
				break;
			case Rudy::GraphicsAPIType::Directx11:
				break;
			case Rudy::GraphicsAPIType::Directx12:
				break;
			case Rudy::GraphicsAPIType::Directx13:
				break;
			case Rudy::GraphicsAPIType::Vulkan:
				break;
			default:
				break;
		}
	}
	void ImGuiGraphicsAPIImplementation::NewFrameCore(GraphicsAPIType apiType)
	{
		switch (apiType)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
				ImGui_ImplOpenGL3_NewFrame();
				break;
			case Rudy::GraphicsAPIType::DÝrectx9:
				break;
			case Rudy::GraphicsAPIType::Directx11:
				break;
			case Rudy::GraphicsAPIType::Directx12:
				break;
			case Rudy::GraphicsAPIType::Directx13:
				break;
			case Rudy::GraphicsAPIType::Vulkan:
				break;
			default:
				break;
		}
	}
	void ImGuiGraphicsAPIImplementation::RenderDrawDataCore(GraphicsAPIType apiType)
	{
		switch (apiType)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
				break;
			case Rudy::GraphicsAPIType::DÝrectx9:
				break;
			case Rudy::GraphicsAPIType::Directx11:
				break;
			case Rudy::GraphicsAPIType::Directx12:
				break;
			case Rudy::GraphicsAPIType::Directx13:
				break;
			case Rudy::GraphicsAPIType::Vulkan:
				break;
			default:
				break;
		}
	}
}