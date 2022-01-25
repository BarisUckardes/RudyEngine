#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
namespace Rudy
{
	class ImGuiRenderCommands;
	class ImGuiLayoutCommands;
}
namespace Bite
{
	class GUIPainterEventLedger;
	/// <summary>
	/// Painter class for gui
	/// </summary>
	class BITE_API GUIPainter
	{
		friend class BiteModule;
	public:
		/// <summary>
		/// Returns the event ledger for this GUI painter
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GUIPainterEventLedger* GetEventLedger() const;

		/// <summary>
		/// Returns the render commands implementation for the current graphics api
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::ImGuiRenderCommands* GetRenderCommands() const;

		/// <summary>
		/// Returns the layout commands
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::ImGuiLayoutCommands* GetLayoutCommands() const;
	private:
		GUIPainter(Rudy::GraphicsAPIType apiType);
		~GUIPainter();

		/// <summary>
		/// Called when painter receives an event
		/// </summary>
		/// <param name="event"></param>
		void OnPainterReceivedEvent(Rudy::Event* event);

		/// <summary>
		/// Clears the event ledger
		/// </summary>
		void ClearEvents();

		GUIPainterEventLedger* m_EventLedger;
		Rudy::ImGuiRenderCommands* m_RenderCommands;
		Rudy::ImGuiLayoutCommands* m_LayoutCommands;
	};

}
