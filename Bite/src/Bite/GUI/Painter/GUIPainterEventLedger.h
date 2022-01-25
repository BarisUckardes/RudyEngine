#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Application/Events/Event.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Mathematics/Vector2f.h>
namespace Bite
{
	/// <summary>
	/// GUIPainter's event ledger class
	/// </summary>
	class BITE_API GUIPainterEventLedger
	{
		friend class GUIPainter;
	public:
		/// <summary>
		/// Returns whether the key is pressed for the first time
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE bool IsKeyPressed(unsigned int key) const;

		/// <summary>
		/// Returns whether the key is held down
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE bool IsKeyDown(unsigned int key) const;

		/// <summary>
		/// Returns whether the key is released
		/// </summary>
		/// <param name="key"></param>
		/// <returns></returns>
		FORCEINLINE bool IsKeyReleased(unsigned int key) const;

		/// <summary>
		/// Returns if the specified button is pressed
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		FORCEINLINE bool IsMouseButtonPressed(unsigned int button) const;

		/// <summary>
		/// Returns if the specified button is released
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		FORCEINLINE bool IsMouseButtonReleased(unsigned int button) const;

		/// <summary>
		/// Returns if the specified button is down
		/// </summary>
		/// <param name="button"></param>
		/// <returns></returns>
		FORCEINLINE bool IsMouseButtonDown(unsigned int button) const;

		/// <summary>
		/// Returns the mouse wheel scroll amount
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetMouseWheelAmount() const;

		/// <summary>
		/// Get mouse cursor position in pixel coordinates
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::Vector2f GetMouseCursor() const;

		/// <summary>
		/// Returns the drop file events
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::Array<Rudy::String> GetDropFiles() const;
	private:
		enum class KeyEvent
		{
			NoEventReceived = 0,
			Pressed = 1,
			Down = 2,
			Released = 4
		};

		/// <summary>
		/// Called when ledger receives an event
		/// </summary>
		/// <param name="event"></param>
		void OnLedgerReceivedEvent(Rudy::Event* event);

		/// <summary>
		/// Clears the event buffer
		/// </summary>
		void ClearEvents();

		GUIPainterEventLedger();
		~GUIPainterEventLedger();

		Rudy::Array<KeyEvent> m_KeyStates;
		Rudy::Array<KeyEvent> m_MouseButtonStates;
		Rudy::Vector2f m_CursorPosition;
		float m_MouseWheelAmount;
	};


}