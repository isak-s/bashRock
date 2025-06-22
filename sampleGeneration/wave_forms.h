#ifndef WAVE_FORMS_H
#define WAVE_FORMS_H

double sine_wave(double time, double freq);
double pulse_wave(double time, double freq, double duty);
double square_wave(double time, double freq);
double sawtooth_wave(double time, double freq);
double triangle_wave(double time, double freq);
double noise();

#endif