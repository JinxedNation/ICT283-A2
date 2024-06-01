#include "Date.h"
#include <cassert>
/**
 * @class DateTest Class
 * @brief Used to perform automated testing on the Date Class
 * Contains tests for setting the Default, parameterized, and copy constructors, testing setters and getters for the variables
 * Tests Equality, less than and greater than operators to check if a Date is equal to or less than another date.
 * 
 * @author William Halling
 * @date   June 2024
 */

class TestDate
{
public:
    void testConstructor();
    void testPresetConstructor();
    void testCopyConstructor();
    void testAssignmentOperator();
    void testEqualityOperator();
    void testInequalityOperator();
    void testLessThanOperator();
    void testSetDay();
    void testSetMonth();
    void testSetYear();
    void testCalculateLeapYear();
    void testValidateDay();
    void testValidateMonth();
    void testValidateYear();
    void runAllDateTests();
};