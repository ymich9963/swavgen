#include "swavgen.h"

// TODO: Implement IMA ADPCM.
// TODO: Make other waves i.e. clipped waves, approximated waves, random waves.
// TODO: Add phase shift option.
// FIX: Popping when playing and stopping the sound files.

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
        printf("\nError opening file...exiting.\n");
        return 1;
    }

    /* Set the encoding and wave type based on inputs */
    CHECK_ERR(set_type_encoding(&wave_prop));

    /* Prepare the chunks based on the encoding */
    wave_prop.seth(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* Create the wave */
    double* samples = NULL;
    wave_prop.wave(&samples, &wave_prop);

    /* Encode the samples */
    void* encoded_samples = NULL;
    wave_prop.encd(samples, &encoded_samples, &wave_prop);

    /* Output the chunks */
    wave_prop.outp(file, encoded_samples, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* Final file size */
    wave_prop.size = riff_chunk.chunk_size + sizeof(riff_chunk.chunkID);

    output_file_details(&wave_prop);

    fclose(file);
    return 0;
}
