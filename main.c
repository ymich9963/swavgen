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
// TODO: Add phase shift option.
// TODO: Add tool details to generated file.
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

    check_limit(samples, &wave_prop);

    /* Encode the samples */
    void* encoded_samples = NULL;
    CHECK_ERR(wave_prop.encd(samples, &encoded_samples, &wave_prop));

    /* Output the chunks */
    CHECK_ERR(wave_prop.outp(file, encoded_samples, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));

    /* Final file size */
    wave_prop.size = riff_chunk.chunk_size + sizeof(riff_chunk.chunkID);

    output_file_details(&wave_prop);

    free(samples);
    free(encoded_samples);
    fclose(file);
    return 0;
}
