#pragma once
#include <Rudy/Platform/Implementation/Graphics/GraphicsAPIType.h>
#include <Rudy/Memory/Array.h>

namespace Rudy
{
	RUDY_API Array<GraphicsAPIType> GetSupportedGraphicsAPI();
}
