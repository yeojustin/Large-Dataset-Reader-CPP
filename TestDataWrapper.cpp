#include <iostream>
#include <cassert>
#include "DataWrapper.h"

using namespace std;

int main()
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

    return 0;
}
