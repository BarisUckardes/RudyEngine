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