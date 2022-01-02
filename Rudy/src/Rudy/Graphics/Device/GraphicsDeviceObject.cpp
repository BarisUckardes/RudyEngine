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
	void GraphicsDeviceObject::FreeDeviceObject()
	{
		/*
		* Deference the owner device(no longer a device related object)
		*/
		m_OwnerDevice = nullptr;

		/*
		* Call free device object implementation
		*/
		FreeDeviceObjectCore();
	}
	GraphicsDevice* GraphicsDeviceObject::GetOwnerGraphicsDevice() const
	{
		return m_OwnerDevice;
	}
}