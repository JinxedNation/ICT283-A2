#ifndef STATISTICS_H
#define STATISTICS_H
#include "WeatherRecordsType.h"
#include "Vector.h"

#include <cmath>

    /**
     * @class   Statistics
     * @brief   A class that is utilized to perform statistical calculations on our Vector such as calculating the total, the average and stdDev
     *
     * @author  William Halling 32233703
     * @date    April 2024
     * @version 0.2
     */
class Statistics
{
    public:

            /**
             * @brief Statistics Default Constructor
             * Used to construct a Statistics object.
             */
        Statistics();


            /**
             * @brief Destructor
             * Used to destory the Statistics object and release resources.
             */
        ~Statistics();


            /**
             * @brief  getTotal
             * Used to get the total sum of a given value in a set of data
             *
             *
             * @return float - the total of a set of values
             */
        float getTotal() const;


            /**
             * @brief setTotal
             * Used to set the value m_Total
             *
             *
             * @param newTotal float - a temp variable used to set the value m_Total
             */
        void setTotal(float newTotal);


            /**
             * @brief getAverage
             * Used to get the value m_Average
             *
             *
             * @return the average of a set of values
             */
        float getAverage() const;


            /**
             * @brief  setAverage
             * Used to set the value m_Average
             *
             *
             * @param  newAverage a temp variable used to set the value m_Average
             */
        void setAverage(float newAverage);


            /**
             * @brief  getStandardDev
             * Used to get the value m_StdDev
             *
             *
             * @return m_StdDev the standardDeviation of a set of values
             */
        float getStandardDev() const;


            /**
             * @brief  setStdDev
             * Used to set the value m_StdDev
             *
             *
             * @param  newStdDev float - a temp variable used to set the value m_Average
             */
        void setStdDev(float newStdDev);



            /**
             * @brief  divideByZero
             * Used to check if we are dividing by zero
             *
             *
             * @param  numItems int - a temp variable used to set the value m_Average
             */
        bool divideByZero(int numItems) const;


            /**
             * @brief filterRecords()
             * This function is used to generate a vector of records based off of the dates the user enters and the weather type requested
             *
             *
             * @param recordedData the Vector to be filtered
             * @param enteredMonth the month to filter by
             * @param enteredYear  the year  to filter by
             * @param int weatherType the weather type to be read from our struct
             * @return Vector<float> - the filtered Weather Records requested by the user
             */
        Vector<float> filterRecords(const Vector<WeatherRecordsType>& recordedWeatherData, int enteredMonth, int enteredYear, int weatherType);


            /**
             * @brief  gatherStats
             * Used to gather and calculate the statistical data
             *
             *
             * @param  filteredData - the vector of data that is to be rounded
             * @return the values for stdDev, average rounded.
             */
        void gatherStats(const Vector<float>& filteredData, float& average, float& stdev);


            /**
             * @brief roundStats
             * Used to round the calculated values to one decimal palce.
             *
             *
             * @param  statistic - float statitical value to round.
             * @return the values for stdDev, total and average rounded.
             */
        float roundStats(float statistics) const;


            /**
             * @brief  calculateTotal
             * Used to calculate the total of a set of values
             *
             *
             * @param  recordedData - a  vector floats of a given weather type
             * @return the total
             * @throw  std::invalid_arguement if recordedData is empty
             */
        float calculateTotal(const Vector<float>& recordedData) const;


            /**
             * @brief calculateAverage
             * Used to calculate the average of a set of values
             *
             *
             * @param recordedData - a  vector floats of our given weather type
             * @return the average of a set of values
             */
        float calculateAverage(const Vector<float>& recordedData) const;


            /**
             * @brief calculateStdDev
             * Used to calculate the standard deviation of the values
             *
             *
             * @param  recordedData vector containing newRecords a vector of new records
             * @param  average      - the avereage of the data.
             * @return the standard deviation
             */
        float calculateStdDev(const Vector<float>& recordedData, float average) const;


            /**
             * @brief sPCC()
             * Used to calculate the pearson coefficent calculation
             *
             *
             * @param vectorX -
             * @param vectorY
             */
        float sPCC(const Vector<float>& vectorX, const Vector<float>&  vectorY) const;

    private:

        float m_Total;    /// float used to store the total of a set of values
        float m_Average;  /// float used to store the average of a set of values
        float m_StdDev;   /// float used to store the standard deviation of a set of values

};



#endif // STATISTICS_H
