#include "Temperature.h"

Temperature::Temperature():m_value(0){}

Temperature::Temperature(const float value)
{
    m_value = value;
}

void Temperature::SetValue(const float value)
{
    m_value = value;
}

float Temperature::GetValue() const
{
    return m_value;
}

Temperature::operator string() const
{
    return to_string(GetValue());
}
