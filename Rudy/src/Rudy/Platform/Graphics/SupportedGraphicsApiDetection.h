#pragma once
#include <Rudy/Platform/Graphics/GraphicsAPIType.h>
#include <Rudy/Memory/Array.h>

namespace Rudy
{
	RUDY_API Array<GraphicsAPIType> GetSupportedGraphicsAPI();
}
