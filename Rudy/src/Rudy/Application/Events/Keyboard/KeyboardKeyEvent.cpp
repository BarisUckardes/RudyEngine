#include "KeyboardKeyEvent.h"

namespace Rudy
{
    unsigned int KeyboardKeyEvent::GetRelatedKey() const
    {
        return m_RelatedKey;
    }
    unsigned int KeyboardKeyEvent::GetRepeatCount() const
    {
        return m_RepeatCount;
    }
    KeyboardKeyEvent::KeyboardKeyEvent(unsigned int relatedKey,unsigned int repeatCount)
    {
        m_RelatedKey = relatedKey;
        m_RepeatCount = repeatCount;
    }
}