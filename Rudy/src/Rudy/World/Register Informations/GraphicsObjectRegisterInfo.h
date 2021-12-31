#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Events/Delegate.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
#include <Rudy/Reflection/Object/ReflectableObject.h>
namespace Rudy
{
	class Component;

	/// <summary>
	/// Provides parameterized register/remove to the graphics resolvers
	/// </summary>
	class RUDY_API GraphicsObjectRegisterInfo
	{
	public:
		GraphicsObjectRegisterInfo(RudyType rudyType,const Delegate<void,Component*>& registerDelegate,const Delegate<void,Component*>& removeDelegate);
		GraphicsObjectRegisterInfo() = default;
		~GraphicsObjectRegisterInfo() = default;

		/// <summary>
		/// Returns the target type of this register info
		/// </summary>
		/// <returns></returns>
		FORCEINLINE RudyType GetTargetType() const;

		/// <summary>
		/// Called when an object with the target type registers itself to a WorldGraphicsView
		/// </summary>
		/// <param name="component"></param>
		void Register(Component* component);

		/// <summary>
		/// Called when an object with the target type removes itself from a WorldGraphicsView
		/// </summary>
		/// <param name="component"></param>
		void Remove(Component* component);
	private:
		RudyType m_TargetType;
		Delegate<void, Component*> m_RegisterDelegate;
		Delegate<void, Component*> m_RemoveDelegate;
	};
}