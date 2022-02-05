#include "DeferredRenderable.h"
#include <Rudy/World/Views/WorldGraphicsView.h>
#include <Rudy/World/World.h>
#include <Rudy/World/Entity/Entity.h>
#include <Rudy/Reflection/Type/ReflectionType.h>
namespace Rudy
{
	GENERATE_REFLECTABLE_TYPE(DeferredRenderable);
	void DeferredRenderable::OnAttach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RegisterGraphicsObject(this);
	}
	void DeferredRenderable::OnDetach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RemoveGraphicsObject(this);
	}

	bool DeferredRenderable::ShouldTick() const
	{
		return false;
	}

}