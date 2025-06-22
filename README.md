Useless but slightly interesting stuff below:

aplay is a part of ALSA, which is included in most distros including debian, ubuntu, fedora arch etc.. It's designed to play raw audio files such as .wav. aplay simply parses any data / text passed into it as if it were binary encodings of sound, and attempts to play it. For a clean tone, the data being passed in would be points on a sine wave. , but what if we feed it nonesense?

The command aplay /dev/urandom plays white noise indefinately. this is because urandom is a stream of randomness, meaning that we on average play all frequencies at the same time, giving rise to white noise.

aplay comes with some interesting flags to adjust bitrate and bit depth. With these we can modulate our white noise to sound like a percusison instrument.

rock_you.sh is an attempt to recreate Queen's iconic boom boom clap drum-loop from "We will rock you". It sounds pretty scuffed, but it does kind of work.

Instead of sending random gibberish from /dev/random, we can feed aplay some weird gibberish in the form of a text file, or the output from a command.

drums.sh containins the most scuffed drum loop ever, considering that it plays the source code's own unicode as if it were an audio file.

drums.sh is a recreation of this [YouTube video](https://www.youtube.com/watch?v=TwJdcgEClMU), which was the entrance into this rabbit hole for me.

To play some interesting audio:

    find / | aplay

Cheers

I also modulated a bunch of different waveforms that are plotted below.

[sawtooth wave](plots/sawtooth_wave.wav.pdf)

[triangle wave](<plots/triangle_wave.wav full Downsampled waveform.pdf>)

[boing sound effect](<plots/boing.wav full Downsampled waveform.pdf>)

Sources:
https://lacina.io/posts/making-crazy-sounds-with-aplay/

https://samcarcagno.altervista.org/psych/sound_proc/sound_proc_R.html


