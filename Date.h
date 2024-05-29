#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>


    /**
     * @class Date
     * @brief This class is utilized to store and contain date information such as day, month, year.
     *
     *
     * @author  William Halling
     * @version 0.4
     * @date    April 2024
     */
class Date
{
    public:
            /**
             * @brief Default constructor.
             * Used to create a date object
             */
        Date();


            /**
             * @brief Non Default constructor.
             *
             *
             * @param newDay   int value to set the day
             * @param newMonth int value to set the month
             * @param newYear  int value to set the year
             */
        Date(int newDay, int newMonth, int newYear);


            /**
             * @brief Date Copy Constructor
             * otherDate The date object to copy data from
             *
             *
             * @return a copy of a date object
             */
        Date(const Date& otherDate);


            /**
             * @brief  Destructor.
             * Used to destory the Date object and release resources.
             *
             *
             * @return destroyed Date object / NA
             */
       ~Date();


            /**
             * @brief  asignment operator.
             * Used to assign the values of one date into another date object, allows for deep copying of data
             *
             *
             * @return copy of Date
             */
        Date& operator=(const Date& otherDate);


            /**
             * @brief Comparison operator.
             * Used to compare one Date object against another date object
             *
             *
             * @param  otherDate - Date object to compare against
             * @return bool true if one date object equals another date object
             */
        bool operator==(const Date& otherDate) const;


            /**
             * @brief  Not Equals operator
             * Used to check if one date object doesnt equal another date object
             *
             *
             * @param  otherDate - Date object to compare against
             * @return bool true if dates are not equal else false
             */
        bool operator!=(const Date& otherDate) const;


            /**
             * @brief Less than operator
             * Used to check if one date is less than / a day or month or year before the other
             *
             *
             * @param  otherDate - Date object to compare against
             * @return bool true if one date is less than the other date. e.g 1/1/2020 1/2/2020
             */
        bool operator<(const Date& otherDate) const;


            /**
             * @brief getDay()
             * Used to get the day
             *
             *
             * @return m_Day int var for the day
             */
        int getDay() const;


            /**
             * @brief getMonth()
             * Used to get the month
             *
             *
             * @return m_Month int var for the Month
             */
        int getMonth() const;


            /**
             * @brief getYear()
             * Used to get the year
             *
             *
             * @return m_Year int var for the year
             */
        int getYear() const;


            /**
             * @brief setDay()
             * Used to set the day value with a temporary day
             *
             *
             * @param  newDay used to set the day variable
             */
        void setDay(int newDay);


            /**
             * @brief setMonth()
             * Used to set the month value with a temporary month
             *
             *
             * @param  newMonth used to set the month variable
             */
        void setMonth(int newMonth);


            /**
             * @brief setYear()
             * Used to set the year value with a temporary year
             *
             *
             * @param  newYear used to set the year variable
             */
        void setYear(int newYear);


        using DateValidatorFuncPtr = bool(*)(int);


            /**
             * @brief validateMonth()
             * Used to check if a month is within the range of 1 - 12
             *
             *
             * @param  checkMonth the month to check
             * @return True if the month is within 1 - 12
             */
        bool validateMonth(int checkMonth) const;


            /**
             * @brief validateYear()
             * Used to check if a year is within the range of 0 - current
             *
             *
             * @param  checkYear the year to check
             * @return True if the month is within 0 and current year
             */
        bool validateYear(int checkYear) const;


    private:

            /**
             * @brief  validateDay()
             * Used to check if a day is within the acceptable range per days in month
             *
             *
             * @param  dayRead the day to check
             * @return True if the eyar is a leap year.
             */
        bool validateDay(int dayRead) const;


            /**
             * @brief calculateLeapYear()
             * Used to calculate if the year is a leap year
             *
             *
             * @param  newYear the year to check
             * @return True if the eyar is a leap year.
             */
        bool calculateLeapYear(int newYear) const;


        int m_Day;   /// The day for the date a value between 1 & 31 depending on the month
        int m_Month; /// The month of a date a value between 1 and 12
        int m_Year;  /// The Year of a date a value as an int
};

std::istream& operator>>(std::istream& inputs, Date& D);
std::ostream& operator <<(std::ostream& outputs, const Date & D);


#endif // DATE_H
