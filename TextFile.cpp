#include "TextFile.h"

TextFile::TextFile() : m_Files()
{
    //ctor
}

TextFile::TextFile(Vector<std::string> newFiles) : m_Files(newFiles)
{

}


TextFile::TextFile(const TextFile& otherFile): m_Files(otherFile.m_Files) {}



TextFile::~TextFile()
{
    //dtor
}


void TextFile::setFiles(Vector<std::string> newFiles)
{
    m_Files = newFiles;
}


Vector<std::string> TextFile::getDataFiles() const
{
    return m_Files;
}


bool TextFile::isValidFile(const std::string& fileName) const
{
    return ((fileName.size() > 4) && (fileName.substr(fileName.size() - 4) == ".csv"));
}


void TextFile::readFiles(const std::string& fileName)
{
    std::ifstream textFile(fileName);
    std::string file;


    if(textFile.is_open())
    {
        while(std::getline(textFile, file))
        {
            if(!file.empty() && isValidFile(file))
            {
                m_Files.push_back(file);
            }
            else
            {
                std::cerr << "File is not a csv file. " << file << std::endl;
            }
        }
        setFiles(m_Files);
        textFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
    }
}
