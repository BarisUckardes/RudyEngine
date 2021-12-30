#pragma once
#include <Rudy/Object/RudyObject.h>
#include <Rudy/Component/Component.h>
#include <Rudy/Component/Built-in/Spatial.h>
#include <Rudy/World/Views/WorldLogicView.h>
#include <Rudy/World/World.h>
namespace Rudy
{
	class World;
	class RUDY_API Entity : public RudyObject
	{
		friend class World;
	public:
		GENERATE_REFLECTABLE_OBJECT(Entity);
		Entity() = default;
		~Entity() = default;

		/// <summary>
		/// Returns all the components this entity has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<Component*> GetComponents() const;

		/// <summary>
		/// Returns the owner world of this entity
		/// </summary>
		/// <returns></returns>
		FORCEINLINE World* GetOwnerWorld() const;

		/// <summary>
		/// Returns the spatial component of this entity
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Spatial* GetSpatial() const;

		/// <summary>
		/// Creates and returns the component specified
		/// </summary>
		/// <typeparam name="TComponent"></typeparam>
		/// <typeparam name="...TParameters"></typeparam>
		/// <param name="...parameters"></param>
		/// <returns></returns>
		template<typename TComponent,typename...TParameters>
		TComponent* CreateComponent(TParameters... parameters);

		/// <summary>
		/// Tries to delete the component, returns the result of the deletion
		/// </summary>
		/// <typeparam name="TComponent"></typeparam>
		/// <returns></returns>
		template<typename TComponent>
		bool DeleteComponent();

		/// <summary>
		/// Tries to find component and return it, returns nullptr if there was no component with specified type
		/// </summary>
		/// <typeparam name="TComponent"></typeparam>
		/// <returns></returns>
		template<typename TComponent>
		TComponent* GetComponent() const;
	protected:
		virtual void DestroyCore() override;
	private:
		Array<Component*> m_Components;
		World* m_OwnerWorld;
		Spatial* m_Spatial;
	};
	template<typename TComponent, typename ...TParameters>
	inline TComponent* Entity::CreateComponent(TParameters ...parameters)
	{
		/*
		* Create new component
		*/
		TComponent* component = new TComponent(parameters...);
		component->SetOwnerEntity(this);

		/*
		* Register entity to world logic view
		*/
		GetOwnerWorld()->GetView<WorldLogicView>()->RegisterComponent(component);

		/*
		* Register to self list
		*/
		m_Components.Add((Component*)component);

		return component;
	}
	template<typename TComponent>
	inline bool Entity::DeleteComponent()
	{
		for (int i = 0; i < m_Components.GetCursor(); i++)
		{
			/*
			* Get component
			*/
			Component* component = m_Components[i];

			/*
			* Validate component match
			*/
			if (TComponent::GetStaticType() == component->GetType())
			{
				/*
				* Unregister from the world logic view
				*/
				GetOwnerWorld()->GetView<WorldLogicView>()->RemoveComponent(component);
	
				
				return true;
			}
		}
		return false;
	}
	template<typename TComponent>
	inline TComponent* Entity::GetComponent() const
	{
		for (int i = 0; i < m_Components.GetCursor(); i++)
		{
			/*
			* Get component
			*/
			Component* component = m_Components[i];

			/*
			* Validate component match
			*/
			if (TComponent::GetStaticType() == component->GetType())
				return (TComponent*)component;
		}
		return nullptr;
	}
}