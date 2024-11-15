#include "swavgen.h"
#include <stdio.h>

void create_clipped_sine_64bit_float(void* samples, wave_prop_t* wave_prop) {
    double sample;
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        sample = wave_prop->a * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
        if (sample >= 1) {
            ((double*)samples)[n] = 1;
        } else {
            ((double*)samples)[n] = sample;
        }
    }
}

void set_defaults(wave_prop_t* wave_prop) {
    strcpy(wave_prop->file_name, "wav.wav");
    wave_prop->a = 1;
    wave_prop->duration = 2.0; // seconds
    wave_prop->f_s = 48000; // sample rate
    wave_prop->f = 800; // sine wave frequency
    wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration;
    wave_prop->channels = 1;
    wave_prop->bytes_per_sample = 8; // used in IEEE float format
    wave_prop->type = 's'; // sine wave
    wave_prop->encoding = 'f'; // IEEE float
}

void set_pcm(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    wave_prop->bytes_per_sample = 2;
    fact_chunk = (fact_chunk_t*) NULL;

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 16;
    fmt_chunk->wFormatTag = WAVE_FORMAT_PCM;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample, // 16 bit data
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

// FIX: PCM file doesn't play but float file does!
void create_sine_16bit_PCM(void** samples, wave_prop_t* wave_prop) {
    /* const short pcm_max = (1 << ((sizeof(short) * 8) - 1)) - 1; */
    /* *samples = (short*) malloc(wave_prop->total_number_of_samples * sizeof(short)); */
    /* for (int n = 0; n < wave_prop->total_number_of_samples; n++) { */
    /*     ((short*)*samples)[n] = pcm_max * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s); */
    /* } */

    /* const short PCM_MAX = (1 << ((sizeof(short) * 8) - 1)) - 1; */
    /* const short PCM_MIN = (short)(1 << ((sizeof(short) * 8) - 1)); */

    /* printf("%d\n", pcm_max); */
    /* printf("%d\n", pcm_min); */

    *samples = (short*) malloc(wave_prop->total_number_of_samples * sizeof(short));
    double sample;
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((short*)*samples)[n] = PCM_MAX * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
        /* sample = sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s); */
        /* if (sample >= 0) { */
        /*     ((short*)*samples)[n] = PCM_MAX * sample; */
        /* } else { */
        /*     ((short*)*samples)[n] = -(PCM_MIN * sample); */
        /* } */
    }
}

void set_ieee_float(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 16;
    fmt_chunk->wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample, // 64 bit data
        fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

void create_sine_64bit_float(void** samples, wave_prop_t* wave_prop) {
    *samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((double*)*samples)[n] = wave_prop->a * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
    }
}

int get_wave_type(char* str, wave_prop_t* wave_prop) {

    if (!(strcmp("sine", str))) {
        wave_prop->type = 's';
        return 0;
    }
    if (!(strcmp("square", str))) {
        wave_prop->type = 'q';
        return 0;
    }
    if (!(strcmp("triangle", str))) {
        wave_prop->type = 't';
        return 0;
    }
    if (!(strcmp("saw", str))) {
        wave_prop->type = 'w';
        return 0;
    } else {
        printf("Unknown wave type. Please enter either, 'sine', 'square', 'triangle', or 'saw'.");
        return 1;
    }
}

int get_encoding(char* str, wave_prop_t* wave_prop) {

    if (!(strcmp("PCM", str))) {
        wave_prop->encoding = 'p';
        return 0;
    }
    if (!(strcmp("IEEE-float", str))) {
        wave_prop->encoding = 'f';
        return 0;
    } else {
        printf("Unknown encoding. Please enter either, 'PCM 'or 'IEEE-float'.");
        return 1;
    }
}
int get_options(int* argc, char** argv, wave_prop_t* wave_prop) {
    unsigned long lval = 0;
    unsigned long long llval = 0;
    float fval = 0;
    char strval[MAX_FILE_NAME];

    for (int i = 1; i < *argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            CHECK_RES(sscanf(argv[i], "%s", strval));
            get_wave_type(strval, wave_prop);
            continue;
        }
        if (!(strcmp("-e", argv[i])) || !(strcmp("--encoding", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            get_encoding(strval, wave_prop);
            continue;
        }
        if (!(strcmp("-f", argv[i])) || !(strcmp("--frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%ld", &lval));
            CHECK_LIMITS_LONG(lval);
            wave_prop->f = lval;
            continue;
        }
        if (!(strcmp("-s", argv[i])) || !(strcmp("--sampling-frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%ld", &lval));
            CHECK_LIMITS_LONG(lval);
            wave_prop->f_s = lval;
            wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration;
            continue;
        }
        if (!(strcmp("-d", argv[i])) || !(strcmp("--duration", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->duration = fval;
            wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration;
            continue;
        }
        if (!(strcmp("-n", argv[i])) || !(strcmp("--total-samples", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lld", &llval));
            CHECK_LIMITS_LONG(llval);
            wave_prop->total_number_of_samples = llval;
            continue;
        }
        if (!(strcmp("-a", argv[i])) || !(strcmp("--amplitude", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->a = fval;
            continue;
        }
        if (!(strcmp("-o", argv[i])) || !(strcmp("--output", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            strcpy(wave_prop->file_name, strval);
            continue;
        }
    }
    return 0;
}

void set_type_encoding(wave_prop_t* wave_prop) {
    switch (wave_prop->encoding) {
        case 'p':
            wave_prop->encd = &set_pcm;
            wave_prop->outp = &output_pcm;
            switch (wave_prop->type) {
                case 's':
                    wave_prop->wave = &create_sine_16bit_PCM;
                    break;
                default:
                    printf("Entered default wave type\n");
                    break;
            }
            break;
        case 'f':
            wave_prop->encd = &set_ieee_float;
            wave_prop->outp = &output_ieee_float;
            switch (wave_prop->type) {
                case 's':
                    wave_prop->wave = &create_sine_64bit_float;
                    break;
                default:
                    printf("Entered default wave type\n");
                    break;
            }
            break;
        default:
            printf("Entered default encoding.\n");
            break;
    } 
}

void output_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + sizeof(*fmt_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * sizeof(((short*)sampled_data)[0]));

    fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file);
    fwrite(fmt_chunk,  sizeof(fmt_chunk_t),  1, file);
    fwrite(data_chunk, sizeof(data_chunk_t), 1, file);
    fwrite(sampled_data, wave_prop->total_number_of_samples * sizeof(((short*)sampled_data)[0]), 1, file);

    /* Padding added based on if the chunk size is odd or even */
    if (data_chunk->chunk_size % 2 != 0) {
        o_byte padding = 1;
        fwrite(&padding, sizeof(padding), 1, file);
    }
}

void output_ieee_float(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {
    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + sizeof(*fmt_chunk) + sizeof(*fact_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * sizeof(((double*)sampled_data)[0]));

    fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file);
    fwrite(fmt_chunk,  sizeof(fmt_chunk_t),  1, file);
    fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file);
    fwrite(data_chunk, sizeof(data_chunk_t), 1, file);
    fwrite(sampled_data, wave_prop->total_number_of_samples * sizeof(((double*)sampled_data)[0]), 1, file);

    /* Padding added based on if the chunk size is odd or even */
    if (data_chunk->chunk_size % 2 != 0) {
        o_byte padding = 1;
        fwrite(&padding, sizeof(padding), 1, file);
    }
}

void output_file_details(wave_prop_t* wave_prop) {
    printf("\n\tFile Name:\t%s"
            "\n\tSize:\t\t%lld"
            "\n\tDuration:\t%f"
            "\n\tSampling Freq.:\t%ld"
            "\n\tTone Freq.:\t%ld"
            "\n\tTotal Samples:\t%lld"
            "\n\n"
            , wave_prop->file_name, wave_prop->size, wave_prop->duration, wave_prop->f_s, wave_prop->f, wave_prop->total_number_of_samples);
}

