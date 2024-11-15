#include "swavgen.h"

// TODO: Use other types of encoding, A law, mu law, PCM (8/24/32 signed/unsigned)
// TODO: Make other waves, square, triangle, saw, clipped.

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
    
    /* Set the encoding and wave type based on inputs */
    set_type_encoding(&wave_prop);

    /* Prepare the chunks based on the encoding */
    wave_prop.encd(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* Create the wave */
    void* sampled_data = NULL;
    wave_prop.wave(&sampled_data, &wave_prop);

    /* Output the chunks */
    wave_prop.outp(file, sampled_data, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* Final file size */
    wave_prop.size = riff_chunk.chunk_size + sizeof(riff_chunk.chunkID);

    output_file_details(&wave_prop);

    fclose(file);
    return 0;
}
