#include "ByteBlock.h"
#include <stdio.h>

namespace Rudy
{
    ByteBlock::ByteBlock(const ByteBlock& targetBlock, unsigned long startIndex, unsigned long endIndex)
    {
        /*
        * Compute size
        */
        const unsigned long size = endIndex - startIndex;

        /*
        * Copy contents
        */
        Byte* byteBlock = new Byte[size];
        Memory::MemoryCopy(targetBlock.GetBlock(), targetBlock.GetBlock() + startIndex, size);
        m_Block = byteBlock;
        m_BlockSize = size;
        m_TranferType = ByteBlockTransferType::Copy;
    }
    ByteBlock::ByteBlock(void* block, unsigned long size)
    {
        /*
        * Copy contents
        */
        Byte* byteBlock = new Byte[size];
        Memory::MemoryCopy(byteBlock, block, size);
        m_Block = byteBlock;
        m_BlockSize = size;
        m_TranferType = ByteBlockTransferType::Copy;

    }

    ByteBlock::ByteBlock(const ByteBlock& block)
    {
        /*
        * Copy contents
        */
        Byte* byteBlock = new Byte[block.GetBlockSize()];
        Memory::MemoryCopy(byteBlock, block.GetBlock(), block.GetBlockSize());
        m_Block = byteBlock;
        m_BlockSize = block.GetBlockSize();
        m_TranferType = ByteBlockTransferType::Copy;
    }
    
    ByteBlock::ByteBlock()
    {
        m_Block = nullptr;
        m_BlockSize = 0;
        m_TranferType = ByteBlockTransferType::Copy;
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
        if (m_TranferType == ByteBlockTransferType::Copy)
        {
            delete[] m_Block;
        }
    }
    Byte* ByteBlock::GetBlock() const
    {
        return m_Block;
    }
    Byte* ByteBlock::GetAdress(unsigned long offset) const
    {
        return &m_Block[offset];
    }
    unsigned long ByteBlock::GetBlockSize() const
    {
        return m_BlockSize;
    }

    Byte ByteBlock::operator[](unsigned long index) const
    {
        return m_Block[index];
    }
    ByteBlock& ByteBlock::operator=(ByteBlock&& block) noexcept
    {
        /*
        * Set the contents
        */
        m_Block = block.m_Block;
        m_BlockSize = block.m_BlockSize;
        m_TranferType = ByteBlockTransferType::Copy;

        /*
        * Set target block contents to default
        */
        block.m_Block = nullptr;
        block.m_BlockSize = 0;
        m_TranferType = ByteBlockTransferType::Move;

        return *this;
    }
}