#include "Date.h"

Date::Date() : m_Day(-1), m_Month(-1), m_Year(0)
{}


Date::Date(int newDay, int newMonth, int newYear) : m_Day(newDay), m_Month(newMonth), m_Year(newYear)
{}


Date::Date(const Date& otherDate) : m_Day(otherDate.m_Day), m_Month(otherDate.m_Month), m_Year(otherDate.m_Year)
{}


Date::~Date()
{}


Date& Date::operator=(const Date& otherDate)
{
    if (this != &otherDate)
    {
        m_Day   = otherDate.m_Day;
        m_Month = otherDate.m_Month;
        m_Year  = otherDate.m_Year;
    }

    return *this;
}


bool Date::operator==(const Date& otherDate) const
{
    return (m_Year == otherDate.m_Year && m_Month == otherDate.m_Month && m_Day == otherDate.m_Day);
}


bool Date::operator!=(const Date& otherDate) const
{
    return !(*this == otherDate);
}


bool Date::operator<(const Date& otherDate) const
{
    if(m_Year < otherDate.m_Year)
    {
        return true;
    }


    else if(m_Year == otherDate.m_Year && m_Month < otherDate.m_Month)
    {
        return true;
    }


    return false;
}


int Date::getDay() const
{
    return m_Day;
}


int Date::getMonth() const
{
    return m_Month;
}


int Date::getYear() const
{
    return m_Year;
}


void Date::setDay(int newDay)
{
    if (validateDay(newDay))
    {
        m_Day = newDay;
    }
}


void Date::setMonth(int newMonth)
{
    if(validateMonth(newMonth))
    {
        m_Month = newMonth;
    }
}


void Date::setYear(int tempYear)
{
    if(validateYear(tempYear))
    {
        m_Year = tempYear;
    }
}


bool Date::validateDay(int checkDay) const
{
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int maximumDays = daysInMonth[m_Month];


    if(m_Month == 2 && calculateLeapYear(m_Year))
    {
        maximumDays++;
    }

    return (checkDay >= 1 && checkDay <= maximumDays);
}


bool Date::validateMonth(int checkMonth) const
{
    return (checkMonth >= 1 && checkMonth <= 12);
}


bool Date::validateYear(int checkYear) const
{
    return (checkYear >= 0);
}


bool Date::calculateLeapYear(int newYear) const
{
    return (newYear % 400 == 0 || (newYear % 4 == 0 && newYear %100 != 0));
}


std::istream& operator>>(std::istream& inputs, Date& D)
{
    int day, month, year;

    inputs >> day;
    D.setDay(day);
    inputs.ignore(1, '/');


    inputs  >> month;
    D.setMonth(month);
    inputs.ignore(1, '/');

    inputs >> year;
    D.setYear(year);


    return inputs;
}


std::ostream& operator <<(std::ostream& outputs, const Date & D)
{
    outputs << D.getDay() << "/" << D.getMonth() << "/" << D.getYear();

    return outputs;
}
