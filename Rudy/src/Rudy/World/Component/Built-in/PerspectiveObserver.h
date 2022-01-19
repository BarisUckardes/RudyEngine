#pragma once
#include <Rudy/Graphics/Components/ObserverComponent.h>

namespace Rudy
{
	class RUDY_API PerspectiveObserver : public ObserverComponent
	{
		GENERATE_REFLECTABLE_OBJECT(PerspectiveObserver);
	public:
		// Inherited via ObserverComponent
		virtual void DestroyCore() override;

		virtual bool ShouldTick() const override;

		virtual Matrix4x4 GetProjectionMatrix() const override;

		virtual Matrix4x4 GetViewMatrix() const override;

	};


}