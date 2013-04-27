/*
IRSensorArray.cpp - Arduino Library for Analog IR Sensor Array
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

#include "IRSensorArray.h"

//IR SENSOR
SensorIR::SensorIR(int limit)
{
    _limit = limit;
}
int SensorIR::getMean()
{
    int val;
    int total = 0;
    int SensorCount = 0;
    
    //Loops through all 8 analog IR sensors
    for(int i=0; i<8; i++){
        val = analogRead(i);
        
        //if Sensor is detected
        if (val > _limit){
            total += i;
            SensorCount += 1;
        }
    }
    //Calculate mean
    // MEAN RANGE: 0 - 7
    return int( 2 * float(total)/float(SensorCount) );
}
int SensorIR::getCount()
{
    int val;
    int SensorCount = 0;
    
    for(int i=0; i<8; i++){
        val = analogRead(i);
        
        //if Sensor is detected
        if (val > _limit){
            SensorCount += 1;
        }
    }
    return SensorCount;
}
int SensorIR::getLimit()
{
    return _limit;
}
void SensorIR::setLimit(int limit)
{
    _limit = limit;
}
bool SensorIR::phfm(String sensors, int readings)
{
    //We loop through the number of readings that have to have the same sensors on line
    while (readings > 0){
        int val;
        String readSensors;
        // We check which sensors is on, by looping through them all
        for (int i=0; i<8; i++){
            val = analogRead(i);
            if (val > _limit){readSensors += "1";}
            else{readSensors += "0";}
        }
        // if it matches, we reduce the remaining readings by 1
        if (readSensors == sensors){readings -= 1;}
        // else, the test failed
        else {return false;}
    }
    //if it goes out of the while loop, there have been #readings# phfm 
    return true;
}

bool SensorIR::phfmToggle(String sensors, bool on, int readings)
{
    while (readings > 0){
        int val;
        
        for (int i=0; i<8; i++){
            val = analogRead(i);
            
            if (sensors[i] == '1'){
                if (on == true && val > _limit){
                    readings -= 1;
                }
                else if (on == false && val < _limit){
                    readings -= 1;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}

bool SensorIR::phfmCount(int sensors, int readings){
    while (readings > 0){
        int count = getCount();
        if (count == sensors){readings -= 1;}
        else{return false;}
    }
    return true;
}

bool SensorIR::phfmMinCount(int sensors, int readings){
    while (readings > 0){
        int count = getCount();
        if (count >= sensors){readings -= 1;}
        else{return false;}
    }
    return true;
}