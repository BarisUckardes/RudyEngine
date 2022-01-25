#include "GUIPainter.h"
#include <Bite/GUI/Painter/GUIPainterEventLedger.h>
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
#include <Rudy/ImGui/Commands/ImGuiRenderCommands.h>
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

	}
	GUIPainter::~GUIPainter()
	{
		/*
		* Delete event ledger
		*/
	}
}