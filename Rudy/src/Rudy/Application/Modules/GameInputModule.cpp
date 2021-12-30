#include "GameInputModule.h"
#include <stdio.h>
namespace Rudy
{
	void GameInputModule::OnAttach()
	{

	}
	void GameInputModule::OnUpdate()
	{

	}
	void GameInputModule::OnDetach()
	{

	}
	void GameInputModule::OnReceiveApplicationEvent(Event* event)
	{
		printf("Game input received event\n");
	}
}