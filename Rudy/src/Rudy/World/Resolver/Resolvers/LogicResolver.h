#pragma once
#include <Rudy/World/Resolver/IWorldResolver.h>

namespace Rudy
{
	class Component;

	/// <summary>
	/// Base resolver class for all logic resolvers
	/// </summary>
	class RUDY_API LogicResolver : public IWorldResolver
	{
	public:
		LogicResolver() = default;
		~LogicResolver() = default;

		/// <summary>
		/// Called when anew tickable component is created
		/// </summary>
		/// <param name="component"></param>
		virtual void OnRegisterComponent(Component* component) = 0;

		/// <summary>
		/// Called when existing component deleted
		/// </summary>
		/// <param name="component"></param>
		virtual void OnRemoveComponent(Component* component) = 0;
	};


}