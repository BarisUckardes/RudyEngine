#include "ObserverComponent.h"
#include <Rudy/World/World.h>
#include <Rudy/Entity/Entity.h>
#include <Rudy/World/Views/WorldGraphicsView.h>

namespace Rudy
{
	ColorRgba ObserverComponent::GetClearColor() const
	{
		return m_ClearColor;
	}

	float ObserverComponent::GetAspectRatio() const
	{
		return m_AspectRatio;
	}

	float ObserverComponent::GetNearPlane() const
	{
		return m_NearPlane;
	}

	float ObserverComponent::GetFarPlane() const
	{
		return m_FarPlane;
	}

	void ObserverComponent::SetClearColor(const ColorRgba& color)
	{
		m_ClearColor = color;
	}

	void ObserverComponent::SetAspectRatio(float value)
	{
		m_AspectRatio = value;
	}

	void ObserverComponent::SetNearPlane(float value)
	{
		m_NearPlane = value;
	}

	void ObserverComponent::SetFarPlane(float value)
	{
		m_FarPlane = value;
	}

	void ObserverComponent::OnAttach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RegisterObserver(this);
	}

	void ObserverComponent::OnDetach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RemoveObserver(this);
	}

}