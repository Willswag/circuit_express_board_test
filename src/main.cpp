#include <Arduino.h>

#include "my_led_wrapper.h"
#define LED_LOOP_DELAY 500

void chirpTones(unsigned long current_time);

unsigned long last_led_loop_time = 0;

uint8_t led_state = HIGH;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
// put function declarations here:
void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  pixels.begin();
  pixels.clear();

  pixels.show();
}

void loop()
{
  unsigned long current_time = millis();
  // LED test
  if ((current_time - last_led_loop_time) > LED_LOOP_DELAY)
  {
    digitalWrite(LED_BUILTIN, led_state);
    led_state = led_state ^ 0x01;
    last_led_loop_time = current_time;
  }
  // neopixels
  colorWipe(pixels.Color(0, 15, 25), 90, current_time); // Red
  chirpTones(current_time);
}

void chirpTones(unsigned long current_time){
  static unsigned long last_loop_time = 0;
  static uint16_t count = 0;
  const uint16_t steps = 80;
  if ((current_time - last_loop_time) < 6)
  {
    return;
  }
  last_loop_time = current_time;
  count++;
  if (count > steps)
  {
    count = 0;
  }
  tone(A0, count * 25+20);
}