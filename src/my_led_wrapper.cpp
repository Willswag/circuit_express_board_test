#include "my_led_wrapper.h"

extern  Adafruit_NeoPixel pixels;


void colorWipe(uint32_t c, unsigned long wait, unsigned long current_time)
{
  static uint8_t i = 0;
  static unsigned long last_loop_time = 0;
  if ((current_time - last_loop_time) < wait)
  {
    return;
  }
  last_loop_time = current_time;
  i++;
  if (i > pixels.numPixels())
  {
    i = 0;
  }
  pixels.clear();
  pixels.setPixelColor(i, c);

  pixels.show();
}