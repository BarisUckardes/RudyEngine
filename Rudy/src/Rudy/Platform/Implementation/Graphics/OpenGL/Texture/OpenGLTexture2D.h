#pragma once
#include <Rudy/Graphics/Texture/Texture2D.h>

namespace Rudy
{
	/// <summary>
	/// OpenGL implementation of a texture2D
	/// </summary>
	class RUDY_API OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D() = default;
		~OpenGLTexture2D() = default;


		virtual void* GetNativeHandle() const override;
		virtual void SetTextureData(Byte* data, unsigned int size) override;
	protected:
		virtual void InitializeCore() override;

		virtual void FreeDeviceObjectCore() override;
	private:
		unsigned int m_TextureID;
	};

}
