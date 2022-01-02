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
		friend class GraphicsDevice;
	public:
		/// <summary>
		/// Returns the native handle specific for graphics api
		/// </summary>
		/// <returns></returns>
		virtual void* GetNativeHandle() const = 0;

		/// <summary>
		/// Frees the handles and allocations for this device object
		/// </summary>
		void FreeDeviceObject();
	protected:
		/// <summary>
		/// Returns the owner graphics device
		/// </summary>
		/// <returns></returns>
		FORCEINLINE GraphicsDevice* GetOwnerGraphicsDevice() const;

		virtual void FreeDeviceObjectCore() = 0;
		GraphicsDeviceObject() = default;
		virtual ~GraphicsDeviceObject() = 0;
	private:
		void SetGraphicsDevice(GraphicsDevice* device);
		GraphicsDevice* m_OwnerDevice;
	};
}