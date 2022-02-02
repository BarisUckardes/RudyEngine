#pragma once
#include <Rudy/Memory/Memory.h>
namespace Rudy
{

	/// <summary>
	/// The transfer operations for byte block
	/// </summary>
	enum class RUDY_API ByteBlockTransferType
	{
		Copy = 0,
		Move = 1
	};

	/// <summary>
	/// Represents a block of bytes
	/// </summary>
	class RUDY_API ByteBlock
	{
	public:
		ByteBlock(const Rudy::ByteBlock& block, unsigned long startIndex, unsigned long endIndex);
		ByteBlock(void* block, unsigned long size);
		ByteBlock(const Rudy::ByteBlock& block);
		ByteBlock();
		~ByteBlock();

		/// <summary>
		/// Returns the block data 
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Byte* GetBlock() const;

		/// <summary>
		/// Returns the pointer with a offset
		/// </summary>
		/// <param name="offset"></param>
		/// <returns></returns>
		FORCEINLINE Byte* GetAdress(unsigned long offset) const;

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
		TObject To() const;

		/// <summary>
		/// Converts this byte block with an offset
		/// </summary>
		/// <typeparam name="TObject"></typeparam>
		/// <param name="start"></param>
		/// <param name="end"></param>
		/// <returns></returns>
		template<typename TObject>
		TObject To(unsigned long offset) const;

		Byte operator[](unsigned long index) const;
		Rudy::ByteBlock& operator=(Rudy::ByteBlock&& block) noexcept;
	private:
		Byte* m_Block;
		Rudy::ByteBlockTransferType m_TranferType;
		unsigned long m_BlockSize;
	};
	template<typename TObject>
	inline TObject Rudy::ByteBlock::To() const
	{
		return *(TObject*)m_Block;
	}
	template<typename TObject>
	inline TObject Rudy::ByteBlock::To(unsigned long offset) const
	{
		return *(TObject*)(m_Block + offset);
	}

}