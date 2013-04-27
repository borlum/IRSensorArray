/*
IRSensorArray.h - Arduino Library for Analog IR Sensor Array
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * MJC wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy us a beer in return.
 * /MJC; Mikkel, Joakim & Casper
 * ----------------------------------------------------------------------------
 */

#ifndef IRSensorArray_h
#define IRSensorArray_h

#include "Arduino.h"

class SensorIR
{
    public:
        SensorIR(int limit);
        int getMean();
        int getCount();
        int getLimit();
        void setLimit(int limit);
        bool phfm(String sensors, int readings);
        bool phfmToggle(String sensors, bool on, int readings);
        bool phfmCount(int sensors, int readings);
        bool phfmMinCount(int sensors, int readings);
    private:
        int _limit;
};

#endif