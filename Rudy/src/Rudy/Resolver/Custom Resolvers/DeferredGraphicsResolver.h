#pragma once
#include <Rudy/Resolver/Resolvers/GraphicsResolver.h>

namespace Rudy
{
	class DeferredRenderable;
	class ImGuiRenderer;
	/// <summary>
	/// Deferred renderer
	/// </summary>
	class RUDY_API  DeferredGraphicsResolver : public GraphicsResolver
	{
	public:
		DeferredGraphicsResolver() = default;
		~DeferredGraphicsResolver() = default;
		virtual void Resolve() override;
		virtual void OnRegisterObserver(ObserverComponent* observer) override;
		virtual void OnRemoveObserver(ObserverComponent* observer) override;
		virtual Array<GraphicsObjectRegisterInfo> GetRegisterInformations() override;
	private:
		void OnDeferredRenderableRegistered(Component* renderable);
		void OnDeferredRenderableRemoved(Component* renderable);
		
		Array<DeferredRenderable*> m_Renderables;
		ImGuiRenderer* m_Imgui;
	};
}