#include "Speed.h"

Speed::Speed():m_value(0){};

Speed::Speed(float value)
{
    m_value = value;
}

float Speed::GetValue() const
{
    return m_value;
}

void Speed::SetValue(const float value)
{
    m_value = value;
}

Speed::operator string () const
{
    return to_string(GetValue());
}
