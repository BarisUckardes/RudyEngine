#pragma once
#include <Rudy/Application/ApplicationModule.h>

namespace Rudy
{
	/// <summary>
	/// Hanldes the game inputs
	/// </summary>
	class RUDY_API GameInputModule : public ApplicationModule
	{
	public:
		GameInputModule() = default;
		~GameInputModule() = default;
		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnReceiveApplicationEvent(Event* event) override;
	};


}