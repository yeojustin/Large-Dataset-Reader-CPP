/**
 * @brief Header - Class representing a temperature value.
 */
#ifndef TEMPERATURE_H_INCLUDED
#define TEMPERATURE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Temperature
 * @brief Class representing a temperature value.
 */
class Temperature
{
private:
    float m_value;      /**< The temperature value. */

public:
    /**
     * @brief Default constructor for the Temperature class.
     * Initializes the temperature value to 0.0.
     */
    Temperature();

    /**
     * @brief Parameterized constructor for the Temperature class.
     * @param value The temperature value to set.
     */
    Temperature(const float value);

    /**
     * @brief Destructor for the Temperature class.
     */
    ~Temperature(){};

    /**
     * @brief Sets the temperature value.
     * @param value The temperature value to set.
     */
    void SetValue(const float value);

    /**
     * @brief Gets the temperature value.
     * @return The temperature value.
     */
    float GetValue() const;

    /**
     * @brief Conversion operator that returns the temperature value as a string.
     * @return The temperature value as a string.
     */
    operator string() const;
};

#endif // TEMPERATURE_H_INCLUDED
