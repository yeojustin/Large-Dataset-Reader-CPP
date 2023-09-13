#ifndef WINDREC_H_INCLUDED
#define WINDREC_H_INCLUDED

/**
 * @brief Header - Class representing a wind record.
 */
#include "Speed.h"
#include "SolarRad.h"
#include "Temperature.h"

#include <string>

using namespace std;

/**
 * @class WindRec
 * @brief Class representing a wind record.
 */
class WindRec
{
private:
    Speed m_spd;                /**< Wind speed in km/h. */
    SolarRad m_solarRad;        /**< Solar radiation in W/m2. */
    Temperature m_temp;         /**< Temperature in Celsius. */

public:
    /**
     * @brief Default constructor for WindRec.
     */
    WindRec();

    /**
     * @brief Overloaded constructor for WindRec.
     * @param spd The wind speed.
     * @param temp The temperature.
     * @param solar The solar radiation.
     */
    WindRec(const Speed &spd, const Temperature &temp, const SolarRad &solar);

    /**
     * @brief Destructor for WindRec.
     */
    ~WindRec(){};

    /**
     * @brief Sets the wind speed.
     * @param spd The wind speed to set.
     */
    void SetSpeed(const Speed &spd);

    /**
     * @brief Sets the temperature.
     * @param temp The temperature to set.
     */
    void SetTemp(const Temperature &temp);

    /**
     * @brief Sets the solar radiation.
     * @param solar The solar radiation to set.
     */
    void SetSolarRad(const SolarRad &solar);

    /**
     * @brief Gets the wind speed.
     * @return The wind speed.
     */
    Speed GetSpeed() const;

    /**
     * @brief Gets the temperature.
     * @return The temperature.
     */
    Temperature GetTemp() const;

    /**
     * @brief Gets the solar radiation.
     * @return The solar radiation.
     */
    SolarRad GetSolarRad() const;

    /**
     * @brief Converts the wind record to a string representation.
     * @return The string representation of the wind record.
     */
    operator string() const;
};

#endif // WINDREC_H_INCLUDED
