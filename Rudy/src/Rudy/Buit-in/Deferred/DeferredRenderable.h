#pragma once
#include <Rudy/Component/Component.h>

namespace Rudy
{
	class RUDY_API DeferredRenderable : public Component
	{
		GENERATE_REFLECTABLE_OBJECT(DeferredRenderable);
	public:
		DeferredRenderable() = default;
		~DeferredRenderable() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void DestroyCore() override;
		virtual bool ShouldTick() const override;
	};


}