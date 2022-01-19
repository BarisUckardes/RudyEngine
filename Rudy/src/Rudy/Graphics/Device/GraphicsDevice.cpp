#include "GraphicsDevice.h"
#include <Rudy/Platform/Implementation/Graphics/OpenGL/Device/OpenGLGraphicsDevice.h>
#include <Rudy/Graphics/Device/GraphicsDeviceObject.h>
namespace Rudy
{
	GraphicsDevice* GraphicsDevice::Create(Window* window,GraphicsAPIType preferredAPIType)
	{
		switch (preferredAPIType)
		{
			case Rudy::GraphicsAPIType::Undefined:
				break;
			case Rudy::GraphicsAPIType::OpenGL:
			{
				/*
				* Create OpenGL graphics device
				*/
				OpenGLGraphicsDevice* device = new OpenGLGraphicsDevice();

				/*
				* Initialize the device
				*/
				device->Initialize(window);

				return device;
			}
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
	void GraphicsDevice::Initialize(Window* window)
	{
		/*
		* Set the window first
		*/
		m_TargetWindow = window;

		/*
		* Call graphics api implementations
		*/
		InitializeCore();
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

	void GraphicsDevice::SetDeviceObjectTargetDevice(GraphicsDeviceObject* deviceObject)
	{
		deviceObject->SetGraphicsDevice(this);
	}
	
}