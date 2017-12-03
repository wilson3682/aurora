# Aurora

###### Aurora is a Arduino-powered system for controlling neopixels and creating real-time synesthetic audio-reactive effects.

## Equipment
- Arduino MEGA, or any microcontroller capable of 5v logic, and compatible with FastLED (<a href=''>see compatibility</a>) Logic buffer is needed for any 3.3v logic microcontroller.
- Neopixels, or any other LED chipset comptatible with FastLED (see above compatiblity)
- MSGEQ7 Graphic Equilizer chip (or the <a href='https://www.sparkfun.com/products/10468'>Sparfun shield</a>)

## To run locally
- run `git clone https://github.com/FastLED/FastLED.git`
- open in Arduino IDE or PlatformIO
- In `aurora.ino`:
  - set number of leds: `#define NUM_LEDS 100`
  - set data pin: `#define DATA_PIN 2`
  - set strip type: `#define STRIP_TYPE WS2812B` (see <a href='https://github.com/FastLED/FastLED/wiki/Basic-usage'>FastLED basic usage</a>)
- compile and upload to board
