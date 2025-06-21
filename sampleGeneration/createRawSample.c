#include <stdio.h>
#include <math.h>
#include <limits.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SAMPLE_RATE 44100

typedef struct Sample {
    double left;
    double right;
} Sample;

Sample sample_at(double time) {
    Sample s;
    s.left = sin(420.0 * 2.0 * M_PI * time);
    s.right = 0.0;
    return s;
}

double clamp(double x, double a, double b) {
    if (x < a) return a;
    if (x > b) return b;
    return x;
}

void write_short(unsigned short x, FILE *stream) {
    fputc((char)(x & 0xFF), stream);
    fputc((char)((x >> 8) & 0xFF), stream);
}

void write_channel(double x, FILE *stream) {
    short value = (short)(SHRT_MAX * clamp(x, -1.0, 1.0));
    write_short((unsigned short)value, stream);
}

void write_sample(Sample sample, FILE *stream) {
    write_channel(sample.left, stream);
    write_channel(sample.right, stream);
}

int main() {
    // size_t sample_idx = 0;
    // while (1) {
    //     double time = sample_idx / (double)SAMPLE_RATE;
    //     Sample sample = sample_at(time);
    //     write_sample(sample, stdout);
    //     sample_idx++;
    // }
    // return 0;

    FILE *fp = fopen("output.raw", "wb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    for (int i = 0; i < SAMPLE_RATE * 2; ++i) {  // 2 seconds of sound
        double time = i / (double)SAMPLE_RATE;
        Sample sample = sample_at(time);
        write_sample(sample, fp);
    }

    fclose(fp);
    return 0;
}