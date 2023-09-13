#include "WindRec.h"

/**
 * @brief Default constructor for the WindRec class.
 *
 * This constructor creates an instance of the WindRec class with default values for the speed, temperature, and solar
 * radiation members.
 */
WindRec::WindRec(): m_spd(), m_temp(), m_solarRad()
{

}

/**
 * @brief Parameterized constructor for the WindRec class.
 *
 * This constructor creates an instance of the WindRec class with specified values for speed, temperature, and solar
 * radiation.
 *
 * @param spd The speed data to set.
 * @param temp The temperature data to set.
 * @param solar The solar radiation data to set.
 */
WindRec::WindRec(const Speed &spd, const Temperature &temp, const SolarRad &solar)
{
    m_spd = spd;
    m_temp = temp;
    m_solarRad = solar;
}

/**
 * @brief Set the wind speed data for the WindRec.
 *
 * This function sets the wind speed data for the WindRec object.
 *
 * @param spd The wind speed data to set.
 */
void WindRec::SetSpeed(const Speed &spd)
{
    m_spd = spd;
}

/**
 * @brief Set the temperature data for the WindRec.
 *
 * This function sets the temperature data for the WindRec object.
 *
 * @param temp The temperature data to set.
 */
void WindRec::SetTemp(const Temperature &temp)
{
    m_temp = temp;
}

/**
 * @brief Set the solar radiation data for the WindRec.
 *
 * This function sets the solar radiation data for the WindRec object.
 *
 * @param solarRad The solar radiation data to set.
 */
void WindRec::SetSolarRad(const SolarRad &solarRad)
{
    m_solarRad = solarRad;
}

/**
 * @brief Get the wind speed data from the WindRec.
 *
 * This function returns the wind speed data stored in the WindRec object.
 *
 * @return The wind speed data.
 */
Speed WindRec::GetSpeed() const
{
    return m_spd;
}

/**
 * @brief Get the temperature data from the WindRec.
 *
 * This function returns the temperature data stored in the WindRec object.
 *
 * @return The temperature data.
 */
Temperature WindRec::GetTemp() const
{
    return m_temp;
}

/**
 * @brief Get the solar radiation data from the WindRec.
 *
 * This function returns the solar radiation data stored in the WindRec object.
 *
 * @return The solar radiation data.
 */
SolarRad WindRec::GetSolarRad() const
{
    return m_solarRad;
}

/**
 * @brief Conversion operator to convert WindRec to a string representation.
 *
 * This conversion operator allows converting a WindRec object to its string representation.
 *
 * @return A string representation of the WindRec object, including wind speed, temperature, and solar radiation.
 */
WindRec::operator string() const
{
    string speed = "Wind Speed: " + (string)m_spd + " km/h\n";
    string temp = "Temperature: " + (string)m_temp + " C\n";
    string solar = "Solar Radiation: " + (string)m_solarRad + " W/m2\n";

    return speed + temp + solar + "\n";
}

