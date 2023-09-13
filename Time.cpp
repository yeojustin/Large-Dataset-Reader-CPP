#include "Time.h"

Time::Time(): m_hours(0), m_minutes(0) {}


Time::Time(const int hours, const int minutes)
{
    m_hours = hours;
    m_minutes = minutes;
}


void Time::SetHours(int hours)
{
    m_hours = hours;
}


void Time::SetMinutes(int minutes)
{
    m_minutes = minutes;
}


int Time::GetHours() const
{
    return m_hours;
}


int Time::GetMinutes() const
{
    return m_minutes;
}


Time::operator string() const
{
    return to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":00";
}


istream &operator>>(istream &input, Time &time)
{
    char colon;
    int hours;
    int minutes;

    input >> hours >> colon >> minutes;

    if (input) //if there is input from file then set time values
    {
        time.SetHours(hours);
        time.SetMinutes(minutes);
    }
    return input;
}

ostream &operator<<(ostream &output, const Time &time)
{
    output << time.GetHours() << ":" << time.GetMinutes() << ":00" << endl;
    return output;
}
