/*
 * file DFRobot_EC10.h * @ https://github.com/DFRobot/DFRobot_EC10
 *
 * Arduino library for Gravity: Analog Electrical Conductivity Sensor / Meter Kit (K=10), SKU: DFR0300-H
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2018
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  2018-11
 */

#ifndef _DFROBOT_EC10_H_
#define _DFROBOT_EC10_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define ReceivedBufferLength 10  //length of the Serial CMD buffer

class DFRobot_EC10
{
public:
    DFRobot_EC10();
    ~DFRobot_EC10();
    void calibration(float voltage, float temperature,char* cmd);    //calibration by Serial CMD
	void calibration(float voltage, float temperature);   //calibration by Serial CMD
    float readEC(float voltage, float temperature); // voltage to EC value, with temperature compensation
    void begin();   //initialization

private:
    float _ecvalue;
    float _ecvalueRaw;
    float _kvalue;
    float _voltage;
    float _temperature;

    char _cmdReceivedBuffer[ReceivedBufferLength];  //store the Serial CMD
    byte _cmdReceivedBufferIndex;

private:
    boolean cmdSerialDataAvailable();
    void ecCalibration(byte mode); // calibration process, wirte key parameters to EEPROM
    byte    cmdParse(const char* cmd);
    byte    cmdParse();
};

#endif
