#include "chirp_tones.h"

void chirpTones(unsigned long current_time){
  static unsigned long last_loop_time = 0;
  static uint16_t count = 0;
  const uint16_t steps = FREQ_STEPS;
  if ((current_time - last_loop_time) < FREQ_UPDATE_RATE)
  {
    return;
  }
  last_loop_time = current_time;
  count++;
  if (count > steps)
  {
    count = 0;
  }
  tone(A0, count * FREQ_RAMP_RATE+START_FREQ);
}