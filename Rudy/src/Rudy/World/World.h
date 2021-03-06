#pragma once
#include <Rudy/Memory/Array.h>
#include <Rudy/Object/AssetObject.h>
#include <Rudy/World/WorldView.h>
namespace Rudy
{
	class Entity;
	class ApplicationSession;
	class GraphicsDevice;
	/// <summary>
	/// Represents a collection entities and setups
	/// </summary>
	class __declspec(dllexport) World : public AssetObject
	{
		friend class ApplicationSession;
		GENERATE_REFLECTABLE_OBJECT(World);
	public:
		World() = default;
		/// <summary>
		/// Returns all the views this world has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<WorldView*> GetViews() const;

		/// <summary>
		/// Returns all the entities tihs world has
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<Entity*> GetEntities() const;

		/// <summary>
		/// Returns the specificed WorldView
		/// </summary>
		/// <typeparam name="TView"></typeparam>
		/// <returns></returns>
		template<typename TView>
		FORCEINLINE TView* GetView() const;

		/// <summary>
		/// Registers a world view to this world
		/// </summary>
		/// <typeparam name="TView"></typeparam>
		/// <typeparam name="...TParameters"></typeparam>
		/// <param name="...parameters"></param>
		/// <returns></returns>
		template<typename TView, typename... TParameters>
		TView* RegisterView(TParameters... parameters);

		/// <summary>
		/// Creates new entity
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Entity* CreateEntity();

		/// <summary>
		/// Returns the defualt graphics device for application session
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetDefaultGraphicsDevice() const;
	protected:
		virtual void FreeAssetCore() override;
	private:
		World(ApplicationSession* targetSession);
		~World() = default;


		Array<WorldView*> m_Views;
		Array<Entity*> m_Entities;
		ApplicationSession* m_OwnerSession;
	};

	GENERATE_REFLECTION_ACCESSOR(World);

	template<typename TView, typename ...TParameters>
	inline TView* World::RegisterView(TParameters... parameters)
	{
		/*
		* Create new view
		*/
		TView* view = new TView(parameters...);
		view->SetOwnerWorld(this);

		/*
		* Register view
		*/
		m_Views.Add(view);

		return view;

	}
	template<typename TView>
	inline TView* World::GetView() const
	{
		/*
		* Iterate each view and validate match
		*/
		for (int i = 0; i < m_Views.GetCursor(); i++)
		{
			/*
			* Get world view
			*/
			WorldView* worldView = m_Views[i];

			/*
			* Validate match
			*/
			if (worldView->GetType() == TView::GetStaticType())
				return (TView*)worldView;
		}

		return nullptr;
	}
}