#pragma once
#include <Rudy/Memory/Guid.h>

namespace Rudy
{
	class RUDY_API WindowsGuid
	{
	public:
		WindowsGuid() = delete;
		~WindowsGuid() = delete;

		static Guid CreateGuid();
	};


}