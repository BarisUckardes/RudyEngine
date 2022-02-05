#pragma once
#include <Bite/Core/Symbols.h>

namespace Rudy
{
	class ApplicationSession;
	class RudyObject;
	class ByteBlock;
}
namespace Bite
{
	/// <summary>
	/// Asset writer interface for the custom writers to implement
	/// </summary>
	class BITE_API IAssetWriter
	{
	public:
		IAssetWriter(Rudy::ApplicationSession* session);
		~IAssetWriter();

		/// <summary>
		/// Writing asset bytes into destinationBytes implemetnation
		/// </summary>
		/// <param name="sourceBytes"></param>
		/// <param name="destinationBytes"></param>
		virtual void Write(const void* parameters, Rudy::ByteBlock& destinationBytes) = 0;

	protected:

		/// <summary>
		/// Returns the session for the writer
		/// </summary>
		/// <returns></returns>
		Rudy::ApplicationSession* GetSession() const;
	private:
		Rudy::ApplicationSession* m_Session;
	};
}