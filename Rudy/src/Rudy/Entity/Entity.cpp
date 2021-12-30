#include "Entity.h"
#include <Rudy/Component/Built-in/Spatial.h>
namespace Rudy
{
  
    Array<Component*> Entity::GetComponents() const
    {
        return m_Components;
    }
    World* Entity::GetOwnerWorld() const
    {
        return m_OwnerWorld;
    }
    Spatial* Entity::GetSpatial() const
    {
        return m_Spatial;
    }
    void Entity::DestroyCore()
    {

    }
}