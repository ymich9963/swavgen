/*
swavgen : Simple Wave Generator.
Copyright (C) 2024 Yiannis Michael (ymich9963)

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "swavgen.h"

void set_defaults(wave_prop_t* wave_prop) {
    strcpy(wave_prop->file_name, "wave.wav");
    wave_prop->a = 1.0f;
    wave_prop->duration = 2.0;                  // seconds
    wave_prop->f_s = 48000;                     // sample rate
    wave_prop->f = 800.0f;                      // wave frequency
    wave_prop->T = 1.0f/(wave_prop->f * 1e-3);  // wave period 
    wave_prop->channels = 1;
    wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration * wave_prop->channels;
    wave_prop->bytes_per_sample = 8;            // default to 64-bit samples
    wave_prop->representation = 's';            // default to signed representation
    wave_prop->type = 's';                      // sine wave
    strcpy(wave_prop->typestr, "sine");         // sine 
    wave_prop->encoding = WAVE_FORMAT_IEEE_FLOAT; // IEEE float
    strcpy(wave_prop->encodingstr, "IEEE-float"); // IEEE-float
    wave_prop->padding = 0;
    wave_prop->valid_bits = 8 * wave_prop->bytes_per_sample;
    wave_prop->channel_mask = 0;
    wave_prop->extensible = 0;
    wave_prop->raw = 0;
    wave_prop->limit = 0;
    wave_prop->approx = 0;
}

int get_options(int* argc, char** argv, wave_prop_t* wave_prop) {
    unsigned long lval = 0;
    unsigned long long llval = 0;
    float fval = 0;
    double lfval = 0;
    int ival;
    int16_t s16val;
    char strval[MAX_FILE_NAME];

    if (*argc == 1) {
        fprintf(stdout, WELCOME_STR);
        return 0;
    }
    if (*argc == 2) {
        if (!(strcmp("--version", argv[1]))) {
            fprintf(stdout, VERSION_STR);
            return 0;
        }
        if (!(strcmp("--help", argv[1]))) {
            output_help();
            return 0;
        }
    }

    for (int i = 1; i < *argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            CHECK_RES(sscanf(argv[i], "%s", strval));
            CHECK_RET(get_wave_type(argv[i], wave_prop));
            continue;
        }
        if (!(strcmp("-e", argv[i])) || !(strcmp("--encoding", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            CHECK_RET(get_encoding(strval, wave_prop));
            i++;
            continue;
        }
        if (!(strcmp("-f", argv[i])) || !(strcmp("--frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->f = fval;
            wave_prop->T = (1.0f/fval) * 1e3;
            i++;
            continue;
        }
        if (!(strcmp("-T", argv[i])) || !(strcmp("--period", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->T = fval;
            wave_prop->f = 1/(fval * 1e-3);
            i++;
            continue;
        }
        if (!(strcmp("-s", argv[i])) || !(strcmp("--sampling-frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%ld", &lval));
            CHECK_LIMITS_LONG(lval);
            wave_prop->f_s = lval;
            wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration * wave_prop->channels;
            i++;
            continue;
        }
        if (!(strcmp("-d", argv[i])) || !(strcmp("--duration", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->duration = fval;
            wave_prop->total_number_of_samples = wave_prop->f_s * wave_prop->duration * wave_prop->channels;
            i++;
            continue;
        }
        if (!(strcmp("-n", argv[i])) || !(strcmp("--total-samples", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lld", &llval));
            CHECK_LIMITS_LONG(llval);
            wave_prop->total_number_of_samples = llval;
            i++;
            continue;
        }
        if (!(strcmp("-a", argv[i])) || !(strcmp("--amplitude", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            wave_prop->a = fval;
            i++;
            continue;
        }
        if (!(strcmp("-l", argv[i])) || !(strcmp("--sample-length", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &ival));
            if (ival % 8) {
                fprintf(stderr, "\nPlease enter a sample length value divisble by 8.\n");
                return 1;
            }
            wave_prop->bytes_per_sample = ival / 8; // variable is called bytes but it's inputted as bits.
            wave_prop->valid_bits = ival;
            i++;
            continue;
        }
        if (!(strcmp("-r", argv[i])) || !(strcmp("--representation", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            CHECK_ERR(get_represenation(strval, wave_prop));
            i++;
            continue;
        }
        if (!(strcmp("-c", argv[i])) || !(strcmp("--channels", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &ival));
            CHECK_LIMITS_INT(ival);
            wave_prop->channels = ival; 
            i++;
            continue;
        }
        if (!(strcmp("-o", argv[i])) || !(strcmp("--output", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            strcpy(wave_prop->file_name, strval);
            i++;
            continue;
        }
        if (!(strcmp("-x", argv[i])) || !(strcmp("--extensible",argv[i]))) {
            wave_prop->extensible = 1;
            continue;
        }
        if (!(strcmp("-v", argv[i])) || !(strcmp("--valid-bits", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &ival));
            CHECK_LIMITS_INT(ival);
            wave_prop->valid_bits = ival;
            i++;
            continue;
        }
        if (!(strcmp("-m", argv[i])) || !(strcmp("--channel-mask", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            strcpy(wave_prop->channel_mask_str, strval);
            CHECK_ERR(get_channel_mask(strval, wave_prop));
            i++;
            continue;
        }
        if (!(strcmp("--raw", argv[i]))) {
            wave_prop->raw = 1;
            continue;
        }
        if (!(strcmp("--limit", argv[i]))) {
            wave_prop->limit = 1;
            continue;
        }
        if (!(strcmp("-b", argv[i])) || !(strcmp("--approx", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &ival));
            CHECK_LIMITS_INT(ival);
            wave_prop->approx = ival;
            i++;
            continue;
        }
        if (!(strcmp("--convert-double-to-PCM-8bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_8bit_signed(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-16bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_16bit_signed(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-24bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_24bit_signed(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-32bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_32bit_signed(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-8bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_8bit_unsigned(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-16bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_16bit_unsigned(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-24bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_24bit_unsigned(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-double-to-PCM-32bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_32bit_unsigned(&lfval));
            return 1;
        }
        if (!(strcmp("--convert-PCM-16bit-signed-to-A-law", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%hd", &s16val));
            printf("\nConverted %hd to %hhd\n", s16val, convert_pcm_16bit_signed_to_a_law(&s16val));
            return 1;
        }
        if (!(strcmp("--convert-PCM-16bit-signed-to-Mu-law", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%hd", &s16val));
            printf("\nConverted %hd to %hhd\n", s16val, convert_pcm_16bit_signed_to_mu_law(&s16val));
            return 1;
        }
        fprintf(stderr, "\nNo such option '%s'. Please check inputs.\n\n", argv[i]);
        return 1;
    }

    /* Need to check if valid bits are not more than 8 * bytes_per_sample 
     * Also need to check if settings are used that require the extenisble option
     * */
    if (wave_prop->valid_bits > wave_prop->bytes_per_sample * 8) {
        fprintf(stderr, "\nValid bits must not be more than the bits per sample.\n\n");
        return 1;
    }
    if (wave_prop->channel_mask != 0 && wave_prop->extensible == 0) {
        fprintf(stderr, "\nIf using channel masks, the extensible format must be enabled with '-x' or '--extensible'.\n\n");
        return 1;
    }

    return 0;
}

int get_wave_type(char* str, wave_prop_t* wave_prop) {

    if (!(strcmp("sine", str))) {
        wave_prop->type = 's';
    } else if (!(strcmp("square", str))) {
        wave_prop->type = 'q';
    } else if (!(strcmp("triangle", str))) {
        wave_prop->type = 't';
    } else if (!(strcmp("saw", str))) {
        wave_prop->type = 'w';
    } else if (!(strcmp("random", str))) {
        wave_prop->type = 'r';
    } else {
        fprintf(stderr, "\nUnknown wave type. Please enter either, 'sine', 'square', 'triangle', or 'saw'.\n");
        return 1;
    }
    strcpy(wave_prop->typestr, str);
    return 0;
}

int get_encoding(char* str, wave_prop_t* wave_prop) {

    if (!(strcmp("PCM", str))) {
        wave_prop->encoding = WAVE_FORMAT_PCM;
    } else if (!(strcmp("IEEE-float", str))) {
        wave_prop->encoding = WAVE_FORMAT_IEEE_FLOAT;
    } else if (!(strcmp("A-law", str))) {
        wave_prop->encoding = WAVE_FORMAT_ALAW;
    } else if (!(strcmp("Mu-law", str))) {
        wave_prop->encoding = WAVE_FORMAT_MULAW;
    } else {
        printf("\nUnknown encoding. Please enter either, 'PCM', 'IEEE-float', 'A-law', or 'Mu-law'.\n");
        return 1;
    }
    strcpy(wave_prop->encodingstr, str);
    return 0;
}

int get_represenation(char* str, wave_prop_t* wave_prop) {

    if (!(strcmp("signed", str))) {
        wave_prop->representation = 's';
        return 0;
    }
    if (!(strcmp("unsigned", str))) {
        wave_prop->representation = 'u';
        return 0;
    } else {
        fprintf(stderr, "\nUnknown binary representation. Please enter either, 'signed' or 'unsigned'.\n");
        return 1;
    }
}

int get_channel_mask(char* strval, wave_prop_t* wave_prop) {
    char* chp = strtok(strval,",.-");
    uint32_t mask = 0;
    while (chp != NULL) {
        if (!(strcmp("FL", chp))) {
            mask |= SPEAKER_FRONT_LEFT;
        }
        if (!(strcmp("FR", chp))) {
            mask |= SPEAKER_FRONT_RIGHT;
        }
        if (!(strcmp("FC", chp))) {
            mask |= SPEAKER_FRONT_CENTER;
        }
        if (!(strcmp("LF", chp))) {
            mask |= SPEAKER_LOW_FREQUENCY;
        }
        if (!(strcmp("BL", chp))) {
            mask |= SPEAKER_BACK_LEFT;
        }
        if (!(strcmp("BR", chp))) {
            mask |= SPEAKER_BACK_RIGHT;
        }
        if (!(strcmp("FLOC", chp))) {
            mask |= SPEAKER_FRONT_LEFT_OF_CENTER;
        }
        if (!(strcmp("FROC", chp))) {
            mask |= SPEAKER_FRONT_RIGHT_OF_CENTER;
        }
        if (!(strcmp("BC", chp))) {
            mask |= SPEAKER_BACK_CENTER;
        }
        if (!(strcmp("SL", chp))) {
            mask |= SPEAKER_SIDE_LEFT;
        }
        if (!(strcmp("SR", chp))) {
            mask |= SPEAKER_SIDE_RIGHT;
        }
        if (!(strcmp("TC", chp))) {
            mask |= SPEAKER_TOP_CENTER;
        }
        if (!(strcmp("TFL", chp))) {
            mask |= SPEAKER_TOP_FRONT_LEFT;
        }
        if (!(strcmp("TFC", chp))) {
            mask |= SPEAKER_TOP_FRONT_CENTER;
        }
        if (!(strcmp("TFR", chp))) {
            mask |= SPEAKER_TOP_FRONT_RIGHT;
        }
        if (!(strcmp("TBL", chp))) {
            mask |= SPEAKER_TOP_BACK_LEFT;
        }
        if (!(strcmp("TBC", chp))) {
            mask |= SPEAKER_TOP_BACK_CENTER;
        }
        if (!(strcmp("TBR", chp))) {
            mask |= SPEAKER_TOP_BACK_RIGHT;
        }
        if (!(strcmp("SPR", chp))) {
            mask |= SPEAKER_RESERVED;
        }
        chp = strtok (NULL, ",.-");
    }
    wave_prop->channel_mask = mask;
    return 0;
}

int set_type_encoding(wave_prop_t* wave_prop) {
    if (wave_prop->approx == 0) {
        switch (wave_prop->type) {
            case 's':
                wave_prop->wave = &create_sine;
                break;
            case 'q':
                wave_prop->wave = &create_square;
                break;
            case 't':
                wave_prop->wave = &create_triangle;
                break;
            case 'w':
                wave_prop->wave = &create_saw;
                break;
            case 'r':
                wave_prop->wave = &create_random;
                break;
            default:
                fprintf(stderr, "\nWave type '%c' not implemented.\n", wave_prop->type);
                return 1;
        }
    } else {
        switch (wave_prop->type) {
            case 's':
                wave_prop->wave = &create_sine;
                break;
            case 'q':
                wave_prop->wave = &create_square_approx;
                break;
            case 't':
                wave_prop->wave = &create_triangle_approx;
                break;
            case 'w':
                wave_prop->wave = &create_saw_approx;
                break;
            case 'r':
                wave_prop->wave = &create_random;
                break;
            default:
                fprintf(stderr, "\nWave type '%c' not implemented.\n", wave_prop->type);
                return 1;
        }
    }

    switch (wave_prop->encoding) {
        case WAVE_FORMAT_PCM:
            wave_prop->seth = &set_header_pcm;
            wave_prop->outp = &output_pcm;
            wave_prop->encd = &encode_pcm;
            break;
        case WAVE_FORMAT_IEEE_FLOAT:
            wave_prop->seth = &set_header_ieee_float;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_ieee_float;
            break;
        case WAVE_FORMAT_ALAW:
            wave_prop->seth = &set_header_a_law;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_companding;
            break;
        case WAVE_FORMAT_MULAW:
            wave_prop->seth = &set_header_mu_law;
            wave_prop->outp = &output_non_pcm;
            wave_prop->encd = &encode_companding;
            break;
        default:
            fprintf(stderr, "\nEncoding '%d' not implemented.\n", wave_prop->encoding);
            return 1;
    } 

    if (wave_prop->extensible) {
        wave_prop->seth = &set_header_extensible;
        wave_prop->outp = &output_extensible;
    }

    if (wave_prop->raw) {
        wave_prop->outp = &output_raw;
    }

    return 0;
}

void create_sine(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        (*samples)[n] = wave_prop->a * sin((2 * M_PI * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)));
    }
}

void create_square(double** samples, wave_prop_t* wave_prop) {
    double sample;
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        sample = sin(2 * M_PI * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels));
        (*samples)[n] = wave_prop->a * (double) sgn(&sample);
    }
}

void create_square_approx(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int k = 0; k <= wave_prop->approx; k++) {
        for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
            (*samples)[n] += wave_prop->a * sin(2 * M_PI * (2 * k + 1) * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) / (2 * k + 1);
        }
    }
}

void create_triangle(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    /* Two implementations. Not sure which one is best. */
    for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        (*samples)[n] = (2 * wave_prop->a / M_PI) * asin(sin(2 * M_PI * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)));
        /* (*samples)[n] = wave_prop->a * (4 * fabs(((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) - (int)(((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) + 0.5f )) - 1); */
    }
}

void create_triangle_approx(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int k = 0; k <= wave_prop->approx; k++) {
        for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
            (*samples)[n] += wave_prop->a * 8 * pow(-1, k) * sin(2 * M_PI * (2 * k + 1) * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) / pow((2 * k + 1) * M_PI, 2);
        }
    }
}

void create_saw(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    /* Two implementations. Not sure which one is best. */
    for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        /* (*samples)[n] = wave_prop->a * (((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) - (int)((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels))); */
        (*samples)[n] = wave_prop->a * (2 * (((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) - (int)(0.5f + ((double)wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)))));
    }
}

void create_saw_approx(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int k = 1; k <= wave_prop->approx; k++) {
        for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
            (*samples)[n] += -2 * wave_prop->a * pow(-1, k) * sin(2 * M_PI * k * wave_prop->f * n / (wave_prop->f_s * wave_prop->channels)) / (k * M_PI);
        } // encoding causes some samples to flip around, PCM encoding expects values of -1 to 1. Use float if that is not desired, but higher harmonics fix the issue, or amplitude = 0.5.
    }
}

void create_random(double** samples, wave_prop_t* wave_prop) {
    *samples = malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for (int n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        (*samples)[n] = (2 * (double)rand()/RAND_MAX) - 1;
    }
}

void check_limit(double* samples, wave_prop_t* wave_prop) {
    if (wave_prop->limit) {
        for (size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
            if (samples[n] > 1.0f) {
                samples[n] = 1.0f;
            }
            if (samples[n] < -1.0f) {
                samples[n] = -1.0f;
            }
        }
    }
}

char sgn(double* x) {
    return (*x >= 0) ? 1 : -1;
}

int fwrite_data(FILE * file, void* encoded_samples, wave_prop_t* wave_prop) {
    if (wave_prop->bytes_per_sample == 3) {
        int32_t val;
        for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
            val = ((int32_t*)encoded_samples)[n];
            CHECK_WRITE(fwrite(&val, 3, 1, file), 1);
        }
    } else {
        CHECK_WRITE(fwrite(encoded_samples, wave_prop->total_number_of_samples * wave_prop->bytes_per_sample * wave_prop->channels, 1, file), 1);
    }
    return 0;
}

int8_t convert_double_to_pcm_8bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S8BIT_MAX * *sample);
    } else {
        return -(S8BIT_MIN * *sample);
    }
}

int16_t convert_double_to_pcm_16bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S16BIT_MAX * *sample);
    } else {
        return -(S16BIT_MIN * *sample);
    }
}

int32_t convert_double_to_pcm_24bit_signed(double* sample) {
    if (*sample >= 0) {
        return S24BIT_MAX * *sample;
    } else {
        return S24BIT_MIN * *sample; // different from the rest due to actual variable type and not needing to account for overflow
    }
}

int32_t convert_double_to_pcm_32bit_signed(double* sample) {
    if (*sample >= 0) {
        return (S32BIT_MAX * *sample);
    } else {
        return -(S32BIT_MIN * *sample);
    }
}

uint8_t convert_double_to_pcm_8bit_unsigned(double* sample) {
    if (*sample >= 0) {
        return ((U8BIT_MAX-1)*0.5 * *sample) + (U8BIT_MAX+1)*0.5;
    } else {
        return ((U8BIT_MAX-1)*0.5 * *sample) + (U8BIT_MAX-1)*0.5;
    }
}

uint16_t convert_double_to_pcm_16bit_unsigned(double* sample) {
    if (*sample >= 0) {
        return ((U16BIT_MAX-1)*0.5 * *sample) + (U16BIT_MAX+1)*0.5;
    } else {
        return ((U16BIT_MAX-1)*0.5 * *sample) + (U16BIT_MAX-1)*0.5;
    }
}

uint32_t convert_double_to_pcm_24bit_unsigned(double* sample) {
    if (*sample >= 0) {
        return ((U24BIT_MAX-1)*0.5 * *sample) + (U24BIT_MAX+1)*0.5;
    } else {
        return ((U24BIT_MAX-1)*0.5 * *sample) + (U24BIT_MAX-1)*0.5;
    }
}


uint32_t convert_double_to_pcm_32bit_unsigned(double* sample) {
    if (*sample >= 0) {
        return ((U32BIT_MAX-1)*0.5 * *sample) + (U32BIT_MAX+1)*0.5;
    } else {
        return ((U32BIT_MAX-1)*0.5 * *sample) + (U32BIT_MAX-1)*0.5;
    }
}

void set_header_pcm(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* Set as NULL for it to not be unused */
    fact_chunk = (fact_chunk_t*) NULL;

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 16; 
    fmt_chunk->wFormatTag = wave_prop->encoding;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        wave_prop->padding = 1; 
    }
}

int encode_pcm(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    switch (wave_prop->representation) {
        case 's':
            switch (wave_prop->bytes_per_sample) {
                case 1:
                    encode_pcm_signed_8bit(samples, encoded_samples, wave_prop);
                    break;
                case 2:
                    encode_pcm_signed_16bit(samples, encoded_samples, wave_prop);
                    break;
                case 3:
                    encode_pcm_signed_24bit(samples, encoded_samples, wave_prop);
                    break;
                case 4:
                    encode_pcm_signed_32bit(samples, encoded_samples, wave_prop);
                    break;
                default:
                    fprintf(stderr, "\nSample bits must be 8, 16, 24, or 32 for PCM. Please specify with '-l' or '--sample-length'.\n");
                    return 1;
            }
            break;
        case 'u':
            switch (wave_prop->bytes_per_sample) {
                case 1:
                    encode_pcm_unsigned_8bit(samples, encoded_samples, wave_prop);
                    break;
                case 2:
                    encode_pcm_unsigned_16bit(samples, encoded_samples, wave_prop);
                    break;
                case 3:
                    encode_pcm_unsigned_24bit(samples, encoded_samples, wave_prop);
                    break;
                case 4:
                    encode_pcm_unsigned_32bit(samples, encoded_samples, wave_prop);
                    break;
                default:
                    fprintf(stderr, "\nSample bits must be 8, 16, 24, or 32 for PCM. Please specify with '-l' or '--sample-length'.\n");
                    return 1;
            }
            fprintf(stdout, "\n\nUnsigned %d-bit PCM isn't supported by the WAVE format but sure here you go:\n", wave_prop->bytes_per_sample);
            break;
        default:
            fprintf(stderr, "\nRepresentation not implemented. Please specify either 'signed' or 'unsigned' with '-r' or '--representation'.\n");
            return 1;
    }
    return 0;
}

void encode_pcm_signed_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (int8_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int8_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((int8_t*)*encoded_samples)[n] = convert_double_to_pcm_8bit_signed(&samples[n]);
    }
}

void encode_pcm_signed_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (int16_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int16_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((int16_t*)*encoded_samples)[n] = convert_double_to_pcm_16bit_signed(&samples[n]);
    }
}

void encode_pcm_signed_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (int32_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int32_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((int32_t*)*encoded_samples)[n] = convert_double_to_pcm_24bit_signed(&samples[n]);
    }
}

void encode_pcm_signed_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (int32_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int32_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((int32_t*)*encoded_samples)[n] = convert_double_to_pcm_32bit_signed(&samples[n]);
    }
}

void encode_pcm_unsigned_8bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (uint8_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(uint8_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((uint8_t*)*encoded_samples)[n] = convert_double_to_pcm_8bit_unsigned(&samples[n]);
    }
}

void encode_pcm_unsigned_16bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (uint16_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(uint16_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((uint16_t*)*encoded_samples)[n] = convert_double_to_pcm_16bit_unsigned(&samples[n]);
    }
}

void encode_pcm_unsigned_24bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (uint32_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(uint32_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((uint32_t*)*encoded_samples)[n] = convert_double_to_pcm_24bit_unsigned(&samples[n]);
    }
}

void encode_pcm_unsigned_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (uint32_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(uint32_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((uint32_t*)*encoded_samples)[n] = convert_double_to_pcm_32bit_unsigned(&samples[n]);
    }
}

void set_header_ieee_float(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = wave_prop->encoding;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        wave_prop->padding = 1; 
    }
}

int encode_ieee_float(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    switch (wave_prop->bytes_per_sample) {
        case 4:
            encode_ieee_float_32bit(samples, encoded_samples, wave_prop);
            break;
        case 8:
            encode_ieee_float_64bit(samples, encoded_samples, wave_prop);
            break;
        default:
            fprintf(stderr, "\nSample bits must be 32 or 64 for IEEE-float format. Please specify with '-l' or '--sample-length'.\n");
            return 1;
    }
    return 0;
}

void encode_ieee_float_32bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (float*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(float));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((float*)*encoded_samples)[n] = (float)samples[n];
    }
}

void encode_ieee_float_64bit(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    *encoded_samples = (double*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(double));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        ((double*)*encoded_samples)[n] = samples[n];
    }
}

void set_header_a_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = wave_prop->encoding;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample; // 8 bit data
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        wave_prop->padding = 1; 
    }
}

/* Read license in the ITU-T code and attribute accordingly. Mention that the code was changed (also change it more) and is based on that. */
int8_t convert_pcm_16bit_signed_to_a_law(int16_t* x) {
    int16_t ix, exp;
    int8_t out;

    ix = *x < 0          /* 0 <= ix < 2048 */
        ? (~(*x)) >> 4       /* 1's complement for negative values */
        : (*x) >> 4;

    /* Do more, if exponent > 0 */
    if (ix > 15) {              /* exponent=0 for ix <= 15 */
        exp = 1;                 /* first step: */
        while (ix > 16 + 15) {    /* find mantissa and exponent */
            ix >>= 1;
            exp++;
        }
        ix -= 16;                 /* second step: remove leading '1' */

        ix += exp << 4;          /* now compute encoded value */
    }
    if (*x >= 0)
        ix |= (0x0080);           /* add sign bit */

    out = ix ^ (0x0055);  /* toggle even bits */

    return out;
}

void encode_a_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    int16_t pcm_sample;
    *encoded_samples = (int8_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int8_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(&samples[n]);
        ((int8_t*)*encoded_samples)[n] = convert_pcm_16bit_signed_to_a_law(&pcm_sample);
    }
}

void set_header_mu_law(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = wave_prop->encoding;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        wave_prop->padding = 1; 
    }
}

/* Read license in the ITU-T code and attribute accordingly. Mention that the code was changed (also change it more) and is based on that. */
int8_t convert_pcm_16bit_signed_to_mu_law(int16_t *x) {
    int16_t segment;                  /* segment (Table 2/G711, column 1) */
    int16_t out;
    int16_t low_nibble, high_nibble;  /* low/high nibble of log companded sample */

    /* Change from 14 bit left justified to 14 bit right justified. 
     * Compute absolute value; adjust for easy processing */

    /* Compute 1's complement */
    short absval = *x < 0 ? ((~(*x)) >> 2) + 33 : ((*x) >> 2) + 33; /* Absolute value */     
    /* 33 is the difference value between the thresholds for A-law and u-law. */

    if (absval > (0x1FFF))       /* limit to < 8192 */
        absval = (0x1FFF);

    /* Determination of sample's segment */
    int16_t temp = absval >> 6;
    segment = 1;
    while (temp != 0) {
        segment++;
        temp >>= 1;
    }

    /* Mounting the high-nibble of the log-PCM sample */
    high_nibble = (0x0008) - segment;

    /* Mounting the low-nibble of the log PCM sample. Right shift of mantissa and masking away the leading '1' */
    low_nibble = (absval >> segment) & (0x000F);
    low_nibble = (0x000F) - low_nibble;

    /* Joining the high-nibble and the low-nibble of the log PCM sample */
    out = (high_nibble << 4) | low_nibble;

    /* Add sign bit */
    if (*x >= 0)
        out = out | (0x0080);

    return out;
}

void encode_mu_law(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    int16_t pcm_sample;
    *encoded_samples = (int8_t*) malloc(wave_prop->total_number_of_samples * wave_prop->channels * sizeof(int8_t));
    for(size_t n = 0; n < wave_prop->total_number_of_samples * wave_prop->channels; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(&samples[n]);
        ((int8_t*)*encoded_samples)[n] = convert_pcm_16bit_signed_to_mu_law(&pcm_sample);
    }
}

int encode_companding(double* samples, void** encoded_samples, wave_prop_t* wave_prop) {
    switch (wave_prop->encoding) {
        case WAVE_FORMAT_ALAW:
            encode_a_law(samples, encoded_samples, wave_prop);
            break;
        case WAVE_FORMAT_MULAW:
            encode_mu_law(samples, encoded_samples, wave_prop);
            break;
        default:
            return 1;
    }

    if (wave_prop->bytes_per_sample != 1) {
        fprintf(stdout, "\nProgram defaulted to 8 sample bits. No other option available for A-law/Mu-law.\n");
        wave_prop->bytes_per_sample = 1;
    }
    return 0;
}

void set_header_extensible(wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t* fact_chunk, data_chunk_t *data_chunk) {

    /* RIFF Chunk */
    strcpy(riff_chunk->chunkID, "RIFF");
    strcpy(riff_chunk->waveID, "WAVE");

    /* Format Chunk */
    strcpy(fmt_chunk->chunkID, "fmt ");
    fmt_chunk->chunk_size = 40;
    fmt_chunk->wFormatTag = WAVE_FORMAT_EXTENSIBLE;
    fmt_chunk->nChannels = wave_prop->channels;
    fmt_chunk->nSamplesPerSec = wave_prop->f_s;
    fmt_chunk->nAvgBytesPerSec = wave_prop->f_s * wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->nBlockAlign = wave_prop->channels * wave_prop->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * wave_prop->bytes_per_sample;
    fmt_chunk->cbSize = 22;
    fmt_chunk->wValidBitsPerSample = wave_prop->valid_bits;
    fmt_chunk->dwChannelMask = wave_prop->channel_mask; // from 0 to 4 294 967 295
    memcpy(fmt_chunk->SubFormat, "xx\x00\x00\x00\x00\x10\x00\x80\x00\x00\xAA\x00\x38\x9B\x71", 16); // xx gets replaced with the next line.
    memcpy(fmt_chunk->SubFormat, &wave_prop->encoding, 2);

    /* Fact Chunk */
    strcpy(fact_chunk->chunkID, "fact");
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = wave_prop->channels * wave_prop->total_number_of_samples;

    /* Data Chunk */
    strcpy(data_chunk->chunkID, "data");
    data_chunk->chunk_size = wave_prop->bytes_per_sample * wave_prop->channels * wave_prop->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        wave_prop->padding = 1; 
    }
}

int output_pcm(FILE * file, void* encoded_samples, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->cbSize) + sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat); 

    size_t used_fmt_chunk = sizeof(*fmt_chunk) - unused_fmt_chunk;

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + used_fmt_chunk + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * wave_prop->bytes_per_sample * wave_prop->channels) + wave_prop->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  used_fmt_chunk,  1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_RET(fwrite_data(file, encoded_samples, wave_prop));

    /* Padding added based on if the data chunk size is odd or even */
    if (wave_prop->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_non_pcm(FILE * file, void* encoded_samples, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat); 

    size_t used_fmt_chunk = sizeof(*fmt_chunk) - unused_fmt_chunk;

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + used_fmt_chunk + sizeof(*fact_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * wave_prop->bytes_per_sample * wave_prop->channels) + wave_prop->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  used_fmt_chunk,  1, file), 1);
    CHECK_WRITE(fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(encoded_samples, wave_prop->total_number_of_samples * wave_prop->bytes_per_sample * wave_prop->channels, 1, file), 1);

    /* Padding added based on if the data chunk size is odd or even */
    if (wave_prop->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_extensible(FILE * file, void* encoded_samples, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + sizeof(*fmt_chunk) + sizeof(*fact_chunk) + sizeof(*data_chunk) + (wave_prop->total_number_of_samples * wave_prop->bytes_per_sample * wave_prop->channels) + wave_prop->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  sizeof(fmt_chunk_t),  1, file), 1);
    CHECK_WRITE(fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_RET(fwrite_data(file, encoded_samples, wave_prop));

    /* Padding added based on if the data chunk size is odd or even */
    if (wave_prop->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_raw(FILE * file, void* encoded_samples, wave_prop_t* wave_prop, riff_chunk_t *riff_chunk, fmt_chunk_t *fmt_chunk, fact_chunk_t *fact_chunk, data_chunk_t *data_chunk) {

    CHECK_RET(fwrite_data(file, encoded_samples, wave_prop));

    /* Padding added based on if the data chunk size is odd or even */
    if (wave_prop->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_file_details(wave_prop_t* wave_prop) {
    printf("\n\tFile Name:\t%s"
            "\n\tWave Type:\t%s"
            "\n\tSize:\t\t%lld\t[Bytes]"
            "\n\tDuration:\t%.4f\t[s]"
            "\n\tEncoding:\t%s"
            "\n\tSampling Freq.:\t%u\t[Hz]"
            "\n\tTone Freq.:\t%.3f\t[Hz]"
            "\n\tWave Period:\t%.4f\t[ms]"
            "\n\tTotal Samples:\t%lld"
            "\n\tChannels:\t%d"
            "\n\tSample Length:\t%d\t[bits]"
            , wave_prop->file_name, wave_prop->typestr, wave_prop->size, wave_prop->duration, wave_prop->encodingstr, wave_prop->f_s, wave_prop->f, wave_prop->T, wave_prop->total_number_of_samples, wave_prop->channels, wave_prop->bytes_per_sample * 8);

    printf(wave_prop->extensible == 1 ? 
            "\n\tChannel Mask:\t%s"
            : "\r"
            , wave_prop->channel_mask_str);

    printf("\n\n");

    return 0;
}

int output_help() {
    printf("\n\n"
            "General usage,\n"
            "'swavgen <Wave Type> [<Options>]', with an ability to choose between 'sine', 'square', 'triangle', 'saw' wave types.\n\n"
            "Available options are,\n"
            "\t-e,\t--encoding <Encoding>\t= Encoding used for sampled data. Available encodings are IEEE-float (64/32-bit), PCM (signed/unsigned 8/16/24/32-bit), A/Mu-law.\n"
            "\t-f,\t--frequency <Frequency [Hz]>\t= Input the wave frequency in Hertz.\n"
            "\t-T,\t--period <Time [ms]>\t= Input the wave period in milliseconds.\n"
            "\t-s,\t--sampling-frequency <Frequency [Hz]>\t= Wave sampling frequency in Hertz.\n"
            "\t-d,\t--duration <Time [s]>\t= Wave duration in seconds.\n"
            "\t-n,\t--total-samples <Samples>\t= Wave total samples. Gets calculated in the tool with sampling frequency, duaration, and channels. Specifying any of those three options and also specifying the total samples can lead to issues.\n"
            "\t-a,\t--amplitude <Amplitude>\t= Wave amplitude. Affects the amplitude of the generated wave before encoding, therefore it can have some strange effects in the encodings that expect values of -1 to +1.\n"
            "\t-l,\t--sample-length <Length [bits]>\t= Encoded wave sample length in bits. Must be divisible by 8.\n"
            "\t-r,\t--representation <Representation>\t= Choose between 'signed' and 'unsigned' PCM encoding.\n"
            "\t-c,\t--channels <Channels>\t= Choose the number of channels to be created.\n"
            "\t-o,\t--output <File Name>\t= Specify the output file name.\n"
            "\t-x,\t--extensible\t= Enable the extensible format type for WAV. Mandatory when specifying a channel mask or valid bits but otherwise only necessary for some media players.\n"
            "\t-v,\t--valid-bits <Valid Bits [bits]>\t= Valid bits in the sample. Doesn't seem to do anything and is purely informational. Must be less than the sample length.\n"
            "\t-m,\t--channel-mask <Channel Mask Code>\t= Specify the channel mask to be used for panning. The number of speaker locations specified should be the same as the number of channels. For example with '-c 2' an option of '-m FR,FL' should be used. All channel mask options are listed below, and should be separated with a comma, dash, or dot.\n"
            "\t\t--raw\t= Output the data with no header information. Useful for only getting the data of the generated wave.\n"
            "\t\t--limit\t= Enable limiting so that the generated wave is limited from -1 to +1 prior to encoding.\n"
            "\t-b,\t--approx <Number of Waves>\t= Specify the using an amount of approximated waves using additive synthesis instead of pure digitally created waves.\n"
            );

    printf("\n\n\t\t\tCHANNEL MASK CODES\n\n"
            "\t\tFront Left\t\tFL\n"
            "\t\tFront Right\t\tFR\n"
            "\t\tFront Centre\t\tFC\n"
            "\t\tLow Frequency\t\tLF\n"
            "\t\tBack Left\t\tBL\n"
            "\t\tBack Right\t\tBR\n"
            "\t\tFront Left Of Centre\tFLOC\n"
            "\t\tFront Right Of Centre\tFROC\n"
            "\t\tBack Centre\t\tBC\n"
            "\t\tSide Left\t\tSL\n"
            "\t\tSide Right\t\tSR\n"
            "\t\tTop Center\t\tTC\n"
            "\t\tTop Front Left\t\tTFL\n"
            "\t\tTop Front Center\tTFC\n"
            "\t\tTop Front Right\t\tTFR\n"
            "\t\tTop Back Left\t\tTBL\n"
            "\t\tTop Back Center\t\tTBC\n"
            "\t\tTop Back Right\t\tTBR\n"
            "\t\tSpeaker Reserved\tSPR\n"
            "\n\nNotes: Experimentally it was found that combinations from FL to SR work with headphones, therefore a max of 11 channels can be used with a channel mask. Also, channel mask does not affect the number of channels, but if using a channel mask of TC and above, the channels covered by the TC< channel masks will not be played, even though the data is there. Swavgen has not been used on other speaker systems so it is unknown if this changes depending on what the generated wave is played.\n\n");

    printf("\n\n\t\t\tCONVERSION HELPERS\n\n"
            "\t\t--convert-double-to-PCM-8bit-signed <Value>\n"
            "\t\t--convert-double-to-PCM-16bit-signed <Value>\n"
            "\t\t--convert-double-to-PCM-24bit-signed <Value>\n"
            "\t\t--convert-double-to-PCM-32bit-signed <Value>\n"
            "\t\t--convert-double-to-PCM-8bit-unsigned <Value>\n"
            "\t\t--convert-double-to-PCM-16bit-unsigned <Value>\n"
            "\t\t--convert-double-to-PCM-24bit-unsigned <Value>\n"
            "\t\t--convert-double-to-PCM-32bit-unsigned <Value>\n"
            "\t\nNote: <Value> must be between +1 and -1."
            "\n\n"
            "\t\t--convert-PCM-16bit-signed-to-A-law <Value>\n"
            "\t\t--convert-PCM-16bit-signed-to-Mu-law <Value>\n"
            "\t\nNote: <Value> must be between %hd and %hd.\n\n"
            , S16BIT_MAX, S16BIT_MIN);
    return 0;
}

