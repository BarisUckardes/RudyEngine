#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	class World;
	/// <summary>
	/// Base class for all world resolvers
	/// </summary>
	class RUDY_API IWorldResolver
	{
		friend class WorldView;
	public:
		IWorldResolver() = default;
		~IWorldResolver() = default;

		/// <summary>
		/// Resolves this world resolver
		/// </summary>
		virtual void Resolve() = 0;
	protected:
		FORCEINLINE World* GetOwnerWorld() const;
	private:
		void SetOwnerWorld(World* ownerWorld);
		World* m_OwnerWorld;
	};


}