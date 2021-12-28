#include "Texture2D.h"

namespace Rudy
{
	unsigned int Texture2D::GetWidth() const
	{
		return m_Width;
	}
	unsigned int Texture2D::GetHeight() const
	{
		return m_Height;
	}
	Texture2D::Texture2D(GraphicsDevice* device) : Texture(device)
	{
		m_Width = 0;
		m_Height = 0;
	}
	void Texture2D::SetWidth(unsigned int width)
	{
		m_Width = width;
	}
	void Texture2D::SetHeight(unsigned int height)
	{
		m_Height = height;
	}
}