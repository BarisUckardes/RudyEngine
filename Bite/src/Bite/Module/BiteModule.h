#pragma once
#include <Rudy/Application/ApplicationModule.h>
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	class ImGuiRenderer;

}
namespace Bite
{
	class GUIModule;
	class EditorSession;
	/// <summary>
	/// Main bite module
	/// </summary>
	class BITE_API BiteModule : public Rudy::ApplicationModule
	{
	public:
		BiteModule(const Rudy::Array<GUIModule*>& guiModules);
		BiteModule() = default;
		~BiteModule() = default;

		// Inherited via ApplicationModule
		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnReceiveApplicationEvent(Rudy::Event* event) override;
	private:
		Rudy::Array<GUIModule*> m_PendingGUIModules;
		Rudy::Array<GUIModule*> m_GUIModules;
		Rudy::ImGuiRenderer* m_ImGuiRenderer;
		EditorSession* m_Session;
	};



}