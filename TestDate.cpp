#include <iostream>
#include <sstream>
#include <cassert>
#include "Date.h"

using namespace std;

int main()
{
    Date date;

    // Test: Default constructor
    assert(date.GetDay() == 0);
    assert(date.GetMonth() == 0);
    assert(date.GetYear() == 0);
    cout << "Test Passed: Default constructor initializes date to 0/0/0.\n";

    // Test: SetDay method
    date.SetDay(10);
    assert(date.GetDay() == 10);
    cout << "Test Passed: SetDay correctly sets the day.\n";

    // Test: SetMonth method
    date.SetMonth(11);
    assert(date.GetMonth() == 11);
    cout << "Test Passed: SetMonth correctly sets the month.\n";

    // Test: SetYear method
    date.SetYear(2023);
    assert(date.GetYear() == 2023);
    cout << "Test Passed: SetYear correctly sets the year.\n";

    // Test: string conversion operator
    assert(static_cast<string>(date) == "10/11/2023");
    cout << "Test Passed: Operator string correctly returns the date in string format.\n";

    // Test: Stream extraction operator
    istringstream iss("20/12/2023");
    iss >> date;
    assert(date.GetDay() == 20);
    assert(date.GetMonth() == 12);
    assert(date.GetYear() == 2023);
    cout << "Test Passed: Operator >> correctly updates the date from the input stream.\n";

    // Test: Stream insertion operator
    ostringstream oss;
    oss << date;
    assert(oss.str() == "  Date: 20\\12\\2023\n");
    cout << "Test Passed: Operator << correctly outputs the date to the output stream.\n";

    cout << "\nAll tests passed!\n";

    return 0;
}
