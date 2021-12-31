#include "GraphicsResolver.h"
#include <Rudy/World/World.h>
namespace Rudy
{
    GraphicsDevice* GraphicsResolver::GetDefaultGraphicsDevice() const
    {
        return GetOwnerWorld()->GetDefaultGraphicsDevice();
    }
}