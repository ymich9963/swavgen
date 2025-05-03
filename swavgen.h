/*
    swavgen : Simple Swavgen Generator.
    Copyright (C) 2024 Yiannis Michael (ymich9963)

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define	WELCOME_STR "swavgen : Simple Swavgen Generator\nBy Yiannis Michael (ymich9963).\n\nTo generate your first sound file, you must specify the frequency with '-f' or '--frequency'. This generates a 1 channel, 2 second, 440 Hz sine wave with IEEE-float 64-bit encoding at 48 kHz. Use the '--help' option for a list of all the settings.\n\n" "This program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\n"
#define	VERSION_STR "swavgen : Simple Swavgen Generator, Version 1.1.0 \n By Yiannis Michael (ymich9963).\n\n"

/* Standard format codes */
#define	WAVE_FORMAT_PCM 0x0001          // PCM
#define	WAVE_FORMAT_IEEE_FLOAT 0x0003   // IEEE float
#define	WAVE_FORMAT_ALAW 0x0006         // 8-bit ITU-T G.711 A-law
#define	WAVE_FORMAT_MULAW 0x0007        // 8-bit ITU-T G.711 µ-law
#define	WAVE_FORMAT_EXTENSIBLE 0xFFFE   // Determined by SubFormat

#define	MAX_TYPE_STRING 9 
#define	MAX_REPR_STRING 9 
#define	MAX_ENC_STRING  11 
#define	MAX_MASK_STRING 50 
#define	MAX_NOTE_STRING 4
#define	MAX_FREQ_STRING 10
#define	MAX_SAMP_STRING 6
#define	MAX_BYTE_STRING 2
#define	MAX_DURA_STRING 6
#define	MAX_CHAN_STRING 3
#define MIN_STRING      MAX_TYPE_STRING + MAX_REPR_STRING + MAX_ENC_STRING + MAX_MASK_STRING + MAX_NOTE_STRING + MAX_FREQ_STRING + MAX_SAMP_STRING + MAX_BYTE_STRING + MAX_DURA_STRING + MAX_CHAN_STRING
#define	MAX_STRING      MIN_STRING + 100

#define	IVAL_MAX 999999
#define	IVAL_MIN 0
#define	LVAL_MAX 4294967295
#define	LVAL_MIN 0
#define	FVAL_MAX 9999999.9f
#define	FVAL_MIN 0.00001f
#define	UCHAR_VAL_MAX 255
#define	UCHAR_VAL_MIN 0
#define	S32BIT_MAX (int32_t) 0x7FFFFFFF       //  2147483647 or 0b011111111111111111111111
#define	S32BIT_MIN (int32_t) 0x80000000       // -2147483648 or 0b100000000000000000000000
#define	S24BIT_MAX 0x7FFFFF               //  8388607 or 0b011111111111
#define	S24BIT_MIN 0x800000               // -8388608 or 0b100000000000
#define	S16BIT_MAX (int16_t) 0x7FFF         //  32767 or 0b0111111111111111
#define	S16BIT_MIN (int16_t) 0x8000         // -32768 or 0b1000000000000000
#define	S8BIT_MAX (int8_t)  0x7F            //  127 or 0b01111111
#define	S8BIT_MIN (int8_t)  0x80            // -128 or 0b10000000
#define	U32BIT_MAX (uint64_t) 0xFFFFFFFF       //  4294967295 or 0b111111111111111111111111, issue with overflow so needed to use 64 bit integers.
#define	U32BIT_MIN (uint32_t) 0x00000000       //           0 or 0b1000000000000000000000000
#define	U24BIT_MAX 0xFFFFFF               //  8388607 or 0b011111111111
#define	U24BIT_MIN 0x000000               // -8388608 or 0b100000000000
#define	U16BIT_MAX (uint16_t) 0xFFFF         //  65535 or 0b1111111111111111
#define	U16BIT_MIN (uint16_t) 0x0000         //      0 or 0b0000000000000000
#define	U8BIT_MAX (uint8_t)  0xFF            //  255 or 0b11111111
#define	U8BIT_MIN (uint8_t)  0x00            //    0 or 0b00000000
#define	A   87.6
#define	MU  255

/* Channel Masks */
#define	SPEAKER_FRONT_LEFT              0x1
#define	SPEAKER_FRONT_RIGHT             0x2
#define	SPEAKER_FRONT_CENTER            0x4
#define	SPEAKER_LOW_FREQUENCY           0x8
#define	SPEAKER_BACK_LEFT               0x10
#define	SPEAKER_BACK_RIGHT              0x20
#define	SPEAKER_FRONT_LEFT_OF_CENTER    0x40
#define	SPEAKER_FRONT_RIGHT_OF_CENTER   0x80
#define	SPEAKER_BACK_CENTER             0x100
#define	SPEAKER_SIDE_LEFT               0x200
#define	SPEAKER_SIDE_RIGHT              0x400
#define	SPEAKER_TOP_CENTER              0x800
#define	SPEAKER_TOP_FRONT_LEFT          0x1000
#define	SPEAKER_TOP_FRONT_CENTER        0x2000
#define	SPEAKER_TOP_FRONT_RIGHT         0x4000
#define	SPEAKER_TOP_BACK_LEFT           0x8000
#define	SPEAKER_TOP_BACK_CENTER         0x10000
#define	SPEAKER_TOP_BACK_RIGHT          0x20000
#define	SPEAKER_RESERVED                0x80000000

/* Notes */
#define C0 	    16.351f
#define Cs_Db0 	17.324f
#define D0 	    18.354f
#define Ds_Eb0 	19.445f
#define E0 	    20.601f
#define F0 	    21.827f
#define Fs_Gb0 	23.124f
#define G0 	    24.499f
#define Gs_Ab0 	25.956f
#define A0 	    27.5f
#define As_Bb0 	29.135f
#define B0 	    30.868f

#define C1 	    32.703f
#define Cs_Db1 	34.648f
#define D1 	    36.708f
#define Ds_Eb1 	38.891f
#define E1 	    41.203f
#define F1 	    43.654f
#define Fs_Gb1 	46.249f
#define G1 	    48.999f
#define Gs_Ab1 	51.913f
#define A1 	    55.0f
#define As_Bb1 	58.27f
#define B1 	    61.735f

#define C2 	    65.406f
#define Cs_Db2 	69.296f
#define D2 	    73.416f
#define Ds_Eb2 	77.782f
#define E2 	    82.407f
#define F2 	    87.307f
#define Fs_Gb2 	92.499f
#define G2 	    97.999f
#define Gs_Ab2 	103.826f
#define A2 	    110.0f
#define As_Bb2 	116.541 	
#define B2 	    123.471 	

#define C3 	    130.813f
#define Cs_Db3 	138.591f
#define D3 	    146.832f
#define Ds_Eb3 	155.563f
#define E3 	    164.814f
#define F3 	    174.614f
#define Fs_Gb3 	184.997f
#define G3 	    195.998f
#define Gs_Ab3 	207.652f
#define A3 	    220.0f
#define As_Bb3 	233.082f
#define B3 	    246.942f

#define C4 	    261.626f
#define Cs_Db4 	277.183f
#define D4 	    293.665f
#define Ds_Eb4 	311.127f
#define E4 	    329.628f
#define F4 	    349.228f
#define Fs_Gb4 	369.994f
#define G4 	    391.995f
#define Gs_Ab4 	415.305f
#define A4 	    440.0f
#define As_Bb4 	466.164f
#define B4 	    493.883f

#define C5 	    523.251f
#define Cs_Db5 	554.365f
#define D5 	    587.33f
#define Ds_Eb5 	622.254f
#define E5 	    659.255f
#define F5 	    698.456f
#define Fs_Gb5 	739.989f
#define G5 	    783.991f
#define Gs_Ab5 	830.609f
#define A5 	    880.0f
#define As_Bb5 	932.328f
#define B5 	    987.767f

#define C6 	    1046.502f
#define Cs_Db6 	1108.731f
#define D6 	    1174.659f
#define Ds_Eb6 	1244.508f
#define E6 	    1318.51f
#define F6 	    1396.913f
#define Fs_Gb6 	1479.978f
#define G6 	    1567.982f
#define Gs_Ab6 	1661.219f
#define A6 	    1760.0f
#define As_Bb6 	1864.655f
#define B6 	    1975.533f

#define C7 	    2093.005f
#define Cs_Db7 	2217.461f
#define D7 	    2349.318f
#define Ds_Eb7 	2489.016f
#define E7 	    2637.021f
#define F7 	    2793.826f
#define Fs_Gb7 	2959.955f
#define G7 	    3135.964f
#define Gs_Ab7 	3322.438f
#define A7 	    3520.0f
#define As_Bb7 	3729.31f
#define B7 	    3951.066f

#define C8 	    4186.009f
#define Cs_Db8 	4434.922f
#define D8 	    4698.636f
#define Ds_Eb8 	4978.032f
#define E8 	    5274.042f
#define F8 	    5587.652f
#define Fs_Gb8 	5919.91f
#define G8 	    6271.928f
#define Gs_Ab8 	6644.876f
#define A8 	    7040.0f
#define As_Bb8 	7458.62f
#define B8 	    7902.132f

#define C9 	    8372.018f
#define Cs_Db9 	8869.844f
#define D9 	    9397.272f
#define Ds_Eb9 	9956.064f
#define E9 	    10548.084f
#define F9 	    11175.304f
#define Fs_Gb9 	11839.82f
#define G9 	    12543.856f
#define Gs_Ab9 	13289.752f
#define A9 	    14080.0f 	
#define As_Bb9 	14917.24f
#define B9 	    15804.26f

/* Check macros */
/* Check response from sscanf */
#define	CHECK_RES(x) ({ if (!(x)) { \
							fprintf(stderr, "Argument entered was wrong...\n"); \
							return 1; \
						} \
					  })

/* Check if value is between numerical limits */
#define	CHECK_LIMITS_LONG(x) ({ if ((x) >= LVAL_MAX || (x) <= LVAL_MIN) { \
									fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %lld.\n", LVAL_MIN, LVAL_MAX); \
									return 1; \
								} \
							  })

#define	CHECK_LIMITS_FLOAT(x) ({ if ((x) >= FVAL_MAX || (x) <= FVAL_MIN) { \
									 fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %f and %f.\n", FVAL_MIN, FVAL_MAX); \
									 return 1; \
								 } \
							   })

#define	CHECK_LIMITS_UCHAR(x) ({ if ((x) >= UCHAR_VAL_MAX || (x) <= UCHAR_VAL_MIN) { \
									 fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", UCHAR_VAL_MIN, UCHAR_VAL_MAX); \
									 return 1; \
								 } \
							   })

#define	CHECK_LIMITS_INT(x) ({ if ((x) > IVAL_MAX || (x) < IVAL_MIN) { \
								   fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", IVAL_MIN, IVAL_MAX); \
								   return 1; \
							   } \
							 })

#define	CHECK_LIMITS_CONV(x) ({ if ((x) > 1 || (x) < -1) { \
									fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", 1, -1); \
									return 1; \
								} \
							  })

/* Check if an error occured to exit program */
#define	CHECK_ERR(x) ({ if ((x)) { \
							exit(EXIT_FAILURE); \
						} \
					  })

/* Check if a function returns failure */
#define	CHECK_RET(x) ({ if ((x)) { \
							return 1; \
						} \
					  })

/* Check if write was succesful by comparing the expected and actual writes */
#define	CHECK_WRITE(x, y) ({ if ((x != y)) { \
								 return 1; \
							 } \
						   })

/* data Chunk */
// FIX: Fit sampled_data into the struct.
typedef struct Data_Chunk {
	char chunkID[4];                        // "data"
	uint32_t chunk_size;
} data_chunk_t;

/* fact Chunk */
typedef struct Fact_Chunk {
	char chunkID[4];                        // "fact"
	uint32_t chunk_size;
	uint32_t dwSampleLength;
} fact_chunk_t;

/* Full format chunk */
typedef struct Format_Chunk {
	char chunkID[4];                        // "fmt "
	uint32_t chunk_size;
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	uint16_t cbSize;
	uint16_t wValidBitsPerSample;
	uint32_t dwChannelMask;
	uint8_t SubFormat[16];
} fmt_chunk_t;

/* Main RIFF chunk */
typedef struct RIFF_Chunk {
	char chunkID[4];                        // "RIFF"
	uint32_t chunk_size;                    // Number of chunks containing sample and format information
	char waveID[4];                         // "WAVE"
} riff_chunk_t;

typedef struct Swavgen_config swavgen_config_t;

typedef struct Swavgen_config {
    /* Swavgen properties */
    float a;                                // amplitude
    double f;                               // tone frequency
    uint32_t f_s;                           // sampling frequency
	float duration;                         // wave duration
	float T;                                // period, in ms
    uint8_t channels;
    size_t total_number_of_samples;

    /* Output file */
    char file_name[MAX_STRING];
    uint64_t size;

    /* Used in WAVE headers */
	uint8_t bytes_per_sample;
    uint16_t encoding;
    uint16_t valid_bits;
    uint32_t channel_mask;

    /* Strings used internally */
	char typestr[MAX_TYPE_STRING];
	char representationstr[MAX_REPR_STRING];
	char encodingstr[MAX_ENC_STRING];
	char channel_mask_str[MAX_MASK_STRING];
	char music_note[MAX_NOTE_STRING];
	char custom_string[MAX_STRING];

    /* Number of waves used for approximation */ 
    uint8_t approx;

    /* Flags */
    char representation;
    char type;
    uint8_t padding;
    uint8_t extensible;
	uint8_t raw;
	uint8_t limit;

    /* Function members */
	void (*defv)(swavgen_config_t*);                 // Set default values
	void (*seth)(swavgen_config_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Set header values
	void (*wave)(double**, swavgen_config_t*);       // Swavgen generation function
	int (*encd)(double*, void**, swavgen_config_t*); // Encoding function
	int (*fgen)(swavgen_config_t*);                  // File name generator 
	int (*outp)(FILE*, void*, swavgen_config_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Output function
} swavgen_config_t;

/**
 * @brief Set the default values for default behaviour.
 *
 * @param swavgen_config wave properties struct.
 */
void set_defaults(swavgen_config_t* swavgen_config);

/**
 * @brief Get the options from the terminal.
 *
 * @param argc Argument count.
 * @param argv Argument vector
 * @param swavgen_config Swavgen properties struct
 * @return
 */
int get_options(int argc, char** argv, swavgen_config_t* swavgen_config);

/**
 * @brief Get the wave type based on the inputs.
 *
 * @param str Swavgen type string.
 * @param typestr String of the specific wave type.
 * @param type Char that represents the wave type.
 * @return Success or failure.
 */
int get_wave_type(char* str, char* typestr, char* type);

/**
 * @brief Get the encoding type depending on the input.
 *
 * @param str Swavgen type string.
 * @param encodingstr String of the specific wave data encoding.
 * @param encoding Char that represents the wave data encoding.
 * @return Success or failure.
 */
int get_encoding(char* str, char* encodingstr, uint16_t* encoding);

/**
 * @brief Use signed or unsigned representation based on inputs.
 *
 * @param str Representation string, only values allowed are 'signed' or 'unsigned'.
 * @param representationstr String of representation type.
 * @param representation Pointer to representation swavgen_config_t struct member.
 * @return Success or failure.
 */
int get_represenation(char* str, char* representationstr, char* representation);

/**
 * @brief Get the channel mask values from the input string.
 *
 * @param strval Input string with channel mask codes.
 * @param channel_mask Pointer to channel mask swavgen_config_t struct member.
 * @return Success or failure.
 */
int get_channel_mask(char* strval, uint32_t* channel_mask);

/**
 * @brief Get the music note frequency and assign it.
 *
 * @param music_note String containing the music note.
 * @param f Frequency of wave.
 * @return Success or failure.
 */
int get_music_note_frequency(char music_note[4], double* f);

/**
 * @brief Set the wave type and the encoding type.
 *
 * @param swavgen_config Swavgen properties struct.
 * @return Success or failure.
 */
int set_type_encoding(swavgen_config_t* swavgen_config);

/**
 * @brief Set the wave type and the encoding type.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param str String used in argument.
 * @return Success or failure.
 */
int set_file_name_generator(swavgen_config_t* swavgen_config, char* str);

/**
 * @brief Get the phase angle from the inputted theta value.
 *
 * @param swavgen_config Swavgen properties struct.
 */
void get_phase(swavgen_config_t* swavgen_config);

/**
 * @brief Create a sine wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_sine(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create a square wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_square(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create an approximated square wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_square_approx(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create a triangle wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_triangle(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create aapproximated triangle wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_triangle_approx(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create a saw wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_saw(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create an approximated saw wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_saw_approx(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Create a random wave with values between -1 and +1, using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void create_random(double** samples, swavgen_config_t* swavgen_config);

/**
 * @brief Check if the user selected limitting on the wave samples. This will limit all samples to have values between -1 and +1.
 *
 * @param samples Samples array.
 * @param swavgen_config Swavgen properties struct.
 */
void check_limit(double* samples, swavgen_config_t* swavgen_config);

/**
 * @brief Sgn function to retrieve the sign of the value.
 *
 * @param x Input of type double.
 * @return Either +1 or -1 depending on the sign of the value.
 */
char sgn(double x);

/**
 * @brief Write the sampled encoded data to file.
 *
 * @param file FILE pointer.
 * @param sampled_data Sampled data array.
 * @param swavgen_config Swavgen properties struct.
 * @return Success or failure.
 */
int fwrite_data(FILE* file, void* sampled_data, swavgen_config_t* swavgen_config);

/**
 * @brief Convert a type double value to 8-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed PCM value.
 */
int8_t convert_double_to_pcm_8bit_signed(double sample);

/**
 * @brief Convert a type double value to 16-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 16-bit signed PCM value.
 */
int16_t convert_double_to_pcm_16bit_signed(double sample);

/**
 * @brief Convert a type double value to 24-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 24-bit signed PCM value.
 */
int32_t convert_double_to_pcm_24bit_signed(double sample);

/**
 * @brief Convert a type double value to 32-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit signed PCM value.
 */
int32_t convert_double_to_pcm_32bit_signed(double sample);

/**
 * @brief Convert a type double value to 8-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed PCM value.
 */
uint8_t convert_double_to_pcm_8bit_unsigned(double sample);

/**
 * @brief Convert a type double value to 16-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 16-bit signed PCM value.
 */
uint16_t convert_double_to_pcm_16bit_unsigned(double sample);

/**
 * @brief Convert a type double value to 24-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit value containing the 24-bit signed PCM value.
 */
uint32_t convert_double_to_pcm_24bit_unsigned(double sample);

/**
 * @brief Convert a type double value to 32-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit signed PCM value.
 */
uint32_t convert_double_to_pcm_32bit_unsigned(double sample);

/**
 * @brief Set the WAVE header for PCM data.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_pcm(swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Called to decide on which PCM encoding to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
int encode_pcm(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 8-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_signed_8bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 16-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_signed_16bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 24-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_signed_24bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 32-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_signed_32bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 8-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_unsigned_8bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 16-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_unsigned_16bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 24-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_unsigned_24bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with PCM 32-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_pcm_unsigned_32bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Set the WAVE header for IEEE float data.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_ieee_float(swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Called to decide on which IEEE float encoding to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
int encode_ieee_float(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with IEEE float 32-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_ieee_float_32bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Encode all the samples in the samples array with IEEE float 64-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_ieee_float_64bit(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Set the WAVE header for A-law 8-bit data.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_a_law(swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Called to decide on which compansion encoding (A/Mu-law) to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
int encode_companding(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Convert a 16-bit signed PCM value to an 8-bit A-law value.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed A-law value.
 */
int8_t convert_pcm_16bit_signed_to_a_law(int16_t x);

/**
 * @brief Encode all the samples in the samples array with A-law 8-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_a_law(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Set the WAVE header for Mu-law 8-bit data.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_mu_law(swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Convert a 16-bit signed PCM value to an 8-bit Mu-law value.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed Mu-law value.
 */
int8_t convert_pcm_16bit_signed_to_mu_law(int16_t x);

/**
 * @brief Encode all the samples in the samples array with Mu-law 8-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param swavgen_config  Swavgen properties struct.
 */
void encode_mu_law(double* samples, void** encoded_samples, swavgen_config_t* swavgen_config);

/**
 * @brief Set the WAVE header for the extensible format. A header can be of extensible format and another subformat.
 *
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_extensible(swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Output the PCM encoded data and the corresponding chunks. Used only for PCM data.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_pcm(FILE* file, void* sampled_data, swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Output the encoded data and the corresponding chunks, when it is in any non-PCM format.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_non_pcm(FILE* file, void* sampled_data, swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Output the encoded data and the corresponding chunks when the extensible format is selected. Can be used for any format.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_extensible(FILE* file, void* sampled_data, swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Output the encoded data only. No header information is written.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param swavgen_config Swavgen properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_raw(FILE* file, void* sampled_data, swavgen_config_t* swavgen_config, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Output the details of the written file to the screen.
 *
 * @param swavgen_config Swavgen properties struct.
 * @return Success or failure.
 */
int output_file_details(swavgen_config_t* swavgen_config);

/**
 * @brief Get the current date in a string format.
 *
 * @return Return a string of the date in dmy format.
 */
char* get_date_string();

/**
 * @brief Get the current time.
 *
 * @return Return a string of the current time in HMS format.
 */
char* get_time_string();

/**
 * @brief Generate the date and time string format preset.
 *
 * @param swavgen_config Swavgen config struct.
 * @return Success or failure.
 */
int generate_file_name_datetime_format(swavgen_config_t* swavgen);

/**
 * @brief Generate the properties string format preset.
 *
 * @param swavgen_config Swavgen config struct.
 * @return Success or failure.
 */
int generate_file_name_properties_format(swavgen_config_t* swavgen_config);

/**
 * @brief Generate a file name using a custom format.
 *
 * @param swavgen_config Swavgen config struct.
 * @return Success or failure.
 */
int generate_file_name_custom_format(swavgen_config_t* swavgen_config);

/**
 * @brief Used to set the function pointer when setting a specific file name.
 *
 * @param swavgen_config Swavgen config struct.
 * @return Success or failure.
 */
int generate_file_name_ignore(swavgen_config_t* swavgen_config);

/**
 * @brief Output the help text.
 *
 * @return Success or failure.
 */
int output_help();
