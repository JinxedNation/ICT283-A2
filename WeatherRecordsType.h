#ifndef WEATHERRECORDSTYPE_H
#define WEATHERRECORDSTYPE_H
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <fstream>

/**
 * @brief WeatherRecordsType
 * A container for Weather Records that contains the Date, Time
 * windspeed, solar radiation and temperature
 */
struct WeatherRecordsType
{
    Date m_Date;    ///Date object
    Time m_Time;    ///Time object
    float m_Speed;
    float m_SolarR;
    float m_Temperature;
};


#endif // WEATHERRECORDSTYPE_H
