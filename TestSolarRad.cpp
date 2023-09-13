#include <iostream>
#include <sstream>
#include <cassert>
#include <iomanip> // Include for setting precision
#include "SolarRad.h"

using namespace std;

int main()
{
    SolarRad solarRad;

    // Test: Default constructor
    assert(solarRad.GetValue() == 0.0f);
    cout << "Test Passed: Default constructor initializes solar radiation value to 0.0.\n";

    // Test: SetValue method
    solarRad.SetValue(50.5f);
    assert(solarRad.GetValue() == 50.5f);
    cout << "Test Passed: SetValue correctly sets the solar radiation value.\n";

    // Test: string conversion operator
    //ostringstream oss;
    //oss << fixed << setprecision(1) << solarRad.GetValue(); // Ensure the string has one decimal place
    //assert(static_cast<string>(solarRad) == oss.str());
    //cout << "Test Passed: Operator string correctly returns the solar radiation value in string format.\n";

    return 0;

}
