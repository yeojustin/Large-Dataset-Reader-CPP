#ifndef TESTSUITE_H_INCLUDED
#define TESTSUITE_H_INCLUDED

#include "Bst.h"
#include "DataWrapper.h"
#include "Date.h"
#include "SolarRad.h"
#include "Speed.h"
#include "Temperature.h"
#include "Time.h"
#include "WindRec.h"
#include "WindRecCollections.h"

#include <iostream>
#include <cassert>

class TestSuite
{

/**
 * @brief The name of the output test file.
 */
string OUTPUT_TESTFILE = "WindTempSolarTest";

/**
 * @brief Helper function to print an integer data.
 * @param data The integer data to be printed.
 */
static void Print(int& data)
{
    cout << data << " ";
}

public:
    /**
     * @brief Default constructor for the TestSuite class.
     */
    TestSuite() {}

    /**
     * @brief Destructor for the TestSuite class.
     */
    ~TestSuite() {}

    /**
     * @brief Executes the test cases for the Time class.
     */
    void TestTimeClass();

    /**
     * @brief Executes the test cases for the Temperature class.
     */
    void TestTemperature();

    /**
     * @brief Executes the test cases for the Speed class.
     */
    void TestSpeedClass();

    /**
     * @brief Executes the test cases for the SolarRad class.
     */
    void TestSolarRadClass();

    /**
     * @brief Executes the test cases for the Date class.
     */
    void TestDateClass();

    /**
     * @brief Executes the test cases for the WindRec class.
     */
    void TestWindRecClass();

    /**
     * @brief Executes the test cases for the WindRecCollections class.
     */
    void TestWindRecCollectionsClass();

    /**
     * @brief Executes the test cases for the Bst class (template binary search tree).
     */
    void TestTemplateBstClass();

    /**
     * @brief Executes the test cases for the DataWrapper class.
     */
    void TestDataWrapperClass();
};



#endif // TESTSUITE_H_INCLUDED
