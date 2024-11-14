#include "swavgen.h"

// TODO: Use other types of encoding, A law, mu law, PCM
// TODO: Make other waves, square, triangle, saw, clipped sine.

int main (int argc, char** argv) {

    wave_prop_t wave_prop;
    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk;
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_defaults(&wave_prop);

    CHECK_ERR(get_options(&argc, argv, &wave_prop));

    FILE * file = fopen(wave_prop.file_name, "wb");
    if (!(file)) {
        printf("Error opening file...exiting.");
        return 1;
    }

    set_ieee_float(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    set_pcm(&wave_prop, &riff_chunk, &fmt_chunk, &data_chunk);

    /* Create the sine wave */
    double* sampled_data = (double*) malloc(wave_prop.total_number_of_samples * sizeof(double));
    create_sine_64bit_float(sampled_data, &wave_prop);

    short* sampled_data = (short*) malloc(wave_prop.total_number_of_samples * sizeof(double));
    create_sine_16bit_PCM(sampled_data, &wave_prop);

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
