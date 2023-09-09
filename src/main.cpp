#include <Arduino.h>


#include "my_led_wrapper.h"
#include "chirp_tones.h"
#include "my_pdm_wrapper.h"


#define LED_LOOP_DELAY 500


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

// Configure serial port.
  while (!Serial);
  Serial.begin(115200);
  Serial.println("SAMD PDM DMA Demo");

  // Initialize the PDM/I2S receiver

  setup_pdm();
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
  //chirpTones(current_time);
  run_pdm();
}

