#include "WindRecCollections.h"

string OUTPUT_TESTFILE = "WindTempSolarTest";

void TestWindRecCollectionsClass()
{
    // SETUP: Create the WindRecCollections object on the heap
    WindRecCollections* windRecColl = new WindRecCollections();

    // Load the data
    string filename = INPUT_DIR + "data_source.txt";
    windRecColl->LoadMultipleCSVFiles(filename);

    // TEST CASE 0: Check the number of loaded records
    cout << "TEST CASE 0: Number of records\n";
    cout << "No of records: " << windRecColl->GetRecords().GetSize() << endl << endl;

    // TEST CASE 1: Standard deviation and average for January 2011
    cout << "TEST CASE 1: Std deviation and average for 2011 Jan\n";
    windRecColl->CalculateAverageAndStdDevForWindSpeed(1, 2011);

    // TEST CASE 2: Average and sample standard deviation for temperature (2000-2023)
    cout << "TEST CASE 2: Average and Sample Std Dev for Temperature\n";
    for (int i = 2000; i <= 2023; i++) {
        windRecColl->CalculateAverageAndSampleStdDevForTemperature(i);
    }

    // TEST CASE 3: Sample PCC for wind, temperature, and solar (for all months)
    cout << "TEST CASE 3: Sample PCC for Wind, Temperature, and Solar\n";
    for (int i = 1; i <= 12; i++) {
        windRecColl->CalculateSamplePCCForWindTempSolar(i);
    }

    // TEST CASE 4: Total solar radiation (2000-2023)
    cout << "TEST CASE 4: Total Solar Radiation\n";
    for (int i = 2000; i <= 2023; i++) {
        windRecColl->CalculateTotalSolarRadiation(i);
    }

    // TEST CASE 5: Store and output wind, temperature, and solar data (2000-2023)
    cout << "TEST CASE 5: Store and Output Wind, Temp, Solar Data\n";
    for (int i = 2000; i <= 2023; i++) {
        string path = "OutputTests/";
        string testfile = path + OUTPUT_TESTFILE + to_string(i) + ".csv";
        windRecColl->CalculateAndStoreWindTempSolarData(i);
        windRecColl->OutputToFile(testfile, i);
        cout << "Output to " << testfile << " successfully!" << endl;
    }

    // BONUS TEST CASE: Reload ALL data (Old data will be DELETED)
    cout << "BONUS TEST CASE: Reload All Data\n";
    if (windRecColl != nullptr) {
        delete windRecColl;
        windRecColl = nullptr;
        cout << "Data deleted successfully." << endl;
    }
    cout << "Reloading data..." << endl << endl;
    windRecColl = new WindRecCollections();
    windRecColl->LoadMultipleCSVFiles(filename);
}
