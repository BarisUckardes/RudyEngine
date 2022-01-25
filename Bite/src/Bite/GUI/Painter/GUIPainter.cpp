#include "GUIPainter.h"
#include <Bite/GUI/Painter/GUIPainterEventLedger.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
#include <Rudy/ImGui/Commands/ImGuiLayoutCommands.h>
namespace Bite
{
	void GUIPainter::OnPainterReceivedEvent(Rudy::Event* event)
	{
		m_EventLedger->OnLedgerReceivedEvent(event);
	}
	void GUIPainter::ClearEvents()
	{
		m_EventLedger->ClearEvents();
	}
	GUIPainterEventLedger* GUIPainter::GetEventLedger() const
	{
		return m_EventLedger;
	}
	Rudy::ImGuiRenderCommands* GUIPainter::GetRenderCommands() const
	{
		return m_RenderCommands;
	}
	Rudy::ImGuiLayoutCommands* GUIPainter::GetLayoutCommands() const
	{
		return m_LayoutCommands;
	}
	GUIPainter::GUIPainter(Rudy::GraphicsAPIType graphicsApiType)
	{
		/*
		* Create event ledger
		*/
		m_EventLedger = new GUIPainterEventLedger();

		/*
		* Create render commands
		*/
		m_RenderCommands = Rudy::ImGuiRenderCommands::Create(graphicsApiType);

		/*
		* Create layout commands
		*/
		m_LayoutCommands = new Rudy::ImGuiLayoutCommands();

	}
	GUIPainter::~GUIPainter()
	{
		/*
		* Delete event ledger
		*/
	}
}