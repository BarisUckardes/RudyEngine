#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Reflection/ReflectionCore.h>
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
		/// Sets the name of the rudy object
		/// </summary>
		/// <param name="name"></param>
		void SetName(const String& name);
	protected:
		RudyObject();
		~RudyObject() = default;

	private:
		String m_Name = "Rudy Object";
	};
}
