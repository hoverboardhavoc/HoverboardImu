#include <Arduino.h>
#include <ITG3200.h>
ITG3200 itg;
void setup()
{
  Serial2.begin(19200);
  while (!Serial2)
  {
  }
  Serial2.println("Hello");
  itg.initialize();
}

void loop()
{
  Serial2.println(itg.x());
  Serial2.println(itg.y());
  Serial2.println(itg.z());
}