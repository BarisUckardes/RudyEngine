#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	/// <summary>
	/// Base class for all world resolvers
	/// </summary>
	class RUDY_API IWorldResolver
	{
	public:
		IWorldResolver() = default;
		~IWorldResolver() = default;

		/// <summary>
		/// Resolves this world resolver
		/// </summary>
		virtual void Resolve() = 0;
	};


}