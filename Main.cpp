#include "WindRecCollections.h"
#include "Helper.h"
#include "TestSuite.h"

void DisplayMenu();

int main()
{
    int choice;
    Helper helper;

    // 0. Load and process file
    WindRecCollections* windRecColl = new WindRecCollections();
    windRecColl->LoadMultipleCSVFiles(DATA_SOURCE);

    // 1. Get user Input
    do
    {
        int year;
        int month;

        DisplayMenu();
        choice = helper.GetInt("Please enter your choice: ");

        // Process the user's choice
        switch (choice)
        {
        case 1:
        {
            year = helper.GetInt("Enter year of interest: ");
            month = helper.GetInt("Enter month of interest: ");
            windRecColl->CalculateAverageAndStdDevForWindSpeed(month, year);
            break;
        }
        case 2:
        {
            year = helper.GetInt("Enter year of interest: ");
            windRecColl->CalculateAverageAndSampleStdDevForTemperature(year);
            break;
        }
        case 3:
        {
            month = helper.GetInt("Enter month of interest: ");
            windRecColl->CalculateSamplePCCForWindTempSolar(month);
            break;
        }
        case 4:
        {
            year = helper.GetInt("Enter year of interest: ");
            windRecColl->CalculateTotalSolarRadiation(year);
            break;
        }
        case 5:
        {
            year = helper.GetInt("Enter year of interest: ");
            windRecColl->CalculateAndStoreWindTempSolarData(year);
            windRecColl->OutputToFile(OUTPUT_FILENAME, year);
            cout << "Output to file successfully" << endl;
            break;
        }
        case 6:
        {
            if (windRecColl != nullptr)
            {
                delete windRecColl;
                windRecColl = nullptr;
                cout << "Data deleted successfully." << endl;

                cout << "Reloading data..." << endl << endl;
                windRecColl = new WindRecCollections();
                windRecColl->LoadMultipleCSVFiles(DATA_SOURCE);
            }
            else
            {
                cout << "Nothing to delete.";
            }
            break;
        }
        case 7:
        {
            cout << "Exiting the program..." << endl;
            if (windRecColl != nullptr)
            {
                delete windRecColl;
                windRecColl = nullptr;
            }
            cout << "Program exited." << endl;
            break;
        }
        case 8:
        {
            cout << "Testing program..." << endl;
            TestSuite test;
            test.TestDateClass();
            test.TestTimeClass();
            test.TestTemperature();
            test.TestSolarRadClass();
            test.TestSpeedClass();
            test.TestWindRecClass();
            test.TestWindRecCollectionsClass();
            test.TestTemplateBstClass();
            test.TestDataWrapperClass();
            cout << "No problems found..." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    while (choice != 7);     // Loop continues until user chooses option 7 to exit

    return 0;
}


void DisplayMenu()
{
    cout <<endl
         << "WELCOME MENU" << endl
         << "---------------------------------------------------------------------------------------------------------" << endl
         << "1. Print average wind speed (in km/h) and its sample standard deviation for a specified month and year" << endl
         << "2. Print average ambient air temperature (in degrees C) and its sample standard deviation for each month" << endl
         << "   of a specified year" << endl
         << "3. Print Sample Pearson Correlation Coefficient for a specific month for all years" << endl
         << "4. Print total solar radiation in (kWh/m2) for each month of a specified year" << endl
         << "5. Output average wind speed, average ambient air temperature and their standard deviations" << endl
         << "   and total solar radiation for each month of a specified year" << endl
         << "6. BONUS: Reload ALL data (Old data will be DELETED)" << endl
         << "7. Exit the program" << endl
         << "8. Test program " << endl
         << "---------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
}
