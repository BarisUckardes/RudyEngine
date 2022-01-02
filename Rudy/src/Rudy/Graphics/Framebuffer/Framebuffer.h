#pragma once
#include <Rudy/Graphics/Framebuffer/FramebufferAttachment.h>
#include <Rudy/Graphics/Framebuffer/FramebufferAttachmentCreateParameters.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	/// <summary>
	/// Base class for all framebuffer classes
	/// </summary>
	class RUDY_API Framebuffer : public GraphicsDeviceObject
	{
	public:
		Framebuffer() = default;
		virtual ~Framebuffer() = 0;

		/// <summary>
		/// Returns the attachment list of this framebuffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Array<FramebufferAttachment*> GetAttachments() const;

		/// <summary>
		/// Returns the depth texture of this framebuffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Texture2D* GetDepthTexture() const;

		/// <summary>
		/// Returns the depth texture of this framebuffer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool HasDepthTexture() const;

		/// <summary>
		/// Creates new framebuffer 
		/// </summary>
		/// <param name="createParameters"></param>
		void Create(unsigned int width,unsigned int height,const Array<FramebufferAttachmentCreateParameters>& createParameters,bool createDetphTexture);
	protected:
		/// <summary>
		/// Returns the graphics device
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetOwnerGraphicsDevice() const;

		/// <summary>
		/// User implemetation
		/// </summary>
		/// <param name="createParameters"></param>
		virtual void CreateCore(unsigned int width, unsigned int height,const Array<FramebufferAttachmentCreateParameters>& createParameters,Array<FramebufferAttachment*>& attachments,Texture2D* depthTexture,bool createDepthTexture) = 0;
	private:
		
		Array<FramebufferAttachment*> m_Attachments;
		Texture2D* m_DepthTexture;
		bool m_HasDepthTexture;
	};

}
