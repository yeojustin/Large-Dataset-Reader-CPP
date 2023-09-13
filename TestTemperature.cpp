#include <iostream>
#include <sstream>
#include <cassert>
#include <iomanip>
#include "Temperature.h"

using namespace std;

int main()
{
    Temperature temperature;

    // Test: Default constructor
    assert(temperature.GetValue() == 0.0f);
    cout << "Test Passed: Default constructor initializes temperature value to 0.0.\n";

    // Test: SetValue method
    temperature.SetValue(37.5f);
    assert(temperature.GetValue() == 37.5f);
    cout << "Test Passed: SetValue correctly sets the temperature value.\n";

    // Test: string conversion operator
    //ostringstream oss;
    //oss << fixed << setprecision(1) << 37.5f;
    //assert(static_cast<string>(temperature) == oss.str());
    //cout << "Test Passed: Operator string correctly returns the temperature value in string format.\n";

    return 0;
}
