# DFRobot_EC10
- [中文版](./README_CN.md)

DFRobot Gravity: analog electrical conductivity sensor/meter(K=10) is particularly used to measure the high electrical conductivity liquid, such as seawater, concentrated brine, etc. The measurement range is up to 100ms/cm. This product is suitable for the water quality application of mariculture, for example, marine fisheries, marine aquariums. <br>

![Product Image](./resources/images/DFR0300-H.jpg)

## Product Link (https://www.dfrobot.com/product-1797.html)
    DFR0300-H: Gravity: Analog Electrical Conductivity Sensor / Meter(K=10)

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an Arduino Library for users to read eletrical conductivity from DFR0300-H.
## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
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
   * @brief Calibrate sensor. If the probe is used for the first time or hasn't been used for a long time, please calibrate it to improve accuracy. 
   * @param voltage  The voltage obtained when measuring standard buffer solution(12.88ms/cm)
   * @param temperature The calibration solution temperature 
   * @param cmd  Calibration command 
   */
  void calibration(float voltage, float temperature,char* cmd);
  
  /*!
   * @fn calibration
   * @brief Calibrate sensor. If the probe is used for the first time or hasn't been used for a long time, please calibrate it to improve accuracy. 
   * @param voltage The voltage obtained when measuring standard buffer solution(12.88ms/cm)
   * @param temperature The calibration solution temperature 
   */
  void calibration(float voltage, float temperature);   

  /*!
   * @fn readEC
   * @brief Get solution electrical conducitivity 
   * @param voltage  Measured analog voltage
   * @param temperature  Temeprature of the solution to be measured
   */
  float readEC(float voltage, float temperature); 
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
mpython        |      √       |              |             | 
microbit        |      √       |              |             | 



## History

- 2022/05/05 - Version 1.0.0 released.
## Credits

Written by fengli(li.feng@dfrobot.com), 2022.05.05 (Welcome to our [website](https://www.dfrobot.com/))
