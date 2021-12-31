#include "DeferredRenderable.h"
#include <Rudy/World/Views/WorldGraphicsView.h>
#include <Rudy/World/World.h>
#include <Rudy/Entity/Entity.h>
namespace Rudy
{
	void DeferredRenderable::OnAttach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RegisterGraphicsObject(this);
	}
	void DeferredRenderable::OnDetach()
	{
		GetOwnerEntity()->GetOwnerWorld()->GetView<WorldGraphicsView>()->RemoveGraphicsObject(this);
	}

	void DeferredRenderable::DestroyCore()
	{
	}

	bool DeferredRenderable::ShouldTick() const
	{
		return false;
	}

}