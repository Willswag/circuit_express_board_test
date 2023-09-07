#include <Arduino.h>
#define LED_LOOP_DELAY 500

unsigned long last_loop_time = 0;
uint8_t led_state = HIGH;
// put function declarations here:
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  unsigned long current_time = millis();

  if ((current_time - last_loop_time)> LED_LOOP_DELAY)
  {
    digitalWrite(LED_BUILTIN,led_state);
    led_state = led_state ^ 0x01;
    last_loop_time = current_time;
  }

  
}
