#include "CsvFile.h"

CsvFile::CsvFile() : m_Records(), m_ColumnMap({{"WAST", -1}, {"SR", -1}, {"S", -1}, {"T", -1}})
{
}


CsvFile::CsvFile(const CsvFile& other) : m_Records(other.m_Records), m_ColumnMap(other.m_ColumnMap)
{}


CsvFile::~CsvFile(){}


Vector<WeatherRecordsType> CsvFile::getRecords() const
{
    return m_Records;
}


void CsvFile::setRecords(Vector<WeatherRecordsType> tempRecords)
{
    m_Records = tempRecords;
}


int CsvFile::getColumnNumber(const std::string& columnName) const
{
    std::map<std::string, int>::const_iterator columnItr = m_ColumnMap.find(columnName);

    if (columnItr != m_ColumnMap.end())
    {
        return columnItr->second;
    }
    return -1;
}


void CsvFile::findColumns(std::stringstream& idCodes, std::map<std::string, int>& columnMap)
{
    std::string columnID;
    int columnCount = 0;

    while(std::getline(idCodes, columnID, ','))
    {
        if(columnMap.find(columnID) != columnMap.end())
        {
            columnMap[columnID] = columnCount;
        }

        columnCount++;
    }
}

void CsvFile::readFile(const std::string& fileName, Vector<WeatherRecordsType>& m_Records)
{
    std::ifstream infile(fileName);

    if (!infile)
    {
        throw std::runtime_error("Error: could not find file " + fileName);

        return;
    }

    std::string header;
    std::getline(infile, header);
    std::stringstream headerStream(header);


    findColumns(headerStream, m_ColumnMap);
    std::string currentLine;

    while (std::getline(infile, currentLine))
    {
        processLine(currentLine, m_Records);
    }
    infile.close();


    setRecords(m_Records);
}


void CsvFile::processLine(const std::string& thisRow, Vector<WeatherRecordsType>& weatherRecords)
{
    std::stringstream currentRow(thisRow);
    WeatherRecordsType tempWeatherRecords;

    std::string columnData;
    int currentColumn = 0;

    while (std::getline(currentRow, columnData, ','))
    {
        if (currentColumn == m_ColumnMap["WAST"])
        {
            processDateTime(columnData, tempWeatherRecords);
        }
        else if (currentColumn == m_ColumnMap["SR"])
        {
            processSolarRadiation(columnData, tempWeatherRecords);
        }
        else if (currentColumn == m_ColumnMap["T"])
        {
            processTemperature(columnData, tempWeatherRecords);
        }
        else if (currentColumn == m_ColumnMap["S"])
        {
            processSpeed(columnData, tempWeatherRecords);
        }

        currentColumn++;
    }
    weatherRecords.push_back(tempWeatherRecords);
}


void CsvFile::processDateTime(const std::string& dateTimeStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream dateTimeStream(dateTimeStr);

    dateTimeStream >> weatherRecord.m_Date >> weatherRecord.m_Time;
}


void CsvFile::processSolarRadiation(const std::string& solarStr, WeatherRecordsType& weatherRecord)
{
    float solarData = 0.0f;
    std::stringstream solarRadiationSS(solarStr);

    solarRadiationSS >> solarData;

    if (solarData > 100)
    {
        weatherRecord.m_SolarR = solarData * (1.0 / 6.0) / 100.0;
    }
}


void CsvFile::processTemperature(const std::string& tempStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream temperatureSS(tempStr);

    temperatureSS >> weatherRecord.m_Temperature;
}


void CsvFile::processSpeed(const std::string& speedStr, WeatherRecordsType& weatherRecord)
{
    std::stringstream speedSS(speedStr);

    speedSS >> weatherRecord.m_Speed;
}
