#include "Options.h"

Options::Options(){}


Options::~Options(){}


Options::Options(const Statistics& statistics) : m_Stats(statistics)
{}


void Options::displayNoData(const std::string& monthName, int year)
{
    std::cout << monthName << " " << year << " " << " No Data " << std::endl;
}


void Options::displayWindspeedData(const Vector<WeatherRecordsType>& recordedData, int month, int year)
{
    int weatherType = 1;
    std::string monthName = DateUtility::getEnteredMonthName(month);

    Vector<float> filteredData = m_Stats.filterRecords(recordedData, month, year, weatherType);

    float average = 0.0f;
    float stdDev  = 0.0f;


    if(filteredData.size() > 0)
    {
        average = m_Stats.calculateAverage(filteredData);
        stdDev  = m_Stats.calculateStdDev(filteredData, average);
        average *= 3.6;

        average = m_Stats.roundStats(average);
        stdDev  = m_Stats.roundStats(stdDev);

        std::cout << monthName << "  " << year    << ": "   << std::endl;
        std::cout << "Average Speed: " << average << "km/h" << std::endl;
        std::cout << "Sample stdev:  " << stdDev  << std::endl;
    }
    else
    {
        displayNoData(monthName, year);
    }
}



void Options::displayTemperatureData(const Vector<WeatherRecordsType>& recordedData, const int year)
{
    int weatherType = 2;

    std::cout << year << std::endl;

    float average = 0.0f;
    float stdDev  = 0.0f;

    for(int month = 1; month <= 12; ++month)
    {
        std::string monthName = DateUtility::getEnteredMonthName(month);

        Vector<float> filteredData = m_Stats.filterRecords(recordedData, month, year, weatherType);

        if(filteredData.size() > 0)
        {
            average = m_Stats.calculateAverage(filteredData);
            stdDev  = m_Stats.calculateStdDev(filteredData, average);

            std::cout << "\n" << monthName << ":" << "average: " << m_Stats.roundStats(average) << " degrees C, stdev: " << m_Stats.roundStats(stdDev) << std::endl;
        }
        else
        {
            std::cout << "\n" << monthName << ": No Data" << std::endl;
        }
    }
}



//Prompt the user for the month as a numeric value. So, for January, user will enter 1.
//So, if the user enters 1 at the Option 3 prompt,
//The output will be as shown below: Sample Pearson Correlation Coefficient for January//
//S_T: n.nn
//S_R: n.nn
//T_R: n.nn

//where

//n.nn is the actual calculated value for each sPCC.

    ///Note that for this Option 3, the selected month applies to all years that have been loaded. So multiple years’ data for the user specified mont



/****
void Options::displaySPCC(const Vector<WeatherRecordsType>& recordedData, const int month)
{
    std::string monthName = DateUtility::getEnteredMonthName(month);
    std::cout << "Sample Pearson Correlation Coefficient for : " << monthName << " : " std::endl;

    try
    {
        Vector<float> filteredSpeed          = m_Stats.filterRecords(recordedData, month, 1);
        Vector<float> filteredTemperature    = m_Stats.filterRecords(recordedData, month, 2);
        Vector<float> filteredSolarRadiation = m_Stats.filterRecords(recordedData, month, 3);


        float sPCC_S_T = m_Stats.sPCC(filteredSpeed, filteredTemperature);
        float sPCC_S_R = m_Stats.sPCC(filteredSpeed, filteredSolarRadiation);
        float sPCC_T_R = m_Stats.sPCC(filteredTemperature, filteredSolarRadiation);


        std::cout << "S_T: " << sPCC_S_T << std::endl;
        std::cout << "S_R: " << sPCC_S_T << std::endl;
        std::cout << "T_R: " << sPCC_S_T << std::endl;
    }
    catch(const std::invalid_argument& error)
    {
        std::cerr << "Error calculating SPCC " << error.what() << std::endl;
    }
}
**/




void Options::displaySolarRadiationData(const Vector<WeatherRecordsType>& recordedData, const int year)
{
    int weatherType = 3;
    std::cout << year << std::endl;

    for(int month = 1; month <= 12; ++month)
    {
        Vector<float> filteredData = m_Stats.filterRecords(recordedData, month, year, weatherType);

        float totalSolar = m_Stats.calculateTotal(filteredData);

        std::cout << DateUtility::getEnteredMonthName(month) << ": ";

        if(filteredData.size() > 0)
        {
            std::cout << "\n" << m_Stats.roundStats(totalSolar) << " kWh/m^2" << std::endl;
        }
        else if(totalSolar == 0)
        {
            std::cout << "\n" << "No Data" << std::endl;
        }
    }
}



/***
void Options::displaySolarRadiationData(const Vector<WeatherRecordsType>& recordedData, const int year)
{
    int weatherType = 3;
    std::cout << year << std::endl;

    for(int month = 1; month <= 12; ++month)
    {
        Vector<float> filteredData = m_Stats.filterRecords(recordedData, month, year, weatherType);

        float totalSolar = m_Stats.calculateTotal(filteredData);

        std::cout << DateUtility::getEnteredMonthName(month) << ": ";

        if(filteredData.size() > 0)
        {
            std::cout << "\n" << m_Stats.roundStats(totalSolar) << " kWh/m^2" << std::endl;
        }
        else if(totalSolar == 0)
        {
            std::cout << "\n" << "No Data" << std::endl;
        }
    }
}***/


std::string DateUtility::convertName(int enteredMonth)
{
    std::map<int, std::string> monthNames =
    {
        {1, "January"},
        {2, "February"},
        {3, "March"},
        {4, "April"},
        {5, "May"},
        {6, "June"},
        {7, "July"},
        {8, "August"},
        {9, "September"},
        {10, "October"},
        {11, "November"},
        {12, "December"}
    };

    std::map<int, std::string>::iterator monthItr = monthNames.find(enteredMonth);

    if(monthItr != monthNames.end())
    {
        return monthItr->second;
    }
    else
    {
        return "Invalid";
    }
}


std::string DateUtility::getEnteredMonthName(int enteredMonth)
{
    if(enteredMonth >= 1 && enteredMonth <= MAX_MONTHS)
    {
        return convertName(enteredMonth);
    }
}
