#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Object/RudyObject.h>
namespace Rudy
{
	class World;

	/// <summary>
	/// Represents a single application session
	/// </summary>
	class RUDY_API ApplicationSession : RudyObject
	{
		friend class Application;
		GENERATE_REFLECTABLE_OBJECT(ApplicationSession);
	public:
		/// <summary>
		/// Registers anew world to this session
		/// </summary>
		/// <param name="world"></param>
		World* CreateWorld();

		/// <summary>
		/// Removes a world from this session
		/// </summary>
		/// <param name="world"></param>
		void RemoveWorld(World* world);
	protected:
		virtual void DestroyCore() override;
	private:
		ApplicationSession() = default;
		~ApplicationSession() = default;
		Array<World*> m_Worlds;
	};
}