# swavgen: Simple wave.wav File Generator
A simple tool to generate WAVE (.wav) files containing different wave types and encodings with no external dependencies! Uses a variety of features of the WAVE audio file format. The ideal end of the project is to implement most of the WAVE formats listed in the [IANA WAVE and AVI Codec Registries](https://www.iana.org/assignments/wave-avi-codec-registry/wave-avi-codec-registry.xhtml), as well as fully use the WAVE format.

It implements a small bunch of basic DSP concepts such as sampling, encoding, and wave generation.

## Why
Reasons for writing this program were many. Firstly, I couldn't find anything similar that could just be a sine wave generator from the command line. After I accomplished that I realised I could make it generate other wave types as well. Then, due to using the WAVE format, it made sense to try and make use of it as much as possible by using different encodings and formats. Overral, I believe it's an interesting implementation of a variety of DSP concepts, and I hope someone can find this as interesting and/or useful as I did!
