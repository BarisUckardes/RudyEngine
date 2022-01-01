#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>
#include <Rudy/Mathematics/ColorRgba.h>
namespace Rudy
{
	class RUDY_API OpenGLClearColorRC : public RenderCommand
	{
	public:
		OpenGLClearColorRC(const ColorRgba& color);
		~OpenGLClearColorRC() = default;

		virtual void Execute() override;
	private:
		ColorRgba m_Color;
	};


}