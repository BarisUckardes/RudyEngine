#pragma once
#include <Bite/Core/Symbols.h>

namespace Bite
{
	class EditorSession;

	/// <summary>
	/// A command which only executed upon editor initialization and finalization
	/// </summary>
	class BITE_API EditorCommand
	{
		friend class BiteModule;
	public:
		EditorCommand() = default;
		virtual ~EditorCommand() = 0;

		/// <summary>
		/// Called when the editor is intialized
		/// </summary>
		virtual void OnInitialize() = 0;

		/// <summary>
		/// Called when the editor is initialized
		/// </summary>
		virtual void OnFinalize() = 0;
	protected:

		/// <summary>
		/// Returns the owner editor session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE EditorSession* GetOwnerSession() const;
	private:

		/// <summary>
		/// Sets the owner editor session
		/// </summary>
		/// <param name="session"></param>
		void SetOwnerSession(EditorSession* session);
		EditorSession* m_OwnerSession;
	};


}