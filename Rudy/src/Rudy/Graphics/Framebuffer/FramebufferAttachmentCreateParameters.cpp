#include "FramebufferAttachmentCreateParameters.h"
namespace Rudy
{
	FramebufferAttachmentCreateParameters::FramebufferAttachmentCreateParameters(const String& name, TextureFormat format, TextureInternalFormat internalFormat, TextureDataType dataType)
	{
		Name = name;
		Format = format;
		InternalFormat = internalFormat;
		DataType = dataType;
	}
}