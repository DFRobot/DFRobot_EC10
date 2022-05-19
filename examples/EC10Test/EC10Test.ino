/*!
 * @file EC10Test.ino
 * @brief This is the sample code for Gravity: Analog Electrical Conductivity Sensor / Meter Kit(K=10), SKU: DFR0300-H.
 * @n In order to guarantee precision, a temperature sensor such as DS18B20 is needed, to execute automatic temperature compensation.
 * @n You can send commands in the serial monitor to execute the calibration.
 * @n Serial Commands:
 * @n  enterec -> enter the calibration mode
 * @n  calec -> calibrate with the standard buffer solution, one buffer solutions(12.88ms/cm) will be automaticlly recognized
 * @n  exitec -> save the calibrated parameters and exit from calibration mode
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @License The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @ version V1.0
 * @date 2022-05-05
 * @https://github.com/DFRobot/DFRobot_EC10
 */
 
#include "DFRobot_EC10.h"
#include <EEPROM.h>

#define EC_PIN A1
float voltage,ecValue,temperature = 25;
DFRobot_EC10 ec;

void setup()
{
  Serial.begin(115200);  
  ec.begin();
}

void loop()
{
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U)  //time interval: 1s
    {
      timepoint = millis();
      voltage = analogRead(EC_PIN)/1024.0*5000;  // read the voltage
      Serial.print("voltage:");
      Serial.print(voltage);
      //temperature = readTemperature();  // read your temperature sensor to execute temperature compensation
      ecValue =  ec.readEC(voltage,temperature);  // convert voltage to EC with temperature compensation
      Serial.print("  temperature:");
      Serial.print(temperature,1);
      Serial.print("^C  EC:");
      Serial.print(ecValue,1);
      Serial.println("ms/cm");
    }
    ec.calibration(voltage,temperature);  // calibration process by Serail CMD
}

float readTemperature()
{
  //add your code here to get the temperature from your temperature sensor
}
