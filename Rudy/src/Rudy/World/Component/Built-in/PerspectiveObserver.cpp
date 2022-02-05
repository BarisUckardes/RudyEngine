#include "PerspectiveObserver.h"

namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(PerspectiveObserver);

	bool PerspectiveObserver::ShouldTick() const
	{
		return false;
	}
	Matrix4x4 PerspectiveObserver::GetProjectionMatrix() const
	{
		return Matrix4x4();
	}
	Matrix4x4 PerspectiveObserver::GetViewMatrix() const
	{
		return Matrix4x4();
	}
}