#include "Time.h"

Time::Time() : m_Hour(0), m_Minute(0), m_Second(0)
{}

Time::~Time()
{
    //dtor
}


Time::Time(int tempHour, int tempMinute, int tempSecond) : m_Hour(tempHour), m_Minute(tempMinute), m_Second(tempSecond)
{

}


Time::Time(const Time& otherTime) : m_Hour(otherTime.m_Hour), m_Minute(otherTime.m_Minute), m_Second(otherTime.m_Second)
{

}


const Time& Time::operator=(const Time& otherTime)
{
    if (this != &otherTime)
    {
        m_Hour   = otherTime.m_Hour;
        m_Minute = otherTime.m_Minute;
        m_Second = otherTime.m_Second;
    }

    return *this;
}


bool Time::operator ==(const Time& otherTime) const
{
    return (m_Hour == otherTime.m_Hour && m_Minute == otherTime.m_Minute && m_Second == otherTime.m_Second);
}


bool Time::operator!=(const Time& otherTime) const
{
    return !(*this == otherTime);
}


int Time::getHour()   const { return m_Hour;   }
int Time::getMinute() const { return m_Minute; }
int Time::getSecond() const { return m_Second; }


void Time::setSecond(int newSecond)
{
    if(isValidTime(newSecond))
    {
        m_Second = newSecond;
    }
}


void Time::setMinute(int newMinute)
{
    if (isValidTime(newMinute))
    {
        m_Minute = newMinute;
    }
}


void Time::setHour(int newHour)
{
    if(isValidHour(newHour))
    {
        m_Hour = newHour;
    }
}


bool Time::isValidTime(int newTime) const
{
    return (newTime >= 0 && newTime <= 59);
}


bool Time::isValidHour(int checkHour) const
{
    return (checkHour >= 0 && checkHour <= 23);
}


std::istream& operator>>(std::istream& inputs, Time& time)
{
    int hour, minute, second;
    char delimiter;

    inputs >> hour;
    time.setHour(hour);
    inputs.ignore();

    inputs >> minute;
    time.setMinute(minute);


    return inputs;
}


std::ostream & operator <<(std::ostream & outputs, const Time& time)
{
    outputs << time.getHour() << ":";

    if(time.getMinute() < 10)
        outputs << "0";

    outputs << time.getMinute();

    return outputs;
}
