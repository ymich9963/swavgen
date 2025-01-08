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
        .padding = 0,
        .encoding = WAVE_FORMAT_PCM,
    };

    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk; 
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_header_extensible(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

void test_encode_companding() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    wave_prop.encoding = WAVE_FORMAT_ALAW;
    TEST_ASSERT_EQUAL_INT(0 ,encode_companding(samples, &encoded_samples, &wave_prop));

    wave_prop.encoding = WAVE_FORMAT_MULAW;
    encode_companding(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT(0 ,encode_companding(samples, &encoded_samples, &wave_prop));

    wave_prop.encoding = 123;
    TEST_ASSERT_EQUAL_INT(1, encode_companding(samples, &encoded_samples, &wave_prop));
}

void test_encode_mu_law() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    encode_mu_law(samples, &encoded_samples, &wave_prop);

    TEST_ASSERT_EQUAL_INT8(-128, ((int8_t*)encoded_samples)[0]);
}


void test_convert_pcm_16bit_signed_to_mu_law() {
    /* Checked implementation using files under compand-test/ */
    int16_t val;

    val = 0;
    TEST_ASSERT_EQUAL_INT8(255, convert_pcm_16bit_signed_to_mu_law(&val));

    val = -1;
    TEST_ASSERT_EQUAL_INT8(127, convert_pcm_16bit_signed_to_mu_law(&val));
}

void test_set_header_mu_law() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 0,
        .encoding = WAVE_FORMAT_MULAW,
    };

    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk; 
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_header_mu_law(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

void test_encode_a_law() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    encode_a_law(samples, &encoded_samples, &wave_prop);

    TEST_ASSERT_EQUAL_INT8(-86, ((int8_t*)encoded_samples)[0]);
}


void test_convert_pcm_16bit_signed_to_a_law() {
    /* Checked implementation using files under compand-test/ */
    int16_t val;

    val = 0;
    TEST_ASSERT_EQUAL_INT8(213, convert_pcm_16bit_signed_to_a_law(&val));

    val = -1;
    TEST_ASSERT_EQUAL_INT8(85, convert_pcm_16bit_signed_to_a_law(&val));
}

void test_set_header_a_law() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 0,
        .encoding = WAVE_FORMAT_ALAW,
    };

    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk; 
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_header_a_law(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

void test_encode_ieee_float() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};

    wave_prop.bytes_per_sample = 4;
    encode_ieee_float(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, ((float*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 8;
    encode_ieee_float(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, ((double*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 10;
    TEST_ASSERT_EQUAL_INT(1, encode_ieee_float(samples, &encoded_samples, &wave_prop));

    /* Since using this encoding is so simple, the individual functions are not tested */
}

void test_set_header_ieee_float() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 0,
        .encoding = WAVE_FORMAT_IEEE_FLOAT,
    };

    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk; 
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_header_ieee_float(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

void test_encode_pcm() {
    /* Test all PCM encoding functions here */
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
    };

    void* encoded_samples = NULL;

    /* Signed tests */
    double samples[1] = {1};
    wave_prop.representation = 's';
    wave_prop.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT8(S8BIT_MAX, ((int8_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT16(S16BIT_MAX, ((int16_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT32(S24BIT_MAX, ((int32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT32(S32BIT_MAX, ((int32_t*)encoded_samples)[0]);

    samples[0] = -1;
    wave_prop.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT8(S8BIT_MIN, ((int8_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT16(S16BIT_MIN, ((int16_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT32(-S24BIT_MIN, ((int32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT32(S32BIT_MIN, ((int32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 5;
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &wave_prop));

    /* Unsigned tests */
    samples[0] = 1;
    wave_prop.representation = 'u';
    wave_prop.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT8(U8BIT_MAX, ((uint8_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT16(U16BIT_MAX, ((uint16_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(U24BIT_MAX, ((uint32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(U32BIT_MAX, ((uint32_t*)encoded_samples)[0]);

    samples[0] = -1;
    wave_prop.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT8(0, ((uint8_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT16(0, ((uint16_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(0, ((uint32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(0, ((uint32_t*)encoded_samples)[0]);

    samples[0] = 0;
    wave_prop.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT8(U8BIT_MAX/2 + 1, ((uint8_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT16(U16BIT_MAX/2 + 1, ((uint16_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(U24BIT_MAX/2 + 1, ((uint32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &wave_prop);
    TEST_ASSERT_EQUAL_UINT32(U32BIT_MAX/2 + 1, ((uint32_t*)encoded_samples)[0]);

    wave_prop.bytes_per_sample = 5;
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &wave_prop));

    wave_prop.bytes_per_sample = 4;
    wave_prop.representation = 'z';
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &wave_prop));

}

void test_set_header_pcm() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 0,
        .encoding = WAVE_FORMAT_PCM,
    };

    riff_chunk_t riff_chunk;
    fmt_chunk_t fmt_chunk; 
    fact_chunk_t fact_chunk;
    data_chunk_t data_chunk;

    set_header_pcm(&wave_prop, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, wave_prop.padding);
}

void test_fwrite_data() {
    FILE * file = stdout;
    char encoded_samples[1] = {1};
    wave_prop_t wave_prop = {
        .total_number_of_samples = 1,
        .channels = 1,
        .padding = 1
    };

    wave_prop.bytes_per_sample = 1,
        TEST_ASSERT_EQUAL_INT(0, fwrite_data(file, encoded_samples, &wave_prop));
    wave_prop.bytes_per_sample = 3,
        TEST_ASSERT_EQUAL_INT(0, fwrite_data(file, encoded_samples, &wave_prop));
}

void test_sgn() {
    double val = 1;
    TEST_ASSERT_EQUAL_INT(1, sgn(&val));
    val = -1;
    TEST_ASSERT_EQUAL_INT(-1, sgn(&val));
}

void test_check_limit() {
    wave_prop_t wave_prop = {
        .limit = 1,
        .total_number_of_samples = 2,
        .channels = 1,
    };

    double samples[2] = {1.1f, -1.1f};
    check_limit(samples, &wave_prop);
    TEST_ASSERT_EQUAL_INT(1, samples[0]);
    TEST_ASSERT_EQUAL_INT(-1, samples[1]);
}

void test_create_random() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 100,
        .channels = 1,
    };

    double* samples = NULL;
    create_random(&samples, &wave_prop);

    char flag = 0; 
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] > -1 && samples[n] < 1) {
            flag = 1;
        }
    }
    TEST_ASSERT_EQUAL_INT8(1, flag);
}

void test_create_saw_approx() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_saw_approx(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-1, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-1, -1, smallest);
}

void test_create_saw() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_saw(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(5e-2, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(5e-2, -1, smallest);
}

void test_create_triangle_approx() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_triangle_approx(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-1, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-1, -1, smallest);
}

void test_create_triangle() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_triangle(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -1, smallest);
}

void test_create_square_approx() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_square_approx(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-1, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-1, -1, smallest);
}

void test_create_square() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_square(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -1, smallest);
}

void test_create_sine() {
    wave_prop_t wave_prop = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_sine(&samples, &wave_prop);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < wave_prop.total_number_of_samples; n++) {
        if (samples[n] < smallest) {
            smallest = samples[n];
        }
        if (samples[n] > largest) {
            largest = samples[n];
        }
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, largest);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -1, smallest);
}

void test_set_type_encoding() {
    wave_prop_t wave_prop = {
        .extensible = 0,
        .raw = 0,
    };

    char type_arr[5] = {'s', 'q', 't', 'w', 'r'};
    int enc_arr[4] = {WAVE_FORMAT_PCM, WAVE_FORMAT_IEEE_FLOAT, WAVE_FORMAT_ALAW, WAVE_FORMAT_MULAW};
    int ret = 0;

    wave_prop.approx = 0;
    for (int n = 0; n < 5; n++) {
        wave_prop.type = type_arr[n];
        for (int c = 0; c < 4; c++) {
            wave_prop.encoding = enc_arr[c];
            ret = set_type_encoding(&wave_prop);
        }
    }
    TEST_ASSERT_EQUAL_INT(0, ret);

    wave_prop.approx = 1;
    for (int n = 0; n < 5; n++) {
        wave_prop.type = type_arr[n];
        for (int c = 0; c < 4; c++) {
            wave_prop.encoding = enc_arr[c];
            ret = set_type_encoding(&wave_prop);
        }
    }
    TEST_ASSERT_EQUAL_INT(0, ret);

    wave_prop.raw = 1;
    wave_prop.extensible = 1;
    ret = set_type_encoding(&wave_prop);
    TEST_ASSERT_EQUAL_INT(0, ret);

    wave_prop.encoding = 123;
    ret = set_type_encoding(&wave_prop);
    TEST_ASSERT_EQUAL_INT(1, ret);

    wave_prop.type = 'z';
    wave_prop.approx = 0;
    ret = set_type_encoding(&wave_prop);
    TEST_ASSERT_EQUAL_INT(1, ret);

    wave_prop.type = 'z';
    wave_prop.approx = 1;
    ret = set_type_encoding(&wave_prop);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void test_get_channel_mask() {
    wave_prop_t wave_prop = {
        .channel_mask = 0,
    };
    char channel_masks[] = {"FL,FR,FC,LF,BL,BR,FLOC,FROC,BC,SL,SR,TC,TFL,TFC,TFR,TBL,TBC,TBR,SPR"};
    get_channel_mask(channel_masks, &wave_prop); 
    TEST_ASSERT_EQUAL_UINT32(0x80000000 + 0x40000 - 1, wave_prop.channel_mask);

    char channel_mask[] = {"FR"};
    get_channel_mask(channel_mask, &wave_prop); 
    TEST_ASSERT_EQUAL_UINT32(SPEAKER_FRONT_RIGHT, wave_prop.channel_mask);
}

void test_get_representation() {
    wave_prop_t wave_prop;

    get_represenation("signed", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('s', wave_prop.representation);

    get_represenation("unsigned", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('u', wave_prop.representation);

    TEST_ASSERT_EQUAL_INT(1, get_represenation("test", &wave_prop));
}

void test_get_encoding() {
    wave_prop_t wave_prop;

    get_encoding("PCM", &wave_prop);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_PCM, wave_prop.encoding);
    get_encoding("IEEE-float", &wave_prop);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_IEEE_FLOAT, wave_prop.encoding);
    get_encoding("A-law", &wave_prop);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_ALAW, wave_prop.encoding);
    get_encoding("Mu-law", &wave_prop);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_MULAW, wave_prop.encoding);

    TEST_ASSERT_EQUAL_INT(1, get_encoding("test", &wave_prop));
}

void test_get_wave_type() {
    wave_prop_t wave_prop;

    get_wave_type("sine", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('s', wave_prop.type);
    get_wave_type("square", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('q', wave_prop.type);
    get_wave_type("triangle", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('t', wave_prop.type);
    get_wave_type("saw", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('w', wave_prop.type);
    get_wave_type("random", &wave_prop);
    TEST_ASSERT_EQUAL_INT8('r', wave_prop.type);
    TEST_ASSERT_EQUAL_STRING("random", wave_prop.typestr);

    TEST_ASSERT_EQUAL_INT(1, get_encoding("test", &wave_prop));
}

void split(char* cmd, char** argv, int* argc) {
    char* token = strtok(cmd," "); 
    *argc = 0;
    while(token != NULL) {
        argv[*argc] = token; 
        token = strtok(NULL," "); 
        *argc = *argc + 1;
    }
}

void reset(char** argv, wave_prop_t* wave_prop, int size) {
    for(int i = 0; i < size; i++) {
        argv[i] = "\0";
    }
    wave_prop_t x = { 0 };
    *wave_prop = x;
}

void test_get_options() {
    wave_prop_t wave_prop = {0};
    int argc;
    char* argv[100];

    argc = 1;
    argv[0] = "first";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argc = 2;
    argv[1] = "--help";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argc = 2;
    argv[1] = "--version";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    char cmd0[] = "first sine -e PCM -f 500 -T 0.02 -s 48000 -d 2.0 -n 96000 -a 1 -l 16 -r signed -c 1 -o out -x -v 16 -m 1 --raw --limit -b 10";
    split(cmd0, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd1[] = "first --encoding PCM --frequency 500 --period 0.02 --sampling-frequency 48000 --duration 2.0 --total-samples 96000 --amplitude 1 --sample-length 16 --representation signed --channels 1 --output out --extensible --valid-bits 16 --channel-mask 1 --raw --limit --approx 10";
    split(cmd1, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd2[] = "first -l 16 -v 20";
    split(cmd2, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd3[] = "first -m FR";
    split(cmd3, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd4[] = "first -z";
    split(cmd4, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd5[] = "first swav";
    split(cmd5, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);

    char cmd6[] = "first -l 15";
    split(cmd6, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
    reset(argv, &wave_prop, 100);
}

void test_conversions() {
    int argc = 3;
    char* argv[3];
    wave_prop_t wave_prop = {0};

    argv[0] = "first";
    argv[1] = "--convert-double-to-PCM-8bit-signed";
    argv[2] = "1";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-16bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-24bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-32bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-8bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-16bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-24bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-double-to-PCM-32bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-PCM-16bit-signed-to-A-law";
    argv[2] = "0";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));

    argv[1] = "--convert-PCM-16bit-signed-to-Mu-law";
    argv[2] = "0";
    TEST_ASSERT_EQUAL_INT(1, get_options(&argc, argv, &wave_prop));
}

void test_set_defaults() {
    wave_prop_t wave_prop;
    set_defaults(&wave_prop);
    TEST_ASSERT_EQUAL_INT(0, wave_prop.approx);
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
    RUN_TEST(test_encode_companding);
    RUN_TEST(test_encode_mu_law);
    RUN_TEST(test_convert_pcm_16bit_signed_to_mu_law);
    RUN_TEST(test_set_header_mu_law);
    RUN_TEST(test_encode_a_law);
    RUN_TEST(test_convert_pcm_16bit_signed_to_a_law);
    RUN_TEST(test_set_header_a_law);
    RUN_TEST(test_encode_ieee_float);
    RUN_TEST(test_set_header_ieee_float);
    RUN_TEST(test_encode_pcm);
    RUN_TEST(test_set_header_pcm);
    RUN_TEST(test_fwrite_data);
    RUN_TEST(test_sgn);
    RUN_TEST(test_check_limit);
    RUN_TEST(test_create_random);
    RUN_TEST(test_create_saw_approx);
    RUN_TEST(test_create_saw);
    RUN_TEST(test_create_triangle_approx);
    RUN_TEST(test_create_triangle);
    RUN_TEST(test_create_square_approx);
    RUN_TEST(test_create_square);
    RUN_TEST(test_create_sine);
    RUN_TEST(test_set_type_encoding);
    RUN_TEST(test_get_channel_mask);
    RUN_TEST(test_get_representation);
    RUN_TEST(test_get_encoding);
    RUN_TEST(test_get_wave_type);
    RUN_TEST(test_get_options);
    RUN_TEST(test_conversions);
    RUN_TEST(test_set_defaults);
    return UNITY_END();
}
