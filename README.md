# swavgen : Simple Wave Generator
A simple tool to generate different wave types using different encodings and saving them in WAVE (.wav) format with no external dependencies! Uses a variety of features of the WAVE audio file format. The ideal end of the project is to implement most of the WAVE formats listed in the [IANA WAVE and AVI Codec Registries](https://www.iana.org/assignments/wave-avi-codec-registry/wave-avi-codec-registry.xhtml). It implements a small bunch of basic DSP concepts such as sampling, encoding, and wave generation.

## Features
- Sine, Square, Triangle, Saw wave outputs.
    - Digitally created versions and approximated versions using additive synthesis.
- Supported encodings,
    - IEEE float 32/64-bit.
    - PCM signed/unsigned 8/16/24/32-bit.
    - A/Mu-law (See note below). 
    - Hopefully more added soon!
- Raw output for outputting only encoded data to file with no header information.
- Conversion functionalities,
    - Convert any decimal value from +1 to -1 to any available PCM encoding.
    - Convert any 16-bit signed PCM value to A/Mu-law encoding.
- Change the provided wave types by varying the amplitude or by using limiting (e.g. Generate a square wave from a triangle wave).
- Panning using channel masks provided by the WAVE format.

A-law and Mu-law implementations were adapted from, and tested with, the [ITU-T Software Tools Library (STL)](https://github.com/openitu/STL) in [Recommendation ITU-T G.191 "Software tools for speech and audio coding standardization"](http://itu.int/ITU-T/G.191).

## Why
Reasons for writing this program were many. Firstly, I couldn't find anything similar that could just be a sine wave generator from the command line. After I accomplished that I realised I could make it generate other wave types as well. Then, due to using the WAVE format, it made sense to try and make use of it as much as possible by using different encodings and formats. Overral, I believe it's an interesting implementation of a variety of DSP concepts, and I hope someone can find this as interesting and/or useful as I did!
