/**
 * @brief Header - Class providing helper functions.
 */
#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * @class Helper
 * @brief Class providing helper functions.
 */
class Helper
{
public:

    /**
     * @brief Default constructor for Helper.
     */
    Helper(){};

    /**
     * @brief Destructor for Helper.
     */
    ~Helper(){};

    /**
     * @brief Retrieves an integer value from the user.
     * @param message The message to display when prompting the user.
     * @return The integer value entered by the user.
     * @throw std::invalid_argument If the input is not a valid integer.
     */
    int GetInt(const string message);

    /**
     * @brief Converts a month number to its string representation.
     * @param month The month number (1-12).
     * @return The string representation of the month.
     * @throw std::invalid_argument If the month number is not valid.
     */
    string GetMonthToString(const int month);
};


#endif // HELPER_H_INCLUDED
