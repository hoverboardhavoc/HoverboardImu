#include <Arduino.h>
#include <Wire.h>

uint8_t Low_Address = 1;
uint8_t High_Address = 127;

void debug(byte address)
{
  Serial2.print("Found at 0x");
  Serial2.println(address, HEX);
}

void setup()
{
  Serial2.begin(19200);
  while (!Serial2)
  {
  };
  Serial2.print("Hello world");
  Wire.begin();
}

byte scan(byte address)
{
  Wire.beginTransmission(address);
  byte error = Wire.endTransmission();
  return error;
}

void loop()
{
  for (byte address = Low_Address; address < High_Address; address++)
  {
    byte error = scan(address);
    if (error == 0)
    {
      debug(address);
    }
  }

  delay(5000);
}