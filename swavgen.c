#include "swavgen.h"
#include <stdio.h>

void set_defaults(wave_prop_t* wave_prop) {
    strcpy(wave_prop->file_name, "wav.wav");
    wave_prop->a = 1;
    wave_prop->duration = 2.0; // seconds
    wave_prop->f_s = 48000; // sample rate
    wave_prop->f = 800; // sine wave frequency
    wave_prop->p = 1.0f/wave_prop->f; // sine wave period 
    wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration;
    wave_prop->channels = 1;
    wave_prop->bytes_per_sample = 8; // used in IEEE float format
    wave_prop->type = 's'; // sine wave
    wave_prop->encoding = 'f'; // IEEE float
}

int get_options(int* argc, char** argv, wave_prop_t* wave_prop) {
    unsigned long lval = 0;
    unsigned long long llval = 0;
    float fval = 0;
    int ival;
    char strval[MAX_FILE_NAME];

    for (int i = 1; i < *argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            CHECK_RES(sscanf(argv[i], "%s", strval));
            CHECK_ERR(get_wave_type(strval, wave_prop));
            continue;
        }
        if (!(strcmp("-e", argv[i])) || !(strcmp("--encoding", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            CHECK_ERR(get_encoding(strval, wave_prop));
            continue;
        }
        if (!(strcmp("-f", argv[i])) || !(strcmp("--frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%ld", &lval));
            CHECK_LIMITS_LONG(lval);
            wave_prop->f = lval;
            wave_prop->p = 1.0f/lval;
            continue;
        }
        if (!(strcmp("-p", argv[i])) || !(strcmp("--period", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->p = fval;
            wave_prop->f = 1/fval;
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
        if (!(strcmp("-l", argv[i])) || !(strcmp("--sample-length", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &ival));
            wave_prop->bytes_per_sample = ival;
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
        printf("\nUnknown wave type. Please enter either, 'sine', 'square', 'triangle', or 'saw'.\n");
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
    }
    if (!(strcmp("A-law", str))) {
        wave_prop->encoding = 'a';
        return 0;
    }
    if (!(strcmp("Mu-law", str))) {
        wave_prop->encoding = 'm';
        return 0;
    } else {
        printf("Unknown encoding. Please enter either, 'PCM 'or 'IEEE-float'.");
        return 1;
    }
}

int set_type_encoding(wave_prop_t* wave_prop) {
    switch (wave_prop->type) {
        case 's':
            wave_prop->wave = &create_sine;
            break;
        case 'q':
            wave_prop->wave = &create_square;
            break;
        case 't':
            wave_prop->wave = &create_triangle;
            break;
        case 'w':
            wave_prop->wave = &create_saw;
            break;
        default:
            printf("How did we get here?\n");
            return 1;
    }

    switch (wave_prop->encoding) {
        case 'p':
            wave_prop->seth = &set_pcm;
            wave_prop->outp = &output_pcm;
            wave_prop->encd = &encode_pcm;
            break;
        case 'f':
            wave_prop->seth = &set_ieee_float;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_float_64bit;
            break;
        case 'a':
            wave_prop->seth = &set_a_law;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_a_law;
            break;
        case 'm':
            wave_prop->seth = &set_mu_law;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_mu_law;
            break;
        default:
            printf("How did we get here?\n");
            return 1;
    } 
    return 0;
}

void create_sine(double** samples, wave_prop_t* wave_prop) {
    *samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((double*)*samples)[n] = wave_prop->a * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
    }
}

void create_square(double** samples, wave_prop_t* wave_prop) {
    double sample;
    *samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        sample = sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
        ((double*)*samples)[n] = wave_prop->a * (double) sgn(&sample);
    }
}

void create_triangle(double** samples, wave_prop_t* wave_prop) {
    *samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    /* Two implementations. Not sure which one is best. */
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((double*)*samples)[n] = (2 * wave_prop->a / M_PI) * asin(sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s));
        /* ((double*)*samples)[n] = wave_prop->a * (4 * fabs(((double)wave_prop->f * n / wave_prop->f_s) - (int)(((double)wave_prop->f * n / wave_prop->f_s) + 0.5f )) - 1); */
    }
}

void create_saw(double** samples, wave_prop_t* wave_prop) {
    *samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    /* Two implementations. Not sure which one is best. */
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        /* ((double*)*samples)[n] = wave_prop->a * (((double)wave_prop->f * n / wave_prop->f_s) - (int)((double)wave_prop->f * n / wave_prop->f_s)); */
        ((double*)*samples)[n] = wave_prop->a * (2 * (((double)wave_prop->f * n / wave_prop->f_s) - (int)(0.5f + ((double)wave_prop->f * n / wave_prop->f_s))));
    }
}

char sgn(double* x) {
    char sgn = (*x >= 0) ? 1 : -1;
    return sgn;
}

char convert_double_to_pcm_8bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S8BIT_MAX * *sample);
    } else {
        return -(S8BIT_MIN * *sample);
    }
}

short convert_double_to_pcm_16bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S16BIT_MAX * *sample);
    } else {
        return -(S16BIT_MIN * *sample);
    }
}

int convert_double_to_pcm_32bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S32BIT_MAX * *sample);
    } else {
        return -(S32BIT_MIN * *sample);
    }
}

void set_pcm(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* Set as NULL for it to not be unused */
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
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

void encode_pcm(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    switch (wave_prop->bytes_per_sample) {
        case 1:
            *encoded_samples = (char*) malloc(wave_prop->total_number_of_samples * sizeof(char));
            encode_pcm_signed_8bit(samples, encoded_samples, wave_prop);
            break;
        case 2:
            *encoded_samples = (short*) malloc(wave_prop->total_number_of_samples * sizeof(short));
            encode_pcm_signed_16bit(samples, encoded_samples, wave_prop);
            break;
        case 3:
            break;
        case 4:
            *encoded_samples = (int*) malloc(wave_prop->total_number_of_samples * sizeof(int));
            encode_pcm_signed_32bit(samples, encoded_samples, wave_prop);
            break;
        default:
            printf("How did we get here?\n");
            break;
    }
}

void encode_pcm_signed_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((char*)*encoded_samples)[n] = convert_double_to_pcm_8bit_signed(&samples[n]);
    }
}

void encode_pcm_signed_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((short*)*encoded_samples)[n] = convert_double_to_pcm_16bit_signed(&samples[n]);
    }
}

void encode_pcm_signed_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((int*)*encoded_samples)[n] = convert_double_to_pcm_32bit_signed(&samples[n]);
    }
}

void set_ieee_float(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample; // 64 bit data
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

void encode_float_64bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (double*) malloc(wave_prop->total_number_of_samples * sizeof(double));
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        ((double*)*encoded_samples)[n] = samples[n];
    }
}

void set_a_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* Default to 1 byte of data */
    wave_prop->bytes_per_sample = 1;

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = WAVE_FORMAT_ALAW;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample; // 8 bit data
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

/* Based on the Wikipedia equation. Does not work! Left in to show attempt. Issue with x = 0. */
char a_law_compress_old(double* x) {
    double resd = 0.0f;
    char resc = 0;
    char sgn = (*x >= 0) ? 1 : -1;
    if (fabs(*x) < (1/A)) {
        resd = sgn * ((A * fabs(*x)) / (1 + log(A)));
    } else if ((fabs(*x) >= (1/A)) && (fabs(*x) <= 1)) {
        resd = sgn * ((1 + log(A * fabs(*x))) / (1 + log(A)));
    }
    if (resd >= 0) {
        resc =  (S8BIT_MAX * resd);
    } else {
        resc = -(S8BIT_MIN * resd);
    }
    /* resc = resc ^ (0x55);  #<{(| toggle even bits? not in wikipedia equation |)}># */
    return resc;
}

/* Read license in the ITU-T code and attribute accordingly. Mention that the code was changed (also change it more) and is based on that. */
char a_law_compress(short* x) {
    short ix, exp;
    short out;

    ix = *x < 0          /* 0 <= ix < 2048 */
        ? (~(*x)) >> 4       /* 1's complement for negative values */
        : (*x) >> 4;

    /* Do more, if exponent > 0 */
    if (ix > 15) {              /* exponent=0 for ix <= 15 */
        exp = 1;                 /* first step: */
        while (ix > 16 + 15) {    /* find mantissa and exponent */
            ix >>= 1;
            exp++;
        }
        ix -= 16;                 /* second step: remove leading '1' */

        ix += exp << 4;          /* now compute encoded value */
    }
    if (*x >= 0)
        ix |= (0x0080);           /* add sign bit */

    out = ix ^ (0x0055);  /* toggle even bits */

    return out;
}

void encode_a_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    short pcm_sample;
    *encoded_samples = (char*) malloc(wave_prop->total_number_of_samples * sizeof(char));
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(&samples[n]);
        ((char*)*encoded_samples)[n] = a_law_compress(&pcm_sample);
    }
}

void set_mu_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* Default to 1 byte of data */
    wave_prop->bytes_per_sample = 1;

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = WAVE_FORMAT_MULAW;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample; // 8 bit data
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;
}

/* Based on the Wikipedia equation. Does not work! Sometimes values agree. */
char mu_law_compress_old(double* x) {
    double resd = 0.0f;
    char resc = 0;
    char sgn = (*x >= 0) ? 1 : -1;

    resd = sgn * (log(1 + MU * fabs(*x)))/(log(1 + MU));

    if (resd >= 0) {
        resc =  (S8BIT_MAX * resd);
    } else {
        resc = -(S8BIT_MIN * resd);
    }
    return resc;
}

/* Read license in the ITU-T code and attribute accordingly. Mention that the code was changed (also change it more) and is based on that. */
char mu_law_compress(short *x) {
    short segment;                  /* segment (Table 2/G711, column 1) */
    short out;
    short low_nibble, high_nibble;  /* low/high nibble of log companded sample */

    /* Change from 14 bit left justified to 14 bit right justified. 
     * Compute absolute value; adjust for easy processing */

    /* Compute 1's complement */
    short absval = *x < 0 ? ((~(*x)) >> 2) + 33 : ((*x) >> 2) + 33; /* Absolute value */     
    /* 33 is the difference value between the thresholds for A-law and u-law. */

    if (absval > (0x1FFF))       /* limit to < 8192 */
        absval = (0x1FFF);

    /* Determination of sample's segment */
    short temp = absval >> 6;
    segment = 1;
    while (temp != 0) {
        segment++;
        temp >>= 1;
    }

    /* Mounting the high-nibble of the log-PCM sample */
    high_nibble = (0x0008) - segment;

    /* Mounting the low-nibble of the log PCM sample. Right shift of mantissa and masking away the leading '1' */
    low_nibble = (absval >> segment) & (0x000F);
    low_nibble = (0x000F) - low_nibble;

    /* Joining the high-nibble and the low-nibble of the log PCM sample */
    out = (high_nibble << 4) | low_nibble;

    /* Add sign bit */
    if (*x >= 0)
        out = out | (0x0080);

    return out;
}

void encode_mu_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    short pcm_sample;
    *encoded_samples = (char*) malloc(wave_prop->total_number_of_samples * sizeof(char));
    for(int n = 0; n < wave_prop->total_number_of_samples; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(&samples[n]);
        ((char*)*encoded_samples)[n] = mu_law_compress(&pcm_sample);
    }
}

void output_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + sizeof(*fmt_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * wave_prop->bytes_per_sample);

    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->cbSize) + sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat); 

    fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file);
    fwrite(fmt_chunk,  sizeof(fmt_chunk_t) - unused_fmt_chunk,  1, file);
    fwrite(data_chunk, sizeof(data_chunk_t), 1, file);
    fwrite(sampled_data, wave_prop->total_number_of_samples * wave_prop->bytes_per_sample, 1, file);

    /* Padding added based on if the chunk size is odd or even */
    if (data_chunk->chunk_size % 2 != 0) {
        o_byte padding = 1;
        fwrite(&padding, sizeof(padding), 1, file);
    }
}

void output_non_pcm(FILE * file, void* sampled_data, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {
    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat); 

    size_t used_fmt_chunk = sizeof(*fmt_chunk) - unused_fmt_chunk;

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + used_fmt_chunk + sizeof(*fact_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * wave_prop->bytes_per_sample);

    fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file);
    fwrite(fmt_chunk,  used_fmt_chunk,  1, file);
    fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file);
    fwrite(data_chunk, sizeof(data_chunk_t), 1, file);
    fwrite(sampled_data, wave_prop->total_number_of_samples * wave_prop->bytes_per_sample, 1, file);

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
            "\n\tPeriod:\t\t%f"
            "\n\tTotal Samples:\t%lld"
            "\n\n"
            , wave_prop->file_name, wave_prop->size, wave_prop->duration, wave_prop->f_s, wave_prop->f, wave_prop->p, wave_prop->total_number_of_samples);
}

