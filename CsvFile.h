#ifndef CSVFILE_H
#define CSVFILE_H

//#include "BinarySearchTree.h"
#include "WeatherRecordsType.h"
#include "Vector.h"

#include <map>
#include <string>
#include <sstream>
#include <fstream>


    /**
     * @class  CsvFile
     * @brief  Used to read data from a Csv File
     *
     * This class enables the program to read data from a Csv File and store the data withn a vector, in the instance of this program WeatherRecordsType structs
     *
     * @author  William Halling 32233703
     * @date    April 2024
     * @version 0.5
     */
class CsvFile
{

    public:

            /**
             * @brief Default Constructor
             * Used to construct a CsvFile object.
             */
        CsvFile();


            /**
             * @brief Copy constructor
             * Used to construct a copy of the CsvFile Object
             *
             *
             * @param otherFile the csvFile object to copy
             */
        CsvFile(const CsvFile& otherFile);


            /**
             * @brief Destructor
             * Used to destory the CsvFile object and release resources.
             */
       ~CsvFile();


            /**
             * @brief getColumnNumber()
             * Used to get the column numbers of our weather type IDS
             *
             *
             * @param  columnData - the name of the columnData
             * @return the columnNumbers for WAST, SR, S & T
             */
        int getColumnNumber(const std::string& columnData) const;


            /**
             * @brief setRecords
             * Used to set the Vector for WeatherRecordsType
             *
             *
             * @param Vector<WeatherRecordsType> tempRecords
             */
        void setRecords(Vector<WeatherRecordsType> tempRecords);


            /**
             * @brief getRecords
             * Used to get the Vector for WeatherRecordsType
             *
             *
             * @return the BST with populated full of weatherRecordsStructs.
             */
        Vector<WeatherRecordsType> getRecords() const;


            /**
             * @brief   readFile
             * Reads weather records from a CSV file.
             *
             *
             * @param   fileName The name of the CSV file to read.
             */

        void readFile(const std::string& fileName, Vector<WeatherRecordsType>& m_Records);


    private:

        std::map<std::string, int> m_ColumnMap;
        //BST<WeatherRecordsType> m_Records;
        Vector<WeatherRecordsType> m_Records;

            /**
             * @brief findColumns
             * Finds the column numbers for WAST, S, SR, and T columns
             *
             *
             * @param idCodes   std::stringstream containing the column ids
             * @param columnMap std::map<std::string, int>
             */
        void findColumns(std::stringstream& idCodes, std::map<std::string, int>& columnMap);


            /**
             * @brief readLine
             * Used to read a csv file line by line
             *
             *
             * @param thisRow the current row from the CSV file
             */
        void processLine(const std::string& thisRow, Vector<WeatherRecordsType>& weatherRecords);


            /**
             * @brief processDateTime
             * Used to processes date and time
             *
             *
             * @param thisRow the current row from the CSV file
             * @param weatherRecords object to store the processed date and time
             */
        void processDateTime(const std::string& dateTimeStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processSolarRadiation
             * Used to processes solar radiation
             *
             *
             * @param solarStr the string containing solar radiation data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processSolarRadiation(const std::string& solarStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processTemperature
             * Used to processes temperature
             *
             *
             * @param tempStr the string containing temperature data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processTemperature(const std::string& tempStr, WeatherRecordsType& weatherRecord);


            /**
             * @brief processSpeed
             * Used to process the speed data.
             *
             *
             * @param speedStr  the string containing the speed data
             * @param weatherRecords the weatherRecordsType object to store the processed data
             */
        void processSpeed(const std::string& speedStr, WeatherRecordsType& weatherRecord);
};

#endif // CSV_H
