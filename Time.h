#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <sstream>
#include <fstream>


    /**
     * @class Time
     * @brief This class is utilized to store and contain Time information such as hour, minute, second.
     *
     *
     * @author  William Halling
     * @version 0.2
     * @date    April 2024
     */
class Time
{
    public:

            /**
             * @brief Time Default constructor.
             * Used to create a time object
             */
        Time();


            /**
             * @brief Time Parameterized constructor.
             *
             *
             * @param newHour   int value to set the hour
             * @param newMinute int value to set the minute
             * @param newSecond int value to set the second
             */
        Time(int newHour, int newMinute, int newSecond);


            /**
             * @brief Time Copy Constructor
             *
             *
             * @param newTime The time object to copy data from
             * @return a copy of a time object
             */
        Time(const Time& newTime);


            /**
             * @brief Time Destructor
             * Used to destroy a time object and release resources.
             *
             *
             * @return destroyed time object / NA
             */
        ~Time();


            /**
             * @brief Asignment operator.
             * Used to assign the values of a Time object into another Time object, allows for deep copying of data
             *
             *
             * @return copy of Date
             */
        const Time& operator=(const Time& otherTime);


            /**
             * @brief  comparison operator.
             * Used to compare one Time object against another Time object
             *
             *
             * @param  otherTime - Time object to compare against
             * @return bool true if one Time object equals another Time object
             */
        bool operator==(const Time& otherTime) const;



            /**
             * @brief  Not Equals operator
             * Used to check that one time object doesnt equal another time object
             *
             *
             * @param  otherTime - Time object to compare against
             * @return bool true if Time are not equal else false
             */
        bool operator!=(const Time& otherTime) const;


        bool operator>(const Time& otherTime) const;



        bool operator<(const Time& otherTime) const;


            /**
             * @brief getHour
             * Used to get the hour of a time object
             *
             *
             * @return const int m_Hour
             */
        int getHour() const;


            /**
             * @brief getMinute
             * Used to get the Minute of a time object
             *
             *
             * @return const int m_Minute
             */
        int getMinute() const;


            /**
             * @brief getSecond
             * Used to get the Second of a time object
             *
             *
             * @return const int m_Second
             */
        int getSecond() const;


            /**
             * @brief setHour
             * Used to set the Hour of a time object
             *
             *
             * @param int newHour
             */
        void setHour(int newHour);


            /**
             * @brief setMinute
             * Used to set the Minute of a time object
             *
             *
             * @param int newMinute
             */
        void setMinute(int newMinute);


            /**
             * @brief setSecond
             * @brief Used to set the Second of a time object
             *
             *
             * @param int newSecond
             */
        void setSecond(int newSecond);


    private:

            /**
             * @brief setSecond
             * Used to set the Second of a time object
             *
             *
             * @param int newSecond
             * @return true if the time is between 0 and 59 false otherwise
             */
        bool isValidTime(int newTime) const;


            /**
             * @brief isValidHour()
             * Used to check if the hour is between 0 - 23
             *
             *
             * @param checkHour - the hour to check
             * @return true if the hour is between 0 and 23 false otherwise
             */
        bool isValidHour(int checkHour) const;


        int m_Hour;   /// int value for the hour as a value between 1 and 23
        int m_Minute; /// int value for the hour as a value between 0 and 60
        int m_Second; /// int value for the hour as a value between 0 and 60
};

std::istream & operator >>(std::istream& inputs, Time& t);

#endif // TIME_H