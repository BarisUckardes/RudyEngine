#include <Rudy/Windowing/Window.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/ImGui/ImGuiRenderer.h>
#include <Rudy/ImGui/ImGuiRenderCommands.h>
#include <Rudy/Graphics/Command/CommandBuffer.h>
#include <Rudy/Mathematics/ColorRgba.h>
void RenderGUI();

int main(int argumentCount, char** arguments)
{
	/*
	* Create window
	*/
	Rudy::Window* window = Rudy::Window::Create("Slope", 100, 100, 1280, 720);

	/*
	* Create renderer
	*/
	Rudy::ImGuiRenderer* renderer = new Rudy::ImGuiRenderer(Rudy::Vector2i(1280, 720), window->GetGraphicsDevice()->GetApiType());

	/*
	* Register event delegate
	*/
	Rudy::Delegate<void, Rudy::Event*> rendererEvent = Rudy::Delegate<void, Rudy::Event*>(RUDY_BIND_TARGET_EVENT(renderer, Rudy::ImGuiRenderer::OnEventReceived));
	window->RegisterCallBack(rendererEvent);

	/*
	* Slope loop
	*/
	bool exitRequest = false;
	while (!exitRequest)
	{
		/*
		* Clear color
		*/
		Rudy::CommandBuffer* cmdBuffer = window->GetGraphicsDevice()->CreateCommandBuffer();
		cmdBuffer->StartRecording();
		cmdBuffer->ClearColor(Rudy::ColorRgba(0, 0, 0, 1.0f));
		cmdBuffer->FinalizeRecording();
		cmdBuffer->Execute();
		delete cmdBuffer;

		/*
		* Update window
		*/
		window->PollBufferedEvents();

		/*
		* Render gui
		*/
		renderer->Begin();
		RenderGUI();
		renderer->End();

		/*
		* Swapbuffers
		*/
		window->GetGraphicsDevice()->Swapbuffers();

		/*
		* Validate exit
		*/
		if (window->HasCloseRequest())
			exitRequest = true;

	}
	return 0;
}
void RenderGUI()
{
	if (Rudy::ImGuiRenderCommands::BeginWindow("Hloa"))
	{

	}
	Rudy::ImGuiRenderCommands::FinalizeWindow();
}