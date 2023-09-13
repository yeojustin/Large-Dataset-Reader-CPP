#include "Helper.h"

string Helper::GetMonthToString(const int month)
{
    string monthString;
    switch (month)
    {
        case 1:
            monthString = "January";
            break;
        case 2:
            monthString = "February";
            break;
        case 3:
            monthString = "March";
            break;
        case 4:
            monthString = "April";
            break;
        case 5:
            monthString = "May";
            break;
        case 6:
            monthString = "June";
            break;
        case 7:
            monthString = "July";
            break;
        case 8:
            monthString = "August";
            break;
        case 9:
            monthString = "September";
            break;
        case 10:
            monthString = "October";
            break;
        case 11:
            monthString = "November";
            break;
        case 12:
            monthString = "December";
            break;
        default:
            monthString = "Invalid month";
            break;
    }

    return monthString;
}


int Helper::GetInt(const string message)
{
    int value;
    bool validInput = false;
    do
    {
        try
        {
            cout << message;
            cin >> value;

            // Check if the input was a valid integer
            if (cin.fail())
            {
                throw runtime_error("Invalid input. Please enter number only.");
            }

            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = true;
        }
        catch (const exception &e)
        {
            cin.clear();  // Clear the error state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the invalid input
            cout << "Error: " << e.what() << endl;
        }

    } while (!validInput);


    return value;
}
