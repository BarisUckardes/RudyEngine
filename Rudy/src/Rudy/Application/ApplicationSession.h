#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Object/RudyObject.h>
namespace Rudy
{
	class World;
	class GraphicsDevice;
	class Window;
	class Guid;
	class AssetPool;
	/// <summary>
	/// Represents a single application session
	/// </summary>
	class RUDY_API ApplicationSession
	{
		friend class Application;
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
		/// Loads and creates via guid
		/// </summary>
		/// <param name="worldID"></param>
		/// <returns></returns>
		World* LoadViaAsset(const Guid& worldID);

		/// <summary>
		/// Removes a world from this session
		/// </summary>
		/// <param name="world"></param>
		void RemoveWorld(World* world);

		/// <summary>
		/// Returns the session window
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Window* GetSessionWindow() const;

		/// <summary>
		/// Returns the default graphics device for this session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetDefaultGraphicsDevice() const;
	private:
		ApplicationSession(const String& packagesPath,Window* window,GraphicsDevice* defaultGraphicsDevice);
		~ApplicationSession();

		Array<World*> m_Worlds;
		AssetPool* m_AssetPool;
		Window* m_Window;
		GraphicsDevice* m_DefaultDevice;

	};
}