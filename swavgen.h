#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Standard format codes */
#define WAVE_FORMAT_PCM         0x0001  // PCM
#define WAVE_FORMAT_IEEE_FLOAT  0x0003  // IEEE float
#define WAVE_FORMAT_ALAW        0x0006  // 8-bit ITU-T G.711 A-law
#define WAVE_FORMAT_MULAW       0x0007  // 8-bit ITU-T G.711 µ-law
#define WAVE_FORMAT_EXTENSIBLE  0xFFFE  // Determined by SubFormat

#define MAX_FILE_NAME   100
#define LVAL_MAX        999999999
#define LVAL_MIN        0
#define FVAL_MAX        300.0f
#define FVAL_MIN        0.00001f
#define UCHAR_VAL_MAX   255     
#define UCHAR_VAL_MIN   0 
#define S32BIT_MAX      (int) 0x7fffffff  //  2147483647 or 0b011111111111111111111111
#define S32BIT_MIN      (int) 0x80000000  // -2147483648 or 0b100000000000000000000000
#define S16BIT_MAX      (short) 0x7fff    //  32767 or 0b0111111111111111
#define S16BIT_MIN      (short) 0x8000    // -32768 or 0b1000000000000000
#define S8BIT_MAX       (char)  0x7f      //  127 or 0b01111111
#define S8BIT_MIN       (char)  0x80      // -128 or 0b10000000
#define U32BIT_MAX      (unsigned int) 0xffffffff  //  4294967295 or 0b111111111111111111111111
#define U32BIT_MIN      (unsigned int) 0x00000000  //           0 or 0b1000000000000000000000000
#define U16BIT_MAX      (unsigned short) 0xffff    //  65535 or 0b1111111111111111
#define U16BIT_MIN      (unsigned short) 0x0000    //      0 or 0b0000000000000000
#define U8BIT_MAX       (unsigned char)  0xff      //  255 or 0b11111111
#define U8BIT_MIN       (unsigned char)  0x00      //    0 or 0b00000000
#define A               87.6
#define MU              255

/* Check macros */
/* Check response from sscanf */
#define CHECK_RES(x)        ({ if (!(x)) { \
        fprintf(stderr, "Argument entered was wrong...\n"); \
        return 1; \
        } }) 

/* Check if value is between numerical limits */
#define CHECK_LIMITS_LONG(x)     ({ if ((x) > LVAL_MAX || (x) < LVAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range. Please check inputs and enter numbers between, \n%d and %d", LVAL_MIN, LVAL_MAX); \
        return 1; \
        } }) 

#define CHECK_LIMITS_FLOAT(x)     ({ if ((x) > FVAL_MAX || (x) < FVAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range. Please check inputs and enter numbers between, \n%f and %f", FVAL_MIN, FVAL_MAX); \
        return 1; \
        } }) 

#define CHECK_LIMITS_UCHAR(x)     ({ if ((x) > UCHAR_VAL_MAX || (x) < UCHAR_VAL_MIN) { \
        fprintf(stderr, "Detected numbers out of range. Please check inputs and enter numbers between, \n%d and %d", UCHAR_VAL_MIN, UCHAR_VAL_MAX); \
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

typedef unsigned char       o_byte;     // 8  bits
typedef unsigned short      t_bytes;    // 16 bits
typedef unsigned long       f_bytes;    // 32 bits
typedef unsigned long long  e_bytes;    // 64 bits

/* data Chunk */
// FIX: Fit sampled_data into the struct.
typedef struct Data_Chunk {
    char chunkID[4]; // "data"
    f_bytes chunk_size;
}data_chunk_t;

/* fact Chunk */
typedef struct Fact_Chunk {
    char chunkID[4]; // "fact"
    f_bytes chunk_size;
    f_bytes dwSampleLength;
}fact_chunk_t;

/* Full format chunk */
typedef struct Format_Chunk {
    char chunkID[4]; // "fmt "
    f_bytes chunk_size;
    t_bytes wFormatTag;
    t_bytes nChannels;
    f_bytes nSamplesPerSec;
    f_bytes nAvgBytesPerSec;
    t_bytes nBlockAlign;
    t_bytes wBitsPerSample;
    t_bytes cbSize;
    t_bytes wValidBitsPerSample;
    f_bytes dwChannelMask;
    o_byte SubFormat[16];
}fmt_chunk_t;

/* Main RIFF chunk */
typedef struct RIFF_Chunk {
    char chunkID[4]; // "RIFF"
    f_bytes chunk_size;  // Number of chunks containing sample and format information 
    char waveID[4]; // "WAVE"
}riff_chunk_t;

typedef struct Wave_Properties wave_prop_t;

typedef struct Wave_Properties {
    char file_name[MAX_FILE_NAME];
    float duration; // wave duration
    unsigned long f_s; // sampling frequency
    unsigned long f; // tone frequency
    float p;        // period
    unsigned long long total_number_of_samples;
    float a; // amplitude
    unsigned long long size;
    o_byte channels;
    o_byte bytes_per_sample;
    o_byte representation;
    char type;
    char typestr[10];
    char encoding;
    char encodingstr[10];
    void (*defv)(wave_prop_t*); // Set default values 
    void (*seth)(wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Set header values 
    void (*wave)(double**, wave_prop_t*); // Wave generation function 
    void (*encd)(double*, void**, wave_prop_t*); // Encoding function
    void (*outp)(FILE*, void*, wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Output function
}wave_prop_t;

void set_defaults(wave_prop_t* wave_prop);
int get_options(int* argc, char** argv, wave_prop_t* wave_prop);
int check_encoding_bytes(wave_prop_t* wave_prop);
int get_wave_type(char* str, wave_prop_t* wave_prop);
int get_encoding(char* str, wave_prop_t* wave_prop);
int get_represenation(char* str, wave_prop_t* wave_prop);
int set_type_encoding(wave_prop_t* wave_prop);
void create_sine(double** samples, wave_prop_t* wave_prop);
void create_square(double** samples, wave_prop_t* wave_prop);
void create_triangle(double** samples, wave_prop_t* wave_prop);
void create_saw(double** samples, wave_prop_t* wave_prop);
char convert_double_to_pcm_8bit_signed(double* sample);
short convert_double_to_pcm_16bit_signed(double* sample);
int convert_double_to_pcm_32bit_signed(double* sample);
unsigned char convert_double_to_pcm_8bit_unsigned(double* sample);
unsigned short convert_double_to_pcm_16bit_unsigned(double* sample);
unsigned int convert_double_to_pcm_32bit_unsigned(double* sample);
char sgn(double* x);
void set_header_pcm(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);
void encode_pcm(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_signed_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_pcm_unsigned_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_ieee_float(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);
void encode_ieee_float(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_ieee_float_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void encode_ieee_float_64bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_a_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);
char a_law_compress_old(double* x);
char a_law_compress (short* x);
void encode_a_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void set_header_mu_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk);
char mu_law_compress_old(double* x);
char mu_law_compress (short* x);
void encode_mu_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop);
void output_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
void output_non_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk);
void output_file_details(wave_prop_t* wave_prop);

