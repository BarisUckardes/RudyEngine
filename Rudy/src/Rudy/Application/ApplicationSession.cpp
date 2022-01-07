#include "ApplicationSession.h"
#include <Rudy/World/World.h>
#include <Rudy/Asset/AssetPool.h>
#include <Rudy/Windowing/Window.h>
#include <Rudy/Platform/Utility/PlatformDirectory.h>
namespace Rudy
{
	ApplicationSession::ApplicationSession(const String& packagesPath,Window* window,GraphicsDevice* defaultDevice)
	{
		/*
		* Set default graphics device
		*/
		m_DefaultDevice = defaultDevice;
		m_Window = window;

		/*
		* Find packages
		*/
		Array<String> packagePaths;
		PlatformDirectory::GetFilesInDirectoryViaExtension(packagesPath, ".rpackage", packagePaths);

		/*
		* Create asset pool
		*/
		m_AssetPool = new AssetPool(packagePaths);
	}
	ApplicationSession::~ApplicationSession()
	{
		/*
		* Delete worlds
		*/
		for (int i = 0; i < m_Worlds.GetCursor(); i++)
		{
			/*
			* Get world
			*/
			World* world = m_Worlds[i];
			
			/*
			* Destroy world
			*/
			world->Destroy();

			/*
			* Delete heap object
			*/
			delete world;
		}
		m_Worlds.Clear();

		/*
		* Delete asset pool
		*/
		delete m_AssetPool;
	}
	Array<World*> ApplicationSession::GetWorlds() const
	{
		return m_Worlds;
	}
	World* ApplicationSession::CreateWorld()
	{
		/*
		* Create new world
		*/
		World* world = new World(this);

		/*
		* Register
		*/
		m_Worlds.Add(world);

		return world;
	}

	World* ApplicationSession::LoadViaAsset(const Guid& worldID)
	{
		return nullptr;
	}

	void ApplicationSession::RemoveWorld(World* world)
	{
		/*
		* Try find world
		*/
		for (int i = 0; i < m_Worlds.GetCursor(); i++)
		{
			/*
			* Get world
			*/
			World* world = m_Worlds[i];

			/*
			* Destroy the world
			*/
			world->Destroy();

			/*
			* Free the memory
			*/
			delete world;
			return;
		}

	}

	Window* ApplicationSession::GetSessionWindow() const
	{
		return m_Window;
	}

	GraphicsDevice* ApplicationSession::GetDefaultGraphicsDevice() const
	{
		return m_DefaultDevice;
	}
}