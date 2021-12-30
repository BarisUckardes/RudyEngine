#pragma once
#include <Rudy/Application/ApplicationModule.h>

namespace Rudy
{
	class RUDY_API TestModule : public ApplicationModule
	{
	public:
		TestModule() = default;
		~TestModule() = default;


		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnReceiveApplicationEvent(Event* event) override;
	};
}