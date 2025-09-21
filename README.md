# swavgen : Simple Wave Generator
![badge](https://badgen.net/badge/Coverage/100/blue) 
<a href="https://scan.coverity.com/projects/ymich9963-swavgen">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/31179/badge.svg"/>
</a>

A simple tool to generate different wave types using different encodings and saving them in WAVE (.wav) format with no external dependencies! Uses a variety of features of the WAVE audio file format. The ideal end of the project is to implement most of the WAVE formats listed in the [IANA WAVE and AVI Codec Registries](https://www.iana.org/assignments/wave-avi-codec-registry/wave-avi-codec-registry.xhtml). It implements a small bunch of basic DSP concepts such as sampling, encoding, and wave generation.

## Features
- Sine, Square, Triangle, Saw, and Random wave outputs.
    - Digitally created versions and approximated versions using additive synthesis.
    - Random wave type uses a pseudo-random data generation method.
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
Currently an automatic installation exists only for Windows, and binaries are built only for Windows. For other Operating Systems you need to build from source.

### Windows
To install automatically, use the install script located in `install/` by executing the command below in a PowerShell terminal with Admin rights,

```
irm "https://raw.githubusercontent.com/ymich9963/swavgen/refs/heads/main/install/swavgen-windows-install.ps1" | iex
```

The script downloads the executable, moves it to `C:\Program Files\swavgen\`, and adds that path to the system environment variable. If you do not want the automated script feel free to download the executable or build from source. In case your organisation doesn't allow you to install from the script due to protected paths, download the script and change the `$Swavgen_install_path` variable to a location that suits you.

### macOS & Linux
Please the Building section. Use `make` to build from source.

## Usage
The `--help` option which provides a list of the available commands is listed below, followed by example uses.

```
General usage,
'swavgen <Wave Type> [<Options>]', with an ability to choose between 'sine', 'square', 'triangle', 'saw' wave types. Use 'random' for some random white noise.

Available options are,
        -e,     --encoding <Encoding>                   = Encoding used for sampled data. Available encodings are 'IEEE-float' (64/32-bit), 'PCM' (signed/unsigned 8/16/24/32-bit), 'A-law', and 'Mu-law'.
        -f,     --frequency <Frequency [Hz]>            = Input the wave frequency in Hertz.
        -T,     --period <Time [ms]>                    = Input the wave period in milliseconds.
        -s,     --sampling-frequency <Frequency [Hz]>   = Wave sampling frequency in Hertz.
        -d,     --duration <Time [s]>                   = Wave duration in seconds.
        -n,     --total-samples <Samples>               = Wave total samples. Gets calculated in the tool with sampling frequency, duaration, and channels. Specifying any of those three options and also specifying the total samples ca
n lead to issues.
        -a,     --amplitude <Amplitude>                 = Wave amplitude. Affects the amplitude of the generated wave before encoding, therefore it can have some strange effects in the encodings that expect values of -1 to +1.
        -l,     --sample-length <Length [bits]>         = Encoded wave sample length in bits. Must be divisible by 8.
        -r,     --representation <Representation>       = Choose between 'signed' and 'unsigned' PCM encoding.
        -c,     --channels <Channels>                   = Choose the number of channels to be created.
        -o,     --output <File Name>                    = Specify the output file name.
        -x,     --extensible                            = Enable the extensible format type for WAV. Mandatory when specifying a channel mask or valid bits but otherwise only necessary for some media players.
        -q,     --quiet                                 = Silence output. Errors are still shown.
        -v,     --valid-bits <Valid Bits [bits]>        = Valid bits in the sample. Doesn't seem to do anything and is purely informational. Must be less than the sample length.
        -m,     --channel-mask <Channel Mask Code>      = Specify the channel mask to be used for panning. The number of speaker locations specified should be the same as the number of channels. For example with '-c 2' an option of '-
m FR,FL' should be used. All channel mask options are listed below, and should be separated with a comma, dash, or dot.
                --raw                                   = Output the data with no header information. Useful for only getting the data of the generated wave.
                --limit                                 = Enable limiting so that the generated wave is limited from -1 to +1 prior to encoding.
        -b,     --approx <Number of Waves>              = Specify the using an amount of approximated waves using additive synthesis instead of pure digitally created waves.
                --output-name-format <Format>           = Specify the format of the output file name. Choose between 'date/time', 'properties', and 'custom'. Defaults to 'properties'. To use the 'custom' output format, specify with '--output-na
me-format custom:<SPECIFIERS>'. Separete any of the following specifiers with '-' to create a custom naming format, 'swavgen', 'output', 'type', 'frequency', 'sampling', 'representation', 'encoding', 'length', 'duration', 'channels', 
'note', 'mask', 'date', and 'time'.


                        CHANNEL MASK CODES

                Front Left              FL
                Front Right             FR
                Front Centre            FC
                Low Frequency           LF
                Back Left               BL
                Back Right              BR
                Front Left Of Centre    FLOC
                Front Right Of Centre   FROC
                Back Centre             BC
                Side Left               SL
                Side Right              SR
                Top Center              TC
                Top Front Left          TFL
                Top Front Center        TFC
                Top Front Right         TFR
                Top Back Left           TBL
                Top Back Center         TBC
                Top Back Right          TBR
                Speaker Reserved        SPR


Notes: Experimentally it was found that combinations from FL to SR work with headphones, therefore a max of 11 channels can be used with a channel mask. Also, channel mask does not affect the number of channels, but if using a channel
 mask of TC and above, the channels covered by the TC< channel masks will not be played, even though the data is there. Swavgen has not been used on other speaker systems so it is unknown if this changes depending on what the generate
d wave is played.



                        CONVERSION HELPERS

                --convert-double-to-PCM-8bit-signed <Value>
                --convert-double-to-PCM-16bit-signed <Value>
                --convert-double-to-PCM-24bit-signed <Value>
                --convert-double-to-PCM-32bit-signed <Value>
                --convert-double-to-PCM-8bit-unsigned <Value>
                --convert-double-to-PCM-16bit-unsigned <Value>
                --convert-double-to-PCM-24bit-unsigned <Value>
                --convert-double-to-PCM-32bit-unsigned <Value>

Note: <Value> must be between +1 and -1.

                --convert-PCM-16bit-signed-to-A-law <Value>
                --convert-PCM-16bit-signed-to-Mu-law <Value>

Note: <Value> must be between 32767 and -32768.

```

### Example Uses
Most basic usage of the tool would be to create a sine wave in a specific frequency, let's say 400 Hz,
```
swavgen sine -f 440
```
Default duration is 2 seconds, so let's change it to 5 seconds,
```
swavgen sine -f 440 -d 5
```
To reduce the file size you may want to change the encoding to signed 16-bit PCM.
```
swavgen sine -f 440 -d 5 -e PCM -r signed -l 16
```
Use `--raw` to output the generated data with no WAVE header data. This will not be playable by most audio players.
```
swavgen sine -f 440 -d 5 -e PCM -r signed -l 16 --raw
```
Let's change the command to output a triangle wave, approximated with 4 sine waves instead of digitally synthesised.
```
swavgen triangle -f 440 -d 5 -e PCM -r signed -l 16 --approx 4
```
Instead of specifying the frequency, you can use note names with `--note` instead. For example, 440Hz is A4,
```
swavgen triangle --note A4 -d 5 -e PCM -r signed -l 16 --approx 4
```
You must've noticed the long names by now, you can change the name by specifying `-o`,
```
swavgen triangle -f 440 -d 5 -e PCM -r signed -l 16 --approx 4 -o example.wav
```
Choose to use the formatting presets 'data/time' or 'properties' which is the default,
```
swavgen triangle -f 440 -d 5 -e PCM -r signed -l 16 --approx 4 --output-name-format date/time
```
Use a custom naming scheme with the options specified in `--help`,
```
swavgen triangle -f 440 -d 5 -e PCM -r signed -l 16 --approx 4 --output-name-format custom:frequency-date
```
Specify panning by using channel masks by using `-x` and `-m`,
```
swavgen sine -f 440 -x -m FR
```

Can use the conversion functions to convert between values in different encodings,
```
swavgen --convert-double-to-PCM-8bit-signed 0.1
```

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

## Motivation 
I couldn't find anything similar that could just be a sine wave generator from the command line. After I accomplished that I realised I could make it generate other wave types as well. Then, due to using the WAVE format, it made sense to try and make use of it as much as possible by using different encodings and formats. Overral, I believe it's an interesting implementation of a variety of DSP concepts, and I hope someone can find this as interesting and/or useful as I did!

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
- [UNSW](https://newt.phys.unsw.edu.au/jw/notes.html).
- [Lutherie Information](https://www.liutaiomottola.com/formulae/freqtab.htm).
