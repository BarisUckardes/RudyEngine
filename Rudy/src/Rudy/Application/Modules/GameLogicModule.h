#pragma once
#include <Rudy/Application/ApplicationModule.h>


namespace Rudy
{
	class RUDY_API GameLogicModule : public ApplicationModule
	{
	public:
		GameLogicModule() = default;
		~GameLogicModule() = default;

		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnReceiveApplicationEvent(Event* event) override;
	};


}