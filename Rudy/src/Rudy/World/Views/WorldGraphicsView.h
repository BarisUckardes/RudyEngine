#pragma once
#include <Rudy/World/WorldView.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/World/Register Informations/GraphicsObjectRegisterInfo.h>
namespace Rudy
{
	class ObserverComponent;
	class Component;
	class GraphicsResolver;

	/// <summary>
	/// Handles the graphics aspect of a world
	/// </summary>
	class RUDY_API WorldGraphicsView : public WorldView
	{
		GENERATE_REFLECTABLE_OBJECT(WorldGraphicsView);
	public:
		WorldGraphicsView() = default;
		~WorldGraphicsView() = default;

		/// <summary>
		/// Registers a new observer to the graphics view
		/// </summary>
		/// <param name="observer"></param>
		void RegisterObserver(ObserverComponent* observer);

		/// <summary>
		/// Removes the existing object from the graphics view
		/// </summary>
		/// <param name="observer"></param>
		void RemoveObserver(ObserverComponent* observer);

		/// <summary>
		/// Registers a new graphics object to the graphics view
		/// </summary>
		/// <param name="component"></param>
		void RegisterGraphicsObject(Component* component);

		/// <summary>
		/// Removes the existing object from the graphics view
		/// </summary>
		/// <param name="component"></param>
		void RemoveGraphicsObject(Component* component);

		/// <summary>
		/// Returns all the graphics resolvers this graphics view has
		/// </summary>
		/// <returns></returns>
		Array<GraphicsResolver*> GetGraphicsResolvers() const;
	private:
		virtual void RegisterResolverCore(IWorldResolver* resolver) override;
		virtual void RemoveResolverCore(IWorldResolver* resolver) override;

		Array<Array<GraphicsObjectRegisterInfo>> m_RegisterInformations;
		Array<GraphicsResolver*> m_GraphicsResolvers;

		
	};


}