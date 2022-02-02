#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Reflection/ReflectionCore.h>
namespace Bite
{
	class EditorSession;
	class GUIPainter;
	class GUIPainterEventLedger;
	/// <summary>
	/// A renderable layout object for window GUI behaviours
	/// </summary>
	class BITE_API WindowLayout : public Rudy::ReflectableObject
	{
		friend class GUIWindowManager;
		friend class WindowGUIModule;
	public:
		GENERATE_REFLECTABLE_OBJECT(WindowLayout);
		WindowLayout() = default;
		~WindowLayout() = default;

		/// <summary>
		/// Returns whether this window is visible or not
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsVisible() const;

		/// <summary>
		/// Called when first created
		/// </summary>
		virtual void OnLayoutSetup() = 0;

		/// <summary>
		/// Called when gui rendered
		/// </summary>
		virtual void OnLayoutRender() = 0;

		/// <summary>
		/// Called when deleted
		/// </summary>
		virtual void OnLayoutFinalize() = 0;

		/// <summary>
		/// Called when become visible
		/// </summary>
		virtual void OnVisible() = 0;

		/// <summary>
		/// Called when become invisible
		/// </summary>
		virtual void OnInvisible() = 0;

		/// <summary>
		/// Returns the window name
		/// </summary>
		/// <returns></returns>
		virtual Rudy::String GetWindowName() const;
	protected:
		/// <summary>
		/// Returns the owner session for this window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE EditorSession* GetOwnerSession() const;

		/// <summary>
		/// Returns the session painter
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GUIPainter* GetPainter() const;

		/// <summary>
		/// Returns the event ledger for the session painter
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GUIPainterEventLedger* GetEventLedger() const;
	private:
		/// <summary>
		/// Internal session setter
		/// </summary>
		/// <param name="session"></param>
		void SetEditorSession(EditorSession* session);

		/// <summary>
		/// Internal visiblity setter
		/// </summary>
		/// <param name="state"></param>
		void SetVisibilityState(bool state);
		EditorSession* m_OwnerSession;
		bool m_Visible;
	};
	GENERATE_REFLECTION_ACCESSOR(WindowLayout);

}
