# Hoverboard IMU
The objective of this project is to collect accelerometer and gyroscope data from an Inertial Measurement Unit (IMU) connected to a Classy Walk hoverboard's motherboard. This could lead to a future project aimed at building a balance robot based on a hoverboard.

<img width="200" alt="Stay classy, people" src="https://github.com/user-attachments/assets/d3308508-4633-40ea-8271-befb98a1abc1">

## The motherboard
![classywalk](https://github.com/user-attachments/assets/85e6cda1-4b22-473d-ab47-2d1407d0d309)

The hoverboard has a split motherboard, each side equipped with a GD32F130C8 microcontroller. It is compatible with the [Hoverboard-Firmware-Hack-Gen2](https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/90) project.

# The IMU
<img width="224" alt="IMU" src="https://github.com/user-attachments/assets/dd6f34fa-91d6-4a8b-8690-2bda375f5e2d">

The chip believed to be the IMU is marked with `16A 3C6A C3C`

# Approach

I used the arduino framework to scan all the possible I2C addresses and then attempted to communicate with the devices that responded. A device was found at address [0x68](https://i2cdevices.org/addresses/0x68). main.cpp scans all registers on all devices, producing the following output:

```
device address: 0x68 register address: 0x0 value: 0x0
device address: 0x68 register address: 0x1 value: 0x0
device address: 0x68 register address: 0x2 value: 0x0
device address: 0x68 register address: 0x3 value: 0xC
device address: 0x68 register address: 0x4 value: 0xFF
device address: 0x68 register address: 0x5 value: 0xFF
device address: 0x68 register address: 0x6 value: 0x19
device address: 0x68 register address: 0x7 value: 0xF4
device address: 0x68 register address: 0x8 value: 0x15
device address: 0x68 register address: 0x9 value: 0x25
device address: 0x68 register address: 0xA value: 0x3
device address: 0x68 register address: 0xB value: 0xFE
device address: 0x68 register address: 0xC value: 0xFF
device address: 0x68 register address: 0xD value: 0x62
device address: 0x68 register address: 0xE value: 0x5B
device address: 0x68 register address: 0xF value: 0x79
device address: 0x68 register address: 0x10 value: 0xAF
device address: 0x68 register address: 0x11 value: 0xA1
device address: 0x68 register address: 0x12 value: 0x3
device address: 0x68 register address: 0x13 value: 0x0
device address: 0x68 register address: 0x14 value: 0x0
device address: 0x68 register address: 0x15 value: 0x0
device address: 0x68 register address: 0x16 value: 0x0
device address: 0x68 register address: 0x17 value: 0x0
device address: 0x68 register address: 0x18 value: 0x0
device address: 0x68 register address: 0x19 value: 0x0
device address: 0x68 register address: 0x1A value: 0x80
device address: 0x68 register address: 0x1B value: 0x10
device address: 0x68 register address: 0x1C value: 0x0
device address: 0x68 register address: 0x1D value: 0x0
device address: 0x68 register address: 0x1E value: 0x0
device address: 0x68 register address: 0x1F value: 0x0
device address: 0x68 register address: 0x20 value: 0x0
device address: 0x68 register address: 0x21 value: 0x0
device address: 0x68 register address: 0x22 value: 0x0
device address: 0x68 register address: 0x23 value: 0x0
device address: 0x68 register address: 0x24 value: 0x0
device address: 0x68 register address: 0x25 value: 0x0
device address: 0x68 register address: 0x26 value: 0x0
device address: 0x68 register address: 0x27 value: 0x0
device address: 0x68 register address: 0x28 value: 0x0
device address: 0x68 register address: 0x29 value: 0x0
device address: 0x68 register address: 0x2A value: 0x0
device address: 0x68 register address: 0x2B value: 0x0
device address: 0x68 register address: 0x2C value: 0x0
device address: 0x68 register address: 0x2D value: 0x0
device address: 0x68 register address: 0x2E value: 0x0
device address: 0x68 register address: 0x2F value: 0x0
device address: 0x68 register address: 0x30 value: 0x0
device address: 0x68 register address: 0x31 value: 0x0
device address: 0x68 register address: 0x32 value: 0x0
device address: 0x68 register address: 0x33 value: 0x0
device address: 0x68 register address: 0x34 value: 0x0
device address: 0x68 register address: 0x35 value: 0x0
device address: 0x68 register address: 0x36 value: 0x0
device address: 0x68 register address: 0x37 value: 0x0
device address: 0x68 register address: 0x38 value: 0x0
device address: 0x68 register address: 0x39 value: 0x0
device address: 0x68 register address: 0x3A value: 0x1
device address: 0x68 register address: 0x3B value: 0xFE
device address: 0x68 register address: 0x3C value: 0x4
device address: 0x68 register address: 0x3D value: 0x2
device address: 0x68 register address: 0x3E value: 0xAC
device address: 0x68 register address: 0x3F value: 0x3E
device address: 0x68 register address: 0x40 value: 0x64
device address: 0x68 register address: 0x41 value: 0x6
device address: 0x68 register address: 0x42 value: 0x70
device address: 0x68 register address: 0x43 value: 0xFF
device address: 0x68 register address: 0x44 value: 0xC2
device address: 0x68 register address: 0x45 value: 0x0
device address: 0x68 register address: 0x46 value: 0x18
device address: 0x68 register address: 0x47 value: 0x0
device address: 0x68 register address: 0x48 value: 0x1B
device address: 0x68 register address: 0x49 value: 0x0
device address: 0x68 register address: 0x4A value: 0x0
device address: 0x68 register address: 0x4B value: 0x0
device address: 0x68 register address: 0x4C value: 0x0
device address: 0x68 register address: 0x4D value: 0x0
device address: 0x68 register address: 0x4E value: 0x0
device address: 0x68 register address: 0x4F value: 0x0
device address: 0x68 register address: 0x50 value: 0xBF
device address: 0x68 register address: 0x51 value: 0xC4
device address: 0x68 register address: 0x52 value: 0xCE
device address: 0x68 register address: 0x53 value: 0x9E
device address: 0x68 register address: 0x54 value: 0xA4
device address: 0x68 register address: 0x55 value: 0xCD
device address: 0x68 register address: 0x56 value: 0xB2
device address: 0x68 register address: 0x57 value: 0x4
device address: 0x68 register address: 0x58 value: 0x6
device address: 0x68 register address: 0x59 value: 0x10
device address: 0x68 register address: 0x5A value: 0x27
device address: 0x68 register address: 0x5B value: 0x0
device address: 0x68 register address: 0x5C value: 0x0
device address: 0x68 register address: 0x5D value: 0x0
device address: 0x68 register address: 0x5E value: 0x0
device address: 0x68 register address: 0x5F value: 0x0
device address: 0x68 register address: 0x60 value: 0x0
device address: 0x68 register address: 0x61 value: 0x0
device address: 0x68 register address: 0x62 value: 0x0
device address: 0x68 register address: 0x63 value: 0x1C
device address: 0x68 register address: 0x64 value: 0x0
device address: 0x68 register address: 0x65 value: 0x0
device address: 0x68 register address: 0x66 value: 0x0
device address: 0x68 register address: 0x67 value: 0x0
device address: 0x68 register address: 0x68 value: 0x0
device address: 0x68 register address: 0x69 value: 0x0
device address: 0x68 register address: 0x6A value: 0x0
device address: 0x68 register address: 0x6B value: 0x0
device address: 0x68 register address: 0x6C value: 0x0
device address: 0x68 register address: 0x6D value: 0x0
device address: 0x68 register address: 0x6E value: 0x0
device address: 0x68 register address: 0x6F value: 0x0
device address: 0x68 register address: 0x70 value: 0x0
device address: 0x68 register address: 0x71 value: 0x0
device address: 0x68 register address: 0x72 value: 0x0
device address: 0x68 register address: 0x73 value: 0x0
device address: 0x68 register address: 0x74 value: 0x7F
device address: 0x68 register address: 0x75 value: 0x2E
device address: 0x68 register address: 0x76 value: 0x0
device address: 0x68 register address: 0x77 value: 0xFF
device address: 0x68 register address: 0x78 value: 0x26
device address: 0x68 register address: 0x79 value: 0x0
device address: 0x68 register address: 0x7A value: 0x0
device address: 0x68 register address: 0x7B value: 0x46
device address: 0x68 register address: 0x7C value: 0x0
device address: 0x68 register address: 0x7D value: 0xFD
device address: 0x68 register address: 0x7E value: 0x4
device address: 0x68 register address: 0x7F value: 0x0
device address: 0x68 register address: 0x80 value: 0x0
device address: 0x68 register address: 0x81 value: 0x0
device address: 0x68 register address: 0x82 value: 0x0
device address: 0x68 register address: 0x83 value: 0xC
device address: 0x68 register address: 0x84 value: 0xFF
device address: 0x68 register address: 0x85 value: 0xFF
device address: 0x68 register address: 0x86 value: 0x19
device address: 0x68 register address: 0x87 value: 0xF4
device address: 0x68 register address: 0x88 value: 0x15
device address: 0x68 register address: 0x89 value: 0x25
device address: 0x68 register address: 0x8A value: 0x3
device address: 0x68 register address: 0x8B value: 0xFE
device address: 0x68 register address: 0x8C value: 0xFF
device address: 0x68 register address: 0x8D value: 0x62
device address: 0x68 register address: 0x8E value: 0x5B
device address: 0x68 register address: 0x8F value: 0x79
device address: 0x68 register address: 0x90 value: 0xAF
device address: 0x68 register address: 0x91 value: 0xA1
device address: 0x68 register address: 0x92 value: 0x3
device address: 0x68 register address: 0x93 value: 0x0
device address: 0x68 register address: 0x94 value: 0x0
device address: 0x68 register address: 0x95 value: 0x0
device address: 0x68 register address: 0x96 value: 0x0
device address: 0x68 register address: 0x97 value: 0x0
device address: 0x68 register address: 0x98 value: 0x0
device address: 0x68 register address: 0x99 value: 0x0
device address: 0x68 register address: 0x9A value: 0x80
device address: 0x68 register address: 0x9B value: 0x10
device address: 0x68 register address: 0x9C value: 0x0
device address: 0x68 register address: 0x9D value: 0x0
device address: 0x68 register address: 0x9E value: 0x0
device address: 0x68 register address: 0x9F value: 0x0
device address: 0x68 register address: 0xA0 value: 0x0
device address: 0x68 register address: 0xA1 value: 0x0
device address: 0x68 register address: 0xA2 value: 0x0
device address: 0x68 register address: 0xA3 value: 0x0
device address: 0x68 register address: 0xA4 value: 0x0
device address: 0x68 register address: 0xA5 value: 0x0
device address: 0x68 register address: 0xA6 value: 0x0
device address: 0x68 register address: 0xA7 value: 0x0
device address: 0x68 register address: 0xA8 value: 0x0
device address: 0x68 register address: 0xA9 value: 0x0
device address: 0x68 register address: 0xAA value: 0x0
device address: 0x68 register address: 0xAB value: 0x0
device address: 0x68 register address: 0xAC value: 0x0
device address: 0x68 register address: 0xAD value: 0x0
device address: 0x68 register address: 0xAE value: 0x0
device address: 0x68 register address: 0xAF value: 0x0
device address: 0x68 register address: 0xB0 value: 0x0
device address: 0x68 register address: 0xB1 value: 0x0
device address: 0x68 register address: 0xB2 value: 0x0
device address: 0x68 register address: 0xB3 value: 0x0
device address: 0x68 register address: 0xB4 value: 0x0
device address: 0x68 register address: 0xB5 value: 0x0
device address: 0x68 register address: 0xB6 value: 0x0
device address: 0x68 register address: 0xB7 value: 0x0
device address: 0x68 register address: 0xB8 value: 0x0
device address: 0x68 register address: 0xB9 value: 0x0
device address: 0x68 register address: 0xBA value: 0x1
device address: 0x68 register address: 0xBB value: 0xFE
device address: 0x68 register address: 0xBC value: 0x14
device address: 0x68 register address: 0xBD value: 0x2
device address: 0x68 register address: 0xBE value: 0xA0
device address: 0x68 register address: 0xBF value: 0x3E
device address: 0x68 register address: 0xC0 value: 0x5C
device address: 0x68 register address: 0xC1 value: 0x6
device address: 0x68 register address: 0xC2 value: 0x50
device address: 0x68 register address: 0xC3 value: 0xFF
device address: 0x68 register address: 0xC4 value: 0xC4
device address: 0x68 register address: 0xC5 value: 0x0
device address: 0x68 register address: 0xC6 value: 0x1C
device address: 0x68 register address: 0xC7 value: 0x0
device address: 0x68 register address: 0xC8 value: 0x1B
device address: 0x68 register address: 0xC9 value: 0x0
device address: 0x68 register address: 0xCA value: 0x0
device address: 0x68 register address: 0xCB value: 0x0
device address: 0x68 register address: 0xCC value: 0x0
device address: 0x68 register address: 0xCD value: 0x0
device address: 0x68 register address: 0xCE value: 0x0
device address: 0x68 register address: 0xCF value: 0x0
device address: 0x68 register address: 0xD0 value: 0xBF
device address: 0x68 register address: 0xD1 value: 0xC4
device address: 0x68 register address: 0xD2 value: 0xCE
device address: 0x68 register address: 0xD3 value: 0x9E
device address: 0x68 register address: 0xD4 value: 0xA4
device address: 0x68 register address: 0xD5 value: 0xCD
device address: 0x68 register address: 0xD6 value: 0xB2
device address: 0x68 register address: 0xD7 value: 0x4
device address: 0x68 register address: 0xD8 value: 0x6
device address: 0x68 register address: 0xD9 value: 0x10
device address: 0x68 register address: 0xDA value: 0x27
device address: 0x68 register address: 0xDB value: 0x0
device address: 0x68 register address: 0xDC value: 0x0
device address: 0x68 register address: 0xDD value: 0x0
device address: 0x68 register address: 0xDE value: 0x0
device address: 0x68 register address: 0xDF value: 0x0
device address: 0x68 register address: 0xE0 value: 0x0
device address: 0x68 register address: 0xE1 value: 0x0
device address: 0x68 register address: 0xE2 value: 0x0
device address: 0x68 register address: 0xE3 value: 0x1C
device address: 0x68 register address: 0xE4 value: 0x0
device address: 0x68 register address: 0xE5 value: 0x0
device address: 0x68 register address: 0xE6 value: 0x0
device address: 0x68 register address: 0xE7 value: 0x0
device address: 0x68 register address: 0xE8 value: 0x0
device address: 0x68 register address: 0xE9 value: 0x0
device address: 0x68 register address: 0xEA value: 0x0
device address: 0x68 register address: 0xEB value: 0x0
device address: 0x68 register address: 0xEC value: 0x0
device address: 0x68 register address: 0xED value: 0x0
device address: 0x68 register address: 0xEE value: 0x0
device address: 0x68 register address: 0xEF value: 0x0
device address: 0x68 register address: 0xF0 value: 0x0
device address: 0x68 register address: 0xF1 value: 0x0
device address: 0x68 register address: 0xF2 value: 0x0
device address: 0x68 register address: 0xF3 value: 0x0
device address: 0x68 register address: 0xF4 value: 0x7F
device address: 0x68 register address: 0xF5 value: 0x2E
device address: 0x68 register address: 0xF6 value: 0x0
device address: 0x68 register address: 0xF7 value: 0xFF
device address: 0x68 register address: 0xF8 value: 0x26
device address: 0x68 register address: 0xF9 value: 0x0
device address: 0x68 register address: 0xFA value: 0x0
device address: 0x68 register address: 0xFB value: 0x46
device address: 0x68 register address: 0xFC value: 0x0
device address: 0x68 register address: 0xFD value: 0xFD
device address: 0x68 register address: 0xFE value: 0x4
device address: 0x68 register address: 0xFF value: 0x0
```

Some IMUs use register 0xF as the the `WHO_AM_I` register, but I could not find any datasheets specifying that that `0x79` is a valid response.

## Arduino Framework Libraries Tried

I've experimented with the following Arduino libraries, each in its own branch:

 * ICM-20948
 * ITG3200
 * LSM6
 * MPU6050
 * MPU9250

The IMU appears similar to the MPU6050. Uncommenting `#define MPU6050LIKE` in the main branch attempts to treat the IMU like an MPU6050. The response changes when the desk is hit, but the gyro and temperature values don't seem accurate. The MPU6050 also produces a response that reacts when the desk is hit.

   
# Installing the firmware

⚠️ Overwriting the firmware is irreversible. Flashing will prevent the hoverboard from functioning in its original capacity. It would be beneficial if someone could figure out how to [extract the original firmware](https://www.usenix.org/system/files/woot20-paper-obermaier.pdf) 

The GD32F130C8 is supported by Platform IO through [platform-gd32](https://github.com/CommunityGD32Cores/platform-gd32)

You can install this firmware on the motherboard using an ST-Link V2 clone. I used an older clone running firmware version V2J17S4. Soldering headers onto the board is required, but the process is relatively straightforward, even with minimal soldering experience.

Installation Steps

* Install Install [VScode](https://code.visualstudio.com/) and [Plafrom IO](https://platformio.org/). Follow [this](https://www.youtube.com/watch?v=PYSy_PLjytQ) PlatformIO tutorial for setup.
* Connect the SWDIO, SWCLK, 3.3V, and GND pins (as marked on the image) to the ST-Link V2.
* For serial output, connect the UART port to your computer. Use a [USB-to-UART converter](https://www.aliexpress.com/item/1005005847955898.html):
  - RX on the motherboard -> TX on the UART converter
  - TX on the motherboard -> RX on the UART converter
  - GND -> GND
  

The UART marked RX and TX is for USART1 (PA3 for RX and PA2 for TX on the microcontroller).

Powering the motherboard via the ST-Link V2 clone works for debugging the IMU.





