#pragma once
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Graphics/Buffer/VertexLayout.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic vertex buffer wrapper
	/// </summary>
	class RUDY_API VertexBuffer : public GraphicsDeviceObject
	{
	public:
		VertexBuffer();
		virtual ~VertexBuffer() = 0;
		/// <summary>
		/// Returns the vertex layout of this vertex buffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE VertexLayout GetVertexLayout() const;

		/// <summary>
		/// Returns the quantity of the vertexes in this vertex buffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned int GetVertexCount() const;

		/// <summary>
		/// Uploads data to the vertex buffer object
		/// </summary>
		/// <param name="dataPtr"></param>
		/// <param name="elementSize"></param>
		/// <param name="elementCount"></param>
		/// <param name="vertexLayout"></param>
		void SetData(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount);

		/// <summary>
		/// Initializes this vertex buffer with the target vertex layout
		/// </summary>
		/// <param name="vertexLayout"></param>
		virtual void Initialize(const VertexLayout& vertexLayout) = 0;
	protected:
		/// <summary>
		/// Returns the owner graphics device
		/// </summary>
		/// <returns></returns>
		GraphicsDevice* GetOwnerGraphicsDevice() const;

		/// <summary>
		/// Set data user implementation
		/// </summary>
		/// <param name="dataPtr"></param>
		/// <param name="elementSize"></param>
		/// <param name="elementCount"></param>
		/// <param name="vertexLayout"></param>
		virtual void SetDataCore(const unsigned char* dataPtr, const unsigned int elementSize, const unsigned int elementCount) = 0;
	private:
		VertexLayout m_VertexLayout;
		unsigned int m_VertexCount;
	};


}