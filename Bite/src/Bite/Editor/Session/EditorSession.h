#pragma once
#include <Bite/Core/Symbols.h>
namespace Rudy
{
	class ApplicationSession;
}
namespace Bite
{
	class BITE_API EditorSession
	{
	public:
		EditorSession(Rudy::ApplicationSession* applicationSession);
		~EditorSession();

		/// <summary>
		/// returns the application session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Rudy::ApplicationSession* GetApplictionSession() const;
	private:
		Rudy::ApplicationSession* m_ApplicationSession;
	};


}