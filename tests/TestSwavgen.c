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

void test_get_date_time() {
    char* date = get_date_string();
    TEST_ASSERT_EQUAL_INT(6, strlen(date));
    char* time = get_time_string();
    TEST_ASSERT_EQUAL_INT(6, strlen(time));
}

void test_generate_file_name_ignore() {
    swavgen_config_t swavgen_config;
    TEST_ASSERT_EQUAL_INT(0, generate_file_name_ignore(&swavgen_config));
}
 
void test_generate_file_name_custom_format() {
    swavgen_config_t swavgen_config1 = {
        .custom_string = "custom:swavgen-output-type-frequency-sampling-representation-encoding-length-duration-channels-note-mask",
        .typestr = "test",
        .f = 1.0f,
        .f_s = 1,
        .representationstr = "test",
        .encodingstr = "test",
        .bytes_per_sample = 1,
        .duration = 1.0f,
        .channels = 1,
        .music_note = "tst",
        .channel_mask_str = "test",
    };

    TEST_ASSERT_EQUAL_INT(0, generate_file_name_custom_format(&swavgen_config1));

    char expected[] = "swavgen-output-test-1.000-1-test-test-8-1.000-1-tst-test.wav";
    TEST_ASSERT_EQUAL_STRING(expected, swavgen_config1.file_name);

    swavgen_config_t swavgen_config2 = {
        .custom_string = "custom;swavgen-output-type-frequency-sampling-representation-encoding-length-duration-channels-note-mask",
        .typestr = "test",
        .f = 1.0f,
        .f_s = 1,
        .representationstr = "test",
        .encodingstr = "test",
        .bytes_per_sample = 1,
        .duration = 1.0f,
        .channels = 1,
        .music_note = "tst",
        .channel_mask_str = "test",
    };
    TEST_ASSERT_EQUAL_INT(1, generate_file_name_custom_format(&swavgen_config2));

    swavgen_config_t swavgen_config3 = {
        .custom_string = "custom:date-time",
        .typestr = "test",
        .f = 1.0f,
        .f_s = 1,
        .representationstr = "test",
        .encodingstr = "test",
        .bytes_per_sample = 1,
        .duration = 1.0f,
        .channels = 1,
        .music_note = "tst",
        .channel_mask_str = "test",
    };

    int expected_length = strlen("ddmmyy-HHMMSS.wav");
    generate_file_name_custom_format(&swavgen_config3);
    TEST_ASSERT_EQUAL_INT(expected_length, strlen(swavgen_config3.file_name));

    swavgen_config_t swavgen_config4 = {
        .custom_string = "custom:test",
        .typestr = "test",
        .f = 1.0f,
        .f_s = 1,
        .representationstr = "test",
        .encodingstr = "test",
        .bytes_per_sample = 1,
        .duration = 1.0f,
        .channels = 1,
        .music_note = "tst",
        .channel_mask_str = "test",
    };
    TEST_ASSERT_EQUAL_INT(1, generate_file_name_custom_format(&swavgen_config4));
}

void test_generate_file_name_properties_format() {
    swavgen_config_t swavgen_config = {
        .typestr = "test",
        .f = 1.0f,
        .f_s = 1,
        .encoding = WAVE_FORMAT_PCM,
        .representationstr = "test",
        .encodingstr = "test",
        .bytes_per_sample = 1,
        .duration = 1.0f,
        .channels = 1,
        .music_note = "tst",
        .extensible = 1,
        .channel_mask_str = "test",
    };

    TEST_ASSERT_EQUAL_INT(0, generate_file_name_properties_format(&swavgen_config));

    char expected[] = "swavgen-output-test-1.000-1-test-test-8-1.000-1-tst-test.wav";
    TEST_ASSERT_EQUAL_STRING(expected, swavgen_config.file_name);
}
 
void test_generate_file_name_datetime_format() {
    swavgen_config_t swavgen_config;

    generate_file_name_datetime_format(&swavgen_config);
    int expected_length = strlen("swavgen-output-ddmmyyHHMMSS.wav");
    TEST_ASSERT_EQUAL_INT(expected_length, strlen(swavgen_config.file_name));
}

void test_output_file_details() {
    swavgen_config_t swavgen_config = {
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
        .bytes_per_sample= 1,
        .encoding        = WAVE_FORMAT_PCM,
        .representationstr = "test",
        .music_note      = "tst",
        .channel_mask    = 1,
        .channel_mask_str= "test",
        .extensible      = 1,
    };

    TEST_ASSERT_EQUAL_INT(0, output_file_details(&swavgen_config));
}

void test_output_raw() {
    FILE * file = stdout;
    char encoded_samples[1] = {1};
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 1,
        .padding = 1
    };

    TEST_ASSERT_EQUAL_INT(0, output_raw(file, encoded_samples, &swavgen_config, NULL, NULL, NULL, NULL));
}

void test_output_extensible() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    swavgen_config_t swavgen_config = {
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

    TEST_ASSERT_EQUAL_INT(0, output_extensible(file, encoded_samples, &swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}
void test_output_non_pcm() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    swavgen_config_t swavgen_config = {
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

    TEST_ASSERT_EQUAL_INT(0, output_non_pcm(file, encoded_samples, &swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}

void test_output_pcm() {
    FILE * file = stdout;
    double encoded_samples[1] = {1};
    swavgen_config_t swavgen_config = {
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

    TEST_ASSERT_EQUAL_INT(0, output_pcm(file, encoded_samples, &swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk));
}

void test_set_header_extensible() {
    swavgen_config_t swavgen_config = {
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

    set_header_extensible(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, swavgen_config.padding);
}

void test_encode_companding() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    swavgen_config.encoding = WAVE_FORMAT_ALAW;
    TEST_ASSERT_EQUAL_INT(0 ,encode_companding(samples, &encoded_samples, &swavgen_config));

    swavgen_config.encoding = WAVE_FORMAT_MULAW;
    encode_companding(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT(0 ,encode_companding(samples, &encoded_samples, &swavgen_config));

    swavgen_config.encoding = 123;
    TEST_ASSERT_EQUAL_INT(1, encode_companding(samples, &encoded_samples, &swavgen_config));
}

void test_encode_mu_law() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    encode_mu_law(samples, &encoded_samples, &swavgen_config);

    TEST_ASSERT_EQUAL_INT8(-128, ((int8_t*)encoded_samples)[0]);
}


void test_convert_pcm_16bit_signed_to_mu_law() {
    /* Checked implementation using files under compand-test/ */
    int16_t val;

    val = 0;
    TEST_ASSERT_EQUAL_INT8(255, convert_pcm_16bit_signed_to_mu_law(val));

    val = -1;
    TEST_ASSERT_EQUAL_INT8(127, convert_pcm_16bit_signed_to_mu_law(val));
}

void test_set_header_mu_law() {
    swavgen_config_t swavgen_config = {
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

    set_header_mu_law(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, swavgen_config.padding);
}

void test_encode_a_law() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
        .bytes_per_sample = 2,
        .padding = 0
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};
    encode_a_law(samples, &encoded_samples, &swavgen_config);

    TEST_ASSERT_EQUAL_INT8(-86, ((int8_t*)encoded_samples)[0]);
}


void test_convert_pcm_16bit_signed_to_a_law() {
    /* Checked implementation using files under compand-test/ */
    int16_t val;

    val = 0;
    TEST_ASSERT_EQUAL_INT8(213, convert_pcm_16bit_signed_to_a_law(val));

    val = -1;
    TEST_ASSERT_EQUAL_INT8(85, convert_pcm_16bit_signed_to_a_law(val));
}

void test_set_header_a_law() {
    swavgen_config_t swavgen_config = {
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

    set_header_a_law(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, swavgen_config.padding);
}

void test_encode_ieee_float() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
    };

    void* encoded_samples = NULL;
    double samples[1] = {1};

    swavgen_config.bytes_per_sample = 4;
    encode_ieee_float(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, ((float*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 8;
    encode_ieee_float(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1, ((double*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 10;
    TEST_ASSERT_EQUAL_INT(1, encode_ieee_float(samples, &encoded_samples, &swavgen_config));

    /* Since using this encoding is so simple, the individual functions are not tested */
}

void test_set_header_ieee_float() {
    swavgen_config_t swavgen_config = {
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

    set_header_ieee_float(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, swavgen_config.padding);
}

void test_encode_pcm() {
    /* Test all PCM encoding functions here */
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
    };

    void* encoded_samples = NULL;

    /* Signed tests */
    double samples[1] = {1};
    swavgen_config.representation = 's';
    swavgen_config.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT8(S8BIT_MAX, ((int8_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT16(S16BIT_MAX, ((int16_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT32(S24BIT_MAX, ((int32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT32(S32BIT_MAX, ((int32_t*)encoded_samples)[0]);

    samples[0] = -1;
    swavgen_config.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT8(S8BIT_MIN, ((int8_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT16(S16BIT_MIN, ((int16_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT32(-S24BIT_MIN, ((int32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT32(S32BIT_MIN, ((int32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 5;
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &swavgen_config));

    /* Unsigned tests */
    samples[0] = 1;
    swavgen_config.representation = 'u';
    swavgen_config.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT8(U8BIT_MAX, ((uint8_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT16(U16BIT_MAX, ((uint16_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(U24BIT_MAX, ((uint32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(U32BIT_MAX, ((uint32_t*)encoded_samples)[0]);

    samples[0] = -1;
    swavgen_config.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT8(0, ((uint8_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT16(0, ((uint16_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(0, ((uint32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(0, ((uint32_t*)encoded_samples)[0]);

    samples[0] = 0;
    swavgen_config.bytes_per_sample = 1;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT8(U8BIT_MAX/2 + 1, ((uint8_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 2;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT16(U16BIT_MAX/2 + 1, ((uint16_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 3;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(U24BIT_MAX/2 + 1, ((uint32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 4;
    encode_pcm(samples, &encoded_samples, &swavgen_config);
    TEST_ASSERT_EQUAL_UINT32(U32BIT_MAX/2 + 1, ((uint32_t*)encoded_samples)[0]);

    swavgen_config.bytes_per_sample = 5;
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &swavgen_config));

    swavgen_config.bytes_per_sample = 4;
    swavgen_config.representation = 'z';
    TEST_ASSERT_EQUAL_INT(1, encode_pcm(samples, &encoded_samples, &swavgen_config));

}

void test_set_header_pcm() {
    swavgen_config_t swavgen_config = {
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

    set_header_pcm(&swavgen_config, &riff_chunk, &fmt_chunk, &fact_chunk, &data_chunk);

    /* If the last line in the function is executed it means all good */
    TEST_ASSERT_EQUAL_INT(1, swavgen_config.padding);
}

void test_fwrite_data() {
    FILE * file = stdout;
    char encoded_samples[1] = {1};
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 1,
        .channels = 1,
        .padding = 1
    };

    swavgen_config.bytes_per_sample = 1,
        TEST_ASSERT_EQUAL_INT(0, fwrite_data(file, encoded_samples, &swavgen_config));
    swavgen_config.bytes_per_sample = 3,
        TEST_ASSERT_EQUAL_INT(0, fwrite_data(file, encoded_samples, &swavgen_config));
}

void test_sgn() {
    double val = 1;
    TEST_ASSERT_EQUAL_INT(1, sgn(val));
    val = -1;
    TEST_ASSERT_EQUAL_INT(-1, sgn(val));
}

void test_check_limit() {
    swavgen_config_t swavgen_config = {
        .limit = 1,
        .total_number_of_samples = 2,
        .channels = 1,
    };

    double samples[2] = {1.1f, -1.1f};
    check_limit(samples, &swavgen_config);
    TEST_ASSERT_EQUAL_INT(1, samples[0]);
    TEST_ASSERT_EQUAL_INT(-1, samples[1]);
}

void test_create_random() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 100,
        .channels = 1,
    };

    double* samples = NULL;
    create_random(&samples, &swavgen_config);

    char flag = 0; 
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
        if (samples[n] > -1 && samples[n] < 1) {
            flag = 1;
        }
    }
    TEST_ASSERT_EQUAL_INT8(1, flag);
}

void test_create_saw_approx() {
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_saw_approx(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_saw(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_triangle_approx(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_triangle(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .approx = 10,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_square_approx(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_square(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .total_number_of_samples = 48000,
        .channels = 1,
        .a = 1,
        .f = 500,
        .f_s = 48000,
    };

    double* samples = NULL;
    create_sine(&samples, &swavgen_config);

    double largest = 0;
    double smallest = 0;
    for (size_t n = 0; n < swavgen_config.total_number_of_samples; n++) {
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
    swavgen_config_t swavgen_config = {
        .extensible = 0,
        .raw = 0,
    };

    char type_arr[5] = {'s', 'q', 't', 'w', 'r'};
    int enc_arr[4] = {WAVE_FORMAT_PCM, WAVE_FORMAT_IEEE_FLOAT, WAVE_FORMAT_ALAW, WAVE_FORMAT_MULAW};
    int ret = 0;

    swavgen_config.approx = 0;
    for (int n = 0; n < 5; n++) {
        swavgen_config.type = type_arr[n];
        for (int c = 0; c < 4; c++) {
            swavgen_config.encoding = enc_arr[c];
            ret = set_type_encoding(&swavgen_config);
        }
    }
    TEST_ASSERT_EQUAL_INT(0, ret);

    swavgen_config.approx = 1;
    for (int n = 0; n < 5; n++) {
        swavgen_config.type = type_arr[n];
        for (int c = 0; c < 4; c++) {
            swavgen_config.encoding = enc_arr[c];
            ret = set_type_encoding(&swavgen_config);
        }
    }
    TEST_ASSERT_EQUAL_INT(0, ret);

    swavgen_config.raw = 1;
    swavgen_config.extensible = 1;
    ret = set_type_encoding(&swavgen_config);
    TEST_ASSERT_EQUAL_INT(0, ret);

    swavgen_config.encoding = 123;
    ret = set_type_encoding(&swavgen_config);
    TEST_ASSERT_EQUAL_INT(1, ret);

    swavgen_config.type = 'z';
    swavgen_config.approx = 0;
    ret = set_type_encoding(&swavgen_config);
    TEST_ASSERT_EQUAL_INT(1, ret);

    swavgen_config.type = 'z';
    swavgen_config.approx = 1;
    ret = set_type_encoding(&swavgen_config);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void test_get_channel_mask() {
    swavgen_config_t swavgen_config = {
        .channel_mask = 0,
    };
    char channel_masks[] = {"FL,FR,FC,LF,BL,BR,FLOC,FROC,BC,SL,SR,TC,TFL,TFC,TFR,TBL,TBC,TBR,SPR"};
    get_channel_mask(channel_masks, swavgen_config.channel_mask_str, &swavgen_config.channel_mask); 
    TEST_ASSERT_EQUAL_UINT32(0x80000000 + 0x40000 - 1, swavgen_config.channel_mask);
    TEST_ASSERT_EQUAL_STRING(channel_masks, swavgen_config.channel_mask_str);

    char channel_mask[] = {"FR"};
    get_channel_mask(channel_mask, swavgen_config.channel_mask_str, &swavgen_config.channel_mask); 
    TEST_ASSERT_EQUAL_UINT32(SPEAKER_FRONT_RIGHT, swavgen_config.channel_mask);
    TEST_ASSERT_EQUAL_STRING(channel_mask, swavgen_config.channel_mask_str);
}

void test_set_file_name() {
    char file_name[MAX_STRING];
    TEST_ASSERT_EQUAL_INT(0, set_file_name(file_name, "test"));
    TEST_ASSERT_EQUAL_INT(1, set_file_name(file_name, "testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"));
}

void test_get_music_note_frequency() {
    double f = 0.0f;

    get_music_note_frequency("C0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C0, f);
    get_music_note_frequency("C#0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db0, f);
    get_music_note_frequency("D0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D0, f);
    get_music_note_frequency("D#0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb0, f);
    get_music_note_frequency("Eb0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb0, f);
    get_music_note_frequency("E0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E0, f);
    get_music_note_frequency("F0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F0, f);
    get_music_note_frequency("F#0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb0, f);
    get_music_note_frequency("Gb0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb0, f);
    get_music_note_frequency("G0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G0, f);
    get_music_note_frequency("G#0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab0, f);
    get_music_note_frequency("Ab0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab0, f);
    get_music_note_frequency("A0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A0, f);
    get_music_note_frequency("A#0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb0, f);
    get_music_note_frequency("Bb0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb0, f);
    get_music_note_frequency("B0", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B0, f);

    get_music_note_frequency("C1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C1, f);
    get_music_note_frequency("C#1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db1, f);
    get_music_note_frequency("D1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D1, f);
    get_music_note_frequency("D#1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb1, f);
    get_music_note_frequency("Eb1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb1, f);
    get_music_note_frequency("E1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E1, f);
    get_music_note_frequency("F1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F1, f);
    get_music_note_frequency("F#1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb1, f);
    get_music_note_frequency("Gb1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb1, f);
    get_music_note_frequency("G1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G1, f);
    get_music_note_frequency("G#1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab1, f);
    get_music_note_frequency("Ab1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab1, f);
    get_music_note_frequency("A1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A1, f);
    get_music_note_frequency("A#1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb1, f);
    get_music_note_frequency("Bb1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb1, f);
    get_music_note_frequency("B1", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B1, f);

    get_music_note_frequency("C2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C2, f);
    get_music_note_frequency("C#2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db2, f);
    get_music_note_frequency("D2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D2, f);
    get_music_note_frequency("D#2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb2, f);
    get_music_note_frequency("Eb2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb2, f);
    get_music_note_frequency("E2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E2, f);
    get_music_note_frequency("F2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F2, f);
    get_music_note_frequency("F#2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb2, f);
    get_music_note_frequency("Gb2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb2, f);
    get_music_note_frequency("G2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G2, f);
    get_music_note_frequency("G#2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab2, f);
    get_music_note_frequency("Ab2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab2, f);
    get_music_note_frequency("A2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A2, f);
    get_music_note_frequency("A#2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb2, f);
    get_music_note_frequency("Bb2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb2, f);
    get_music_note_frequency("B2", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B2, f);

    get_music_note_frequency("C3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C3, f);
    get_music_note_frequency("C#3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db3, f);
    get_music_note_frequency("D3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D3, f);
    get_music_note_frequency("D#3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb3, f);
    get_music_note_frequency("Eb3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb3, f);
    get_music_note_frequency("E3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E3, f);
    get_music_note_frequency("F3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F3, f);
    get_music_note_frequency("F#3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb3, f);
    get_music_note_frequency("Gb3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb3, f);
    get_music_note_frequency("G3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G3, f);
    get_music_note_frequency("G#3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab3, f);
    get_music_note_frequency("Ab3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab3, f);
    get_music_note_frequency("A3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A3, f);
    get_music_note_frequency("A#3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb3, f);
    get_music_note_frequency("Bb3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb3, f);
    get_music_note_frequency("B3", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B3, f);

    get_music_note_frequency("C4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C4, f);
    get_music_note_frequency("C#4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db4, f);
    get_music_note_frequency("D4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D4, f);
    get_music_note_frequency("D#4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb4, f);
    get_music_note_frequency("Eb4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb4, f);
    get_music_note_frequency("E4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E4, f);
    get_music_note_frequency("F4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F4, f);
    get_music_note_frequency("F#4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb4, f);
    get_music_note_frequency("Gb4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb4, f);
    get_music_note_frequency("G4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G4, f);
    get_music_note_frequency("G#4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab4, f);
    get_music_note_frequency("Ab4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab4, f);
    get_music_note_frequency("A4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A4, f);
    get_music_note_frequency("A#4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb4, f);
    get_music_note_frequency("Bb4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb4, f);
    get_music_note_frequency("B4", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B4, f);

    get_music_note_frequency("C5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C5, f);
    get_music_note_frequency("C#5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db5, f);
    get_music_note_frequency("D5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D5, f);
    get_music_note_frequency("D#5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb5, f);
    get_music_note_frequency("Eb5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb5, f);
    get_music_note_frequency("E5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E5, f);
    get_music_note_frequency("F5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F5, f);
    get_music_note_frequency("F#5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb5, f);
    get_music_note_frequency("Gb5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb5, f);
    get_music_note_frequency("G5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G5, f);
    get_music_note_frequency("G#5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab5, f);
    get_music_note_frequency("Ab5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab5, f);
    get_music_note_frequency("A5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A5, f);
    get_music_note_frequency("A#5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb5, f);
    get_music_note_frequency("Bb5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb5, f);
    get_music_note_frequency("B5", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B5, f);

    get_music_note_frequency("C6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C6, f);
    get_music_note_frequency("C#6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db6, f);
    get_music_note_frequency("D6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D6, f);
    get_music_note_frequency("D#6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb6, f);
    get_music_note_frequency("Eb6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb6, f);
    get_music_note_frequency("E6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E6, f);
    get_music_note_frequency("F6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F6, f);
    get_music_note_frequency("F#6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb6, f);
    get_music_note_frequency("Gb6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb6, f);
    get_music_note_frequency("G6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G6, f);
    get_music_note_frequency("G#6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab6, f);
    get_music_note_frequency("Ab6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab6, f);
    get_music_note_frequency("A6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A6, f);
    get_music_note_frequency("A#6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb6, f);
    get_music_note_frequency("Bb6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb6, f);
    get_music_note_frequency("B6", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B6, f);

    get_music_note_frequency("C7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C7, f);
    get_music_note_frequency("C#7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db7, f);
    get_music_note_frequency("D7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D7, f);
    get_music_note_frequency("D#7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb7, f);
    get_music_note_frequency("Eb7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb7, f);
    get_music_note_frequency("E7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E7, f);
    get_music_note_frequency("F7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F7, f);
    get_music_note_frequency("F#7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb7, f);
    get_music_note_frequency("Gb7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb7, f);
    get_music_note_frequency("G7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G7, f);
    get_music_note_frequency("G#7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab7, f);
    get_music_note_frequency("Ab7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab7, f);
    get_music_note_frequency("A7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A7, f);
    get_music_note_frequency("A#7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb7, f);
    get_music_note_frequency("Bb7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb7, f);
    get_music_note_frequency("B7", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B7, f);

    get_music_note_frequency("C8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C8, f);
    get_music_note_frequency("C#8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db8, f);
    get_music_note_frequency("D8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D8, f);
    get_music_note_frequency("D#8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb8, f);
    get_music_note_frequency("Eb8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb8, f);
    get_music_note_frequency("E8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E8, f);
    get_music_note_frequency("F8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F8, f);
    get_music_note_frequency("F#8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb8, f);
    get_music_note_frequency("Gb8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb8, f);
    get_music_note_frequency("G8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G8, f);
    get_music_note_frequency("G#8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab8, f);
    get_music_note_frequency("Ab8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab8, f);
    get_music_note_frequency("A8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A8, f);
    get_music_note_frequency("A#8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb8, f);
    get_music_note_frequency("Bb8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb8, f);
    get_music_note_frequency("B8", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B8, f);

    get_music_note_frequency("C9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, C9, f);
    get_music_note_frequency("C#9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Cs_Db9, f);
    get_music_note_frequency("D9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, D9, f);
    get_music_note_frequency("D#9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb9, f);
    get_music_note_frequency("Eb9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Ds_Eb9, f);
    get_music_note_frequency("E9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, E9, f);
    get_music_note_frequency("F9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, F9, f);
    get_music_note_frequency("F#9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb9, f);
    get_music_note_frequency("Gb9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Fs_Gb9, f);
    get_music_note_frequency("G9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, G9, f);
    get_music_note_frequency("G#9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab9, f);
    get_music_note_frequency("Ab9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, Gs_Ab9, f);
    get_music_note_frequency("A9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, A9, f);
    get_music_note_frequency("A#9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb9, f);
    get_music_note_frequency("Bb9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, As_Bb9, f);
    get_music_note_frequency("B9", &f);
    TEST_ASSERT_FLOAT_WITHIN(0, B9, f);

    TEST_ASSERT_EQUAL_INT(1, get_music_note_frequency("ABCD", &f));
}

void test_set_file_name_generator() {

    swavgen_config_t swavgen_config;

    TEST_ASSERT_EQUAL_INT(0, set_file_name_generator(&swavgen_config, "date/time"));
    TEST_ASSERT_EQUAL_INT(0, set_file_name_generator(&swavgen_config, "properties"));
    TEST_ASSERT_EQUAL_INT(0, set_file_name_generator(&swavgen_config, "custom"));
    TEST_ASSERT_EQUAL_INT(1, set_file_name_generator(&swavgen_config, "test"));
    TEST_ASSERT_EQUAL_INT(1, set_file_name_generator(&swavgen_config, "customtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"));

    swavgen_config.file_name[0] = 't';
    TEST_ASSERT_EQUAL_INT(0, set_file_name_generator(&swavgen_config, NULL));
}

void test_get_representation() {
    swavgen_config_t swavgen_config;

    get_represenation("signed", swavgen_config.representationstr, &swavgen_config.representation);
    TEST_ASSERT_EQUAL_INT8('s', swavgen_config.representation);

    get_represenation("unsigned", swavgen_config.representationstr, &swavgen_config.representation);
    TEST_ASSERT_EQUAL_INT8('u', swavgen_config.representation);

    TEST_ASSERT_EQUAL_INT(1, get_represenation("test", swavgen_config.representationstr, &swavgen_config.representation));
}

void test_get_encoding() {
    swavgen_config_t swavgen_config;

    get_encoding("PCM", swavgen_config.encodingstr, &swavgen_config.encoding);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_PCM, swavgen_config.encoding);
    get_encoding("IEEE-float", swavgen_config.encodingstr, &swavgen_config.encoding);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_IEEE_FLOAT, swavgen_config.encoding);
    get_encoding("A-law", swavgen_config.encodingstr, &swavgen_config.encoding);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_ALAW, swavgen_config.encoding);
    get_encoding("Mu-law", swavgen_config.encodingstr, &swavgen_config.encoding);
    TEST_ASSERT_EQUAL_INT16(WAVE_FORMAT_MULAW, swavgen_config.encoding);

    TEST_ASSERT_EQUAL_INT(1, get_encoding("test", swavgen_config.encodingstr, &swavgen_config.encoding));
}

void test_get_wave_type() {
    swavgen_config_t swavgen_config;

    get_wave_type("sine", swavgen_config.typestr, &swavgen_config.type);
    TEST_ASSERT_EQUAL_INT8('s', swavgen_config.type);
    get_wave_type("square", swavgen_config.typestr, &swavgen_config.type);
    TEST_ASSERT_EQUAL_INT8('q', swavgen_config.type);
    get_wave_type("triangle", swavgen_config.typestr, &swavgen_config.type);
    TEST_ASSERT_EQUAL_INT8('t', swavgen_config.type);
    get_wave_type("saw", swavgen_config.typestr, &swavgen_config.type);
    TEST_ASSERT_EQUAL_INT8('w', swavgen_config.type);
    get_wave_type("random", swavgen_config.typestr, &swavgen_config.type);
    TEST_ASSERT_EQUAL_INT8('r', swavgen_config.type);
    TEST_ASSERT_EQUAL_STRING("random", swavgen_config.typestr);

    TEST_ASSERT_EQUAL_INT(1, get_wave_type("test", swavgen_config.typestr, &swavgen_config.type));
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

void reset(char** argv, swavgen_config_t* swavgen_config, int size) {
    for(int i = 0; i < size; i++) {
        argv[i] = "\0";
    }
    swavgen_config_t x = { 0 };
    *swavgen_config = x;
}

void test_get_options() {
    swavgen_config_t swavgen_config = {0};
    int argc;
    char* argv[100];

    argc = 1;
    argv[0] = "first";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argc = 2;
    argv[1] = "--help";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argc = 2;
    argv[1] = "--version";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    char cmd0[] = "first sine -e PCM -f 500 -T 0.02 -s 48000 -d 2.0 -n 96000 -a 1 -l 16 -r signed -c 1 -o out -x -v 16 -m 1 --raw --limit -b 10";
    split(cmd0, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd1[] = "first --encoding PCM --frequency 500 --period 0.02 --sampling-frequency 48000 --duration 2.0 --total-samples 96000 --amplitude 1 --sample-length 16 --representation signed --channels 1 --output out --extensible --valid-bits 16 --channel-mask 1 --raw --limit --approx 10";
    split(cmd1, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd2[] = "first --note A2";
    split(cmd2, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd3[] = "first --output-name-format date";
    split(cmd3, argv, &argc);
    TEST_ASSERT_EQUAL_INT(0, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd4[] = "first -l 16 -v 20";
    split(cmd4, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd5[] = "first -m FR";
    split(cmd5, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd6[] = "first -z";
    split(cmd6, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd7[] = "first swav";
    split(cmd7, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);

    char cmd8[] = "first -l 15";
    split(cmd8, argv, &argc);
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
    reset(argv, &swavgen_config, 100);
}

void test_conversions() {
    int argc = 3;
    char* argv[3];
    swavgen_config_t swavgen_config = {0};

    argv[0] = "first";
    argv[1] = "--convert-double-to-PCM-8bit-signed";
    argv[2] = "1";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-16bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-24bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-32bit-signed";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-8bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-16bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-24bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-double-to-PCM-32bit-unsigned";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-PCM-16bit-signed-to-A-law";
    argv[2] = "0";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));

    argv[1] = "--convert-PCM-16bit-signed-to-Mu-law";
    argv[2] = "0";
    TEST_ASSERT_EQUAL_INT(1, get_options(argc, argv, &swavgen_config));
}

void test_set_defaults() {
    swavgen_config_t swavgen_config;
    set_defaults(&swavgen_config);
    TEST_ASSERT_EQUAL_INT(0, swavgen_config.approx);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_output_help);
    RUN_TEST(test_get_date_time);
    RUN_TEST(test_generate_file_name_ignore);
    RUN_TEST(test_generate_file_name_custom_format);
    RUN_TEST(test_generate_file_name_properties_format);
    RUN_TEST(test_generate_file_name_datetime_format);
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
    RUN_TEST(test_set_file_name_generator);
    RUN_TEST(test_get_music_note_frequency);
    RUN_TEST(test_set_file_name);
    RUN_TEST(test_get_channel_mask);
    RUN_TEST(test_get_representation);
    RUN_TEST(test_get_encoding);
    RUN_TEST(test_get_wave_type);
    RUN_TEST(test_get_options);
    RUN_TEST(test_conversions);
    RUN_TEST(test_set_defaults);

    return UNITY_END();
}
