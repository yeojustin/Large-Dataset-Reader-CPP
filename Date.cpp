// DATE.CPP - DATE class implementation

#include "Date.h"

Date::Date():m_day(0), m_month(0), m_year(0){}

Date::Date(const int day, const int month, const int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Date::SetDay(int day)
{
    if (day >=1 && day <=31)
    {
        m_day = day;
    }
}

void Date::SetMonth(const int month)
{
    if (month >= 1 && month <= 12)
    {
        m_month = month;
    }
}

void Date::SetYear(const int year)
{
    if (year > 0000 && year < 9999)
    {
        m_year = year;
    }
}

int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}


Date::operator string() const
{
    return to_string(GetDay()) + "/" + to_string(GetMonth()) + "/" + to_string(GetYear());
}


istream &operator>>(istream &input, Date &date)
{
    int day;
    int month;
    int year;
    char slash;

    input >> day >> slash >> month >> slash >> year;

    // Set the values in the Date object
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);

    return input;
}

ostream &operator<<(ostream &output, const Date &date)
{
    output << "  Date: " << date.GetDay() << "\\" << date.GetMonth() << "\\" << date.GetYear() << endl;
    return output;
}
