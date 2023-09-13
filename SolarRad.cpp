 #include "SolarRad.h"

SolarRad::SolarRad():m_value(0){}

SolarRad::SolarRad(const float value)
{
    m_value = value;
}

void SolarRad::SetValue(const float value)
{
    m_value = value;
}

float SolarRad::GetValue() const
{
    return m_value;
}

SolarRad::operator string() const
{
    return to_string(GetValue());
}
