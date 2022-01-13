#pragma once
#include <Rudy/Memory/Memory.h>
#include <Rudy/Memory/ByteBlockTransferType.h>
namespace Rudy
{

	/// <summary>
	/// Represents a block of bytes
	/// </summary>
	class RUDY_API ByteBlock
	{
	public:
		ByteBlock(const ByteBlock& block, unsigned long startIndex, unsigned long endIndex, ByteBlockTransferType transferType = ByteBlockTransferType::Copy);
		ByteBlock(Byte* block, unsigned long size,ByteBlockTransferType transferType = ByteBlockTransferType::Copy);
		ByteBlock(const ByteBlock& block) = delete;
		ByteBlock() = default;
		~ByteBlock();

		/// <summary>
		/// Returns the block data 
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Byte* GetBlock() const;

		/// <summary>
		/// Returns the size of the block
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetBlockSize() const;

		/// <summary>
		/// Converts this byte block to the object type specified
		/// </summary>
		/// <typeparam name="TBlock"></typeparam>
		/// <returns></returns>
		template<typename TObject>
		TObject To();
	private:
		Byte* m_Block;
		ByteBlockTransferType m_TranferType;
		unsigned long m_BlockSize;
	};
	template<typename TObject>
	inline TObject ByteBlock::To()
	{
		return *(TObject*)m_Block;
	}
}