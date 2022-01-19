#pragma once
#include <Rudy/Graphics/Buffer/VertexLayoutDataType.h>

namespace Rudy
{
	/// <summary>
	/// Utility class responsible for vertex data conversions
	/// </summary>
	class RUDY_API OpenGLVertexDataTypeConversions
	{
	public:
		OpenGLVertexDataTypeConversions() = delete;
		~OpenGLVertexDataTypeConversions() = delete;

		/// <summary>
		/// Returns the opengl representation of the vertex layout data type
		/// </summary>
		/// <param name="dataType"></param>
		/// <returns></returns>
		static unsigned int GetOpenGLDataType(VertexLayoutDataType dataType);
	};


}