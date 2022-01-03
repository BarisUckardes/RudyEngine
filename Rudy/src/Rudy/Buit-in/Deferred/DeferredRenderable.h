#pragma once
#include <Rudy/Component/Component.h>

namespace Rudy
{
	class VertexBuffer;
	class IndexBuffer;
	class ShaderProgram;
	class RUDY_API DeferredRenderable : public Component
	{
		GENERATE_REFLECTABLE_OBJECT(DeferredRenderable);
	public:
		DeferredRenderable() = default;
		~DeferredRenderable() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void DestroyCore() override;
		virtual bool ShouldTick() const override;

		VertexBuffer* m_VertexBuffer;
		IndexBuffer* m_IndexBuffer;
		ShaderProgram* m_Program;
	};


}