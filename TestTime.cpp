#include <iostream>
#include <sstream>
#include <cassert>
#include "Time.h"

using namespace std;

int main()
{
    Time time;

    // Test: Default constructor
    assert(time.GetHours() == 0);
    assert(time.GetMinutes() == 0);
    cout << "Test Passed: Default constructor initializes time to 0:0:00.\n";

    // Test: SetHours and SetMinutes method
    time.SetHours(10);
    time.SetMinutes(30);
    assert(time.GetHours() == 10);
    assert(time.GetMinutes() == 30);
    cout << "Test Passed: SetHours and SetMinutes correctly set the time.\n";

    // Test: string conversion operator
    assert(static_cast<std::string>(time) == "10:30:00");
    cout << "Test Passed: Operator string correctly returns the time in string format.\n";

    // Test: Stream extraction operator
    istringstream iss("11:45");
    iss >> time;
    assert(time.GetHours() == 11);
    assert(time.GetMinutes() == 45);
    cout << "Test Passed: Operator >> correctly updates the time from the input stream.\n";

    // Test: Stream insertion operator
    ostringstream oss;
    oss << time;
    assert(oss.str() == "11:45:00\n");
    cout << "Test Passed: Operator << correctly outputs the time to the output stream.\n";

    cout << "\nAll tests passed!\n";

    return 0;
}
