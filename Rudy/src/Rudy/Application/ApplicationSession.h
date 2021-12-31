#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Object/RudyObject.h>
namespace Rudy
{
	class World;
	class GraphicsDevice;
	/// <summary>
	/// Represents a single application session
	/// </summary>
	class RUDY_API ApplicationSession : RudyObject
	{
		friend class Application;
		GENERATE_REFLECTABLE_OBJECT(ApplicationSession);
	public:
		/// <summary>
		/// Returns all the worlds this session has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<World*> GetWorlds() const;

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

		/// <summary>
		/// Returns the default graphics device for this session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetDefaultGraphicsDevice() const;
	protected:
		virtual void DestroyCore() override;
	private:
		ApplicationSession(GraphicsDevice* device);
		~ApplicationSession() = default;
		Array<World*> m_Worlds;
		GraphicsDevice* m_DefaultDevice;
	};
}