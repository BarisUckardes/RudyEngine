#pragma once
#include <Rudy/Graphics/Command/RenderCommand.h>

namespace Rudy
{
	class RUDY_API OpenGLClearDepthRC : public RenderCommand
	{
	public:
		OpenGLClearDepthRC(float value);
		~OpenGLClearDepthRC() = default;

		virtual void Execute() override;
	private:
		float m_DetphValue;
	};


}