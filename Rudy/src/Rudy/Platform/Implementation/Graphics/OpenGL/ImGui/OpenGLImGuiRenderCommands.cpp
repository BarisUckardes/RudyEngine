#include "OpenGLImGuiRenderCommands.h"
#include <IMGUI/imgui.h>
#include <Rudy/Graphics/Texture/Texture2D.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Rudy
{
	bool Rudy::OpenGLImGuiRenderCommands::CreateTexturedButton(const String& name, const Vector2f& size, const Texture2D* texture) const
	{
		int texID = *(int*)texture->GetNativeHandle();
		ImGui::PushID(*name);
		bool state = ImGui::ImageButton((int*)texID, ImVec2(size.X, size.Y));
		ImGui::PopID();
		return state;
	}

}