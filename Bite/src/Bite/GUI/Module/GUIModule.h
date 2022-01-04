#pragma once
#include <Bite/Core/Symbols.h>

namespace Bite
{
	class EditorSession;
	class BITE_API GUIModule
	{
		friend class BiteModule;
	public:
		GUIModule() = default;
		virtual ~GUIModule() = 0;

		virtual void OnAttach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDetach() = 0;
	protected:
		FORCEINLINE EditorSession* GetOwnerSession() const;
	private:
		void SetOwnerSession(EditorSession* session);
		EditorSession* m_OwnerSession;
	};
}