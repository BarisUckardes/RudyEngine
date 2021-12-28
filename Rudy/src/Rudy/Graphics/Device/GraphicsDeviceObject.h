#pragma once
#include <Rudy/Core/Symbols.h>

namespace Rudy
{
	class GraphicsDevice;

	/// <summary>
	/// Represents an object created using a graphics device
	/// </summary>
	class RUDY_API GraphicsDeviceObject
	{
	public:
		GraphicsDeviceObject(GraphicsDevice* device);
		virtual ~GraphicsDeviceObject();

		/// <summary>
		/// Returns the native handle specific for graphics api
		/// </summary>
		/// <returns></returns>
		virtual void* GetNativeHandle() const = 0;
	protected:
		/// <summary>
		/// Returns the owner graphics device
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetOwnerGraphicsDevice() const;

	private:
		GraphicsDevice* m_OwnerDevice;
	};
}