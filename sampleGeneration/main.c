#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

#include "config.h"
#include "wave_forms.h"

typedef struct {
    double left;
    double right;
} Sample;

double clamp(double x, double a, double b) {
    return x < a ? a : (x > b ? b : x);
}

void write_short_le(FILE *fp, uint16_t val) {
    fputc(val & 0xFF, fp);
    fputc((val >> 8) & 0xFF, fp);
}

void write_int_le(FILE *fp, uint32_t val) {
    fputc(val & 0xFF, fp);
    fputc((val >> 8) & 0xFF, fp);
    fputc((val >> 16) & 0xFF, fp);
    fputc((val >> 24) & 0xFF, fp);
}

void write_wav_header(FILE *fp, uint32_t num_samples) {
    uint32_t byte_rate = SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE / 8;
    uint16_t block_align = NUM_CHANNELS * BITS_PER_SAMPLE / 8;
    uint32_t data_chunk_size = num_samples * block_align;
    uint32_t riff_chunk_size = 36 + data_chunk_size;

    // RIFF header
    fwrite("RIFF", 1, 4, fp);
    write_int_le(fp, riff_chunk_size);
    fwrite("WAVE", 1, 4, fp);

    // fmt subchunk
    fwrite("fmt ", 1, 4, fp);
    write_int_le(fp, 16);                    // Subchunk1Size (16 for PCM)
    write_short_le(fp, 1);                   // AudioFormat (1 = PCM)
    write_short_le(fp, NUM_CHANNELS);        // NumChannels
    write_int_le(fp, SAMPLE_RATE);           // SampleRate
    write_int_le(fp, byte_rate);             // ByteRate
    write_short_le(fp, block_align);         // BlockAlign
    write_short_le(fp, BITS_PER_SAMPLE);     // BitsPerSample

    // data subchunk
    fwrite("data", 1, 4, fp);
    write_int_le(fp, data_chunk_size);       // Subchunk2Size
}

Sample sample_at(double time) {
    Sample s;
    s.left = square_wave(time, 440);  // A4
    s.right = 0.0;
    return s;
}

void write_sample(FILE *fp, Sample sample) {
    short l = (short)(SHRT_MAX * clamp(sample.left, -1.0, 1.0));
    short r = (short)(SHRT_MAX * clamp(sample.right, -1.0, 1.0));
    write_short_le(fp, (uint16_t)l);
    write_short_le(fp, (uint16_t)r);
}

int main() {
    const uint32_t num_samples = SAMPLE_RATE * SECONDS;

    FILE *fp = fopen("square_wave.wav", "wb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    write_wav_header(fp, num_samples);

    for (uint32_t i = 0; i < num_samples; ++i) {
        double t = i / (double)SAMPLE_RATE;
        Sample s = sample_at(t);
        write_sample(fp, s);
    }

    fclose(fp);
    printf("WAV file written: square_wave.wav\n");
    return 0;
}
