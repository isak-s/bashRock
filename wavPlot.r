# install.packages('sound', dep=TRUE)
# install.packages('tuneR', dep=TRUE)
library(sound)
library(tuneR)
library(stringr)

args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
    filename <- "output.wav"
} else {
    filename <- args[1]
}

wave_data <- tuneR::readWave(str_interp("sampleGeneration/${filename}"))

# Plot first 300 samples

n <- 300

left_channel <- wave_data@left[1:n]

right_channel <- wave_data@right[1:n]

fs <- wave_data@samp.rate

t <- (0:(n-1)) / fs

plot_rubric <- str_interp("${filename} first 300 samples raw audio data")
pdf(str_interp("plots/${filename}.pdf"))
plot(t, left_channel, type = "l", main = plot_rubric, xlab = "time", ylab = "Amplitude")

# plot full downsampled waveform

step <- 100
left_full <- wave_data@left
left_ds <- left_full[seq(1, length(left_full), by = step)]
t_ds <- (seq(0, length(left_ds)-1) * step) / fs

plot_rubric <- str_interp("${filename} full Downsampled waveform")

plot(t_ds, left_ds, type = "l",
     main = str_interp("${filename} - Downsampled waveform"),
     xlab = "Time (s)", ylab = "Amplitude")