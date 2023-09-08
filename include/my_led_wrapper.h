
#include <stdint.h>
#include <Adafruit_NeoPixel.h>


#define NEOPIXEL_LOOP_DELAY 1500
#define NEOPIXEL_COUNT 10
#define NEOPIXEL_PIN 8

void colorWipe(uint32_t c, unsigned long wait, unsigned long current_time);