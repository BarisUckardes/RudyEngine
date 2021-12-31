#pragma once
#include <Rudy/Object/RudyObject.h>
#include <Rudy/Memory/Array.h>

namespace Rudy
{
	/// <summary>
	/// Base class for all world views
	/// </summary>
	class IWorldResolver;
	class World;
	class RUDY_API WorldView : public RudyObject
	{
		friend class World;
	public:
		/// <summary>
		/// Register a new resolver to this view
		/// </summary>
		/// <typeparam name="TResolver"></typeparam>
		template<typename TResolver,typename... TParameters>
		void RegisterResolver(TParameters... parameters);

		/// <summary>
		/// Removes an exisitng resolver from this view
		/// </summary>
		template<typename TResolver>
		void RemoveResolver();
	protected:
		WorldView() = default;
		~WorldView() = default;

		/// <summary>
		/// Implementation method for registering a resolver
		/// </summary>
		/// <param name="resolver"></param>
		virtual void RegisterResolverCore(IWorldResolver* resolver) = 0;

		/// <summary>
		/// Implementation method for removing a resolver
		/// </summary>
		/// <param name="resolver"></param>
		virtual void RemoveResolverCore(IWorldResolver* resolver) = 0;
	private:
		/// <summary>
		/// Sets world as owner world for this world view
		/// </summary>
		/// <param name="world"></param>
		void SetOwnerWorld(World* world);
		World* m_OwnerWorld;
	};



	template<typename TResolver, typename ...TParameters>
	inline void WorldView::RegisterResolver(TParameters... parameters)
	{
		/*
		* Create resolver
		*/
		TResolver* resolver = new TResolver(parameters...);
		resolver->SetOwnerWorld(m_OwnerWorld);

		/*
		* Register this resolver
		*/
		RegisterResolverCore(resolver);
	}

	template<typename TResolver>
	inline void WorldView::RemoveResolver()
	{
		/*
		* Itereate each resolver and validate match
		*/
		//for (int i = 0; i < m_Resolvers.GetCursor(); i++)
		//{
		//	/*
		//	* Get resolver
		//	*/
		//	IWorldResolver* resolver = m_Resolvers[i];

		//	/*
		//	* Validate match
		//	*/
		//	//RemoveResolverCore(resolver);
		//}

	}

}