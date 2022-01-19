#pragma once
#include <Rudy/World/Component/Component.h>
#include <Rudy/Mathematics/ColorRgba.h>
#include <Rudy/Mathematics/Matrix4x4.h>
namespace Rudy
{
	/// <summary>
	/// Base observer class
	/// </summary>
	class RUDY_API ObserverComponent : public Component
	{
	public:

		/// <summary>
		/// Returns the clear color of this observer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE ColorRgba GetClearColor() const;

		/// <summary>
		/// Returns the aspect ratio of this observer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetAspectRatio() const;

		/// <summary>
		/// Returns the frustum near plane of this observer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetNearPlane() const;

		/// <summary>
		/// Returns the frustum far plane of this observer
		/// </summary>
		/// <returns></returns>
		FORCEINLINE float GetFarPlane() const;

		/// <summary>
		/// Sets the clear color for this observer
		/// </summary>
		/// <param name="color"></param>
		void SetClearColor(const ColorRgba& color);

		/// <summary>
		/// Sets the aspect ratio for this observer
		/// </summary>
		/// <param name="value"></param>
		void SetAspectRatio(float value);

		/// <summary>
		/// Seths the near plane for this observer's frustum
		/// </summary>
		/// <param name="value"></param>
		void SetNearPlane(float value);

		/// <summary>
		/// Sets the far plane for this observer's frustum
		/// </summary>
		/// <param name="value"></param>
		void SetFarPlane(float value);

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		FORCEINLINE virtual Matrix4x4 GetProjectionMatrix() const = 0;
		FORCEINLINE virtual Matrix4x4 GetViewMatrix() const = 0;
	private:
		ColorRgba m_ClearColor;
		float m_AspectRatio;
		float m_NearPlane;
		float m_FarPlane;
	};

}