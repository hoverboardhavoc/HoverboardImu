#include <Arduino.h>
#include "MPU9250.h"

MPU9250 mpu; // You can also use MPU9255 as is

void setup()
{
  Serial2.begin(19200);
  while (!Serial2)
  {
  };
  Serial2.print("Hello world");
  Wire.begin();
  delay(2000);

  mpu.setup(0x68); 

  Serial2.print("Setup done");
  // change to your own address
}

void loop()
{
  if (mpu.update())
  {
    Serial2.print(mpu.getYaw());
    Serial.print(", ");
    Serial2.print(mpu.getPitch());
    Serial.print(", ");
    Serial2.println(mpu.getRoll());
  }
}