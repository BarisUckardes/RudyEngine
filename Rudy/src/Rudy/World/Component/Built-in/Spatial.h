#pragma once
#include <Rudy/World/Component/Component.h>
#include <Rudy/Mathematics/Vector3f.h>

namespace Rudy
{
	class RUDY_API Spatial : public Component
	{
		GENERATE_REFLECTABLE_OBJECT(Spatial);
	public:
		Spatial(const Vector3f& position = 0,const Vector3f& rotation = 0,const Vector3f& scale = 0);
		~Spatial() = default;

		/// <summary>
		/// Returns the position
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector3f GetPosition() const;

		/// <summary>
		/// Returns the rotation
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector3f GetRotation() const;

		/// <summary>
		/// Returns the scale
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Vector3f GetScale() const;

		/// <summary>
		/// Sets the position
		/// </summary>
		/// <param name="position"></param>
		void SetPosition(const Vector3f& position);

		/// <summary>
		/// Sets the rotation
		/// </summary>
		/// <param name="rotation"></param>
		void SetRotation(const Vector3f& rotation);

		/// <summary>
		/// Sets the scale
		/// </summary>
		/// <param name="scale"></param>
		void SetScale(const Vector3f& scale);

		virtual bool ShouldTick() const override;

	private:
		Vector3f m_Position;
		Vector3f m_Rotation;
		Vector3f m_Scale;
	};


}