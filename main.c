/*
    swavgen : Simple Wave Generator.
    Copyright (C) 2024 Yiannis Michael (ymich9963)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "swavgen.h"

// TODO: Implement more formats like IMA ADPCM, GSM, etc.
// TODO: Add tool details to the generated .wav file.
// TODO: Add phase shift option. 

int main(int argc, char** argv)
{
    swavgen_config_t swavgen_config;
    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk;
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_defaults(&swavgen_config);

    CHECK_ERR(get_options(argc, argv, &swavgen_config));

    /* Set the encoding and wave type based on inputs */
    CHECK_ERR(set_type_encoding(&swavgen_config));

    /* Prepare the chunks based on the encoding */
    swavgen_config.seth(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* Create the wave */
    double* samples = NULL;
    swavgen_config.wave(&samples, &swavgen_config);

    /* Executing limiting if it was selected */
    check_limit(samples, &swavgen_config);

    /* Encode the samples */
    void* encoded_samples = NULL;
    CHECK_ERR(swavgen_config.encd(samples, &encoded_samples, &swavgen_config));

    /* Generate the output file name */
    swavgen_config.fgen(&swavgen_config);

    FILE* file = fopen(swavgen_config.file_name, "wb");
    if (!(file)) {
        printf("\nError opening file...exiting.\n");

        return 1;
    }

    /* Output the chunks */
    CHECK_ERR(swavgen_config.outp(file, encoded_samples, &swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));

    /* Final file size */
    swavgen_config.size = riff_chunk.chunk_size + sizeof(riff_chunk.chunkID);

    output_file_details(&swavgen_config);

    free(samples);
    free(encoded_samples);
    fclose(file);

    return 0;
}
