#include "GraphicsDeviceObject.h"

namespace Rudy
{
	GraphicsDeviceObject::~GraphicsDeviceObject()
	{
		m_OwnerDevice = nullptr;
	}
	void GraphicsDeviceObject::SetGraphicsDevice(GraphicsDevice* device)
	{
		m_OwnerDevice = device;
	}
	GraphicsDevice* GraphicsDeviceObject::GetOwnerGraphicsDevice() const
	{
		return m_OwnerDevice;
	}
}