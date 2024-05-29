#ifndef OPTIONS_H
#define OPTIONS_H

#include "Vector.h"
#include "Statistics.h"
#include "WeatherRecordsType.h"

#include <map>
#include <iostream>
#include <fstream>
#include <string>


    /**
     * @class   Options
     * @brief   A class that is utilized to process options 1 - 4
     *
     * @author  William Halling 32233703
     * @date    April 2024
     * @version 0.2
     */
class Options
{
    public:
            /**
             * @brief Default Constructor
             * Used to construct a DateConverter object.
             */
        Options();


            /**
             * @brief Parameterized Constructor
             * Used to construct an Options object with a DateConverter and Statistics
             *
             *
             * @param Statistics - statistics object used to perform statistics
             */
        Options(const Statistics& statistics);


            /**
             * @brief Destructor
             * Used to destory the Options object and release resources.
             */
       ~Options();


            /**
             * @brief getStatistics()
             * Used to get statistics object so calculations can be performed.
             *
             *
             * @return m_Statistics Statistics object
             */
        const Statistics& getStatistics() const;


            /**
             * @brief setStatistics()
             * Used to set a Statistics Object for our Options class
             *
             *
             * @param newStats Statistics Object used for calculations
             */
        void setStatistics(const Statistics& newStats);


            /**
             * @brief displayWindspeedData()
             * Takes our recordedWeatherData vector and filters it based on the month and year entered
             * Then displays the Average and standard deviation of windspeed
             *
             *
             * @param recordedData The Vector of WeatherRecordsType
             * @param year  The year entered by the user
             * @param month The month entered by the user
             */
        void displayWindspeedData(const Vector<WeatherRecordsType>& recordedData, const int month, const int year);


            /**
             * @brief displayTemperatureData()
             * Takes our recordedWeatherData vector and filters it based off of the year entered
             * Displays the average and stddev of temperature for each month the entered the year
             *
             *
             * @param recordedData the Vector of WeatherRecordsType
             * @param enteredYear the year entered by the user
             */
        void displayTemperatureData(const Vector<WeatherRecordsType>& recordedData, const int enteredYear);


            /***
             * @brief displaySolarRadiationData()
             * Takes our recordedWeatherData vector and filters it based off of the year entered
             * Displays the Total solar radiation in kWh/m^2 for each month of a selected year
             *
             *
             * @param recordedData The Vector of WeatherRecordsType
             * @param enteredYear The year entered by the user
             */
        void displaySolarRadiationData(const Vector<WeatherRecordsType>& recordedData, const int enteredYear);


    private:

            /**
             * @brief displayNoData
             * Used to display no data
             *
             *
             * @return name of the month based off of the month entered
             */
        void displayNoData(const std::string& monthName, int year);


        Statistics m_Stats;       ///Statistics an object used to perform statisitcs on the WeatherRecordsType Vector
};


namespace DateUtility
{

            /**
             * @brief convertName
             * Used to convert the name of the month to a string
             *
             *
             * @return name of the month based off of the month entered
             */
    std::string convertName(int enteredMonth);



            /**
             * @brief getEnteredMonthName
             * Used to getEnteredMonthName the month the user wants to recieve
             *
             *
             * @param enteredMonth - a temporary int variable as a range between 1 - 12 for the names of the month.
             * @return
             */
    std::string getEnteredMonthName(int enteredMonth);


    const int MAX_MONTHS = 12;
}


#endif // OPTIONS_H
