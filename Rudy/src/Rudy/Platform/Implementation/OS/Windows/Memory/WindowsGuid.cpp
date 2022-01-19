#include "WindowsGuid.h"
#include <rpc.h>
#include <stdio.h>

namespace Rudy
{
	Guid WindowsGuid::CreateGuid()
	{
		/*
		* Create default guid
		*/
		Guid guid;

		/*
		* Create guid using windows os
		*/
		CoCreateGuid((GUID*)&guid);

		return guid;
	}
}