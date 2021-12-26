#include "KeyboardKeyEvent.h"

namespace Rudy
{
    unsigned int KeyboardKeyEvent::GetRelatedKey() const
    {
        return m_RelatedKey;
    }
    KeyboardKeyEvent::KeyboardKeyEvent(unsigned int relatedKey)
    {
        m_RelatedKey = relatedKey;
    }
}