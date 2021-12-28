#include "GraphicsDeviceObject.h"

namespace Rudy
{
	GraphicsDeviceObject::GraphicsDeviceObject(GraphicsDevice* device)
	{
		m_OwnerDevice = device;
	}
	GraphicsDeviceObject::~GraphicsDeviceObject()
	{
		m_OwnerDevice = nullptr;
	}
	GraphicsDevice* GraphicsDeviceObject::GetOwnerGraphicsDevice() const
	{
		return m_OwnerDevice;
	}
}