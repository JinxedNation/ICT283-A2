#include <iostream>
#include <string>
#include "WeatherRecordsType.h"
#include "TextFile.h"
#include "Options.h"
#include "CsvFile.h"
#include "Vector.h"


using DateValidatorFunc = bool(Date::*)(int) const;


int requestInput(const std::string& prompt, bool(*validateEntry)(int));
void readFileData(TextFile textFile, Vector<WeatherRecordsType>& recordedData);
void displayOptions();
void executeOption(const Vector<WeatherRecordsType>& recordedData);



int main()
{
    Vector<WeatherRecordsType> recordedData;

    TextFile textFile;
    textFile.readFiles("data_source.txt");

    readFileData(textFile, recordedData);
    executeOption(recordedData);

    return 0;
}


void printColumnNumbers(const CsvFile& csvFile)
{
    std::cout << "Column numbers:\n";
    std::cout << "WAST: " << csvFile.getColumnNumber("WAST") << std::endl;
    std::cout << "SR:   " << csvFile.getColumnNumber("SR")   << std::endl;
    std::cout << "S:    " << csvFile.getColumnNumber("S")    << std::endl;
    std::cout << "T:    " << csvFile.getColumnNumber("T")    << std::endl;
}


void readFileData(TextFile textFile, Vector<WeatherRecordsType>& recordedData)
{
    Vector<std::string> dataFiles = textFile.getDataFiles();

    CsvFile csvFile;

    for(int i = 0; i < dataFiles.size(); ++i)
    {
        recordedData = csvFile.getRecords();
        csvFile.readFile(dataFiles[i], recordedData);

        std::cout << "File Name: " << dataFiles[i]  << " : " << dataFiles[i] << " : " << std::endl;
        std::cout << "Number of Records Loaded: "   << recordedData.size()   << std::endl;


        printColumnNumbers(csvFile);
    }
}


int requestInput(const std::string& prompt, Date& tempDate, DateValidatorFunc isValidDate)
{
    int input;
    std::cout << prompt;
    while(true)
    {
        std::cin >> input;
        if((tempDate.*isValidDate)(input))
        {
            return input;
        }
        std::cout << "Invalid Input " << prompt;
    }
}


void displayOptions()
{
    std::cout << "\nDisplaying Options\n";
    std::cout << "1. Print The Averge windspeed and sample standard deviation for this windspeed given a specified month and year \n";
    std::cout << "2. Print to screen average ambient air temperature and sample standard deviation for each month of a specified year. \n";
    std::cout << "3. Print to screen the Total solar radiation in kWh/m^2 for each month of a specified year \n";
    std::cout << "5. Quit program \n";
    std::cout << "Enter choice: ";
}


void executeOption(const Vector<WeatherRecordsType>& recordedData)
{
        ///std::cout << "Entering the execute options func: " << std::endl;
    Options selectedOption;
    Date dateValidator;

    int choice = 0;
    int enteredMonth = 0;
    int enteredYear  = 0;

    do
    {
        displayOptions();
        std::cin  >> choice;


        switch(choice)
        {
            case 1:
                enteredMonth = requestInput("Enter month (1-12): ", dateValidator, &Date::validateMonth);
                enteredYear  = requestInput("Enter Year: ", dateValidator, &Date::validateYear);
                std::cout << "You entered Month: " << enteredMonth << " Year input " << enteredYear << std::endl;

                selectedOption.displayWindspeedData(recordedData, enteredMonth, enteredYear);
                break;


            case 2:
                enteredYear = requestInput("Enter Year: ", dateValidator, &Date::validateYear);
                selectedOption.displayTemperatureData(recordedData, enteredYear);
                break;


            case 3:
                enteredMonth = requestInput("Enter month (1-12): ", dateValidator, &Date::validateMonth);
                selectedOption.displaySolarRadiationData(recordedData, enteredYear);
                break;

            case 5:
                std::cout << "Exiting the Program " << std::endl;
                break;

            default:
                std::cout << "Invalid choice please enter a valid option " << std::endl;
                break;
        }
    }
    while(choice != 5);
}

