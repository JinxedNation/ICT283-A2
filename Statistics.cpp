#include "Statistics.h"




Statistics::Statistics() : m_Total(0.0f), m_Average(0.0f), m_StdDev(0.0f){}


Statistics::~Statistics(){}


float Statistics::getTotal() const            { return m_Total;     }
void Statistics::setTotal(float newTotal)     { m_Total = newTotal; }

float Statistics::getAverage() const          { return m_Average;       }
void Statistics::setAverage(float newAverage) { m_Average = newAverage; }

float Statistics::getStandardDev() const      { return m_StdDev;      }
void Statistics::setStdDev(float newStdDev)   { m_StdDev = newStdDev; }


float Statistics::roundStats(float value) const
{
    return roundf(value * 10.0f) / 10.0f;
}


bool Statistics::divideByZero(int numItems) const
{
    if(numItems == 0)
    {
        throw std::invalid_argument("Error: Unable to divide by 0");

        return true;
    }

    return false;
}


float Statistics::calculateTotal(const Vector<float>& recordedData) const
{
    float total = 0.0f;

    for(int i = 0; i < recordedData.size(); ++i)
    {
        total += recordedData[i];
    }

    return total;
}


float Statistics::calculateAverage(const Vector<float>& recordedData) const
{
    if(recordedData.size() == 0)
    {
        throw std::invalid_argument("Error: Unable to calculate the Average as no data was provided: ");
    }

    float total = calculateTotal(recordedData);

    if(divideByZero(recordedData.size()))
    {
        throw std::invalid_argument("Error: Unable to calculate the Average as no data was provided: ");
    }


    return total / recordedData.size();
}


float Statistics::calculateStdDev(const Vector<float>& recordedData, float average) const
{
    if(recordedData.size() < 2)
    {
        std::cout << "Error: Standard Deviation cannot be calculated with fewer than 2 items"<< std::endl;
    }

    float sqrdRangeDif = 0.0f;

    for(int i = 0; i < recordedData.size(); ++i)
    {
         float variation = recordedData[i] - average;

         sqrdRangeDif   += variation * variation ;
    }

    float range = sqrdRangeDif / (recordedData.size() - 1);


    return sqrt(range);
}


float Statistics::sPCC(const Vector<float>& vectorX, const Vector<float>&  vectorY) const
{
    if(vectorX.size() != vectorY.size() || vectorX.size() == 0)
    {
        throw std::invalid_argument("Vectors x and y must be of the same size");
    }


    double mean_X = calculateAverage(vectorX);
    double mean_Y = calculateAverage(vectorY);


    double numerator = 0.0;
    double totalSquaredDiffX = 0.0;
    double totalSquaredDiffY = 0.0;


    for(int i = 0; i < vectorX.size(); ++i)
    {
        float difference_X = vectorX[i] - mean_X;
        float difference_Y = vectorY[i] - mean_Y;

        numerator         += difference_X * difference_Y;
        totalSquaredDiffX += difference_X * difference_X;
        totalSquaredDiffY += difference_Y * difference_Y;
    }


    float denominator = sqrt(totalSquaredDiffX * totalSquaredDiffY);

    if(denominator == 0)
    {
        throw std::invalid_argument("Error: Denominator is 0 unable to calculate PCC");
    }

    return numerator / denominator;
}





Vector<float> Statistics::filterRecords(const Vector<WeatherRecordsType>& recordedWeatherData, int enteredMonth, int enteredYear, int weatherType)
{
    Vector<float> filteredWeatherData;

    for(int i = 0; i < recordedWeatherData.size(); ++i)
    {
        if(enteredMonth == recordedWeatherData[i].m_Date.getMonth() && enteredYear == recordedWeatherData[i].m_Date.getYear())
        {
            switch(weatherType)
            {
                case 1:
                    filteredWeatherData.push_back(recordedWeatherData[i].m_Speed);
                break;


                case 2:
                    filteredWeatherData.push_back(recordedWeatherData[i].m_Temperature);
                break;


                case 3:
                    filteredWeatherData.push_back(recordedWeatherData[i].m_SolarR);
                break;



                default:
                    std::cerr << "Invalid weather type!" << std::endl;
            }
        }
    }
    //std::cout << "Testing if we have actually added new Vector Data : " << std::endl;
    //std::cout << "Statistics::dateFilterRecords  ---> Filtered Records Size:  " << filteredWeatherData.getLength() << std::endl;

    return filteredWeatherData;
}
