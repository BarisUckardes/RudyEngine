#pragma once
#include <Rudy/Application/ApplicationModule.h>

namespace Rudy
{
	class RUDY_API GraphicsModule : public ApplicationModule
	{
	public:


		// Inherited via ApplicationModule
		virtual void OnAttach() override;

		virtual void OnUpdate() override;

		virtual void OnDetach() override;

		virtual void OnReceiveApplicationEvent(Event* event) override;

	};


}