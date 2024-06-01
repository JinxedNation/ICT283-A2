#ifndef TESTTIME_H
#define TESTTIME_H
#include "Time.h"
#include <cassert>
#include <iostream>

class TestTime
{
    public: 
        void testConstructor();
        void testPresetConstructor();
        void testCopyConstructor();
        void testAssignmentOperator();
        void testEqualityOperator();
        void testInequalityOperator();
        void testGetters();
        void testSetHour();
        void testSetMinute();
        void testSetSecond();
        void testIsValidTime();
        void runAllTimeTests();
};

#endif