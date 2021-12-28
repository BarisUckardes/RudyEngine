#pragma once
#include <Rudy/Graphics/Buffer/VertexLayoutDataType.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	/// <summary>
	/// An element specifying one vertex element of the vertex layout
	/// </summary>
	struct RUDY_API VertexLayoutElement
	{
		
		VertexLayoutElement(VertexLayoutDataType dataType, const String& name, bool isNormalized = false);
		VertexLayoutElement() = default;

		/// <summary>
		/// Returns the component count for this element
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetComponentCount() const;

		/// <summary>
		/// The data type for this element
		/// </summary>
		VertexLayoutDataType DataType;

		/// <summary>
		/// Name of the element
		/// </summary>
		String Name;

		/// <summary>
		/// Size of this element
		/// </summary>
		unsigned int Size;

		/// <summary>
		/// Offset of this element
		/// </summary>
		unsigned int Offset;

		/// <summary>
		/// Whether this element will normalized or not
		/// </summary>
		bool IsNormalized;
	};


}