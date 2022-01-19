#include "SupportedGraphicsApiDetection.h"

namespace Rudy
{
	/// <summary>
	/// Returns the supported graphics api types for the current platyform
	/// </summary>
	/// <returns></returns>
	Array<GraphicsAPIType> GetSupportedGraphicsAPI()
	{
		Array<GraphicsAPIType> supportedTypes;
#ifdef RUDY_OS_WINDOWS
		supportedTypes.Add(GraphicsAPIType::OpenGL);
		supportedTypes.Add(GraphicsAPIType::Directx12);
		supportedTypes.Add(GraphicsAPIType::Directx11);
		supportedTypes.Add(GraphicsAPIType::Vulkan);
#elif RUDY_OS_LINUX
		supportedTypes.Add(GraphicsAPIType::OpenGL);
		supportedTypes.Add(GraphicsAPIType::Vulkan);
#endif

		return supportedTypes;
	}
}