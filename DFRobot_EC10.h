/*!
 * @file DFRobot_EC10.h
 * @brief Define the basic structure of class DFRobot_EC10 
 * @details This library is used to drive the analog electrical conductivity meter to measure solution EC. 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @License     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-5-5
 * @https://github.com/DFRobot/DFRobot_EC10
 */
#ifndef _DFROBOT_EC10_H_
#define _DFROBOT_EC10_H_



#include "Arduino.h"
//#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif



#define ReceivedBufferLength 10  ///<length of the Serial CMD buffer

class DFRobot_EC10
{
public:

  /*!
   * @fn DFRobot_EC10
   * @brief Constructor 
   */
  DFRobot_EC10();
  
  /*!
   * @fn ~DFRobot_EC10
   * @brief destructor 
   */
  ~DFRobot_EC10();

  /*!
   * @fn begin
   * @brief Init sensor 
   */
  void begin();
  
  /*!
   * @fn calibration
   * @brief Calibrate sensor. If the probe is used for the first time or has not been used for a long time, please calibrate it to improve accuracy. 
   * @param voltage  The voltage obtained when measuring standard buffer solution(12.88ms/cm)
   * @param temperature The calibration solution temperature 
   * @param cmd  Calibration command 
   */
  void calibration(float voltage, float temperature,char* cmd);
  
  /*!
   * @fn calibration
   * @brief Calibrate sensor. If the probe is used for the first time or hasn't been used for a long time, please calibrate it to improve accuracy. 
   * @param voltage The voltage obtained when measuring standard buffer solution(12.88ms/cm)
   * @param temperature  The calibration solution temperature 
   */
  void calibration(float voltage, float temperature);   

  /*!
   * @fn readEC
   * @brief Get solution electrical conducitivity 
   * @param voltage  Measured analog voltage
   * @param temperature  Temeprature of the solution to be measured
   */
  float readEC(float voltage, float temperature); 


private:
    float _ecvalue;
    float _ecvalueRaw;
    float _kvalue;
    float _voltage;
    float _temperature;

    char _cmdReceivedBuffer[ReceivedBufferLength]; 
    byte _cmdReceivedBufferIndex;

private:
    boolean cmdSerialDataAvailable();
    void ecCalibration(byte mode); 
    byte    cmdParse(const char* cmd);
    byte    cmdParse();
};

#endif
