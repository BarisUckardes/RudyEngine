#include "GraphicsObjectRegisterInfo.h"

namespace Rudy
{
    GraphicsObjectRegisterInfo::GraphicsObjectRegisterInfo(RudyType type, const Delegate<void, Component*>& registerDelegate, const Delegate<void, Component*>& removeDelegate)
    {
        m_TargetType = type;
        m_RegisterDelegate = registerDelegate;
        m_RemoveDelegate = removeDelegate;
    }
    RudyType GraphicsObjectRegisterInfo::GetTargetType() const
    {
        return m_TargetType;
    }
    void GraphicsObjectRegisterInfo::Register(Component* component)
    {
        m_RegisterDelegate.Invoke(component);
    }
    void GraphicsObjectRegisterInfo::Remove(Component* component)
    {
        m_RemoveDelegate.Invoke(component);
    }
}