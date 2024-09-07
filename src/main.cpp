#include <Arduino.h>
#include <Wire.h>
#include <Wire.h>

// Function to read a byte from a specific register of a device
byte readRegister(byte deviceAddress, byte registerAddress)
{
  Serial2.print(" Register 0x");
  Serial2.print(registerAddress, HEX);
  Wire.beginTransmission(deviceAddress); // Start transmission to the device
  Wire.write(registerAddress);           // Send the register address to read
  byte error = Wire.endTransmission();
  Serial2.print(" error: ");
  Serial2.println(error);
  if (error == 0)
  {                                           // Check if transmission was successful
    Wire.requestFrom(deviceAddress, (byte)1); // Request 1 byte from the device
    delay(5);
    /*  while(!Wire.available()) {

      }*/
    if (Wire.available())
    {
      return Wire.read(); // Return the byte read from the register
    }
  }
  // Wire.endTransmission();
  return 0xFF; // Return 0xFF if the read failed
}

void bruteForceScan()
{
  Serial2.println("registers...");
  for (byte registerAddress = 0x01; registerAddress <= 0xFF; registerAddress++)
  {
    byte data = readRegister(0x68, registerAddress);

    // Print the result if it's not 0xFF (a default value that often means no response)
    if (data != 0xFF)
    {
      Serial2.print(" Register 0x");
      Serial2.print(registerAddress, HEX);
      Serial2.print(": 0x");
      Serial2.println(data, HEX);
    }
    delay(5);
  }
}

void setup()
{
  Wire.begin();
  Serial2.begin(19200);
  while (!Serial2)
  {
  };
  Serial2.println("Hello world");
}

void loop()
{
  // Empty loop, all work is done in setup()
  delay(1000); // Give some time to set up

  bruteForceScan(); // Start brute force reading
}