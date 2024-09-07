#include <Arduino.h>
#include <I2CScanner.h>

I2CScanner scanner;

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
  scanner.Init();
}

void loop()
{
  scanner.Execute(debug);
  delay(5000);
}