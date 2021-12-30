#pragma once
#include <Rudy/Object/RudyObject.h>

namespace Rudy
{

	class Entity;
	/// <summary>
	/// Base component class for all entity components
	/// </summary>
	class RUDY_API Component : public RudyObject
	{
		friend class Entity;
	public:
		/// <summary>
		/// Returns the owner entity of this component
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Entity* GetOwnerEntity() const;

		/// <summary>
		/// Returns whether this component should thick or not
		/// </summary>
		/// <returns></returns>
		virtual bool ShouldTick() const = 0;

		/// <summary>
		/// Called when logic module ticked
		/// </summary>
		virtual void OnUpdate();

		/// <summary>
		/// Called when first time attached to an entity
		/// </summary>
		virtual void OnAttach();

		/// <summary>
		/// Called when delete from an entity
		/// </summary>
		virtual void OnDetach();
	protected:
		Component() = default;
		~Component();
	private:
		/// <summary>
		/// Sets the owner entity for this component
		/// </summary>
		/// <param name="ownerEntity"></param>
		void SetOwnerEntity(Entity* ownerEntity);
		Entity* m_OwnerEntity;
	};


}