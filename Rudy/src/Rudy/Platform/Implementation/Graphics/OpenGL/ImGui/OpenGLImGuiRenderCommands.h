#pragma once
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>

namespace Rudy
{
	class OpenGLImGuiRenderCommands : public ImGuiRenderCommands
	{
	public:
		OpenGLImGuiRenderCommands() = default;
		~OpenGLImGuiRenderCommands() = default;


		// Inherited via ImGuiRenderCommands
		virtual bool CreateTexturedButton(const String& name, const Vector2f& size, const Texture2D* texture) const override;

	};
}