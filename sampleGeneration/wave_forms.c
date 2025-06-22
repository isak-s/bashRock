#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "config.h"

double pulse_wave(double time, double freq, double duty) {
    double phase = round(SAMPLE_RATE * time) / round(SAMPLE_RATE / freq);
    return fmod(phase, 1.0) < duty ? 1.0 : -1.0;
}

double square_wave(double time, double freq){
    return pulse_wave(time, freq, 0.5);
}

double sine_wave(double time, double freq){
    return sin(freq * 2.0 * M_PI * time);
}

double sawtooth_wave(double time, double freq) {
    return 2 * (freq * time - floor(freq * time + 0.5));
}

double triangle_wave(double time, double freq) {
    return fabs(4.0 * fmod(freq * time + 0.75, 1.0) - 2.0) - 1.0;
}

double noise() {
  return 2.0 * rand() / RAND_MAX - 1.0;
}
