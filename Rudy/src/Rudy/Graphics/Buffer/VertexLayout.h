#pragma once
#include <Rudy/Graphics/Buffer/VertexLayoutElement.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/// <summary>
	/// A layout for single vertex buffer object
	/// </summary>
	class RUDY_API VertexLayout
	{
	public:
		VertexLayout(const Array<VertexLayoutElement>& elements);
		VertexLayout() = default;
		~VertexLayout() = default;

		/// <summary>
		/// Returns the element array 
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<VertexLayoutElement> GetElements() const;

		/// <summary>
		/// Returns the total stride of this layout
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetStride() const;
	private:
		/// <summary>
		/// Calculates stride and offsets for this layout
		/// </summary>
		void CalculateOffsetsAndStride();
	private:
		Array<VertexLayoutElement> m_Elements;
		unsigned int m_Stride;
	};

}
