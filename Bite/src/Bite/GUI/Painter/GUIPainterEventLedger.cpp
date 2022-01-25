#include "GUIPainterEventLedger.h"
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyReleasedEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonDownEvent.h>
#include <Rudy/Application/Events/Mouse/MouseButtonUpEvent.h>
#include <Rudy/Application/Events/Mouse/MousePositionChangedEvent.h>
#include <Rudy/Application/Events/Mouse/MouseScrolledEvent.h>
#include <Rudy/Application/Events/Window/WindowDropFileEvent.h>
#include <Rudy/ImGui/Commands/ImGuiEventCommands.h>
#include <stdio.h>

namespace Bite
{
	GUIPainterEventLedger::GUIPainterEventLedger()
	{
		m_KeyStates.Reserve(360);
	}
	GUIPainterEventLedger::~GUIPainterEventLedger()
	{

	}
	void GUIPainterEventLedger::ClearEvents()
	{
		m_KeyStates.Clear();
		m_KeyStates.Reserve(360);
		m_FileDrops.Clear();
	}
	bool GUIPainterEventLedger::IsKeyPressed(unsigned int key) const
	{
		return m_KeyStates[key] == KeyEvent::Pressed;
	}
	bool GUIPainterEventLedger::IsKeyDown(unsigned int key) const
	{
		return m_KeyStates[key] == KeyEvent::Down;
	}
	bool GUIPainterEventLedger::IsKeyReleased(unsigned int key) const
	{
		return m_KeyStates[key] == KeyEvent::Released;
	}
	bool GUIPainterEventLedger::IsMouseButtonReleased(unsigned int button) const
	{
		return m_KeyStates[button] == KeyEvent::Released;
	}
	bool GUIPainterEventLedger::IsMouseButtonDown(unsigned int button) const
	{
		return m_KeyStates[button] == KeyEvent::Down;
	}
	bool GUIPainterEventLedger::IsWindowHavored() const
	{
		return Rudy::ImGuiEventCommands::IsWindowHavored();
	}
	bool GUIPainterEventLedger::IsWindowFocused() const
	{
		return Rudy::ImGuiEventCommands::IsWindowFocused();
	}
	bool GUIPainterEventLedger::IsAnyItemHavored() const
	{
		return Rudy::ImGuiEventCommands::IsAnyItemHavored();
	}
	bool GUIPainterEventLedger::IsCurrentItemHavored() const
	{
		return Rudy::ImGuiEventCommands::IsCurrentItemHavored();
	}
	Rudy::Vector2f GUIPainterEventLedger::GetMouseWheelAmount() const
	{
		return m_MouseWheelAmount;
	}
	Rudy::Vector2i GUIPainterEventLedger::GetMouseCursor() const
	{
		return m_CursorPosition;
	}
	Rudy::Array<Rudy::String> GUIPainterEventLedger::GetFileDrops() const
	{
		return m_FileDrops;
	}
	void GUIPainterEventLedger::OnLedgerReceivedEvent(Rudy::Event* event)
	{
		/*
		* Get event type
		*/
		const Rudy::EventType type = event->GetEventType();

		/*
		* Catch event type
		*/
		switch (type)
		{
			case Rudy::EventType::Undefined:
				break;
			case Rudy::EventType::KeyboardKeyDown:
			{
				/*
				* Get keydown event
				*/
				Rudy::KeyboardKeyDownEvent* kEvent = (Rudy::KeyboardKeyDownEvent*)event;

				/*
				* Validate if its a first time pressed or not
				*/
				if (kEvent->GetRepeatCount() == 0)
				{
					m_KeyStates[kEvent->GetRelatedKey()] = KeyEvent::Pressed;
				}
				else
				{
					m_KeyStates[kEvent->GetRelatedKey()] = KeyEvent::Down;
				}
				break;
			}
			case Rudy::EventType::KeyboardKeyUp:
			{
				/*
				* Get key released event
				*/
				Rudy::KeyboardKeyReleasedEvent* kEvent = (Rudy::KeyboardKeyReleasedEvent*)event;

				/*
				* Set released key
				*/
				m_KeyStates[kEvent->GetRelatedKey()] = KeyEvent::Released;
				break;
			}
			case Rudy::EventType::KeyboardChar:
				break;
			case Rudy::EventType::WindowResized:
				break;
			case Rudy::EventType::WindowClosed:
				break;
			case Rudy::EventType::WindowOffsetChanged:
				break;
			case Rudy::EventType::MouseButtonDown:
			{
				/*
				* Get mouse button down event
				*/
				Rudy::MouseButtonDownEvent* mEvent = (Rudy::MouseButtonDownEvent*)event;

				/*
				* Validate if its a pressed or down event
				*/
				m_KeyStates[mEvent->GetButton()] = KeyEvent::Down;
				break;
			}
			case Rudy::EventType::MouseButtonUp:
			{
				/*
				* Get mouse button down event
				*/
				Rudy::MouseButtonUpEvent* mEvent = (Rudy::MouseButtonUpEvent*)event;

				/*
				* Set release button
				*/
				m_KeyStates[mEvent->GetButton()] = KeyEvent::Released;
				break;
			}
			case Rudy::EventType::MouseScrolled:
			{
				/*
				* Get mouse wheel scrolled
				*/
				Rudy::MouseScrolledEvent* mEvent = (Rudy::MouseScrolledEvent*)event;

				/*
				* Set scroll
				*/
				m_MouseWheelAmount = mEvent->GetAmount();

				break;
			}
			case Rudy::EventType::MousePositionChanged:
			{
				/*
				* Get mouse position
				*/
				Rudy::MousePositionChangedEvent* mEvent = (Rudy::MousePositionChangedEvent*)event;

				/*
				* Set mouse position
				*/
				m_CursorPosition = mEvent->GetPosition();
				break;
			}
			case Rudy::EventType::WindowFileDrop:
			{
				/*
				* get file drop event
				*/
				Rudy::WindowDropFileEvent* wEvent = (Rudy::WindowDropFileEvent*)event;

				/*
				* Set file drops
				*/
				m_FileDrops = wEvent->GetDropFilePaths();
				break;
			}
			default:
				break;
		}
	}
}