#include "unity/unity.h"
#include "../swavgen.h"
#include "unity/unity_internals.h"
#include <stdio.h>

void setUp() {}

void tearDown() {
    fflush(stdout);
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

   output_file_details(&wave_prop);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_output_file_details);
    return UNITY_END();
}
