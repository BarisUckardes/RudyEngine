#include "Spatial.h"
#include <stdio.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(Spatial);
	Spatial::Spatial(const Vector3f& position, const Vector3f& rotation, const Vector3f& scale)
	{
		m_Position = position;
		m_Rotation = rotation;
		m_Scale = scale;
	}
	Vector3f Spatial::GetPosition() const
	{
		return m_Position;
	}
	Vector3f Spatial::GetRotation() const
	{
		return m_Rotation;
	}
	Vector3f Spatial::GetScale() const
	{
		return m_Scale;
	}
	void Spatial::SetPosition(const Vector3f& position)
	{
		m_Position = position;
	}
	void Spatial::SetRotation(const Vector3f& rotation)
	{
		m_Rotation = rotation;
	}
	void Spatial::SetScale(const Vector3f& scale)
	{
		m_Scale = scale;
	}
	bool Spatial::ShouldTick() const
	{
		return false;
	}
}