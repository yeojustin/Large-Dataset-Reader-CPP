#include "WindRecCollections.h"

/**
 * @brief Default constructor for the WindRecCollections class.
 *
 * This constructor creates an instance of the WindRecCollections class. The constructor does not perform any specific
 * actions or initialization for the class members, as it is intended to be used as a default constructor.
 */
WindRecCollections::WindRecCollections()
{

}


/**
 * @brief Get a wrapper object containing the records stored in the WindRecCollections.
 *
 * This function returns a DataWrapper object containing the records stored in the WindRecCollections. The DataWrapper
 * allows access to the internal data structure m_records in a controlled manner.
 *
 * @return A DataWrapper object containing the records stored in the WindRecCollections.
 * @note The returned DataWrapper can be used to access, modify, or perform operations on the internal records data.
 */
DataWrapper<WindRec> WindRecCollections::GetRecords() const
{
    return m_records;
}


/**
 * @brief Generate a unique key based on day, month, year, hours, and minutes.
 *
 * This function generates a unique long integer key by combining the day, month, year,
 * hours, and minutes into a single value. The key is used to uniquely identify a wind
 * and weather record.
 *
 * @param day The day of the month (1 to 31).
 * @param month The month (1 to 12).
 * @param year The year (e.g., 2023).
 * @param hours The hour of the day (0 to 23).
 * @param mins The minute of the hour (0 to 59).
 * @return A long integer representing the generated key.
 */
long WindRecCollections::GenerateKey(int day, int month, int year, int hours, int mins)
{
    return year*100000000L + month*1000000 + day*10000 + hours*100 + mins;
}

/**
 * @brief Load and process a CSV file containing wind and weather records.
 *
 * This function reads wind and weather records from a CSV file, processes the data,
 * and stores it in the internal data structure. It also handles error logging to a file
 * if any data conversion issues occur during processing.
 *
 * @param filename The name of the CSV file to read and process.
 * @note The CSV file format is assumed to have headers with columns: "WAST", "T", "SR", "S".
 */
void WindRecCollections::LoadAndProcessCSVFile(const string filename)
{
    ofstream errorFile(INPUT_LOG_FILE, ios::app);

    try
    {
        ifstream inputFile(filename.c_str());

        if (inputFile.rdstate() == 0)
        {
            cout << "File ready...reading file..." << endl;
        }

        string line;
        getline(inputFile, line); //Read in the header

        stringstream headerStream(line); //Store header as a stream for processing

        map<string, int> headerIndices;
        string field;
        int index = 0;
        while(getline(headerStream, field, CSV_DELIMITER))
        {
            headerIndices[field] = index;
            index++;
        }

        int rowCount = 1;

        while(getline(inputFile, line))
        {
            rowCount++;
            stringstream ss(line);
            string field;
            int columnIndex = 0;

            int year;
            int month;
            int day;
            int hours;
            int mins;

            float speed;
            float temp;
            float solar;

            bool skipRow = false;

            while(getline(ss, field, CSV_DELIMITER))
            {
                if (field.empty())
                {
                    skipRow = true;
                    break;
                }

                if (columnIndex == headerIndices["WAST"])
                {
                    stringstream datetimeStream(field);
                    string dataInField;

                    getline(datetimeStream, dataInField, '/');
                    day = stoi(dataInField);
                    getline(datetimeStream, dataInField, '/');
                    month = stoi(dataInField);
                    getline(datetimeStream, dataInField, ' ');
                    year = stoi(dataInField);

                    getline(datetimeStream, dataInField, ':');
                    hours = stoi(dataInField);
                    getline(datetimeStream, dataInField, ':');
                    mins = stoi(dataInField);
                    getline(datetimeStream, dataInField);
                }

                if (columnIndex == headerIndices["T"])
                {
                    try
                    {
                        temp = stof(field);
                    }
                    catch (const exception& ex)
                    {
                        errorFile << "Unable to convert 'T' field: " << field << " at row:" << rowCount << endl;
                        skipRow = true;
                        break;
                    }
                }

                if (columnIndex == headerIndices["SR"])
                {
                    try
                    {
                        solar = stof(field);
                    }
                    catch (const exception& ex)
                    {
                        errorFile << "Unable to convert 'SR' field: " << field << " at row:" << rowCount << endl;
                        skipRow = true;
                        break;
                    }
                }

                if (columnIndex == headerIndices["S"])
                {
                    try
                    {
                        speed = stof(field);
                    }
                    catch (const exception& ex)
                    {
                        errorFile << "Unable to convert 'S' field: " << field << " at row:" << rowCount << endl;
                        skipRow = true;
                        break;
                    }
                }

                columnIndex++;
            }

            if (skipRow)
            {
                continue;
            }

            WindRec windData(speed, temp, solar);
            long BstKey = GenerateKey(day, month, year, hours, mins);

            m_records.InsertRecord(year, BstKey, windData);
        }

        inputFile.close();
    }
    catch (const exception &ex)
    {
        errorFile << typeid(ex).name() << " caught: " << ex.what() << endl;
    }

    errorFile.close();
}

/**
 * @brief Load and process multiple CSV files containing wind and weather records.
 *
 * This function reads multiple CSV files, each containing wind and weather records,
 * and processes the data, storing it in the internal data structure. It also handles
 * error logging to a file if any data conversion issues occur during processing.
 *
 * @param filename The name of the text file that contains a list of CSV file names.
 * @note Each line in the text file should contain a single CSV file name.
 */
void WindRecCollections::LoadMultipleCSVFiles(const string filename)
{
    ofstream errorFile(INPUT_LOG_FILE, ios::app);

    try
    {
        ifstream inputFile;
        inputFile.open(filename);

        if (inputFile.rdstate() == 0)
        {
            string line;
            while(getline(inputFile, line))
            {
                string csvfilename = INPUT_DIR + line;
                LoadAndProcessCSVFile(csvfilename);
                cout << line << " loaded successfully..." << endl;
                errorFile << line << endl;
            }
        }
        else
        {
            throw runtime_error("Unable to open file.");
        }

        inputFile.close();
    }
    catch (const exception &e)
    {
        errorFile << e.what() << endl;
    }

    errorFile.close();
}

/**
 * @brief Calculate the average and standard deviation of wind speed for a given month and year.
 *
 * This function calculates the average and standard deviation of wind speed for a given
 * month and year. The wind speed data is obtained from the internal data structure.
 *
 * @param month The month for which to calculate the average and standard deviation.
 * @param year The year for which to calculate the average and standard deviation.
 * @note The wind speed data is measured in kilometers per hour (km/h).
 */
void WindRecCollections::CalculateAverageAndStdDevForWindSpeed(const int month, const int year)
{
    float sum = 0.0f;
    float sumOfSquares = 0.0f;
    int count = 0;

    if (m_records.ContainsRecordInMap(year))
    {
        const Bst<WindRec>* yearlyRecords = &m_records.GetBstFromKey(year);

        long endKey = GenerateKey(31, month, year, 99, 99);
        long startKey = GenerateKey(1, month, year, 0, 0);

        for (long searchKey=startKey; searchKey<=endKey; searchKey++)
        {
            if (yearlyRecords->Search(searchKey))
            {
                WindRec windData = yearlyRecords->GetData(searchKey);

                float speed = windData.GetSpeed().GetValue();

                sum += speed;
                sumOfSquares += speed * speed;
                count++;
            }
        }

        if (count > 0)
        {
            // At this point, we know that there is a Sum as count > 0.
            // We will use this average to calculate std dev too
            float average = sum / count;
            float variance = (sumOfSquares / count) - (average * average);
            float stdDev = sqrt(variance);

            cout << helper.GetMonthToString(month) << " " << year << endl
                 << "Average Speed: " << fixed << setprecision(2) << average << "km/h " << endl
                 << "Standard Deviation: " << fixed << setprecision(2) << stdDev << "km/h" << endl;
        }
        else
        {
            cout << "No records found for the given month and year." << endl;
            return;
        }
    }
    else
    {
        cout << "Year record not found in database." << endl;
        return;
    }
}

/**
 * @brief Calculate the average and sample standard deviation of temperature for a given year.
 *
 * This function calculates the average and sample standard deviation of temperature for each
 * month in a given year. The temperature data is obtained from the internal data structure.
 *
 * @param year The year for which to calculate the average and sample standard deviation.
 * @note The temperature data is measured in degrees Celsius (°C).
 */
void WindRecCollections::CalculateAverageAndSampleStdDevForTemperature(const int year)
{
    if (m_records.ContainsRecordInMap(year))
    {
        float sum = 0.0f;
        float sumOfSquares = 0.0f;
        int count = 0;

        const Bst<WindRec>* yearlyRecords = &m_records.GetBstFromKey(year);

        for (int month = 1; month <= 12; month++)
        {
            long startKey = GenerateKey(1, month, year, 0, 0);
            long endKey = GenerateKey(31, month, year, 99, 99);

            for (long searchKey=startKey; searchKey<=endKey; searchKey++)
            {
                if (yearlyRecords->Search(searchKey))
                {
                    WindRec windData = yearlyRecords->GetData(searchKey);

                    float temp = windData.GetTemp().GetValue();

                    sum += temp;
                    sumOfSquares += temp * temp;
                    count++;
                }
            }

            if (count > 0)
            {
                // At this point, we know that there is a Sum as count > 0.
                // We will use this average to calculate std dev too
                float average = sum / count;
                float variance = (sumOfSquares / (count - 1)) - (average * average);
                float stdDev = sqrt(variance);

                cout << helper.GetMonthToString(month) << ": " << fixed
                     << setprecision(2) << "average: " << average << " degrees C, stdev: " << setprecision(2) << stdDev << endl;
            }
            else
            {
                cout << "No records found for " << helper.GetMonthToString(month) << endl;
            }
        }
    }
    else
    {
        cout << year << " record not found in database." << endl;
        return;
    }
}


/**
 * @brief Calculate the sample Pearson correlation coefficients (PCC) for wind speed, temperature, and solar radiation for a given month.
 *
 * This function calculates the sample Pearson correlation coefficients (PCC) for wind speed (S) and temperature (T),
 * wind speed (S) and solar radiation (R), and temperature (T) and solar radiation (R) for a given month. The data is obtained
 * from the internal data structure.
 *
 * @param month The month for which to calculate the correlation coefficients.
 * @note The correlation coefficients range from -1 to 1, where 1 indicates a perfect positive correlation,
 * -1 indicates a perfect negative correlation, and 0 indicates no correlation.
 */
void WindRecCollections::CalculateSamplePCCForWindTempSolar(const int month)
{
    for (int year = 2000; year <= 2023; year++)
    {
        if (m_records.ContainsRecordInMap(year))
        {
            const Bst<WindRec>* yearlyRecords = &m_records.GetBstFromKey(year);

            cout << year << endl;

            int count = 0;
            float sumTemp = 0, sumSpeed = 0, sumSolar = 0;
            float sumTempSq = 0, sumSpeedSq = 0, sumSolarSq = 0;
            float sumSpeedTemp = 0, sumSpeedSolar = 0, sumTempSolar = 0;

            long startKey = GenerateKey(1, month, year, 0, 0);
            long endKey = GenerateKey(31, month, year, 99, 99);

            for (long searchKey = startKey; searchKey <= endKey; searchKey++)
            {
                if (yearlyRecords->Search(searchKey))
                {
                    WindRec windData = yearlyRecords->GetData(searchKey);

                    float temp = windData.GetTemp().GetValue();
                    float speed = windData.GetSpeed().GetValue();
                    float solar = windData.GetSolarRad().GetValue();

                    sumTemp += temp;
                    sumSpeed += speed;
                    sumSolar += solar;
                    sumTempSq += temp * temp;
                    sumSpeedSq += speed * speed;
                    sumSolarSq += solar * solar;

                    sumSpeedTemp += speed * temp;
                    sumSpeedSolar += speed * solar;
                    sumTempSolar += temp * solar;

                    count++;
                }
            }

            if (count > 0 && count - 1 > 0)
            {
                float meanTemp = sumTemp / count;
                float meanSpeed = sumSpeed / count;
                float meanSolar = sumSolar / count;

                float varTemp = (sumTempSq - count * meanTemp * meanTemp) / (count - 1);
                float varSpeed = (sumSpeedSq - count * meanSpeed * meanSpeed) / (count - 1);
                float varSolar = (sumSolarSq - count * meanSolar * meanSolar) / (count - 1);

                float stdDevTemp = sqrt(varTemp);
                float stdDevSpeed = sqrt(varSpeed);
                float stdDevSolar = sqrt(varSolar);

                float covSpeedTemp = (sumSpeedTemp - meanSpeed * meanTemp * count) / (count - 1);
                float covSpeedSolar = (sumSpeedSolar - meanSpeed * meanSolar * count) / (count - 1);
                float covTempSolar = (sumTempSolar - meanTemp * meanSolar * count) / (count - 1);

                float pccSpeedTemp = covSpeedTemp / (stdDevSpeed * stdDevTemp);
                float pccSpeedSolar = covSpeedSolar / (stdDevSpeed * stdDevSolar);
                float pccTempSolar = covTempSolar / (stdDevTemp * stdDevSolar);

                cout << helper.GetMonthToString(month) << endl
                     << "S_T: " << fixed << setprecision(2) << pccSpeedTemp << endl
                     << "S_R: " << fixed << setprecision(2) << pccSpeedSolar << endl
                     << "T_R: " << fixed << setprecision(2) << pccTempSolar << endl;
            }
            else
            {
                cout << "Data(s) is not found for " << helper.GetMonthToString(month) << endl;
            }
        }
    }
}


/**
 * @brief Calculate the total solar radiation for each month of a given year.
 *
 * This function calculates the total solar radiation for each month of a given year. The solar radiation data
 * is obtained from the internal data structure and is measured in kilowatt-hours per square meter (kWh/m^2).
 *
 * @param year The year for which to calculate the total solar radiation.
 * @note The function outputs the total solar radiation for each month to the console.
 */
void WindRecCollections::CalculateTotalSolarRadiation(const int year)
{
    if (m_records.ContainsRecordInMap(year))
    {
        cout << year << endl;

        const Bst<WindRec>* yearlyRecords = &m_records.GetBstFromKey(year);

        for (int month = 1; month <= 12; month++)
        {
            float sum = 0.0f;
            int count = 0;

            long startKey = GenerateKey(1, month, year, 0, 0);
            long endKey = GenerateKey(31, month, year, 99, 99);

            for (long searchKey=startKey; searchKey<=endKey; searchKey++)
            {
                if (yearlyRecords->Search(searchKey))
                {
                    WindRec windData = yearlyRecords->GetData(searchKey);

                    float solar = windData.GetSolarRad().GetValue() * 0.001; // Convert from W to kW -> 1w = 0.001kW

                    sum += solar;
                    count++;
                }
            }

            if (count > 0)
            {
                // Print the total solar radiation for the month
                cout << helper.GetMonthToString(month) << ": " << fixed << setprecision(2) << sum << " kWh/m2" << endl;
            }
            else
            {
                cout << helper.GetMonthToString(month) << ": No data" << endl;
            }
        }
    }
    else
    {
        cout << year << " record not found in database." << endl;
        return;
    }
}

/**
 * @brief Calculate and store wind speed, temperature, and solar radiation data for each month of a given year.
 *
 * This function calculates and stores the average wind speed, average temperature, standard deviation of wind speed,
 * standard deviation of temperature, and total solar radiation for each month of a given year. The data is obtained
 * from the internal data structure and is stored in a member variable m_csvDataByYearMonth.
 *
 * @param year The year for which to calculate and store the wind, temperature, and solar radiation data.
 * @note The function stores the calculated data in the m_csvDataByYearMonth member variable.
 */
void WindRecCollections::CalculateAndStoreWindTempSolarData(const int year)
{
    if (m_records.ContainsRecordInMap(year))
    {
        const Bst<WindRec>* yearlyRecords = &m_records.GetBstFromKey(year);

        for (int month = 1; month <= 12; month++)
        {
            float sumWindSpeed = 0.0f;
            float sumTemp = 0.0f;
            float sumSolarRadiation = 0.0f;

            float sumSquaredWindSpeed = 0.0f;
            float sumSquaredTemp = 0.0f;

            int count = 0;

            long startKey = GenerateKey(1, month, year, 0, 0);
            long endKey = GenerateKey(31, month, year, 99, 99);

            for (long searchKey = startKey; searchKey <= endKey; searchKey++)
            {
                if (yearlyRecords->Search(searchKey))
                {
                    WindRec windData = yearlyRecords->GetData(searchKey);

                    float windSpeed = windData.GetSpeed().GetValue();
                    float temp = windData.GetTemp().GetValue();

                    sumWindSpeed += windSpeed;
                    sumTemp += temp;
                    sumSolarRadiation += (windData.GetSolarRad().GetValue() * 0.001);

                    sumSquaredWindSpeed += windSpeed * windSpeed;
                    sumSquaredTemp += temp * temp;

                    count++;
                }
            }

            m_csvData csvData; // Declare an instance of m_csvData structure

            if (count > 0)
            {
                stringstream ss;
                ss << fixed << setprecision(2) << (sumWindSpeed / count);
                csvData.monthlyAvgWindSpeed = ss.str();
                ss.str(""); // Clears the contents of the stream
                ss.clear(); // Clears the error state flags of the stream

                ss << fixed << setprecision(2) << (sumTemp / count);
                csvData.monthlyAvgTemp = ss.str();
                ss.str("");
                ss.clear();

                float varianceWindSpeed = (sumSquaredWindSpeed - sumWindSpeed * sumWindSpeed / count) / (count - 1);
                float varianceTemp = (sumSquaredTemp - sumTemp * sumTemp / count) / (count - 1);

                ss << fixed << setprecision(2) << sqrt(varianceWindSpeed);
                csvData.monthlyStdDevWindSpeed = "(" + ss.str() + ")";
                ss.str("");
                ss.clear();

                ss << fixed << setprecision(2) << sqrt(varianceTemp);
                csvData.monthlyStdDevTemp = "(" + ss.str() + ")";
                ss.str("");
                ss.clear();

                ss << fixed << setprecision(2) << sumSolarRadiation;
                csvData.monthlyTotalSolarRad = ss.str();
            }
            else
            {
                // Store blank data if any of the data is not found
                csvData.monthlyAvgWindSpeed = "";
                csvData.monthlyAvgTemp = "";
                csvData.monthlyTotalSolarRad = "";
                csvData.monthlyStdDevWindSpeed = "";
                csvData.monthlyStdDevTemp = "";
            }

            m_csvDataByYearMonth[month] = csvData;
        }
    }
}


/**
 * @brief Output wind speed, temperature, and solar radiation data to a file for each month of a given year.
 *
 * This function outputs the wind speed, temperature, and solar radiation data for each month of a given year to a CSV file.
 * The data is retrieved from the m_csvDataByYearMonth member variable and is written to the specified file.
 *
 * @param filename The name of the CSV file to which the data will be written.
 * @param year The year for which to output the data.
 * @note The data is output in a tabular format with columns for average wind speed, standard deviation of wind speed,
 * average temperature, standard deviation of temperature, and total solar radiation for each month.
 */
void WindRecCollections::OutputToFile(const string filename, const int year)
{
    ofstream outputFile(filename);

    outputFile << year << endl;

    for (int month = 1; month <= 12; month++)
    {
        m_csvData csvData = m_csvDataByYearMonth[month];

        outputFile << helper.GetMonthToString(month) << CSV_DELIMITER;

        // Use the stored strings directly; they will be empty if the data was missing
        outputFile << csvData.monthlyAvgWindSpeed << csvData.monthlyStdDevWindSpeed << CSV_DELIMITER
                   << csvData.monthlyAvgTemp << csvData.monthlyStdDevTemp << CSV_DELIMITER
                   << csvData.monthlyTotalSolarRad;

        outputFile << endl;
    }
}
