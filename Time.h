#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Time
 * @brief The Time class represents a time in hours and minutes.
 */
class Time
{
private:
    int m_hours;    ///< The hours component of the time.
    int m_minutes;  ///< The minutes component of the time.

public:
    /**
     * @brief Default constructor for the Time class.
     * Initializes the time to 0 hours and 0 minutes.
     */
    Time();

    /**
     * @brief Parameterized constructor for the Time class.
     * @param hours The hours component of the time.
     * @param minutes The minutes component of the time.
     */
    Time(const int hours, const int minutes);

    /**
     * @brief Destructor for the Time class.
     */
    ~Time(){};

    /**
     * @brief Sets the hours component of the time.
     * @param hours The hours to set.
     */
    void SetHours(const int hours);

    /**
     * @brief Sets the minutes component of the time.
     * @param minutes The minutes to set.
     */
    void SetMinutes(const int minutes);

    /**
     * @brief Gets the hours component of the time.
     * @return The hours component of the time.
     */
    int GetHours() const;

    /**
     * @brief Gets the minutes component of the time.
     * @return The minutes component of the time.
     */
    int GetMinutes() const;

    /**
     * @brief Conversion operator that returns the time in string format (HH:MM).
     * @return The time in string format (HH:MM).
     */
    operator string() const;
};

/**
 * @brief Stream extraction operator to read time from the input stream.
 * @param input The input stream.
 * @param time The Time object to be updated with the values read from the stream.
 * @return The input stream after reading the time.
 */
istream &operator>>(istream &input, Time &time);

/**
 * @brief Stream insertion operator to output time to the output stream.
 * @param output The output stream.
 * @param time The Time object to be outputted to the stream.
 * @return The output stream after writing the time.
 */
ostream &operator<<(ostream &output, const Time &time);

#endif // TIME_H_INCLUDED

