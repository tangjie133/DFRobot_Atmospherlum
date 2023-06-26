/*!
 * @file calibration.ino
 * @brief 这是一个校验云雀风速的例程
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license      The MIT License (MIT)
 * @author       [TangJie](jie.tang@dfrobot.com)
 * @version      V1.0.0
 * @date         2023-06-8
 * @url         https://github.com/DFRobot/DFRobot_Atmospherlum
 */
#include "DFRobot_Atmospherlum.h"
#include "SoftwareSerial.h"
#define DEVICE_ADDR                  0x42
DFRobot_Atmospherlum_I2C atm(DEVICE_ADDR,&Wire);
//SoftwareSerial mySerial(2,3);//RX=2,TX=3
//DFRobot_Atmospherlum_UART atm(&mySerial);
void setup(void){
  Serial.begin(115200);
  //mySerial.begin(9600);
  //delay(1000);
  while(atm.begin()!= 0){
    Serial.println("init error");
    delay(1000);
  }
  Serial.println("init success");
  atm.setRadius(23.75);
  delay(100);
  atm.setSpeed1(4.8);
  delay(100);
  atm.setSpeed2(5.8);
  delay(100);
  atm.calibrationSpeed();
}

void loop(void){
    delay(100);
}