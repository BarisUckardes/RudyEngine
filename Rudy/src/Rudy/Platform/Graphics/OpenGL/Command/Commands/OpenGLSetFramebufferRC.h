#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLSetFramebufferRC : public RenderCommand
	{
	public:
		OpenGLSetFramebufferRC(unsigned int framebufferID);
		~OpenGLSetFramebufferRC() = default;

		virtual void Execute() override;
	private:
		unsigned int m_FramebufferID;
	};


}