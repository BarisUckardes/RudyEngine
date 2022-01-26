#pragma once
#include <Rudy/Memory/ByteBlock.h>
#include <Rudy/Asset/Containers/AssetHeaderContainer.h>

namespace Rudy
{
	/// <summary>
	/// Utility class for asset definition generators
	/// </summary>
	class RUDY_API AssetHeaderGenerator
	{
	public:
		AssetHeaderGenerator() = delete;
		~AssetHeaderGenerator() = delete;
		 
		/// <summary>
		/// Generates abyte block out of the definition
		/// </summary>
		/// <param name="defintion"></param>
		/// <returns></returns>
		FORCEINLINE static ByteBlock GenerateByteBlock(const AssetHeaderContainer& defintion);

		/// <summary>
		/// Generates a definition out of the byte block
		/// </summary>
		/// <param name="block"></param>
		/// <returns></returns>
		FORCEINLINE static AssetHeaderContainer GenerateHeader(const ByteBlock& block);
	};


}