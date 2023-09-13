/**
 * @brief Header - Class representing a speed value.
 */
#ifndef SPEED_H_INCLUDED
#define SPEED_H_INCLUDED

#include <iostream>

using namespace std;

/**
 * @class Speed
 * @brief Class representing a speed value.
 */
class Speed
{
private:
    float m_value;      /**< The speed value. */

public:
    /**
     * @brief Default constructor for the Speed class.
     * Initializes the speed value to 0.0.
     */
    Speed();

    /**
     * @brief Parameterized constructor for the Speed class.
     * @param value The speed value to set.
     */
    Speed(float value);

    /**
     * @brief Destructor for the Speed class.
     */
    ~Speed() {};

    /**
     * @brief Gets the speed value.
     * @return The speed value.
     */
    float GetValue() const;

    /**
     * @brief Sets the speed value.
     * @param value The speed value to set.
     */
    void SetValue(const float value);

    /**
     * @brief Conversion operator that returns the speed value as a string.
     * @return The speed value as a string.
     */
    operator string() const;
};


#endif // SPEED_H_INCLUDED
