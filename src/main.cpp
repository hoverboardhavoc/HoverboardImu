#define DEFAULT_HWSERIAL_INSTANCE 2
#include <Arduino.h>
#include <Wire.h>

//#define MPU6050LIKE

void readRegister(byte deviceAddress, byte registerAddress)
{
  Wire.beginTransmission(deviceAddress); // Start transmission to the device
  Wire.write(registerAddress);           // Send the register address to read
  byte error = Wire.endTransmission();
  if (error == 0)
  {                                           // Check if transmission was successful
    Wire.requestFrom(deviceAddress, (byte)1); // Request 1 byte from the device
    delay(5);
    if (Wire.available())
    {
      Serial.print("device address: 0x");
      Serial.print(deviceAddress, HEX);
      Serial.print(" register address: 0x");
      Serial.print(registerAddress, HEX);
      Serial.print(" value: 0x");
      Serial.println(Wire.read(), HEX); // Return the byte read from the register
    }
  }
}

void setupDevice(byte address)
{
  // Inspired by https://forum.arduino.cc/t/i2c-protocol-tutorial-using-an-mpu6050/387512
  Serial.print("Probing device at at 0x");
  Serial.println(address, HEX);

  Wire.beginTransmission(address);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // set to zero (wakes up the MPU-6050)
  Wire.endTransmission();

  Wire.beginTransmission(address);
  Wire.write(0x1B);
  Wire.write(0x10);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  Wire.write(0x1C);
  Wire.write(0x00);
  Wire.endTransmission();
}

void fetchData(byte address)
{
  Wire.beginTransmission(address);
  Wire.write(0x3B); // starting register for accelerometer data
  Wire.endTransmission();
  Wire.requestFrom(address, 14, true);            // request a total of 14 registers
  int16_t accX = Wire.read() << 8 | Wire.read();  // 0x3B (accX high byte) and 0x3C (accX low byte)
  int16_t accY = Wire.read() << 8 | Wire.read();  // 0x3D (accY high byte) and 0x3E (accY low byte)
  int16_t accZ = Wire.read() << 8 | Wire.read();  // 0x3F (accZ high byte) and 0x40 (accZ low byte)
  int16_t temp = Wire.read() << 8 | Wire.read();  // 0x41 (temp high byte) and 0x42 (temp low byte)
  int16_t gyroX = Wire.read() << 8 | Wire.read(); // 0x43 (gyroX high byte) and 0x44 (gyroX low byte)
  int16_t gyroY = Wire.read() << 8 | Wire.read(); // 0x45 (gyroY high byte) and 0x46 (gyroY low byte)
  int16_t gyroZ = Wire.read() << 8 | Wire.read(); // 0x47 (gyroZ high byte) and 0x48 (gyroZ low byte)

  // Print the values to the serial monitor
  Serial.print("AccX: ");
  Serial.print(accX);
  Serial.print(" AccY: ");
  Serial.print(accY);
  Serial.print(" AccZ: ");
  Serial.print(accZ);
  Serial.print(" Temp: ");
  Serial.print(temp / 340.00 + 36.53); // temperature formula?? Does not work
  Serial.print(" GyroX: ");
  Serial.print(gyroX);
  Serial.print(" GyroY: ");
  Serial.print(gyroY);
  Serial.print(" GyroZ: ");
  Serial.println(gyroZ);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  };

  Wire.begin();
  Serial.println("Hello world");
}

byte scan(byte address)
{
  Wire.beginTransmission(address);
  byte error = Wire.endTransmission();
  return error;
}

void loop()
{
  for (byte address = 1; address < 127; address++)
  {
    byte error = scan(address);
    if (error == 0)
    {
#ifdef MPU6050LIKE
      setupDevice(address);
      for (int i = 0; i < 1000; i++)
      {
        fetchData(address);
      }
#endif
      for (byte registerAddress = 0x00; registerAddress <= 0xFF; registerAddress++)
      {
        readRegister(address, registerAddress);
      }
    }
  }
}