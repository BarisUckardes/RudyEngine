#include "GraphicsDevice.h"
#include <Rudy/Platform/Graphics/OpenGL/Device/OpenGLGraphicsDevice.h>

namespace Rudy
{
	GraphicsDevice* GraphicsDevice::Create(Window* window,GraphicsAPIType preferredAPIType)
	{
		switch (preferredAPIType)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
				return new OpenGLGraphicsDevice(window);
				break;
			case Rudy::GraphicsAPIType::DÝrectx9:
				break;
			case Rudy::GraphicsAPIType::Directx11:
				break;
			case Rudy::GraphicsAPIType::Directx12:
				break;
			case Rudy::GraphicsAPIType::Directx13:
				break;
			case Rudy::GraphicsAPIType::Vulkan:
				break;
			default:
				break;
		}
	}
	GraphicsDevice::GraphicsDevice(Window* targetWindow)
	{
		/*
		* Set target window
		*/
		m_TargetWindow = targetWindow;
	}
	bool GraphicsDevice::HasTargetWindow() const
	{
		return m_TargetWindow != nullptr;
	}
	Window* GraphicsDevice::GetTargetWindow() const
	{
		return m_TargetWindow;
	}
	GraphicsAPIType GraphicsDevice::GetApiType() const
	{
		return m_APIType;
	}
	GraphicsDevice::~GraphicsDevice()
	{
		/*
		* Set target window pointer to nullptr
		*/
		m_TargetWindow = nullptr;
	}

	void GraphicsDevice::SetApiType(GraphicsAPIType apiType)
	{
		m_APIType = apiType;
	}
	
}