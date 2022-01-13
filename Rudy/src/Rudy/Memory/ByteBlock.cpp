#include "ByteBlock.h"

namespace Rudy
{
    ByteBlock::ByteBlock(const ByteBlock& targetBlock, unsigned long startIndex, unsigned long endIndex, ByteBlockTransferType transferType)
    {
        /*
        * Compute size
        */
        const unsigned long size = endIndex - startIndex;

        /*
        * Catch transfer type
        */
        switch (transferType)
        {
            case Rudy::ByteBlockTransferType::Copy:
            {
                Byte* byteBlock = new Byte[size];
                Memory::MemoryCopy(targetBlock.GetBlock(), targetBlock.GetBlock() + startIndex, size);
                m_Block = byteBlock;
            }
            break;
            case Rudy::ByteBlockTransferType::Move:
            {
                m_Block = (targetBlock.GetBlock() + startIndex);
            }
            break;
            default:
                break;
        }
        m_BlockSize = size;
        m_TranferType = transferType;
    }
    ByteBlock::ByteBlock(Byte* block, unsigned long size, ByteBlockTransferType transferType)
    {
        /*
        * Catch transfer type
        */
        switch (transferType)
        {
            case Rudy::ByteBlockTransferType::Copy:
            {
                Byte* byteBlock = new Byte[size];
                Memory::MemoryCopy(byteBlock, block, size);
                m_Block = byteBlock;
            }
                break;
            case Rudy::ByteBlockTransferType::Move:
            {
                m_Block = block;
            }
                break;
            default:
                break;
        }
        m_BlockSize = size;
        m_TranferType = transferType;
    }
    ByteBlock::~ByteBlock()
    {
        if (m_Block == nullptr)
            return;

        if (m_TranferType == ByteBlockTransferType::Copy)
        {
            //delete[] m_Block;
        }
    }
    Byte* ByteBlock::GetBlock() const
    {
        return m_Block;
    }
    unsigned long ByteBlock::GetBlockSize() const
    {
        return m_BlockSize;
    }
}