#pragma once
#include <Rudy/World/WorldView.h>

namespace Rudy
{
	class Component;
	class LogicResolver;

	/// <summary>
	/// Handles the logic aspect of a world
	/// </summary>
	class RUDY_API WorldLogicView : public WorldView
	{
		GENERATE_REFLECTABLE_OBJECT(WorldLogicView);
	public:
		WorldLogicView() = default;
		~WorldLogicView() = default;

		/// <summary>
		/// Returns all the component logic view has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<Component*> GetComponents() const;

		/// <summary>
		/// Returns the logic resolvers
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<LogicResolver*> GetLogicResolvers() const;

		/// <summary>
		/// Registers new component
		/// </summary>
		/// <param name="component"></param>
		FORCEINLINE void RegisterComponent(Component* component);

		/// <summary>
		/// Removes the existing component
		/// </summary>
		/// <param name="component"></param>
		FORCEINLINE void RemoveComponent(Component* component);
	protected:
		virtual void RegisterResolverCore(IWorldResolver* resolver) override;
		virtual void RemoveResolverCore(IWorldResolver* resolver) override;
	private:
		Array<LogicResolver*> m_Resolvers;
		Array<Component*> m_Components;

		
	};


}