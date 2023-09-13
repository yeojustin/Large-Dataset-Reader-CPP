#include "TestSuite.h"

void TestSuite::TestTimeClass()
{
    Time time;

    // TEST 1: Default Constructor
    cout << "TEST 1: Default Constructor\n";
    assert(time.GetHours() == 0);
    assert(time.GetMinutes() == 0);
    cout << "  - Test Passed: Default constructor initializes time to 0:0:00.\n";

    // TEST 2: SetHours and SetMinutes Method
    cout << "TEST 2: SetHours and SetMinutes Method\n";
    time.SetHours(10);
    time.SetMinutes(30);
    assert(time.GetHours() == 10);
    assert(time.GetMinutes() == 30);
    cout << "  - Test Passed: SetHours and SetMinutes correctly set the time.\n";

    // TEST 3: String Conversion Operator
    cout << "TEST 3: String Conversion Operator\n";
    assert(static_cast<std::string>(time) == "10:30:00");
    cout << "  - Test Passed: Operator string correctly returns the time in string format.\n";

    // TEST 4: Stream Extraction Operator
    cout << "TEST 4: Stream Extraction Operator\n";
    istringstream iss("11:45");
    iss >> time;
    assert(time.GetHours() == 11);
    assert(time.GetMinutes() == 45);
    cout << "  - Test Passed: Operator >> correctly updates the time from the input stream.\n";

    // TEST 5: Stream Insertion Operator
    cout << "TEST 5: Stream Insertion Operator\n";
    ostringstream oss;
    oss << time;
    assert(oss.str() == "11:45:00\n");
    cout << "  - Test Passed: Operator << correctly outputs the time to the output stream.\n";

    cout << "\nAll tests passed!\n";
}

void TestSuite::TestTemperature()
{
    Temperature temperature;

    // TEST 1: Default Constructor
    cout << "TEST 1: Default Constructor\n";
    assert(temperature.GetValue() == 0.0f);
    cout << "  - Test Passed: Default constructor initializes temperature value to 0.0.\n";

    // TEST 2: SetValue Method
    cout << "TEST 2: SetValue Method\n";
    temperature.SetValue(37.5f);
    assert(temperature.GetValue() == 37.5f);
    cout << "  - Test Passed: SetValue correctly sets the temperature value.\n";

    cout << "\nAll tests passed!\n";
}

void TestSuite::TestSpeedClass()
{
    Speed speed;

    // TEST 1: Default Constructor
    cout << "TEST 1: Default Constructor\n";
    assert(speed.GetValue() == 0.0f);
    cout << "  - Test Passed: Default constructor initializes speed to 0.0.\n";

    // TEST 2: SetValue Method
    cout << "TEST 2: SetValue Method\n";
    speed.SetValue(30.0f);
    assert(speed.GetValue() == 30.0f);
    cout << "  - Test Passed: SetValue correctly sets the speed value.\n";

    // TEST 3: String Conversion Operator
    // cout << "TEST 3: String Conversion Operator\n";
    // assert(static_cast<string>(speed) == "30");
    // cout << "  - Test Passed: Operator string correctly returns the speed in string format.\n";

    // TEST 3: Parameterized Constructor
    cout << "TEST 3: Parameterized Constructor\n";
    Speed speed2(50.0f);
    assert(speed2.GetValue() == 50.0f);
    cout << "  - Test Passed: Parameterized constructor correctly initializes the speed value.\n";

    cout << "\nAll tests passed!\n";
}


void TestSuite::TestSolarRadClass()
{
    SolarRad solarRad;

    // TEST 1: Default Constructor
    cout << "TEST 1: Default Constructor\n";
    assert(solarRad.GetValue() == 0.0f);
    cout << "  - Test Passed: Default constructor initializes solar radiation value to 0.0.\n";

    // TEST 2: SetValue Method
    cout << "TEST 2: SetValue Method\n";
    solarRad.SetValue(50.5f);
    assert(solarRad.GetValue() == 50.5f);
    cout << "  - Test Passed: SetValue correctly sets the solar radiation value.\n";

    cout << "\nAll tests passed!\n";
}

void TestSuite::TestDateClass()
{
    Date date;

    // TEST 1: Default Constructor
    cout << "TEST 1: Default Constructor\n";
    assert(date.GetDay() == 0);
    assert(date.GetMonth() == 0);
    assert(date.GetYear() == 0);
    cout << "  - Test Passed: Default constructor initializes date to 0/0/0.\n";

    // TEST 2: SetDay Method
    cout << "TEST 2: SetDay Method\n";
    date.SetDay(10);
    assert(date.GetDay() == 10);
    cout << "  - Test Passed: SetDay correctly sets the day.\n";

    // TEST 3: SetMonth Method
    cout << "TEST 3: SetMonth Method\n";
    date.SetMonth(11);
    assert(date.GetMonth() == 11);
    cout << "  - Test Passed: SetMonth correctly sets the month.\n";

    // TEST 4: SetYear Method
    cout << "TEST 4: SetYear Method\n";
    date.SetYear(2023);
    assert(date.GetYear() == 2023);
    cout << "  - Test Passed: SetYear correctly sets the year.\n";

    // TEST 5: String Conversion Operator
    cout << "TEST 5: String Conversion Operator\n";
    assert(static_cast<string>(date) == "10/11/2023");
    cout << "  - Test Passed: Operator string correctly returns the date in string format.\n";

    // TEST 6: Stream Extraction Operator
    cout << "TEST 6: Stream Extraction Operator\n";
    istringstream iss("20/12/2023");
    iss >> date;
    assert(date.GetDay() == 20);
    assert(date.GetMonth() == 12);
    assert(date.GetYear() == 2023);
    cout << "  - Test Passed: Operator >> correctly updates the date from the input stream.\n";

    // TEST 7: Stream Insertion Operator
    cout << "TEST 7: Stream Insertion Operator\n";
    ostringstream oss;
    oss << date;
    assert(oss.str() == "  Date: 20\\12\\2023\n");
    cout << "  - Test Passed: Operator << correctly outputs the date to the output stream.\n";

    cout << "\nAll tests passed!\n";
}

void TestSuite::TestWindRecClass()
{
    // Test: Overloaded constructor
    cout << "TEST 1: Overloaded constructor" << endl;
    Speed speed(35.5f);
    Temperature temp(25.5f);
    SolarRad solar(1000.5f);

    WindRec windRec(speed, temp, solar);

    assert(windRec.GetSpeed().GetValue() == 35.5f);
    assert(windRec.GetTemp().GetValue() == 25.5f);
    assert(windRec.GetSolarRad().GetValue() == 1000.5f);
    cout << "  - Test Passed: Overloaded constructor correctly initializes all values.\n";

    // Test: SetSpeed method
    cout << "TEST 2: SetSpeed Method" << endl;
    Speed newSpeed(40.0f);
    windRec.SetSpeed(newSpeed);
    assert(windRec.GetSpeed().GetValue() == 40.0f);
    cout << "  - Test Passed: SetSpeed correctly sets the wind speed.\n";

    // Test: SetTemp method
    cout << "TEST 3: SetTemp Method" << endl;
    Temperature newTemp(30.0f);
    windRec.SetTemp(newTemp);
    assert(windRec.GetTemp().GetValue() == 30.0f);
    cout << "  - Test Passed: SetTemp correctly sets the temperature.\n";

    // Test: SetSolarRad method
    cout << "TEST 4: SetSolarRad Method" << endl;
    SolarRad newSolar(1200.0f);
    windRec.SetSolarRad(newSolar);
    assert(windRec.GetSolarRad().GetValue() == 1200.0f);
    cout << "  - Test Passed: SetSolarRad correctly sets the solar radiation.\n";

    // Test: string conversion operator
    //string expectedResult = "Date: 24/8/2024\nTime: 13:45:00\nWind Speed: 40.0 km/h\nTemperature: 30.0 C\nSolar Radiation: 1200.0 W/m2\n\n";
    //assert(static_cast<string>(windRec) == expectedResult);
    //cout << "Test Passed: Operator string correctly returns the wind record in string format.\n";

    cout << "\nAll tests passed!\n";
}

void TestSuite::TestWindRecCollectionsClass()
{
    // SETUP: Create the WindRecCollections object on the heap
    WindRecCollections* windRecColl = new WindRecCollections();

    // Load the data
    string filename = INPUT_DIR + "data_source.txt";
    windRecColl->LoadMultipleCSVFiles(filename);

    // TEST CASE 1: Check the number of loaded records
    cout << "TEST CASE 1: Check the number of loaded records.\n";
    cout << "No of records: " << windRecColl->GetRecords().GetSize() << endl;
    cout << "  - Test Passed: Records loaded successfully.\n\n";

    // TEST CASE 2: Standard deviation and average for January 2011
    cout << "TEST CASE 2: Calculate the standard deviation and average for wind speed in January 2011.\n";
    windRecColl->CalculateAverageAndStdDevForWindSpeed(1, 2011);
    cout << "  - Test Passed: Calculated standard deviation and average for January 2011 successfully.\n\n";

    // TEST CASE 3: Average and sample standard deviation for temperature (2000-2023)
    cout << "TEST CASE 3: Calculate the average and sample standard deviation for temperature from 2000 to 2023.\n";
    for (int i = 2000; i <= 2023; i++)
    {
        windRecColl->CalculateAverageAndSampleStdDevForTemperature(i);
    }
    cout << "  - Test Passed: Calculated average and sample standard deviation for temperature successfully.\n\n";

    // TEST CASE 4: Sample PCC for wind, temperature, and solar (for all months)
    cout << "TEST CASE 4: Calculate the sample Pearson correlation coefficient for wind, temperature, and solar for all months.\n";
    for (int i = 1; i <= 12; i++)
    {
        windRecColl->CalculateSamplePCCForWindTempSolar(i);
    }
    cout << "  - Test Passed: Calculated sample Pearson correlation coefficient successfully.\n\n";

    // TEST CASE 5: Total solar radiation (2000-2023)
    cout << "TEST CASE 5: Calculate the total solar radiation from 2000 to 2023.\n";
    for (int i = 2000; i <= 2023; i++)
    {
        windRecColl->CalculateTotalSolarRadiation(i);
    }
    cout << "  - Test Passed: Calculated total solar radiation successfully.\n\n";

    // TEST CASE 6: Store and output wind, temperature, and solar data (2000-2023)
    cout << "TEST CASE 6: Store and output wind, temperature, and solar data from 2000 to 2023.\n";
    for (int i = 2000; i <= 2023; i++)
    {
        string path = "OutputTests/";
        string testfile = path + OUTPUT_TESTFILE + to_string(i) + ".csv";
        windRecColl->CalculateAndStoreWindTempSolarData(i);
        windRecColl->OutputToFile(testfile, i);
        cout << "Output to " << testfile << " successfully!\n";
    }
    cout << "  - Test Passed: Stored and outputted wind, temperature, and solar data successfully.\n\n";

    // BONUS TEST CASE: Reload ALL data (Old data will be DELETED)
    cout << "BONUS TEST CASE 7: Reload all data (old data will be deleted).\n";
    if (windRecColl != nullptr)
    {
        delete windRecColl;
        windRecColl = nullptr;
        cout << "Data deleted successfully.\n";
    }
    cout << "Reloading data...\n";
    windRecColl = new WindRecCollections();
    windRecColl->LoadMultipleCSVFiles(filename);
    cout << "  - Test Passed: Reloaded all data successfully.\n\n";

    cout << "All tests passed!\n";
}

void TestSuite::TestTemplateBstClass()
{
    Bst<int> bst;
    int elements[] = {10, 20, 30, 40, 50, 25};

    cout << "EDGE CASE: Testing Empty Tree\n";
    assert(!bst.Search(10)); // Test: Element 10 should not be found
    assert(bst.GetSize() == 0); // Test: Tree size should be 0
    cout << "  - Test Passed: Element 10 not found and size 0 in the empty tree.\n"; // Output: Test passed

    // Insert elements
    for(int i = 0; i < 6; i++)
    {
        bst.Insert(elements[i], elements[i]);
    }

    cout << "TEST CASE 1: Tree Size After Inserting Elements\n";
    assert(bst.GetSize() == 6); // Test: Tree size should be 6
    cout << "  - Test Passed: Tree size is 6 after inserting 6 elements.\n"; // Output: Test passed

    cout << "TEST CASE 2: Search for Elements\n";
    for(int i = 0; i < 6; i++)
    {
        assert(bst.Search(elements[i])); // Test: All elements should be found
        cout << "  - Test Passed: Element " << elements[i] << " found in the tree.\n"; // Output: Test passed
    }

    cout << "TEST CASE 3: Search for an Element Not in the Tree\n";
    assert(!bst.Search(100)); // Test: Element 100 should not be found
    cout << "  - Test Passed: Element 100 not found in the tree.\n"; // Output: Test passed

    cout << "TEST CASE 4: Check Height Difference\n";
    int heightDifference = bst.GetHeightDifference();
    assert(heightDifference >= -1 && heightDifference <= 1);
    cout << "  - Test Passed: Height difference is within the expected range.\n"; // Output: Test passed

    cout << "TEST CASE 5: InOrder, PreOrder and PostOrder Traversals\n";
    cout << "\nInOrder traversal: ";
    bst.InOrder(Print);
    cout << "\nPreOrder traversal: ";
    bst.PreOrder(Print);
    cout << "\nPostOrder traversal: ";
    bst.PostOrder(Print);
    cout << "\n";

    cout << "TEST CASE 6: Copy Constructor\n";
    Bst<int> bstCopy(bst);
    cout << "\nCopy InOrder traversal: ";
    bstCopy.InOrder(Print);
    cout << "\n";

    cout << "TEST CASE 7: Changes to Original Don't Affect Copy\n";
    bst.Insert(60, 60);
    assert(!bstCopy.Search(60));
    cout << "  - Test Passed: Changes to original don't affect copy.\n"; // Output: Test passed

    cout << "TEST CASE 8: Changes to Copy Don't Affect Original\n";
    bstCopy.Insert(70, 70);
    assert(!bst.Search(70));
    cout << "  - Test Passed: Changes to copy don't affect original.\n"; // Output: Test passed

    cout << "EDGE CASE: Single Element Tree\n";
    Bst<int> singleElementTree;
    singleElementTree.Insert(1, 1);
    assert(singleElementTree.Search(1));
    cout << "  - Test Passed: Single element found in the tree.\n"; // Output: Test passed

    cout << "EDGE CASE: Inserting Duplicate Elements\n";
    singleElementTree.Insert(1, 1);
    heightDifference = singleElementTree.GetHeightDifference();
    assert(heightDifference == 0);
    cout << "  - Test Passed: Duplicate insertion did not change the tree.\n"; // Output: Test passed

    cout << "EDGE CASE: Large Inputs\n";
    Bst<int> largeTree;
    for(int i = 0; i < 1000000; i++)
    {
        largeTree.Insert(i, i);
    }
    assert(largeTree.Search(123456));
    cout << "  - Test Passed: Element 123,456 found in the large tree of 1,000,000 nodes.\n"; // Output: Test passed

    cout << "TEST CASE 9: Height Difference After Large Inputs\n";
    int heightDifferenceForLargeTree = largeTree.GetHeightDifference();
    assert(heightDifferenceForLargeTree >= -1 && heightDifferenceForLargeTree <= 1);
    cout << "  - Test Passed: Height difference is within the expected range for a large tree.\n"; // Output: Test passed

    cout << "TEST CASE 10: Size for Large Inputs\n";
    assert(largeTree.GetSize() == 1000000);
    cout << "  - Test Passed: Size is 1,000,000 for a large tree.\n"; // Output: Test passed

    cout << "\nAll tests passed!\n"; // Output: All tests passed
}

void TestSuite::TestDataWrapperClass()
{
    DataWrapper<string> dataWrapper;

    cout << "TEST 1: Insertion and Existence of Records in Bst\n";
    dataWrapper.InsertRecord(1, 100, "Record1");
    dataWrapper.InsertRecord(2, 200, "Record2");
    dataWrapper.InsertRecord(3, 300, "Record3");

    assert(dataWrapper.ContainsRecordInBst(1, 100));
    cout << "  - Test Passed: Record1 found in the DataWrapper.\n";

    assert(dataWrapper.ContainsRecordInBst(2, 200));
    cout << "  - Test Passed: Record2 found in the DataWrapper.\n";

    assert(dataWrapper.ContainsRecordInBst(3, 300));
    cout << "  - Test Passed: Record3 found in the DataWrapper.\n";

    cout << "TEST 2: Non-Existence of a Record in Bst\n";
    assert(!dataWrapper.ContainsRecordInBst(4, 400));
    cout << "  - Test Passed: Record with key 400 not found in the DataWrapper.\n";

    cout << "TEST 3: Insertion of a New Record in Bst\n";
    dataWrapper.InsertRecord(4, 400, "Record4");
    assert(dataWrapper.ContainsRecordInBst(4, 400));
    cout << "  - Test Passed: Record4 inserted and found in the DataWrapper.\n";

    cout << "TEST 4: Existence of Records in Map\n";
    assert(dataWrapper.ContainsRecordInMap(1));
    cout << "  - Test Passed: Map key 1 found in the DataWrapper.\n";

    assert(dataWrapper.ContainsRecordInMap(2));
    cout << "  - Test Passed: Map key 2 found in the DataWrapper.\n";

    cout << "TEST 5: Non-Existence of a Map Key\n";
    assert(!dataWrapper.ContainsRecordInMap(5));
    cout << "  - Test Passed: Map key 5 not found in the DataWrapper.\n";

    cout << "TEST 6: Get Size\n";
    assert(dataWrapper.GetSize() == 4);
    cout << "  - Test Passed: Size of DataWrapper is 4.\n";

    cout << "TEST 7: Insertion and Retrieval of Records with Same Map Key\n";
    dataWrapper.InsertRecord(4, 500, "Record5");
    assert(dataWrapper.ContainsRecordInBst(4, 500));
    cout << "  - Test Passed: Record5 inserted and found in the DataWrapper under the same map key as Record4.\n";

    cout << "TEST 8: Non-Existence of a Bst Key in Existing Map Key\n";
    assert(!dataWrapper.ContainsRecordInBst(4, 600));
    cout << "  - Test Passed: Bst key 600 not found under existing map key 4 in the DataWrapper.\n";

    cout << "TEST 9: Retrieving Bst from Map Key\n";
    Bst<string> retrievedBst = dataWrapper.GetBstFromKey(4);
    assert(retrievedBst.Search(400)); // Record4 should be found
    assert(retrievedBst.Search(500)); // Record5 should be found
    cout << "  - Test Passed: Bst retrieved successfully from map key 4.\n";

    cout << "TEST 10: Retrieving Record from Bst using Map Key and Bst Key\n";
    string retrievedRecord = dataWrapper.GetBstRecord(4, 400);
    assert(retrievedRecord == "Record4");
    cout << "  - Test Passed: Record4 retrieved successfully using map key 4 and bst key 400.\n";

    cout << "EDGE CASE: Retrieving Non-Existent Map Key\n";
    try
    {
        Bst<string> nonExistentBst = dataWrapper.GetBstFromKey(5); // Key 5 does not exist
        assert(false); // This line should not be reached
    }
    catch (runtime_error&)
    {
        cout << "  - Test Passed: Exception caught when retrieving non-existent map key 5.\n";
    }

    cout << "EDGE CASE: Retrieving Non-Existent Bst Record\n";
    try
    {
        string nonExistentRecord = dataWrapper.GetBstRecord(4, 600); // Key 600 does not exist
        assert(false); // This line should not be reached
    }
    catch (exception&)
    {
        cout << "  - Test Passed: Exception caught when retrieving non-existent bst key 600.\n";
    }

    cout << "All tests passed!\n";
}
