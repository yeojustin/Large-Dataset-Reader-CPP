/**
 * @brief Header - Class representing solar radiation.
 */
#ifndef SOLARRAD_H_INCLUDED
#define SOLARRAD_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

/**
 * @class SolarRad
 * @brief Class representing solar radiation.
 */
class SolarRad
{
private:
    float m_value; /**< The solar radiation value. */

public:
    /**
     * @brief Default constructor for the SolarRad class.
     * Initializes the solar radiation value to 0.0.
     */
    SolarRad();

    /**
     * @brief Parameterized constructor for the SolarRad class.
     * @param value The solar radiation value to set.
     */
    SolarRad(const float value);

    /**
     * @brief Destructor for the SolarRad class.
     */
    ~SolarRad(){};

    /**
     * @brief Sets the solar radiation value.
     * @param value The solar radiation value to set.
     */
    void SetValue(const float value);

    /**
     * @brief Gets the solar radiation value.
     * @return The solar radiation value.
     */
    float GetValue() const;

    /**
     * @brief Conversion operator that returns the solar radiation value as a string.
     * @return The solar radiation value as a string.
     */
    operator string() const;
};

#endif // SOLARRAD_H_INCLUDED
