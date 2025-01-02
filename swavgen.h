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
#define S32BIT_MAX      (int32_t) 0x7FFFFFFF  //  2147483647 or 0b011111111111111111111111
#define S32BIT_MIN      (int32_t) 0x80000000  // -2147483648 or 0b100000000000000000000000
#define S24BIT_MAX      0x7FFFFF          //  8388607 or 0b011111111111
#define S24BIT_MIN      0x800000          // -8388608 or 0b100000000000
#define S16BIT_MAX      (int16_t) 0x7FFF    //  32767 or 0b0111111111111111
#define S16BIT_MIN      (int16_t) 0x8000    // -32768 or 0b1000000000000000
#define S8BIT_MAX       (int8_t)  0x7F      //  127 or 0b01111111
#define S8BIT_MIN       (int8_t)  0x80      // -128 or 0b10000000
#define U32BIT_MAX      (uint64_t) 0xFFFFFFFF  //  4294967295 or 0b111111111111111111111111, issue with overflow so needed to use 64 bit integers.
#define U32BIT_MIN      (uint32_t) 0x00000000  //           0 or 0b1000000000000000000000000
#define U24BIT_MAX      0xFFFFFF          //  8388607 or 0b011111111111
#define U24BIT_MIN      0x000000          // -8388608 or 0b100000000000
#define U16BIT_MAX      (uint16_t) 0xFFFF    //  65535 or 0b1111111111111111
#define U16BIT_MIN      (uint16_t) 0x0000    //      0 or 0b0000000000000000
#define U8BIT_MAX       (uint8_t)  0xFF      //  255 or 0b11111111
#define U8BIT_MIN       (uint8_t)  0x00      //    0 or 0b00000000
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

#define CHECK_LIMITS_CONV(x)     ({ if ((x) > 1 || (x) < -1) { \
        fprintf(stderr, "Detected numbers out of range for one of the options. Please check inputs and enter numbers between %d and %d.\n", 1, -1); \
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
    char chunkID[4];                        // "data"
    uint32_t chunk_size;
}data_chunk_t;

/* fact Chunk */
typedef struct Fact_Chunk {
    char chunkID[4];                        // "fact"
    uint32_t chunk_size;
    uint32_t dwSampleLength;
}fact_chunk_t;

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
}fmt_chunk_t;

/* Main RIFF chunk */
typedef struct RIFF_Chunk {
    char chunkID[4];                        // "RIFF"
    uint32_t chunk_size;                    // Number of chunks containing sample and format information 
    char waveID[4];                         // "WAVE"
}riff_chunk_t;

typedef struct Wave_Properties wave_prop_t;

typedef struct Wave_Properties {
    char file_name[MAX_FILE_NAME];
    float duration;                         // wave duration
    uint32_t f_s;                           // sampling frequency
    double f;                               // tone frequency
    float T;                                // period, in ms
    uint64_t total_number_of_samples;
    float a;                                // amplitude
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
    void (*defv)(wave_prop_t*);             // Set default values 
    void (*seth)(wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Set header values 
    void (*wave)(double**, wave_prop_t*);   // Wave generation function 
    int (*encd)(double*, void**, wave_prop_t*); // Encoding function
    int (*outp)(FILE*, void*, wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Output function
}wave_prop_t;

/**
 * @brief Set the default values for default behaviour.
 *
 * @param wave_prop wave properties struct.
 */
void set_defaults(wave_prop_t* wave_prop);

/**
 * @brief Get the options from the terminal.
 *
 * @param argc Argument count.
 * @param argv Argument vector
 * @param wave_prop Wave properties struct
 * @return 
 */
int get_options(int* argc, char** argv, wave_prop_t* wave_prop);

/**
 * @brief Get the wave type based on the inputs.
 *
 * @param str Wave type string.
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int get_wave_type(char* str, wave_prop_t* wave_prop);

/**
 * @brief Get the encoding type depending on the input.
 *
 * @param str Encoding type string.
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int get_encoding(char* str, wave_prop_t* wave_prop);

/**
 * @brief Use signed or unsigned representation based on inputs.
 *
 * @param str Representation string, only values allowed are 'signed' or 'unsigned'.
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int get_represenation(char* str, wave_prop_t* wave_prop);

/**
 * @brief Get the channel mask values from the input string.
 *
 * @param strval Input string with channel mask codes.
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int get_channel_mask(char* strval, wave_prop_t* wave_prop);

/**
 * @brief Set the wave type and the encoding type.
 *
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int set_type_encoding(wave_prop_t* wave_prop);

/**
 * @brief Create a sine wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_sine(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create a square wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_square(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create an approximated square wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_square_approx(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create a triangle wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_triangle(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create aapproximated triangle wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_triangle_approx(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create a saw wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_saw(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create an approximated saw wave using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_saw_approx(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Create a random wave with values between -1 and +1, using the inputted wave properties.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void create_random(double** samples, wave_prop_t* wave_prop);

/**
 * @brief Check if the user selected limitting on the wave samples. This will limit all samples to have values between -1 and +1.
 *
 * @param samples Samples array.
 * @param wave_prop Wave properties struct.
 */
void check_limit(double* samples, wave_prop_t* wave_prop);

/**
 * @brief Sgn function to retrieve the sign of the value.
 *
 * @param x Input of type double.
 * @return Either +1 or -1 depending on the sign of the value.
 */
char sgn(double* x);

/**
 * @brief Write the sampled encoded data to file.
 *
 * @param file FILE pointer.
 * @param sampled_data Sampled data array.
 * @param wave_prop Wave properties struct.
 * @return Success or failure.
 */
int fwrite_data(FILE * file, void* sampled_data, wave_prop_t* wave_prop);

/**
 * @brief Convert a type double value to 8-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed PCM value.
 */
int8_t convert_double_to_pcm_8bit_signed(double* sample);

/**
 * @brief Convert a type double value to 16-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 16-bit signed PCM value.
 */
int16_t convert_double_to_pcm_16bit_signed(double* sample);

/**
 * @brief Convert a type double value to 24-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 24-bit signed PCM value.
 */
int32_t convert_double_to_pcm_24bit_signed(double* sample);

/**
 * @brief Convert a type double value to 32-bit signed PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit signed PCM value.
 */
int32_t convert_double_to_pcm_32bit_signed(double* sample);

/**
 * @brief Convert a type double value to 8-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed PCM value.
 */
uint8_t convert_double_to_pcm_8bit_unsigned(double* sample);

/**
 * @brief Convert a type double value to 16-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 16-bit signed PCM value.
 */
uint16_t convert_double_to_pcm_16bit_unsigned(double* sample);

/**
 * @brief Convert a type double value to 24-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit value containing the 24-bit signed PCM value.
 */
uint32_t convert_double_to_pcm_24bit_unsigned(double* sample);

/**
 * @brief Convert a type double value to 32-bit unsigned PCM.
 *
 * @param sample Pointer to input value.
 * @return 32-bit signed PCM value.
 */
uint32_t convert_double_to_pcm_32bit_unsigned(double* sample);

/**
 * @brief Set the WAVE header for PCM data.
 *
 * @param wave_prop Wave properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_pcm(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Called to decide on which PCM encoding to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
int encode_pcm(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 8-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_signed_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 16-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_signed_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 24-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_signed_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 32-bit signed encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_signed_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 8-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_unsigned_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 16-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_unsigned_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 24-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_unsigned_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with PCM 32-bit unsigned encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_pcm_unsigned_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Set the WAVE header for IEEE float data.
 *
 * @param wave_prop Wave properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_ieee_float(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

/**
 * @brief Called to decide on which IEEE float encoding to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
int encode_ieee_float(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with IEEE float 32-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_ieee_float_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Encode all the samples in the samples array with IEEE float 64-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_ieee_float_64bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Set the WAVE header for A-law 8-bit data.
 *
 * @param wave_prop Wave properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_a_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Called to decide on which compansion encoding (A/Mu-law) to use.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
int encode_companding(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Convert a 16-bit signed PCM value to an 8-bit A-law value.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed A-law value.
 */
int8_t convert_pcm_16bit_signed_to_a_law(int16_t* x);

/**
 * @brief Encode all the samples in the samples array with A-law 8-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_a_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Set the WAVE header for Mu-law 8-bit data.
 *
 * @param wave_prop Wave properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_mu_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Convert a 16-bit signed PCM value to an 8-bit Mu-law value.
 *
 * @param sample Pointer to input value.
 * @return 8-bit signed Mu-law value.
 */
int8_t convert_pcm_16bit_signed_to_mu_law(int16_t* x);

/**
 * @brief Encode all the samples in the samples array with Mu-law 8-bit encoding and place the result in the encoded samples array.
 *
 * @param samples Samples array.
 * @param encoded_samples Encoded samples array. Gets allocated internally.
 * @param wave_prop  Wave properties struct.
 */
void encode_mu_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);

/**
 * @brief Set the WAVE header for the extensible format. A header can be of extensible format and another subformat.
 *
 * @param wave_prop Wave properties struct.
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 */
void set_header_extensible(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Output the PCM encoded data and the corresponding chunks. Used only for PCM data.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param wave_prop Wave properties struct. 
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Output the encoded data and the corresponding chunks, when it is in any non-PCM format.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param wave_prop Wave properties struct. 
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_non_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Output the encoded data and the corresponding chunks when the extensible format is selected. Can be used for any format.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param wave_prop Wave properties struct. 
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_extensible(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Output the encoded data only. No header information is written.
 *
 * @param file FILE pointer to file.
 * @param sampled_data Samples array. Contains the encoded samples.
 * @param wave_prop Wave properties struct. 
 * @param riff_chunk RIFF Chunk struct.
 * @param fmt_chunk Format Chunk struct.
 * @param fact_chunk Fact Chunk struct.
 * @param data_chunk Data chunk struct.
 * @return Success or failure.
 */
int output_raw(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);

/**
 * @brief Output the details of the written file to the screen.
 *
 * @param wave_prop 
 * @return Success or failure.
 */
int output_file_details(wave_prop_t* wave_prop);

/**
 * @brief Output the help text.
 *
 * @return Success or failure.
 */
int output_help();

