#include "TestDate.h"

void TestDate::testConstructor()
{
    std::cout << "Testing Date Default Constructor \n";
    
    Date d;
    assert(d.getDay()   == -1);
    assert(d.getMonth() == -1);
    assert(d.getYear()  == 0);

    std::cout << "Date Default Constructor Test Passed\n\n";
}


void TestDate::testPresetConstructor()
{
    std::cout << "Testing Date NonDefault Constructor \n";
    
    Date d(12, 7, 1994);
    assert(d.getDay()   == 12);
    assert(d.getMonth() == 7);
    assert(d.getYear()  == 1994);

    std::cout << "Date Non Default Constructor Test Passed \n\n";
}    


void TestDate::testCopyConstructor()
{
    std::cout << "Date Default Constructor Test Passed \n";

    Date initialDate(12, 5, 2023);
    Date copyDate(initialDate);

    assert(copyDate.getDay()   == 12);
    assert(copyDate.getMonth() == 5);
    assert(copyDate.getYear()  == 2023);

    std::cout << "Date Copy Constructor Test Passed\n\n";
}


void TestDate::testAssignmentOperator()
{
    std::cout << "Testing Date Assignment Opperator\n";
    Date initialDate(12, 7, 1994);
    Date equalsDate(initialDate);

    assert(equalsDate.getDay()   == 12);
    assert(equalsDate.getMonth() == 7);
    assert(equalsDate.getYear()  == 1994);

    std::cout << "Date Assignment Opperator Test Passed\n\n";
}


void TestDate::testEqualityOperator()
{
    std::cout << "Testing Date Equality Opperator\n\n";

    Date intialDate(12, 5,2020);
    Date sameDate(12,5,2020);
    Date inEqualDate(1,1,2021);

    assert(intialDate   == sameDate);
    assert(!(intialDate == inEqualDate));

    std::cout << "Date Equality Opperator Test Passed\n\n";
}


void TestDate::testInequalityOperator()
{
    std::cout << "Testing Date Inequality Operator \n\n";

    Date initialDate(1,1,2020);
    Date sameDate(1,1,2020);
    Date differentDate(1, 2, 2022);

    assert(!(initialDate != sameDate));
    assert(initialDate != differentDate);
    
    std::cout << "Date Inequal Operator Test Passed\n\n";
}


void TestDate::testLessThanOperator()
{
    std::cout << "Testing Date Less Than Operator\n\n";    
    
    Date firstDate(12, 01, 1990);
    Date secondDate(1,7, 1992);
    Date thirdDate(12, 02, 1989);

    assert(firstDate < secondDate);
    assert(firstDate < thirdDate);
    assert(secondDate < thirdDate);

    std::cout << "Date Less Than Operator Test Passed\n\n";
}


void TestDate::testSetDay() 
{
    std::cout << "Testing Date setDay\n\n";

    Date date(1, 1, 2023);
    date.setDay(15);
    assert(date.getDay() == 15);

    date.setDay(32);
    assert(date.getDay() == 15);

    std::cout << "Date setDay function Test Passed\n\n";
}


void TestDate::testSetMonth() 
{
    std::cout << "Testing Date setMonth\n\n";

    Date date(1, 1, 2023);
    date.setMonth(11);
    assert(date.getMonth() == 11);

    date.setMonth(13);
    assert(date.getMonth() == 11);

    std::cout << "Date setMonth function Test Passed\n\n";
}


void TestDate::testSetYear() 
{
    std::cout << "Testing Date setYear\n\n";

    Date date(1, 1, 1990);
    date.setYear(1970);
    assert(date.getYear() == 1970);

    date.setYear(-1);
    assert(date.getYear() == 1970);

    std::cout << "Date setYear function Test Passed\n\n";
}


void TestDate::testCalculateLeapYear()
{
    std::cout << "Testing Date calculateLeapYear\n\n";

    Date thisDate;
    assert(thisDate.calculateLeapYear(2000));
    assert(!thisDate.calculateLeapYear(2001));
    assert(thisDate.calculateLeapYear(2020));
    assert(!thisDate.calculateLeapYear(1900));

    std::cout << "Date calculateLeapYear function Test Passed\n\n";
}



void TestDate::runAllDateTests()
{
    testConstructor();
    testPresetConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testEqualityOperator();
    testInequalityOperator();
    testLessThanOperator();
    testSetDay();
    testSetMonth();
    testSetYear();
    testCalculateLeapYear();
}

