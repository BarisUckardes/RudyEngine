#include "VertexLayout.h"
#include <stdio.h>

namespace Rudy
{
	VertexLayout::VertexLayout(const Array<VertexLayoutElement>& elements)
	{
		/*
		* Set elements
		*/
		m_Elements = elements;

		/*
		* Calculate offset and stride
		*/
		CalculateOffsetsAndStride();
	}
	Array<VertexLayoutElement> VertexLayout::GetElements() const
	{
		return m_Elements;
	}
	unsigned int VertexLayout::GetStride() const
	{
		return m_Stride;
	}
	void VertexLayout::CalculateOffsetsAndStride()
	{
		unsigned int localOffset = 0;
		m_Stride = 0;
		for (int i = 0; i < m_Elements.GetCursor(); i++)
		{
			m_Elements[i].Offset = localOffset;
			localOffset += m_Elements[i].Size;
			m_Stride += m_Elements[i].Size;
		}
	}
}