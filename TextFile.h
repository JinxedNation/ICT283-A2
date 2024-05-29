#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "Vector.h"
#include <iostream>
#include <fstream>
#include <string>

    /**
     * @class   : TextFile
     * @brief   : Used to read data from a text file.
     *
     * @author  : William Halling 32233703
     * @date    : April 2024
     * @version : 0.2
     */
class TextFile
{
    public:

            /**
             * @brief Default Constructor
             * Used to create a TextFile object
             */
        TextFile();


            /**
             * @brief Parameterized Constructor
             * Used to create a TextFile object with a list of files
             *
             *
             * @param newFiles - a vector of file names to initialize the TextFile Object with
             */
        TextFile(Vector<std::string> newFiles);


            /**
             * @brief Copoy constructor
             * Used to create a copy of the TextFile object
             *
             *
             * @param other textFile object to copy from
             */
        TextFile(const TextFile& otherFile);


            /**
             * @brief Destructor for TextFile object
             * Used to destroy a TextFile object and release resources.
             *
             *
             * @return destroyed TextFile object / NA
             */
       ~TextFile();


            /**
             * @brief getDataFiles()
             * Used to get all of the .csv files stored within data_source.txt
             *
             *
             * @return the list of files as a Vector<std::string>
             */
        Vector<std::string> getDataFiles() const;


            /**
             * @brief setFiles()
             * Used to set the list of file names
             *
             *
             * @param Vector<std::string> fileName
             */
        void setFiles(Vector<std::string> fileName);


            /**
             * @brief readFile()
             * Reads the file names from our data_source.txt and stores them ion and object
             *
             *
             * @param  : fileName the name of the file that is to be read.
             * @return : the content of the file.
             */
        void readFiles(const std::string& fileName);


    private:

        Vector<std::string> m_Files; /// The name of the file


            /**
             * @brief isValidFile()
             * Used to validate if a file has .csv for the file extension and checks if a file ends with .csv
             *
             *
             * @param fileName the name of the file to check
             * @return True if filename is valid, flase otherwise
             */
        bool isValidFile(const std::string& fileName) const;
};

#endif // TEXTFILE_H
