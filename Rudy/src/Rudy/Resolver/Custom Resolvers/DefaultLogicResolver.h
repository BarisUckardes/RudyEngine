#pragma once
#include <Rudy/Resolver/Resolvers/LogicResolver.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	class RUDY_API DefaultLogicResolver : public LogicResolver
	{
	public:
		DefaultLogicResolver();
		~DefaultLogicResolver() = default;

		virtual void Resolve() override;
		virtual void OnRegisterComponent(Component* component) override;
		virtual void OnRemoveComponent(Component* component) override;
	private:
		void InvalidatePendings();

		Array<Component*> m_RegisterPendingComponents;
		Array<Component*> m_RemovePendingComponents;
		Array<Component*> m_ActiveComponents;

	};

}
