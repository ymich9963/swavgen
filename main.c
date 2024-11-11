#include "swavgen.h"

// TODO: Use other types of encoding
// TODO: Make other waves

void create_wave_64bit_float(double* samples, wave_prop_t* wave_prop) {
    for (int n = 0; n < wave_prop->total_number_of_samples; n++) {
        samples[n] = wave_prop->a * sin(2 * M_PI * wave_prop->f * n / wave_prop->f_s);
    }
}

void set_defaults(wave_prop_t* wave_prop) {
    strcpy(wave_prop->file_name, "wav.wav");
    wave_prop->a = 1;
    wave_prop->duration = 2.0;
    wave_prop->f_s = 48000; // sample rate
    wave_prop->f = 800; // sine wave frequency
    wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration;
}

int get_options(int* argc, char** argv, wave_prop_t* wave_prop) {
    unsigned long lval = 0;
    unsigned long long llval = 0;
    float fval = 0;
    char strval[MAX_FILE_NAME];

    for (int i = 1; i < *argc; i++) {
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

void output_file_details(wave_prop_t* wave_prop) {
    printf("\n"
            "\n\tFile Name:\t%s"
            "\n\tSize:\t\t%lld"
            "\n\tDuration:\t%f"
            "\n\tSampling Freq.:\t%ld"
            "\n\tTone Freq.:\t%ld"
            "\n\tTotal Samples:\t%lld"
            "\n\n"
            , wave_prop->file_name, wave_prop->size, wave_prop->duration, wave_prop->f_s, wave_prop->f, wave_prop->total_number_of_samples);
}

int main (int argc, char** argv) {

    wave_prop_t wave_prop;

    set_defaults(&wave_prop);

    CHECK_ERR(get_options(&argc, argv, &wave_prop));

    FILE * file = fopen(wave_prop.file_name, "wb");
    if (!(file)) {
        printf("Error opening file...exiting.");
        return 1;
    }

    o_byte channels = 1;
    o_byte bytes_per_sample = 8;
    double* sampled_data = (double*) malloc(wave_prop.total_number_of_samples * sizeof(double));

    riff_chunk_t riff_chunk = {
        .chunkID = {"RIFF"},
        .waveID = {"WAVE"},
    };

    fmt_chunk_t fmt_chunk = {
        .chunkID = {"fmt "},
        .chunk_size = 16,
        .wFormatTag = WAVE_FORMAT_IEEE_FLOAT,
        .nChannels = channels,
        .nSamplesPerSec = wave_prop.f_s,
        .nAvgBytesPerSec = wave_prop.f_s * channels * bytes_per_sample, // 64 bit data with 1 channel
        .nBlockAlign = channels * bytes_per_sample,
        .wBitsPerSample = 8 * bytes_per_sample,
    };

    fact_chunk_t fact_chunk = {
        .chunkID = {"fact"},
        .chunk_size = 4,
        .dwSampleLength = channels * wave_prop.total_number_of_samples,
    };

    data_chunk_t data_chunk = {
        .chunkID = {"data"},
        .chunk_size = bytes_per_sample * channels * wave_prop.total_number_of_samples,
    };

    /* Create the sine wave */
    create_wave_64bit_float(sampled_data, &wave_prop);

    /* Once everything has been set, decide on the main chunk size */
    riff_chunk.chunk_size = sizeof(riff_chunk.waveID) + sizeof(fmt_chunk) + sizeof(data_chunk) + (wave_prop.total_number_of_samples * sizeof(sampled_data));

    fwrite(&riff_chunk, sizeof(riff_chunk_t), 1, file);
    fwrite(&fmt_chunk,  sizeof(fmt_chunk_t),  1, file);
    fwrite(&fact_chunk, sizeof(fact_chunk_t), 1, file);
    fwrite(&data_chunk, sizeof(data_chunk_t), 1, file);
    fwrite(sampled_data, wave_prop.total_number_of_samples * sizeof(sampled_data), 1, file);

    /* Padding added based on if the chunk size is odd or even */
    if (data_chunk.chunk_size % 2 != 0) {
        o_byte padding = 1;
        fwrite(&padding, sizeof(padding), 1, file);
    }

    /* Final file size */
    wave_prop.size = riff_chunk.chunk_size + sizeof(riff_chunk.chunkID);

    output_file_details(&wave_prop);

    fclose(file);
    return 0;
}
