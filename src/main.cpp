#define DEFAULT_HWSERIAL_INSTANCE 2
#include <Arduino.h>
#include "MPU9250.h"

MPU9250 mpu; // You can also use MPU9255 as is

void setup()
{
  Serial.begin(19200);
  while (!Serial)
  {
  };
  Serial.println("Hello world");
  Wire.begin();
  delay(2000);
  mpu.verbose(true);

  bool result = mpu.setup(0x68);
  Serial.print(result);
  Serial.println("Setup done");
}

void loop()
{
  if (mpu.update())
  {
    Serial.print(mpu.getYaw());
    Serial.print(", ");
    Serial.print(mpu.getPitch());
    Serial.print(", ");
    Serial.println(mpu.getRoll());
  }
}