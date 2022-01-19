#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/World/Resolver/IWorldResolver.h>
#include <Rudy/World/Register Informations/GraphicsObjectRegisterInfo.h>
#include <Rudy/Memory/Array.h>
namespace Rudy
{
	class ObserverComponent;
	class Component;
	class GraphicsDevice;

	/// <summary>
	/// Base resolver class for all graphics resolvers
	/// </summary>
	class RUDY_API GraphicsResolver : public IWorldResolver
	{
	public:
		GraphicsResolver() = default;
		~GraphicsResolver() = default;


		/// <summary>
		/// Called when graphics view broadcasts an observer component registered
		/// </summary>
		/// <param name="observer"></param>
		virtual void OnRegisterObserver(ObserverComponent* observer) = 0;

		/// <summary>
		/// Called when graphics view broadcasts an observer component removed
		/// </summary>
		/// <param name="observer"></param>
		virtual void OnRemoveObserver(ObserverComponent* observer) = 0;

		/// <summary>
		/// Returns the graphics object register information which will be used for broadcasting certain type of objects via WorldGraphicsView
		/// </summary>
		/// <returns></returns>
		virtual Array<GraphicsObjectRegisterInfo> GetRegisterInformations() = 0;
	protected:
		GraphicsDevice* GetDefaultGraphicsDevice() const;
	};
}