#include <iostream>
#include <cassert>
#include "WindRec.h"

using namespace std;

int main()
{
    // Test: Overloaded constructor
    Speed speed(35.5f);
    Temperature temp(25.5f);
    SolarRad solar(1000.5f);

    WindRec windRec(speed, temp, solar);

    assert(windRec.GetSpeed().GetValue() == 35.5f);
    assert(windRec.GetTemp().GetValue() == 25.5f);
    assert(windRec.GetSolarRad().GetValue() == 1000.5f);
    cout << "Test Passed: Overloaded constructor correctly initializes all values.\n";

    // Test: SetSpeed method
    Speed newSpeed(40.0f);
    windRec.SetSpeed(newSpeed);
    assert(windRec.GetSpeed().GetValue() == 40.0f);
    cout << "Test Passed: SetSpeed correctly sets the wind speed.\n";

    // Test: SetTemp method
    Temperature newTemp(30.0f);
    windRec.SetTemp(newTemp);
    assert(windRec.GetTemp().GetValue() == 30.0f);
    cout << "Test Passed: SetTemp correctly sets the temperature.\n";

    // Test: SetSolarRad method
    SolarRad newSolar(1200.0f);
    windRec.SetSolarRad(newSolar);
    assert(windRec.GetSolarRad().GetValue() == 1200.0f);
    cout << "Test Passed: SetSolarRad correctly sets the solar radiation.\n";

    // Test: string conversion operator
    //string expectedResult = "Date: 24/8/2024\nTime: 13:45:00\nWind Speed: 40.0 km/h\nTemperature: 30.0 C\nSolar Radiation: 1200.0 W/m2\n\n";
    //assert(static_cast<string>(windRec) == expectedResult);
    //cout << "Test Passed: Operator string correctly returns the wind record in string format.\n";

    cout << "\nAll tests passed!\n";

    return 0;
}
