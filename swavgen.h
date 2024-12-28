/*
    swavgen : Simple Wave Generator.
    Copyright (C) 2024 Yiannis Michael (ymich9963)

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define WELCOME_STR "swavgen : Simple Wave Generator, Version 1.0.0 \n By Yiannis Michael (ymich9963).\n\nTo generate your first sound file, you must specify the frequency with '-f' or '--frequency'. This generates a 1 channel, 2 second, 500 Hz sine wave with IEEE-float 64-bit encoding at 48 kHz. Use the '--help' option for a list of all the settings.\n\n" "This program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\n"
#define VERSION_STR "swavgen : Simple Wave Generator, Version 1.0.0 \n By Yiannis Michael (ymich9963).\n\n"

/* Standard format codes */
#define WAVE_FORMAT_PCM         0x0001  // PCM
#define WAVE_FORMAT_IEEE_FLOAT  0x0003  // IEEE float
#define WAVE_FORMAT_ALAW        0x0006  // 8-bit ITU-T G.711 A-law
#define WAVE_FORMAT_MULAW       0x0007  // 8-bit ITU-T G.711 µ-law
#define WAVE_FORMAT_DVI_ADPCM   0x0011  // IMA ADPCM
#define WAVE_FORMAT_EXTENSIBLE  0xFFFE  // Determined by SubFormat

#define MAX_FILE_NAME   100
#define IVAL_MAX        999999 
#define IVAL_MIN        0
#define LVAL_MAX        4294967295 
#define LVAL_MIN        0
#define FVAL_MAX        9999999.9f
#define FVAL_MIN        0.00001f
#define UCHAR_VAL_MAX   255     
#define UCHAR_VAL_MIN   0 
#define S32BIT_MAX      (int) 0x7fffffff  //  2147483647 or 0b011111111111111111111111
#define S32BIT_MIN      (int) 0x80000000  // -2147483648 or 0b100000000000000000000000
#define S24BIT_MAX      0x7fffff          //  8388607 or 0b011111111111
#define S24BIT_MIN      0x800000          // -8388608 or 0b100000000000
#define S16BIT_MAX      (short) 0x7fff    //  32767 or 0b0111111111111111
#define S16BIT_MIN      (short) 0x8000    // -32768 or 0b1000000000000000
#define S8BIT_MAX       (char)  0x7f      //  127 or 0b01111111
#define S8BIT_MIN       (char)  0x80      // -128 or 0b10000000
#define U32BIT_MAX      (unsigned int) 0xffffffff  //  4294967295 or 0b111111111111111111111111
#define U32BIT_MIN      (unsigned int) 0x00000000  //           0 or 0b1000000000000000000000000
#define U24BIT_MAX      0xffffff          //  8388607 or 0b011111111111
#define U24BIT_MIN      0x000000          // -8388608 or 0b100000000000
#define U16BIT_MAX      (unsigned short) 0xffff    //  65535 or 0b1111111111111111
#define U16BIT_MIN      (unsigned short) 0x0000    //      0 or 0b0000000000000000
#define U8BIT_MAX       (unsigned char)  0xff      //  255 or 0b11111111
#define U8BIT_MIN       (unsigned char)  0x00      //    0 or 0b00000000
#define A               87.6
#define MU              255

/* Channel Masks */
#define SPEAKER_FRONT_LEFT             0x1
#define SPEAKER_FRONT_RIGHT            0x2
#define SPEAKER_FRONT_CENTER           0x4
#define SPEAKER_LOW_FREQUENCY          0x8
#define SPEAKER_BACK_LEFT              0x10
#define SPEAKER_BACK_RIGHT             0x20
#define SPEAKER_FRONT_LEFT_OF_CENTER   0x40
#define SPEAKER_FRONT_RIGHT_OF_CENTER  0x80
#define SPEAKER_BACK_CENTER            0x100
#define SPEAKER_SIDE_LEFT              0x200
#define SPEAKER_SIDE_RIGHT             0x400
#define SPEAKER_TOP_CENTER             0x800
#define SPEAKER_TOP_FRONT_LEFT         0x1000
#define SPEAKER_TOP_FRONT_CENTER       0x2000
#define SPEAKER_TOP_FRONT_RIGHT        0x4000
#define SPEAKER_TOP_BACK_LEFT          0x8000
#define SPEAKER_TOP_BACK_CENTER        0x10000
#define SPEAKER_TOP_BACK_RIGHT         0x20000
#define SPEAKER_RESERVED               0x80000000

/* Check macros */
/* Check response from sscanf */
#define CHECK_RES(x)        ({ if (!(x)) { \
        fprintf(stderr, "Argument entered was wrong...\n"); \
        return 1; \
        } }) 

/* Check if value is between numerical limits */
#define CHECK_LIMITS_LONG(x)     ({ if ((x) >= LVAL_MAX || (x) <= LVAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %lld.\n", LVAL_MIN, LVAL_MAX); \
        return 1; \
        } }) 

#define CHECK_LIMITS_FLOAT(x)     ({ if ((x) >= FVAL_MAX || (x) <= FVAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %f and %f.\n", FVAL_MIN, FVAL_MAX); \
        return 1; \
        } }) 

#define CHECK_LIMITS_UCHAR(x)     ({ if ((x) >= UCHAR_VAL_MAX || (x) <= UCHAR_VAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", UCHAR_VAL_MIN, UCHAR_VAL_MAX); \
        return 1; \
        } }) 

#define CHECK_LIMITS_INT(x)     ({ if ((x) > IVAL_MAX || (x) < IVAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", IVAL_MIN, IVAL_MAX); \
        return 1; \
        } }) 

/* Check if an error occured to exit program */
#define CHECK_ERR(x)        ({ if ((x)) { \
        exit(EXIT_FAILURE); \
        } }) 

/* Check if a function returns failure */
#define CHECK_RET(x)        ({ if ((x)) { \
        return 1; \
        } }) 

/* Check if write was succesful by comparing the expected and actual writes */
#define CHECK_WRITE(x, y)        ({ if ((x != y)) { \
        return 1; \
        } }) 

/* data Chunk */
// FIX: Fit sampled_data into the struct.
typedef struct Data_Chunk {
    char chunkID[4]; // "data"
    uint32_t chunk_size;
}data_chunk_t;

/* fact Chunk */
typedef struct Fact_Chunk {
    char chunkID[4]; // "fact"
    uint32_t chunk_size;
    uint32_t dwSampleLength;
}fact_chunk_t;

/* Full format chunk */
typedef struct Format_Chunk {
    char chunkID[4]; // "fmt "
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
}fmt_chunk_t;

/* Main RIFF chunk */
typedef struct RIFF_Chunk {
    char chunkID[4]; // "RIFF"
    uint32_t chunk_size;  // Number of chunks containing sample and format information 
    char waveID[4]; // "WAVE"
}riff_chunk_t;

typedef struct Wave_Properties wave_prop_t;

typedef struct Wave_Properties {
    char file_name[MAX_FILE_NAME];
    float duration; // wave duration
    uint32_t f_s; // sampling frequency
    double f; // tone frequency
    float T;        // period, in ms
    uint64_t total_number_of_samples;
    float a; // amplitude
    uint64_t size;
    uint8_t channels;
    uint8_t bytes_per_sample;
    uint8_t representation;
    char type;
    char typestr[10];
    uint16_t encoding;
    char encodingstr[10];
    uint8_t extensible;
    uint8_t padding;
    uint16_t valid_bits;
    uint32_t channel_mask;
    char channel_mask_str[70];
    uint8_t raw;
    uint8_t limit;
    uint8_t approx;
    void (*defv)(wave_prop_t*); // Set default values 
    void (*seth)(wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Set header values 
    void (*wave)(double**, wave_prop_t*); // Wave generation function 
    void (*encd)(double*, void**, wave_prop_t*); // Encoding function
    int (*outp)(FILE*, void*, wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Output function
}wave_prop_t;

void set_defaults(wave_prop_t* wave_prop);
int get_options(int* argc, char** argv, wave_prop_t* wave_prop);
int get_wave_type(char* str, wave_prop_t* wave_prop);
int get_encoding(char* str, wave_prop_t* wave_prop);
int get_represenation(char* str, wave_prop_t* wave_prop);
int get_channel_mask(char* strval, wave_prop_t* wave_prop);
int set_type_encoding(wave_prop_t* wave_prop);
void create_sine(double** samples, wave_prop_t* wave_prop);
void create_sine_approx(double** samples, wave_prop_t* wave_prop);
void create_square(double** samples, wave_prop_t* wave_prop);
void create_square_approx(double** samples, wave_prop_t* wave_prop);
void create_triangle(double** samples, wave_prop_t* wave_prop);
void create_triangle_approx(double** samples, wave_prop_t* wave_prop);
void create_saw(double** samples, wave_prop_t* wave_prop);
void create_saw_approx(double** samples, wave_prop_t* wave_prop);
void create_random(double** samples, wave_prop_t* wave_prop);
void check_limit(double* samples, wave_prop_t* wave_prop);
void smooth_signal(double* samples, wave_prop_t* wave_prop);
char sgn(double* x);
int fwrite_data(FILE * file, void* sampled_data, wave_prop_t* wave_prop);
int8_t convert_double_to_pcm_8bit_signed(double* sample);
int16_t convert_double_to_pcm_16bit_signed(double* sample);
int32_t convert_double_to_pcm_24bit_signed(double* sample);
int32_t convert_double_to_pcm_32bit_signed(double* sample);
uint8_t convert_double_to_pcm_8bit_unsigned(double* sample);
uint16_t convert_double_to_pcm_16bit_unsigned(double* sample);
uint32_t convert_double_to_pcm_24bit_unsigned(double* sample);
uint32_t convert_double_to_pcm_32bit_unsigned(double* sample);
void set_header_pcm(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);
void encode_pcm(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_ieee_float(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);
void encode_ieee_float(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_ieee_float_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_ieee_float_64bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_a_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);
void encode_companding(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
char a_law_compress (short* x);
void encode_a_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_mu_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);
int8_t mu_law_compress(int16_t* x);
void encode_mu_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_extensible(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);
int output_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
int output_non_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
int output_extensible(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
int output_raw(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
int output_file_details(wave_prop_t* wave_prop);
int output_help();

