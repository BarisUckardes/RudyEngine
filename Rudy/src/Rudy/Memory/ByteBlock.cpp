#include "ByteBlock.h"
#include <stdio.h>

namespace Rudy
{
    ByteBlock::ByteBlock(const Rudy::ByteBlock& targetBlock, unsigned long startIndex, unsigned long endIndex)
    {
        /*
        * Compute size
        */
        const unsigned long size = endIndex - startIndex;

        /*
        * Copy contents
        */
        Byte* bytes = new Byte[size];
        Memory::MemoryCopy(targetBlock.GetBlock(), targetBlock.GetBlock() + startIndex, size);
        m_Block = bytes;
        m_BlockSize = size;
        m_TranferType = Rudy::ByteBlockTransferType::Copy;
    }
    ByteBlock::ByteBlock(void* block, unsigned long size)
    {
        /*
        * Copy contents
        */
        Byte* bytes = new Byte[size];
        Memory::MemoryCopy(bytes, block, size);
        m_Block = bytes;
        m_BlockSize = size;
        m_TranferType = Rudy::ByteBlockTransferType::Copy;

    }

    ByteBlock::ByteBlock(const Rudy::ByteBlock& block)
    {
        /*
        * Copy contents
        */
        Byte* bytes = new Byte[block.GetBlockSize()];
        Memory::MemoryCopy(bytes, block.GetBlock(), block.GetBlockSize());
        m_Block = bytes;
        m_BlockSize = block.GetBlockSize();
        m_TranferType = Rudy::ByteBlockTransferType::Copy;
    }
    
    ByteBlock::ByteBlock()
    {
        m_Block = nullptr;
        m_BlockSize = 0;
        m_TranferType = Rudy::ByteBlockTransferType::Copy;
    }
    ByteBlock::~ByteBlock()
    {
        /*
        * Validate pointers
        */
        if (m_Block == nullptr)
            return;

        /*
        * Validate data
        */
        if (m_TranferType == Rudy::ByteBlockTransferType::Copy)
        {
            delete[] m_Block;
        }
    }
    Byte* Rudy::ByteBlock::GetBlock() const
    {
        return m_Block;
    }
    Byte* Rudy::ByteBlock::GetAdress(unsigned long offset) const
    {
        return &m_Block[offset];
    }
    unsigned long Rudy::ByteBlock::GetBlockSize() const
    {
        return m_BlockSize;
    }

    Byte Rudy::ByteBlock::operator[](unsigned long index) const
    {
        return m_Block[index];
    }
    Rudy::ByteBlock& Rudy::ByteBlock::operator=(Rudy::ByteBlock&& block) noexcept
    {
        /*
        * Set the contents
        */
        m_Block = block.m_Block;
        m_BlockSize = block.m_BlockSize;
        m_TranferType = Rudy::ByteBlockTransferType::Copy;

        /*
        * Set target block contents to default
        */
        block.m_Block = nullptr;
        block.m_BlockSize = 0;
        m_TranferType = Rudy::ByteBlockTransferType::Move;

        return *this;
    }
}