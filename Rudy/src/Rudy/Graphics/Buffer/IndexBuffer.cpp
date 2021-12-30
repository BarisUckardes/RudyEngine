#include "IndexBuffer.h"

namespace Rudy
{
    void IndexBuffer::SetData(unsigned char* dataPtr, unsigned int count, unsigned int sizePerElement)
    {
        /*
        * Call graphics api specific set data method
        */
        SetDataCore(dataPtr, count, sizePerElement);

        /*
        * Set index count
        */
        m_ElementCount = count;
    }

    unsigned int IndexBuffer::GetElementCount() const
    {
        return m_ElementCount;
    }

    IndexBuffer::IndexBuffer()
    {
        m_ElementCount = 0;
    }

}