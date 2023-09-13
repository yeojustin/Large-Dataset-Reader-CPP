#ifndef WINDRECCOLLECTIONS_H_INCLUDED
#define WINDRECCOLLECTIONS_H_INCLUDED

#include "Bst.h"
#include "WindRec.h"
#include "DataWrapper.h"
#include "Helper.h"

#include <typeinfo>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string INPUT_DIR = "data/";
const string INPUT_LOG_FILE = "InputErrorLog.txt";
const string OUTPUT_FILENAME = "WindTempSolar.csv";
const string DATA_SOURCE = INPUT_DIR + "data_source.txt";

const char CSV_DELIMITER = ',';

class WindRecCollections
{

private:
    DataWrapper<WindRec> m_records;

    struct m_csvData
    {
        string monthlyAvgWindSpeed;
        string monthlyAvgTemp;
        string monthlyTotalSolarRad;
        string monthlyStdDevWindSpeed;
        string monthlyStdDevTemp;
    };

    map<int, m_csvData> m_csvDataByYearMonth;

    Helper helper;

    // Private helper
    long GenerateKey(int day, int month, int year, int hours, int mins);

public:

    WindRecCollections();
    ~WindRecCollections(){};

    // Getters
    DataWrapper<WindRec> GetRecords() const;

    // Parsing and loading file methods
    void LoadAndProcessCSVFile(const string filename);
    void LoadMultipleCSVFiles(const string filename);

    // Menu options
    void CalculateAverageAndStdDevForWindSpeed(const int month, const int year);
    void CalculateAverageAndSampleStdDevForTemperature(const int year);
    void CalculateSamplePCCForWindTempSolar(const int month);
    void CalculateTotalSolarRadiation(const int year);
    void CalculateAndStoreWindTempSolarData(const int year);
    void OutputToFile(const string filename, const int year);
};

#endif // WINDRECCOLLECTIONS_H_INCLUDED
