#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Reflection/Object/ReflectableObject.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Bite
{
	class EditorSession;
	class BITE_API WindowLayout : public Rudy::ReflectableObject
	{
		friend class GUIWindowManager;
		friend class WindowGUIModule;
	public:
		WindowLayout() = default;
		~WindowLayout() = default;

		FORCEINLINE bool IsVisible() const;

		virtual void OnLayoutSetup() = 0;
		virtual void OnLayoutRender() = 0;
		virtual void OnLayoutFinalize() = 0;
		virtual void OnVisible() = 0;
		virtual void OnInvisible() = 0;

		virtual Rudy::String GetWindowName() const;

	protected:
		FORCEINLINE EditorSession* GetOwnerSession() const;
	private:
		void SetEditorSession(EditorSession* session);
		void SetVisibilityState(bool state);
		EditorSession* m_OwnerSession;
		bool m_Visible;
	};

}
