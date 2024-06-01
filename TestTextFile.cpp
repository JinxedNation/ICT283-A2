#include "TestTextFile.h"

void TestTextFile::testConstructor()
{
    std::cout << "Testing TextFile Default Constructor \n";

    TextFile tempFile;
    assert(tempFile.getDataFiles().size() == 0);


    std::cout << "TextFile Default Constructor Test Passed\n\n";
}
