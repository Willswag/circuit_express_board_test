#include <stdint.h>
#include <Arduino.h>

#define START_FREQ 20
#define FREQ_STEPS 80
#define FREQ_RAMP_RATE 25
#define FREQ_UPDATE_RATE 5

void chirpTones(unsigned long current_time);
