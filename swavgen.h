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

#define MAX_FILE_NAME 100
#define LVAL_MAX 999999999
#define LVAL_MIN 0
#define FVAL_MAX 300.0f
#define FVAL_MIN 0.1f

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

/* Check if an error occured to exit program */
#define CHECK_ERR(x)        ({ if ((x)) { \
        exit(EXIT_FAILURE); \
        } }) 

/* Check if a function returns failure */
#define CHECK_RET(x)        ({ if ((x)) { \
        return 1; \
        } }) 

typedef unsigned char o_byte; // 8 bits
typedef unsigned short t_bytes; // 16 bits
typedef unsigned long f_bytes; // 32 bits
typedef unsigned long long e_bytes; // 64 bits

/* data Chunk */
typedef struct Data_Chunk {
    char chunkID[4]; // "data"
    f_bytes chunk_size;
    // FIX: Get it to work with the struct!
    // double* sampled_data;
    // o_byte padding;
}data_chunk_t;

/* fact Chunk */
typedef struct Fact_Chunk {
    char chunkID[4]; // "fact"
    f_bytes chunk_size;
    f_bytes dwSampleLength;
}fact_chunk_t;

/* Basic format chunk */
typedef struct Format_chunk {
    char chunkID[4]; // "fmt "
    f_bytes chunk_size;
    t_bytes wFormatTag;
    t_bytes nChannels;
    f_bytes nSamplesPerSec;
    f_bytes nAvgBytesPerSec;
    t_bytes nBlockAlign;
    t_bytes wBitsPerSample;

    /* Extensible use only */
    /* cbSize; */
    /* wValidBitsPerSample;  */
    /* dwChannelMask; */
    /* SubFormat; */
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
    unsigned long long total_number_of_samples;
    float a; // amplitude
    unsigned long long size;
    o_byte channels;
    o_byte bytes_per_sample;
    char type;
    char encoding;
    void (*defv)(wave_prop_t*); // Set default values 
    void (*encd)(wave_prop_t*, riff_chunk_t*, fmt_chunk_t*, fact_chunk_t*, data_chunk_t*); // Encoding 
    void (*wave)(void*, wave_prop_t*); // Wave generation function 
    void (*outp)(wave_prop_t*); // Output function
}wave_prop_t;

void create_sine_16bit_PCM(void* samples, wave_prop_t* wave_prop);
void create_sine_64bit_float(void* samples, wave_prop_t* wave_prop);
void create_clipped_sine_64bit_float(void* samples, wave_prop_t* wave_prop);
void set_defaults(wave_prop_t* wave_prop);
void set_encoding_type(wave_prop_t* wave_prop);
int get_options(int* argc, char** argv, wave_prop_t* wave_prop);
void output_file_details(wave_prop_t* wave_prop);
void set_pcm(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);
void set_ieee_float(wave_prop_t* wave_prop, riff_chunk_t* riff_chunk, fmt_chunk_t* fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t* data_chunk);

