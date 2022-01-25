#include "GUIPainterEventLedger.h"
#include <Rudy/Application/Events/Keyboard/KeyboardKeyDownEvent.h>
#include <Rudy/Application/Events/Keyboard/KeyboardKeyReleasedEvent.h>
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
	bool GUIPainterEventLedger::IsMouseButtonPressed(unsigned int button) const
	{
		return m_KeyStates[button] == KeyEvent::Pressed;
	}
	bool GUIPainterEventLedger::IsMouseButtonReleased(unsigned int button) const
	{
		return m_KeyStates[button] == KeyEvent::Released;
	}
	bool GUIPainterEventLedger::IsMouseButtonDown(unsigned int button) const
	{
		return m_KeyStates[button] == KeyEvent::Down;
	}
	float GUIPainterEventLedger::GetMouseWheelAmount() const
	{
		return m_MouseWheelAmount;
	}
	Rudy::Vector2f GUIPainterEventLedger::GetMouseCursor() const
	{
		return m_CursorPosition;
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
				break;
			case Rudy::EventType::MouseButtonUp:
				break;
			case Rudy::EventType::MouseScrolled:
				break;
			case Rudy::EventType::MousePositionChanged:
				break;
			case Rudy::EventType::WindowFileDrop:
				break;
			default:
				break;
		}
	}
}