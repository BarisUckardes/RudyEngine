#pragma once
#include <Bite/Core/Symbols.h>

namespace Bite
{
	class EditorSession;

	/// <summary>
	/// A GUI module for bite main module
	/// </summary>
	class BITE_API GUIModule
	{
		friend class BiteModule;
	public:
		GUIModule() = default;
		virtual ~GUIModule() = 0;

		/// <summary>
		/// Called when intialized via bite
		/// </summary>
		virtual void OnAttach() = 0;

		/// <summary>
		/// Called when bite module tick
		/// </summary>
		virtual void OnUpdate() = 0;

		/// <summary>
		/// Called when terminated by bite
		/// </summary>
		virtual void OnDetach() = 0;
	protected:

		/// <summary>
		/// Returns the owner editor session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE EditorSession* GetOwnerSession() const;
	private:
		/// <summary>
		/// Internal owner session setter
		/// </summary>
		/// <param name="session"></param>
		void SetOwnerSession(EditorSession* session);
		EditorSession* m_OwnerSession;
	};
}