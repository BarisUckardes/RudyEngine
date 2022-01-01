#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>
#include <Rudy/Mathematics/Vector2i.h>

namespace Rudy
{
	class RUDY_API OpenGLSetViewportRC : public RenderCommand
	{
	public:
		OpenGLSetViewportRC(const Vector2i& offset,const Vector2i& size);
		~OpenGLSetViewportRC() = default;

		virtual void Execute() override;
	private:
		Vector2i m_Offset;
		Vector2i m_Size;
	};


}