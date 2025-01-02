# swavgen : Simple Wave Generator
![badge](https://badgen.net/badge/Coverage/100/blue) 
<a href="https://scan.coverity.com/projects/ymich9963-swavgen">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/31179/badge.svg"/>
</a>

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
- Generates files up to the max supported WAV format size which is 4.29 GB.

A-law and Mu-law implementations were adapted from, and tested with, the [ITU-T Software Tools Library (STL)](https://github.com/openitu/STL) in [Recommendation ITU-T G.191 "Software tools for speech and audio coding standardization"](http://itu.int/ITU-T/G.191).

## Installing
Use either the pre-built executable or build your own with (See Building section below), and place it in a directory listed in your PATH environmental variable.

## Usage
Use `--help` option for a list of all the different parameters that can be changed. An example command for a 2-second 440 Hz square wave in 16-bit signed PCM encoding would be:

```swavgen square -d 2.0 -f 440 -e PCM -l 16 -r signed```

By setting the tool to specific frequencies, musical notes can be generated. Some useful links are listed below for the correct frequencies or periods to use,
- [UNSW](https://newt.phys.unsw.edu.au/jw/notes.html).
- [Lutherie Information](https://www.liutaiomottola.com/formulae/freqtab.htm).

## Building
Simply use the `make` command to build the executable.

## Tests and Coverage
Running the tests or coverage can be done by running,

```
make test
```
```
make coverage
```
Testing suite used is [Unity](https://github.com/ThrowTheSwitch/Unity) and LLVM-COV for coverage.

## Why
Reasons for writing this program were many. Firstly, I couldn't find anything similar that could just be a sine wave generator from the command line. After I accomplished that I realised I could make it generate other wave types as well. Then, due to using the WAVE format, it made sense to try and make use of it as much as possible by using different encodings and formats. Overral, I believe it's an interesting implementation of a variety of DSP concepts, and I hope someone can find this as interesting and/or useful as I did!

## Resources
Some resources I used to make the project,

- [WAVE File format](https://www.mmsp.ece.mcgill.ca/Documents/AudioFormats/WAVE/WAVE.html)
- [WaveFileGem](https://wavefilegem.com/how_wave_files_work.html)
- [Multiple channel audio data and WAVE files](https://learn.microsoft.com/en-us/previous-versions/windows/hardware/design/dn653308(v=vs.85))
- [Creating a sine wave with PCM](http://www.topherlee.com/software/pcm-tut-sine.html)
- [ITU-T G.191](https://www.itu.int/itu-t/recommendations/rec.aspx?rec=G.191)
- [ITU-T STL](https://github.com/openitu/STL/tree/dev)
- [Companding on embedded systems](https://github.com/deftio/companders)
- [Waveform Coding Techniques](https://www.cisco.com/c/en/us/support/docs/voice/h323/8123-waveform-coding.html)
- [Mu-Law and A-Law Compression Tutorial](https://web.archive.org/web/20110719132013/http://hazelware.luggle.com/tutorials/mulawcompression.html)
- [Basic Waveforms](https://thewolfsound.com/sine-saw-square-triangle-pulse-basic-waveforms-in-synthesis/)
- [Additive Synthesis](https://pytorch.org/audio/stable/tutorials/additive_synthesis_tutorial.html)
- [Sine Wave](https://en.wikipedia.org/wiki/Sine_wave)
- [Square Wave](https://en.wikipedia.org/wiki/Square_wave)
- [Triangle Wave](https://en.wikipedia.org/wiki/Triangle_wave)
- [Saw Wave](https://en.wikipedia.org/wiki/Sawtooth_wave)
