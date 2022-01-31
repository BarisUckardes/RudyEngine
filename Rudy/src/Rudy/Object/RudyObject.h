#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Reflection/Object/ReflectableObject.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
	/// <summary>
	/// Core rudy object for all engine objects
	/// </summary>
	class RUDY_API RudyObject : public ReflectableObject
	{
		friend class Asset;
	public:
		/// <summary>
		/// Returns the name of this rudy object
		/// </summary>
		/// <returns></returns>
		String GetName() const;

		/// <summary>
		/// Returns whether this rudy object is destroyed or not
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsDestroyed() const;

		/// <summary>
		/// Sets the name of the rudy object
		/// </summary>
		/// <param name="name"></param>
		void SetName(const String& name);

		/// <summary>
		/// Destroys the rudy object
		/// </summary>
		void Destroy();
	protected:
		RudyObject();
		~RudyObject() = default;

		/// <summary>
		/// Implementation of the destroy
		/// </summary>
		virtual void DestroyCore() = 0;
	private:
		String m_Name = "Rudy Object";
		bool m_Destroyed;
	};
}
