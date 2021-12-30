#pragma once
#include <Rudy/Graphics/Device/GraphicsDevice.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation of graphics device
	/// </summary>
	class RUDY_API OpenGLGraphicsDevice : public GraphicsDevice
	{
	public:
		OpenGLGraphicsDevice();
		~OpenGLGraphicsDevice() = default;

		virtual void Swapbuffers() override;

		virtual IndexBuffer* CreateIndexBuffer() override;
		virtual VertexBuffer* CreateVertexBuffer() override;
		virtual Texture2D* CreateTexture2D() override;
		virtual CommandBuffer* CreateCommandBuffer() override;
	protected:
		virtual void InitializeCore() override;;

	};


}