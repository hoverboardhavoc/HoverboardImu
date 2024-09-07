#define DEFAULT_HWSERIAL_INSTANCE 2
#include <Arduino.h>
#include <Wire.h>

uint8_t Low_Address = 1;
uint8_t High_Address = 127;

void debug(byte address)
{
  Serial.print("Found at 0x");
  Serial.println(address, HEX);
}

void setup()
{
  Serial.begin(19200);
  while (!Serial)
  {
  };
  Serial.print("Hello world");
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