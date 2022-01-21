#pragma once
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Graphics/Texture/TextureParameters.h>

namespace Rudy
{
	/// <summary>
	/// Data volume for texture loaded from disk
	/// </summary>
	struct RUDY_API Texture2DDiskLoadResult
	{
		/// <summary>
		/// The actual data for the image
		/// </summary>
		ByteBlock DataBlock;

		/// <summary>
		/// Width of the texture
		/// </summary>
		unsigned int Width;

		/// <summary>
		/// Height of the texture
		/// </summary>
		unsigned int Height;

		/// <summary>
		/// Channel quantity
		/// </summary>
		unsigned int ChannelCount;
	};
}