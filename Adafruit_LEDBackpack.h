/***************************************************
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks
  ----> http://www.adafruit.com/products/
  ----> http://www.adafruit.com/products/

  These displays use I2C to communicate, 2 pins are required to
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
#ifndef Adafruit_LEDBackpack_h
#define Adafruit_LEDBackpack_h

#include "Arduino.h"
#include <Wire.h>

#define LED_ON 1
#define LED_OFF 0

#define LED_RED 1
#define LED_YELLOW 2
#define LED_GREEN 3

#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_CMD_BRIGHTNESS 0xE0



// this is the raw HT16K33 controller
class Adafruit_LEDBackpack {
  public:
    Adafruit_LEDBackpack(void);
    void begin(uint8_t _addr);
    void setBrightness(uint8_t b);
    void blinkRate(uint8_t b);
    void writeDisplay(void);
    void clear(void);
    uint16_t displaybuffer[8];
    void init(uint8_t a);
  protected:
    uint8_t i2c_addr;
};

class Adafruit_Bargraph : public Adafruit_LEDBackpack {
 public:
  Adafruit_Bargraph::Adafruit_Bargraph(void);
  void Adafruit_Bargraph::setBar(uint8_t bar, uint8_t color);

 private:
};

#endif // Adafruit_LEDBackpack_h
