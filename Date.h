#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/**
 * @class Date
 * @brief Class representing a date.
 */
class Date
{
private:
    int m_day;      /**< The day of the date. */
    int m_month;    /**< The month of the date. */
    int m_year;     /**< The year of the date. */

public:
    Date();
    Date(const int day, const int month, const int year);
    ~Date(){};

    void SetDay(const int day);
    void SetMonth(const int month);
    void SetYear(const int year);

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    operator string() const;
};

istream &operator>>(istream &input, Date &date);
ostream &operator<<(ostream &output, const Date &date);

#endif // DATE_H_INCLUDED
