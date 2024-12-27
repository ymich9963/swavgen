#include "unity/unity.h"
#include "unity/unity_internals.h"
#include "../swavgen.h"

void setUp() {}

void tearDown() {
    fflush(stdout);
}

void test_output_help() {
   TEST_ASSERT_EQUAL_INT(0, output_help());
}

void test_output_file_details() {
   wave_prop_t wave_prop = {
       .file_name       = "test",
       .typestr         = "test",
       .size            = 1,
       .duration        = 1,
       .encodingstr     = "test",
       .f_s             = 1,
       .f               = 1,
       .T               = 1,
       .total_number_of_samples = 1,
       .channels        = 1,
       .bytes_per_sample = 1,
       .channel_mask    = 1,
       .extensible      = 1,
   };

   TEST_ASSERT_EQUAL_INT(0, output_file_details(&wave_prop));
}

void test_output_raw() {
    FILE * file = stdout;
    char encoded_samples[1] = {1};
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 1
    };

    TEST_ASSERT_EQUAL_INT(0, output_raw(file, encoded_samples, &wave_prop, NULL, NULL, NULL, NULL));
}

void test_output_extensible() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 1
    };
    riff_chunk_t riff_chunk = {
        .waveID = {1},
        .chunkID = {1},
        .chunk_size = 1,
    };

    fmt_chunk_t fmt_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
        .cbSize = 1,
        .SubFormat = {1},
        .nChannels = 1,
        .wFormatTag = 1,
        .nBlockAlign = 1,
        .dwChannelMask = 1,
        .nSamplesPerSec = 1,
        .wBitsPerSample = 1,
        .nAvgBytesPerSec = 1,
        .wValidBitsPerSample = 1,
    };

    fact_chunk_t fact_chunk = {
        .chunkID = {1},
        .chunk_size = 1,
        .dwSampleLength = 1,
    };

    data_chunk_t data_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
    };

    TEST_ASSERT_EQUAL_INT(0, output_extensible(file, encoded_samples, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}
void test_output_non_pcm() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 1
    };
    riff_chunk_t riff_chunk = {
        .waveID = {1},
        .chunkID = {1},
        .chunk_size = 1,
    };

    fmt_chunk_t fmt_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
        .cbSize = 1,
        .SubFormat = {1},
        .nChannels = 1,
        .wFormatTag = 1,
        .nBlockAlign = 1,
        .dwChannelMask = 1,
        .nSamplesPerSec = 1,
        .wBitsPerSample = 1,
        .nAvgBytesPerSec = 1,
        .wValidBitsPerSample = 1,
    };

    fact_chunk_t fact_chunk = {
        .chunkID = {1},
        .chunk_size = 1,
        .dwSampleLength = 1,
    };

    data_chunk_t data_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
    };

    TEST_ASSERT_EQUAL_INT(0, output_non_pcm(file, encoded_samples, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}

void test_output_pcm() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 1
    };
    riff_chunk_t riff_chunk = {
        .waveID = {1},
        .chunkID = {1},
        .chunk_size = 1,
    };

    fmt_chunk_t fmt_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
        .cbSize = 1,
        .SubFormat = {1},
        .nChannels = 1,
        .wFormatTag = 1,
        .nBlockAlign = 1,
        .dwChannelMask = 1,
        .nSamplesPerSec = 1,
        .wBitsPerSample = 1,
        .nAvgBytesPerSec = 1,
        .wValidBitsPerSample = 1,
    };

    fact_chunk_t fact_chunk = {
        .chunkID = {1},
        .chunk_size = 1,
        .dwSampleLength = 1,
    };

    data_chunk_t data_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
    };

    TEST_ASSERT_EQUAL_INT(0, output_pcm(file, encoded_samples, &wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}

void test_set_header_extensible() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 0
    };
    riff_chunk_t riff_chunk = {
        .waveID = {1},
        .chunkID = {1},
        .chunk_size = 1,
    };

    fmt_chunk_t fmt_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
        .cbSize = 1,
        .SubFormat = {1},
        .nChannels = 1,
        .wFormatTag = 1,
        .nBlockAlign = 1,
        .dwChannelMask = 1,
        .nSamplesPerSec = 1,
        .wBitsPerSample = 1,
        .nAvgBytesPerSec = 1,
        .wValidBitsPerSample = 1,
    };

    fact_chunk_t fact_chunk = {
        .chunkID = {1},
        .chunk_size = 1,
        .dwSampleLength = 1,
    };

    data_chunk_t data_chunk = {
        .chunk_size = 1,
        .chunkID = {1},
    };
    set_header_extensible(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_output_help);
    RUN_TEST(test_output_file_details);
    RUN_TEST(test_output_raw);
    RUN_TEST(test_output_extensible);
    RUN_TEST(test_output_non_pcm);
    RUN_TEST(test_output_pcm);
    RUN_TEST(test_set_header_extensible);

    return UNITY_END();
}
