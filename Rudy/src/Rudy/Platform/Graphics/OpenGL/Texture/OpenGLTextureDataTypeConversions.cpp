#include "OpenGLTextureDataTypeConversions.h"
#include <GLAD/glad.h>
namespace Rudy
{
	unsigned int OpenGLTextureDataTypeConversions::GetOpenGLTextureDataType(TextureDataType dataType)
	{
		switch (dataType)
		{
		case Rudy::TextureDataType::None:
			return 0;
			break;
		case Rudy::TextureDataType::Byte:
			return GL_BYTE;
			break;
		case Rudy::TextureDataType::UnsignedByte:
			return GL_UNSIGNED_BYTE;
			break;
		case Rudy::TextureDataType::Short:
			return GL_SHORT;
			break;
		case Rudy::TextureDataType::UnsignedShort:
			return GL_UNSIGNED_SHORT;
			break;
		case Rudy::TextureDataType::Int:
			return GL_INT;
			break;
		case Rudy::TextureDataType::UnsignedInt:
			return GL_UNSIGNED_INT;
			break;
		case Rudy::TextureDataType::Float:
			return GL_FLOAT;
			break;
		case Rudy::TextureDataType::HalfFloat:
			return GL_HALF_FLOAT;
			break;
		case Rudy::TextureDataType::UnsignedByte332:
			return GL_UNSIGNED_BYTE_3_3_2;
			break;
		case Rudy::TextureDataType::UnsignedByte332Ext:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort4444:
			return GL_UNSIGNED_SHORT_4_4_4_4;
			break;
		case Rudy::TextureDataType::UnsignedShort4444Ext:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort5551:
			return GL_UNSIGNED_SHORT_5_5_5_1;
			break;
		case Rudy::TextureDataType::UnsignedShort5551Ext:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt8888:
			return GL_UNSIGNED_INT_8_8_8_8;
			break;
		case Rudy::TextureDataType::UnsignedInt8888Ext:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt1010102:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt1010102Ext:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedByte233Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort565:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort565Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort4444Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedShort1555Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt8888Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt2101010Reversed:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt248:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt10F11F11FRev:
			return 0;
			break;
		case Rudy::TextureDataType::UnsignedInt5999Rev:
			return 0;
			break;
		case Rudy::TextureDataType::Float32UnsignedInt248Rev:
			return 0;
			break;
		default:
			break;
		}
		return 0;
	}
}