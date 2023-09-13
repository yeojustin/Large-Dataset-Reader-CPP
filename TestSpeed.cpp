#include <iostream>
#include <cassert>
#include "Speed.h"

using namespace std;

int main()
{
    Speed speed;

    // Test: Default constructor
    assert(speed.GetValue() == 0.0f);
    cout << "Test Passed: Default constructor initializes speed to 0.0.\n";

    // Test: SetValue method
    speed.SetValue(30.0f);
    assert(speed.GetValue() == 30.0f);
    cout << "Test Passed: SetValue correctly sets the speed value.\n";

    // Test: string conversion operator
    // assert(static_cast<string>(speed) == "30");
    // cout << "Test Passed: Operator string correctly returns the speed in string format.\n";

    // Test: Parameterized constructor
    Speed speed2(50.0f);
    assert(speed2.GetValue() == 50.0f);
    cout << "Test Passed: Parameterized constructor correctly initializes the speed value.\n";

    cout << "\nAll tests passed!\n";

    return 0;
}
