#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_LOOP_DELAY 500

#define NEOPIXEL_LOOP_DELAY 1500
#define NEOPIXEL_COUNT 10
#define NEOPIXEL_PIN 8

void colorWipe(uint32_t c, unsigned long wait, unsigned long current_time);

unsigned long last_led_loop_time = 0;
unsigned long last_neopixel_loop_time = 0;

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
}

void colorWipe(uint32_t c, unsigned long wait, unsigned long current_time)
{
  static uint8_t i = 2;
  static unsigned long last_loop_time = 0;
  if ((current_time - last_loop_time) < wait)
  {
    return;
  }
  last_loop_time = current_time;
  i++;
  if (i > pixels.numPixels())
  {
    i = 2;
  }
  pixels.clear();
  for (uint8_t j = i; j > (i - 2); j--)
  {
    pixels.setPixelColor(j, c);
  }

  pixels.show();
}