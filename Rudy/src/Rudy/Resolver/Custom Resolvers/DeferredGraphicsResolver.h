#pragma once
#include <Rudy/Resolver/Resolvers/GraphicsResolver.h>

namespace Rudy
{
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
	};
}