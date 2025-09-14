/*
    swavgen : Simple Wave Generator.
    Copyright (C) 2024 Yiannis Michael (ymich9963)

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "swavgen.h"

void set_defaults(swavgen_config_t* restrict swavgen_config)
{
    swavgen_config->a = 1.0f;
    swavgen_config->f = 440.0f;                      // wave frequency
    swavgen_config->f_s = 48000;                     // sample rate
    swavgen_config->duration = 2.0;                  // seconds
    swavgen_config->T = 1.0f / swavgen_config->f;   // wave period
    swavgen_config->channels = 1;
    swavgen_config->total_number_of_samples = swavgen_config->f_s * swavgen_config->duration * swavgen_config->channels;

    swavgen_config->file_name[0] = 0;
    swavgen_config->fgen = &generate_file_name_properties_format;

    strcpy(swavgen_config->representationstr, "signed"); 
    strcpy(swavgen_config->channel_mask_str, "none"); 
    strcpy(swavgen_config->encodingstr, "IEEE-float"); 
    strcpy(swavgen_config->music_note, "N0N"); 

    swavgen_config->encoding = WAVE_FORMAT_IEEE_FLOAT; // IEEE float
    swavgen_config->bytes_per_sample = 8;            // default to 64-bit samples
    swavgen_config->valid_bits = 8 * swavgen_config->bytes_per_sample;
    swavgen_config->channel_mask = 0;

    swavgen_config->approx = 0;

    swavgen_config->type = 0;
    swavgen_config->representation = 's';            // default to signed representation
    swavgen_config->padding = 0;
    swavgen_config->extensible = 0;
    swavgen_config->raw = 0;
    swavgen_config->limit = 0;
}

int get_options(int argc, char** restrict argv, swavgen_config_t* restrict swavgen_config)
{
    unsigned long lval = 0;
    unsigned long long llval = 0;
    float fval = 0;
    double lfval = 0;
    int32_t i32val = 0;
    int16_t s16val = 0;
    char strval[MAX_STRING];

    /* Initialise */
    memset(strval, '\0', sizeof(char) * MAX_STRING);

    if (argc == 1) {
        fprintf(stdout, WELCOME_STR);

        return 1;
    }

    if (argc == 2) {
        if (!(strcmp("--version", argv[1]))) {
            fprintf(stdout, VERSION_STR);

            return 1;
        }

        if (!(strcmp("--help", argv[1]))) {
            output_help();

            return 1;
        }
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            CHECK_RES(sscanf(argv[i], "%s", strval));
            CHECK_RET(get_wave_type(argv[i], swavgen_config->typestr, &swavgen_config->type));
            continue;
        }

        if (!(strcmp("-e", argv[i])) || !(strcmp("--encoding", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            CHECK_RET(get_encoding(strval, swavgen_config->encodingstr, &swavgen_config->encoding));
            i++;
            continue;
        }

        if (!(strcmp("-f", argv[i])) || !(strcmp("--frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            swavgen_config->f = fval;
            swavgen_config->T = (1.0f / fval) * 1e3;
            i++;
            continue;
        }

        if (!(strcmp("-T", argv[i])) || !(strcmp("--period", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            swavgen_config->T = fval;
            swavgen_config->f = 1 / (fval * 1e-3);
            i++;
            continue;
        }

        if (!(strcmp("-s", argv[i])) || !(strcmp("--sampling-frequency", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%ld", &lval));
            CHECK_LIMITS_LONG(lval);
            swavgen_config->f_s = lval;
            swavgen_config->total_number_of_samples = swavgen_config->f_s * swavgen_config->duration * swavgen_config->channels;
            i++;
            continue;
        }

        if (!(strcmp("-d", argv[i])) || !(strcmp("--duration", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            swavgen_config->duration = fval;
            swavgen_config->total_number_of_samples = swavgen_config->f_s * swavgen_config->duration * swavgen_config->channels;
            i++;
            continue;
        }

        if (!(strcmp("-n", argv[i])) || !(strcmp("--total-samples", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lld", &llval));
            CHECK_LIMITS_LONG(llval);
            swavgen_config->total_number_of_samples = llval;
            i++;
            continue;
        }

        if (!(strcmp("-a", argv[i])) || !(strcmp("--amplitude", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%f", &fval));
            CHECK_LIMITS_FLOAT(fval);
            swavgen_config->a = fval;
            i++;
            continue;
        }

        if (!(strcmp("-l", argv[i])) || !(strcmp("--sample-length", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &i32val));

            if (i32val % 8) {
                fprintf(stderr, "\nPlease enter a sample length value divisble by 8.\n");

                return 1;
            }

            swavgen_config->bytes_per_sample = i32val / 8; // variable is called bytes but it's inputted as bits.
            swavgen_config->valid_bits = i32val;
            i++;
            continue;
        }

        if (!(strcmp("-r", argv[i])) || !(strcmp("--representation", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            CHECK_ERR(get_represenation(strval, swavgen_config->representationstr, &swavgen_config->representation));
            i++;
            continue;
        }

        if (!(strcmp("-c", argv[i])) || !(strcmp("--channels", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &i32val));
            CHECK_LIMITS_INT(i32val);
            swavgen_config->channels = i32val;
            i++;
            continue;
        }

        if (!(strcmp("-m", argv[i])) || !(strcmp("--channel-mask", argv[i]))) {
            get_channel_mask(argv[i + 1], swavgen_config->channel_mask_str, &swavgen_config->channel_mask);
            CHECK_LIMITS_INT(i32val);
            swavgen_config->channels = i32val;
            i++;
            continue;
        }

        if (!(strcmp("-o", argv[i])) || !(strcmp("--output", argv[i]))) {
            CHECK_ERR(set_file_name(swavgen_config->file_name, argv[i + 1]));
            swavgen_config->fgen = &generate_file_name_ignore;
            i++;
            continue;
        }

        if (!(strcmp("-x", argv[i])) || !(strcmp("--extensible", argv[i]))) {
            swavgen_config->extensible = 1;
            continue;
        }

        if (!(strcmp("-v", argv[i])) || !(strcmp("--valid-bits", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &i32val));
            CHECK_LIMITS_INT(i32val);
            swavgen_config->valid_bits = i32val;
            i++;
            continue;
        }

        if (!(strcmp("--note", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%s", strval));
            memcpy(swavgen_config->music_note, strval, sizeof(char) * 3);
            CHECK_ERR(get_music_note_frequency(swavgen_config->music_note, &swavgen_config->f));
            i++;
            continue;
        }

        if (!(strcmp("--raw", argv[i]))) {
            swavgen_config->raw = 1;
            continue;
        }

        if (!(strcmp("--limit", argv[i]))) {
            swavgen_config->limit = 1;
            continue;
        }

        if (!(strcmp("-b", argv[i])) || !(strcmp("--approx", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%d", &i32val));
            CHECK_LIMITS_INT(i32val);
            swavgen_config->approx = i32val;
            i++;
            continue;
        }

        if (!(strcmp("--output-name-format", argv[i]))) {
            set_file_name_generator(swavgen_config, argv[i + 1]);
            i++;
            continue;
        }

        if (!(strcmp("--convert-double-to-PCM-8bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_8bit_signed(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-16bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_16bit_signed(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-24bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_24bit_signed(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-32bit-signed", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_32bit_signed(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-8bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_8bit_unsigned(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-16bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_16bit_unsigned(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-24bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_24bit_unsigned(lfval));

            return 1;
        }

        if (!(strcmp("--convert-double-to-PCM-32bit-unsigned", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%lf", &lfval));
            CHECK_LIMITS_CONV(lfval);
            printf("\nConverted %lf to %d\n", lfval, convert_double_to_pcm_32bit_unsigned(lfval));

            return 1;
        }

        if (!(strcmp("--convert-PCM-16bit-signed-to-A-law", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%hd", &s16val));
            printf("\nConverted %hd to %hhd\n", s16val, convert_pcm_16bit_signed_to_a_law(s16val));

            return 1;
        }

        if (!(strcmp("--convert-PCM-16bit-signed-to-Mu-law", argv[i]))) {
            CHECK_RES(sscanf(argv[i + 1], "%hd", &s16val));
            printf("\nConverted %hd to %hhd\n", s16val, convert_pcm_16bit_signed_to_mu_law(s16val));

            return 1;
        }

        fprintf(stderr, "\nNo such option '%s'. Please check inputs.\n\n", argv[i]);

        return 1;
    }

    /* Need to check if valid bits are not more than 8 * bytes_per_sample
     * Also need to check if settings are used that require the extenisble option
     * */
    if (swavgen_config->valid_bits > swavgen_config->bytes_per_sample * 8) {
        fprintf(stderr, "\nValid bits must not be more than the bits per sample.\n\n");

        return 1;
    }

    if (swavgen_config->channel_mask != 0 && swavgen_config->extensible == 0) {
        fprintf(stderr, "\nIf using channel masks, the extensible format must be enabled with '-x' or '--extensible'.\n\n");

        return 1;
    }

    return 0;
}

int get_wave_type(char* restrict str, char* restrict typestr, char* type)
{
    *type = '\0';

    if (!(strcmp("sine", str))) {
        *type = 's';
    }
    if (!(strcmp("square", str))) {
        *type = 'q';
    }
    if (!(strcmp("triangle", str))) {
        *type = 't';
    }
    if (!(strcmp("saw", str))) {
        *type = 'w';
    }
    if (!(strcmp("random", str))) {
        *type = 'r';
    }

    if (!(*type)){
        fprintf(stderr, "\nUnknown wave type. Please enter either, 'sine', 'square', 'triangle', or 'saw'.\n");

        return 1;
    }

    if (strlen(str) < MAX_TYPE_STRING) {
        strcpy(typestr, str);
    }

    return 0;
}

int get_encoding(char* restrict str, char* restrict encodingstr, uint16_t* restrict encoding)
{
    *encoding = 0;

    if (!(strcmp("PCM", str))) {
        *encoding = WAVE_FORMAT_PCM;
    } 
    if (!(strcmp("IEEE-float", str))) {
        *encoding = WAVE_FORMAT_IEEE_FLOAT;
    }
    if (!(strcmp("A-law", str))) {
        *encoding = WAVE_FORMAT_ALAW;
    }
    if (!(strcmp("Mu-law", str))) {
        *encoding = WAVE_FORMAT_MULAW;
    } 

    if (!(*encoding)) {
        printf("\nUnknown encoding. Please enter either, 'PCM', 'IEEE-float', 'A-law', or 'Mu-law'.\n");

        return 1;
    }

    if (strlen(str) < MAX_ENC_STRING) {
        strcpy(encodingstr, str);
    }

    return 0;
}

int get_represenation(char* restrict str, char* restrict representationstr, char* restrict representation)
{
    *representation = '\0';

    if (!(strcmp("signed", str))) {
        *representation = 's';

    }

    if (!(strcmp("unsigned", str))) {
        *representation = 'u';

    } 

    if (!(*representation)) {
        fprintf(stderr, "\nUnknown binary representation. Please enter either, 'signed' or 'unsigned'.\n");

        return 1;
    }

    if (strlen(str) < MAX_REPR_STRING) {
        strcpy(representationstr, str);
    }

    return 0;
}

int get_channel_mask(char* restrict str, char* restrict channel_mask_str, uint32_t* restrict channel_mask)
{
    char* channel_mask_token = strtok(str, ",.-");
    uint32_t mask = 0;

    while (channel_mask_token != NULL) {
        if (!(strcmp("FL", channel_mask_token))) {
            mask |= SPEAKER_FRONT_LEFT;
        }

        if (!(strcmp("FR", channel_mask_token))) {
            mask |= SPEAKER_FRONT_RIGHT;
        }

        if (!(strcmp("FC", channel_mask_token))) {
            mask |= SPEAKER_FRONT_CENTER;
        }

        if (!(strcmp("LF", channel_mask_token))) {
            mask |= SPEAKER_LOW_FREQUENCY;
        }

        if (!(strcmp("BL", channel_mask_token))) {
            mask |= SPEAKER_BACK_LEFT;
        }

        if (!(strcmp("BR", channel_mask_token))) {
            mask |= SPEAKER_BACK_RIGHT;
        }

        if (!(strcmp("FLOC", channel_mask_token))) {
            mask |= SPEAKER_FRONT_LEFT_OF_CENTER;
        }

        if (!(strcmp("FROC", channel_mask_token))) {
            mask |= SPEAKER_FRONT_RIGHT_OF_CENTER;
        }

        if (!(strcmp("BC", channel_mask_token))) {
            mask |= SPEAKER_BACK_CENTER;
        }

        if (!(strcmp("SL", channel_mask_token))) {
            mask |= SPEAKER_SIDE_LEFT;
        }

        if (!(strcmp("SR", channel_mask_token))) {
            mask |= SPEAKER_SIDE_RIGHT;
        }

        if (!(strcmp("TC", channel_mask_token))) {
            mask |= SPEAKER_TOP_CENTER;
        }

        if (!(strcmp("TFL", channel_mask_token))) {
            mask |= SPEAKER_TOP_FRONT_LEFT;
        }

        if (!(strcmp("TFC", channel_mask_token))) {
            mask |= SPEAKER_TOP_FRONT_CENTER;
        }

        if (!(strcmp("TFR", channel_mask_token))) {
            mask |= SPEAKER_TOP_FRONT_RIGHT;
        }

        if (!(strcmp("TBL", channel_mask_token))) {
            mask |= SPEAKER_TOP_BACK_LEFT;
        }

        if (!(strcmp("TBC", channel_mask_token))) {
            mask |= SPEAKER_TOP_BACK_CENTER;
        }

        if (!(strcmp("TBR", channel_mask_token))) {
            mask |= SPEAKER_TOP_BACK_RIGHT;
        }

        if (!(strcmp("SPR", channel_mask_token))) {
            mask |= SPEAKER_RESERVED;
        }

        channel_mask_token = strtok(NULL, ",.-");
    }

    *channel_mask = mask;
    if (strlen(str) < MAX_CHAN_STRING) {
        strcpy(channel_mask_str, str);
    }

    return 0;
}

int set_file_name(char* restrict file_name, char* restrict str)
{
    if (strlen(str) < MAX_STRING) {
        strcpy(file_name, str);
    } else {
        fprintf(stderr, "\nOutput file name is too long, needs to be less than %d characters.\n", MAX_STRING);

        return 1;
    }

    return 0;
}

int get_music_note_frequency(char music_note[MAX_NOTE_STRING], double* restrict f)
{
    *f = 0.0f;

    if (!(strcmp("C0", music_note))) {
        *f = C0;
    } 
    if (!(strcmp("C#0", music_note)) || !(strcmp("Db0", music_note))) {
        *f = Cs_Db0;
    }
    if (!(strcmp("D0", music_note))) {
        *f = D0;
    }
    if (!(strcmp("D#0", music_note)) || !(strcmp("Eb0", music_note))) {
        *f = Ds_Eb0;
    }
    if (!(strcmp("E0", music_note))) {
        *f = E0;
    }
    if (!(strcmp("F0", music_note))) {
        *f = F0;
    }
    if (!(strcmp("F#0", music_note)) || !(strcmp("Gb0", music_note))) {
        *f = Fs_Gb0;
    }
    if (!(strcmp("G0", music_note))) {
        *f = G0;
    }
    if (!(strcmp("G#0", music_note)) || !(strcmp("Ab0", music_note))) {
        *f = Gs_Ab0;
    }
    if (!(strcmp("A0", music_note))) {
        *f = A0;
    }
    if (!(strcmp("A#0", music_note)) || !(strcmp("Bb0", music_note))) {
        *f = As_Bb0;
    }
    if (!(strcmp("B0", music_note))) {
        *f = B0;
    }
    if (!(strcmp("C1", music_note))) {
        *f = C1;
    }
    if (!(strcmp("C#1", music_note)) || !(strcmp("Db1", music_note))) {
        *f = Cs_Db1;
    }
    if (!(strcmp("D1", music_note))) {
        *f = D1;
    }
    if (!(strcmp("D#1", music_note)) || !(strcmp("Eb1", music_note))) {
        *f = Ds_Eb1;
    }
    if (!(strcmp("E1", music_note))) {
        *f = E1;
    }
    if (!(strcmp("F1", music_note))) {
        *f = F1;
    }
    if (!(strcmp("F#1", music_note)) || !(strcmp("Gb1", music_note))) {
        *f = Fs_Gb1;
    }
    if (!(strcmp("G1", music_note))) {
        *f = G1;
    }
    if (!(strcmp("G#1", music_note)) || !(strcmp("Ab1", music_note))) {
        *f = Gs_Ab1;
    }
    if (!(strcmp("A1", music_note))) {
        *f = A1;
    }
    if (!(strcmp("A#1", music_note)) || !(strcmp("Bb1", music_note))) {
        *f = As_Bb1;
    }
    if (!(strcmp("B1", music_note))) {
        *f = B1;
    }
    if (!(strcmp("C2", music_note))) {
        *f = C2;
    }
    if (!(strcmp("C#2", music_note)) || !(strcmp("Db2", music_note))) {
        *f = Cs_Db2;
    }
    if (!(strcmp("D2", music_note))) {
        *f = D2;
    }
    if (!(strcmp("D#2", music_note)) || !(strcmp("Eb2", music_note))) {
        *f = Ds_Eb2;
    }
    if (!(strcmp("E2", music_note))) {
        *f = E2;
    }
    if (!(strcmp("F2", music_note))) {
        *f = F2;
    }
    if (!(strcmp("F#2", music_note)) || !(strcmp("Gb2", music_note))) {
        *f = Fs_Gb2;
    }
    if (!(strcmp("G2", music_note))) {
        *f = G2;
    }
    if (!(strcmp("G#2", music_note)) || !(strcmp("Ab2", music_note))) {
        *f = Gs_Ab2;
    }
    if (!(strcmp("A2", music_note))) {
        *f = A2;
    }
    if (!(strcmp("A#2", music_note)) || !(strcmp("Bb2", music_note))) {
        *f = As_Bb2;
    }
    if (!(strcmp("B2", music_note))) {
        *f = B2;
    }
    if (!(strcmp("C3", music_note))) {
        *f = C3;
    }
    if (!(strcmp("C#3", music_note)) || !(strcmp("Db3", music_note))) {
        *f = Cs_Db3;
    }
    if (!(strcmp("D3", music_note))) {
        *f = D3;
    }
    if (!(strcmp("D#3", music_note)) || !(strcmp("Eb3", music_note))) {
        *f = Ds_Eb3;
    }
    if (!(strcmp("E3", music_note))) {
        *f = E3;
    }
    if (!(strcmp("F3", music_note))) {
        *f = F3;
    }
    if (!(strcmp("F#3", music_note)) || !(strcmp("Gb3", music_note))) {
        *f = Fs_Gb3;
    }
    if (!(strcmp("G3", music_note))) {
        *f = G3;
    }
    if (!(strcmp("G#3", music_note)) || !(strcmp("Ab3", music_note))) {
        *f = Gs_Ab3;
    }
    if (!(strcmp("A3", music_note))) {
        *f = A3;
    }
    if (!(strcmp("A#3", music_note)) || !(strcmp("Bb3", music_note))) {
        *f = As_Bb3;
    }
    if (!(strcmp("B3", music_note))) {
        *f = B3;
    } 
    if (!(strcmp("C4", music_note))) {
        *f = C4;
    } 
    if (!(strcmp("C#4", music_note)) || !(strcmp("Db4", music_note))) {
        *f = Cs_Db4;
    }
    if (!(strcmp("D4", music_note))) {
        *f = D4;
    }
    if (!(strcmp("D#4", music_note)) || !(strcmp("Eb4", music_note))) {
        *f = Ds_Eb4;
    }
    if (!(strcmp("E4", music_note))) {
        *f = E4;
    }
    if (!(strcmp("F4", music_note))) {
        *f = F4;
    }
    if (!(strcmp("F#4", music_note)) || !(strcmp("Gb4", music_note))) {
        *f = Fs_Gb4;
    }
    if (!(strcmp("G4", music_note))) {
        *f = G4;
    }
    if (!(strcmp("G#4", music_note)) || !(strcmp("Ab4", music_note))) {
        *f = Gs_Ab4;
    }
    if (!(strcmp("A4", music_note))) {
        *f = A4;
    }
    if (!(strcmp("A#4", music_note)) || !(strcmp("Bb4", music_note))) {
        *f = As_Bb4;
    }
    if (!(strcmp("B4", music_note))) {
        *f = B4;
    }
    if (!(strcmp("C5", music_note))) {
        *f = C5;
    }
    if (!(strcmp("C#5", music_note)) || !(strcmp("Db5", music_note))) {
        *f = Cs_Db5;
    }
    if (!(strcmp("D5", music_note))) {
        *f = D5;
    }
    if (!(strcmp("D#5", music_note)) || !(strcmp("Eb5", music_note))) {
        *f = Ds_Eb5;
    }
    if (!(strcmp("E5", music_note))) {
        *f = E5;
    }
    if (!(strcmp("F5", music_note))) {
        *f = F5;
    }
    if (!(strcmp("F#5", music_note)) || !(strcmp("Gb5", music_note))) {
        *f = Fs_Gb5;
    }
    if (!(strcmp("G5", music_note))) {
        *f = G5;
    }
    if (!(strcmp("G#5", music_note)) || !(strcmp("Ab5", music_note))) {
        *f = Gs_Ab5;
    }
    if (!(strcmp("A5", music_note))) {
        *f = A5;
    }
    if (!(strcmp("A#5", music_note)) || !(strcmp("Bb5", music_note))) {
        *f = As_Bb5;
    }
    if (!(strcmp("B5", music_note))) {
        *f = B5;
    }
    if (!(strcmp("C6", music_note))) {
        *f = C6;
    }
    if (!(strcmp("C#6", music_note)) || !(strcmp("Db6", music_note))) {
        *f = Cs_Db6;
    }
    if (!(strcmp("D6", music_note))) {
        *f = D6;
    }
    if (!(strcmp("D#6", music_note)) || !(strcmp("Eb6", music_note))) {
        *f = Ds_Eb6;
    }
    if (!(strcmp("E6", music_note))) {
        *f = E6;
    }
    if (!(strcmp("F6", music_note))) {
        *f = F6;
    }
    if (!(strcmp("F#6", music_note)) || !(strcmp("Gb6", music_note))) {
        *f = Fs_Gb6;
    }
    if (!(strcmp("G6", music_note))) {
        *f = G6;
    }
    if (!(strcmp("G#6", music_note)) || !(strcmp("Ab6", music_note))) {
        *f = Gs_Ab6;
    }
    if (!(strcmp("A6", music_note))) {
        *f = A6;
    }
    if (!(strcmp("A#6", music_note)) || !(strcmp("Bb6", music_note))) {
        *f = As_Bb6;
    }
    if (!(strcmp("B6", music_note))) {
        *f = B6;
    }
    if (!(strcmp("C7", music_note))) {
        *f = C7;
    }
    if (!(strcmp("C#7", music_note)) || !(strcmp("Db7", music_note))) {
        *f = Cs_Db7;
    }
    if (!(strcmp("D7", music_note))) {
        *f = D7;
    }
    if (!(strcmp("D#7", music_note)) || !(strcmp("Eb7", music_note))) {
        *f = Ds_Eb7;
    }
    if (!(strcmp("E7", music_note))) {
        *f = E7;
    }
    if (!(strcmp("F7", music_note))) {
        *f = F7;
    }
    if (!(strcmp("F#7", music_note)) || !(strcmp("Gb7", music_note))) {
        *f = Fs_Gb7;
    }
    if (!(strcmp("G7", music_note))) {
        *f = G7;
    }
    if (!(strcmp("G#7", music_note)) || !(strcmp("Ab7", music_note))) {
        *f = Gs_Ab7;
    }
    if (!(strcmp("A7", music_note))) {
        *f = A7;
    }
    if (!(strcmp("A#7", music_note)) || !(strcmp("Bb7", music_note))) {
        *f = As_Bb7;
    }
    if (!(strcmp("B7", music_note))) {
        *f = B7;
    } 
    if (!(strcmp("C8", music_note))) {
        *f = C8;
    }
    if (!(strcmp("C#8", music_note)) || !(strcmp("Db8", music_note))) {
        *f = Cs_Db8;
    }
    if (!(strcmp("D8", music_note))) {
        *f = D8;
    }
    if (!(strcmp("D#8", music_note)) || !(strcmp("Eb8", music_note))) {
        *f = Ds_Eb8;
    }
    if (!(strcmp("E8", music_note))) {
        *f = E8;
    }
    if (!(strcmp("F8", music_note))) {
        *f = F8;
    }
    if (!(strcmp("F#8", music_note)) || !(strcmp("Gb8", music_note))) {
        *f = Fs_Gb8;
    }
    if (!(strcmp("G8", music_note))) {
        *f = G8;
    }
    if (!(strcmp("G#8", music_note)) || !(strcmp("Ab8", music_note))) {
        *f = Gs_Ab8;
    }
    if (!(strcmp("A8", music_note))) {
        *f = A8;
    }
    if (!(strcmp("A#8", music_note)) || !(strcmp("Bb8", music_note))) {
        *f = As_Bb8;
    }
    if (!(strcmp("B8", music_note))) {
        *f = B8;
    }
    if (!(strcmp("C9", music_note))) {
        *f = C9;
    }
    if (!(strcmp("C#9", music_note)) || !(strcmp("Db9", music_note))) {
        *f = Cs_Db9;
    }
    if (!(strcmp("D9", music_note))) {
        *f = D9;
    }
    if (!(strcmp("D#9", music_note)) || !(strcmp("Eb9", music_note))) {
        *f = Ds_Eb9;
    }
    if (!(strcmp("E9", music_note))) {
        *f = E9;
    }
    if (!(strcmp("F9", music_note))) {
        *f = F9;
    }
    if (!(strcmp("F#9", music_note)) || !(strcmp("Gb9", music_note))) {
        *f = Fs_Gb9;
    }
    if (!(strcmp("G9", music_note))) {
        *f = G9;
    }
    if (!(strcmp("G#9", music_note)) || !(strcmp("Ab9", music_note))) {
        *f = Gs_Ab9;
    }
    if (!(strcmp("A9", music_note))) {
        *f = A9;
    }
    if (!(strcmp("A#9", music_note)) || !(strcmp("Bb9", music_note))) {
        *f = As_Bb9;
    }
    if (!(strcmp("B9", music_note))) {
        *f = B9;
    } 
    if (!(*f)) {
        fprintf(stderr, "\nMusic note '%s' not recognised.\n", music_note);
        return 1;
    }

    return 0;
}

int set_file_name_generator(swavgen_config_t* restrict swavgen_config, char* restrict str)
{
    /* Specifying --output always wins */
    if (swavgen_config->file_name[0] != 0) {
        return 0;
    }

    swavgen_config->fgen = NULL;

    if (!(strcmp("date/time", str))) {
        swavgen_config->fgen = &generate_file_name_datetime_format;
    } 
    if (!(strcmp("properties", str))) {
        swavgen_config->fgen = &generate_file_name_properties_format;
    } 
    if (!(strncmp("custom", str, 6))) {
        swavgen_config->fgen = &generate_file_name_custom_format;
        if (strlen(str) < MAX_STRING) {
            strcpy(swavgen_config->custom_string, str);
        } else {
            fprintf(stderr, "\nCustom format string is too long, max is %d characters.\n", MAX_STRING);
            return 1;
        }
    } 

    if (!(swavgen_config->fgen)) {
        fprintf(stderr, "\nOutput file name format '%s' doesn't exist.\n", str);
        return 1;
    }

    return 0;
}

int set_type_encoding(swavgen_config_t* restrict swavgen_config)
{
    if (swavgen_config->approx == 0) {
        switch (swavgen_config->type) {
            case 's':
                swavgen_config->wave = &create_sine;
                break;
            case 'q':
                swavgen_config->wave = &create_square;
                break;
            case 't':
                swavgen_config->wave = &create_triangle;
                break;
            case 'w':
                swavgen_config->wave = &create_saw;
                break;
            case 'r':
                swavgen_config->wave = &create_random;
                break;
            default:
                fprintf(stderr, "\nWave type '%c' not implemented.\n", swavgen_config->type);

                return 1;
        }
    } else {
        switch (swavgen_config->type) {
            case 's':
                swavgen_config->wave = &create_sine;
                break;
            case 'q':
                swavgen_config->wave = &create_square_approx;
                break;
            case 't':
                swavgen_config->wave = &create_triangle_approx;
                break;
            case 'w':
                swavgen_config->wave = &create_saw_approx;
                break;
            case 'r':
                swavgen_config->wave = &create_random;
                break;
            default:
                fprintf(stderr, "\nWave type '%c' not implemented.\n", swavgen_config->type);

                return 1;
        }
    }

    switch (swavgen_config->encoding) {
        case WAVE_FORMAT_PCM:
            swavgen_config->seth = &set_header_pcm;
            swavgen_config->outp = &output_pcm;
            swavgen_config->encd = &encode_pcm;
            break;
        case WAVE_FORMAT_IEEE_FLOAT:
            swavgen_config->seth = &set_header_ieee_float;
            swavgen_config->outp = &output_non_pcm;
            swavgen_config->encd = &encode_ieee_float;
            break;
        case WAVE_FORMAT_ALAW:
            swavgen_config->seth = &set_header_a_law;
            swavgen_config->outp = &output_non_pcm;
            swavgen_config->encd = &encode_companding;
            break;
        case WAVE_FORMAT_MULAW:
            swavgen_config->seth = &set_header_mu_law;
            swavgen_config->outp = &output_non_pcm;
            swavgen_config->encd = &encode_companding;
            break;
        default:
            fprintf(stderr, "\nEncoding '%d' not implemented.\n", swavgen_config->encoding);

            return 1;
    }

    if (swavgen_config->extensible) {
        swavgen_config->seth = &set_header_extensible;
        swavgen_config->outp = &output_extensible;
    }

    if (swavgen_config->raw) {
        swavgen_config->outp = &output_raw;
    }

    return 0;
}

void create_sine(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        (*samples)[n] = swavgen_config->a * sin((2 * M_PI * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)));
    }
}

void create_square(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    double sample;
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        sample = sin(2 * M_PI * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels));
        (*samples)[n] = swavgen_config->a * (double) sgn(sample);
    }
}

void create_square_approx(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (int k = 0; k <= swavgen_config->approx; k++) {
        for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
            (*samples)[n] += swavgen_config->a * sin(2 * M_PI * (2 * k + 1) * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) / (2 * k + 1);
        }
    }
}

void create_triangle(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    /* Two implementations. Not sure which one is best. */
    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        (*samples)[n] = (2 * swavgen_config->a / M_PI) * asin(sin(2 * M_PI * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)));
        /* (*samples)[n] = swavgen_config->a * (4 * fabs(((double)swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) - (int)(((double)swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) + 0.5f )) - 1); */
    }
}

void create_triangle_approx(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (int k = 0; k <= swavgen_config->approx; k++) {
        for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
            (*samples)[n] += swavgen_config->a * 8 * pow(-1, k) * sin(2 * M_PI * (2 * k + 1) * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) / pow((2 * k + 1) * M_PI, 2);
        }
    }
}

void create_saw(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    /* Two implementations. Not sure which one is best. */
    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        /* (*samples)[n] = swavgen_config->a * (((double)swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) - (int)((double)swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels))); */
        (*samples)[n] = swavgen_config->a * (2 * (((double) swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) - (int) (0.5f + ((double) swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)))));
    }
}

void create_saw_approx(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (int k = 1; k <= swavgen_config->approx; k++) {
        for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
            (*samples)[n] += -2 * swavgen_config->a * pow(-1, k) * sin(2 * M_PI * k * swavgen_config->f * n / (swavgen_config->f_s * swavgen_config->channels)) / (k * M_PI);
        } 
        //FIX: Encoding causes some samples to flip around, PCM encoding expects values of -1 to 1. Use float if that is not desired, but higher harmonics fix the issue, or amplitude = 0.5.

    }
}

void create_random(double** restrict samples, swavgen_config_t* restrict swavgen_config)
{
    srand(time(NULL)); // Initialise the random seed based on the current time
    *samples = calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        (*samples)[n] = (2 * (double) rand() / RAND_MAX) - 1;
    }
}

void check_limit(double* restrict samples, swavgen_config_t* restrict swavgen_config)
{
    if (swavgen_config->limit) {
        for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
            if (samples[n] > 1.0f) {
                samples[n] = 1.0f;
            }

            if (samples[n] < -1.0f) {
                samples[n] = -1.0f;
            }
        }
    }
}

char sgn(double x)
{
    return x >= 0 ? 1 : -1;
}

int fwrite_data(FILE* restrict file, void* restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    if (swavgen_config->bytes_per_sample == 3) {
        int32_t val;

        for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
            val = ((int32_t*) encoded_samples)[n];
            CHECK_WRITE(fwrite(&val, 3, 1, file), 1);
        }
    } else {
        CHECK_WRITE(fwrite(encoded_samples, swavgen_config->total_number_of_samples * swavgen_config->bytes_per_sample * swavgen_config->channels, 1, file), 1);
    }

    return 0;
}

int8_t convert_double_to_pcm_8bit_signed(double sample)
{
    if (sample >= 0) {
        return (S8BIT_MAX * sample);
    } else {
        return -(S8BIT_MIN * sample);
    }
}

int16_t convert_double_to_pcm_16bit_signed(double sample)
{
    if (sample >= 0) {
        return (S16BIT_MAX * sample);
    } else {
        return -(S16BIT_MIN * sample);
    }
}

int32_t convert_double_to_pcm_24bit_signed(double sample)
{
    if (sample >= 0) {
        return S24BIT_MAX * sample;
    } else {
        return S24BIT_MIN * sample; // different from the rest due to actual variable type and not needing to account for overflow
    }
}

int32_t convert_double_to_pcm_32bit_signed(double sample)
{
    if (sample >= 0) {
        return (S32BIT_MAX * sample);
    } else {
        return -(S32BIT_MIN * sample);
    }
}

uint8_t convert_double_to_pcm_8bit_unsigned(double sample)
{
    if (sample >= 0) {
        return ((U8BIT_MAX - 1) * 0.5 * sample) + (U8BIT_MAX + 1) * 0.5;
    } else {
        return ((U8BIT_MAX - 1) * 0.5 * sample) + (U8BIT_MAX - 1) * 0.5;
    }
}

uint16_t convert_double_to_pcm_16bit_unsigned(double sample)
{
    if (sample >= 0) {
        return ((U16BIT_MAX - 1) * 0.5 * sample) + (U16BIT_MAX + 1) * 0.5;
    } else {
        return ((U16BIT_MAX - 1) * 0.5 * sample) + (U16BIT_MAX - 1) * 0.5;
    }
}

uint32_t convert_double_to_pcm_24bit_unsigned(double sample)
{
    if (sample >= 0) {
        return ((U24BIT_MAX - 1) * 0.5 * sample) + (U24BIT_MAX + 1) * 0.5;
    } else {
        return ((U24BIT_MAX - 1) * 0.5 * sample) + (U24BIT_MAX - 1) * 0.5;
    }
}

uint32_t convert_double_to_pcm_32bit_unsigned(double sample)
{
    if (sample >= 0) {
        return ((U32BIT_MAX - 1) * 0.5 * sample) + (U32BIT_MAX + 1) * 0.5;
    } else {
        return ((U32BIT_MAX - 1) * 0.5 * sample) + (U32BIT_MAX - 1) * 0.5;
    }
}

void set_header_pcm(swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* Set as NULL for it to not be unused */
    fact_chunk = (fact_chunk_t*) NULL;

    /* RIFF Chunk */
    memcpy(riff_chunk->chunkID, "RIFF", 4);
    memcpy(riff_chunk->waveID, "WAVE", 4);

    /* Format Chunk */
    memcpy(fmt_chunk->chunkID, "fmt ", 4);
    fmt_chunk->chunk_size = 16;
    fmt_chunk->wFormatTag = swavgen_config->encoding;
    fmt_chunk->nChannels = swavgen_config->channels;
    fmt_chunk->nSamplesPerSec = swavgen_config->f_s;
    fmt_chunk->nAvgBytesPerSec = swavgen_config->f_s * swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->nBlockAlign = swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * swavgen_config->bytes_per_sample;

    /* Data Chunk */
    memcpy(data_chunk->chunkID, "data", 4);
    data_chunk->chunk_size = swavgen_config->bytes_per_sample * swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        swavgen_config->padding = 1;
    }
}

int encode_pcm(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    switch (swavgen_config->representation) {
        case 's':

            switch (swavgen_config->bytes_per_sample) {
                case 1:
                    encode_pcm_signed_8bit(samples, encoded_samples, swavgen_config);
                    break;
                case 2:
                    encode_pcm_signed_16bit(samples, encoded_samples, swavgen_config);
                    break;
                case 3:
                    encode_pcm_signed_24bit(samples, encoded_samples, swavgen_config);
                    break;
                case 4:
                    encode_pcm_signed_32bit(samples, encoded_samples, swavgen_config);
                    break;
                default:
                    fprintf(stderr, "\nSample bits must be 8, 16, 24, or 32 for PCM. Please specify with '-l' or '--sample-length'.\n");

                    return 1;
            }

            break;
        case 'u':

            switch (swavgen_config->bytes_per_sample) {
                case 1:
                    encode_pcm_unsigned_8bit(samples, encoded_samples, swavgen_config);
                    break;
                case 2:
                    encode_pcm_unsigned_16bit(samples, encoded_samples, swavgen_config);
                    fprintf(stdout, "\n\nUnsigned %d-bit PCM isn't supported by the WAVE format but sure here you go:\n", swavgen_config->bytes_per_sample * 8);
                    break;
                case 3:
                    encode_pcm_unsigned_24bit(samples, encoded_samples, swavgen_config);
                    fprintf(stdout, "\n\nUnsigned %d-bit PCM isn't supported by the WAVE format but sure here you go:\n", swavgen_config->bytes_per_sample * 8);
                    break;
                case 4:
                    encode_pcm_unsigned_32bit(samples, encoded_samples, swavgen_config);
                    fprintf(stdout, "\n\nUnsigned %d-bit PCM isn't supported by the WAVE format but sure here you go:\n", swavgen_config->bytes_per_sample * 8);
                    break;
                default:
                    fprintf(stderr, "\nSample bits must be 8, 16, 24, or 32 for PCM. Please specify with '-l' or '--sample-length'.\n");

                    return 1;
            }

            break;
        default:
            fprintf(stderr, "\nRepresentation not implemented. Please specify either 'signed' or 'unsigned' with '-r' or '--representation'.\n");

            return 1;
    }

    return 0;
}

void encode_pcm_signed_8bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (int8_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int8_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((int8_t*) *encoded_samples)[n] = convert_double_to_pcm_8bit_signed(samples[n]);
    }
}

void encode_pcm_signed_16bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (int16_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int16_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((int16_t*) *encoded_samples)[n] = convert_double_to_pcm_16bit_signed(samples[n]);
    }
}

void encode_pcm_signed_24bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (int32_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int32_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((int32_t*) *encoded_samples)[n] = convert_double_to_pcm_24bit_signed(samples[n]);
    }
}

void encode_pcm_signed_32bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (int32_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int32_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((int32_t*) *encoded_samples)[n] = convert_double_to_pcm_32bit_signed(samples[n]);
    }
}

void encode_pcm_unsigned_8bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (uint8_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(uint8_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((uint8_t*) *encoded_samples)[n] = convert_double_to_pcm_8bit_unsigned(samples[n]);
    }
}

void encode_pcm_unsigned_16bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (uint16_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(uint16_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((uint16_t*) *encoded_samples)[n] = convert_double_to_pcm_16bit_unsigned(samples[n]);
    }
}

void encode_pcm_unsigned_24bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (uint32_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(uint32_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((uint32_t*) *encoded_samples)[n] = convert_double_to_pcm_24bit_unsigned(samples[n]);
    }
}

void encode_pcm_unsigned_32bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (uint32_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(uint32_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((uint32_t*) *encoded_samples)[n] = convert_double_to_pcm_32bit_unsigned(samples[n]);
    }
}

void set_header_ieee_float(swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* RIFF Chunk */
    memcpy(riff_chunk->chunkID, "RIFF", 4);
    memcpy(riff_chunk->waveID, "WAVE", 4);

    /* Format Chunk */
    memcpy(fmt_chunk->chunkID, "fmt ", 4);
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = swavgen_config->encoding;
    fmt_chunk->nChannels = swavgen_config->channels;
    fmt_chunk->nSamplesPerSec = swavgen_config->f_s;
    fmt_chunk->nAvgBytesPerSec = swavgen_config->f_s * swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->nBlockAlign = swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * swavgen_config->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    memcpy(fact_chunk->chunkID, "fact", 4);
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Data Chunk */
    memcpy(data_chunk->chunkID, "data", 4);
    data_chunk->chunk_size = swavgen_config->bytes_per_sample * swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        swavgen_config->padding = 1;
    }
}

int encode_ieee_float(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    switch (swavgen_config->bytes_per_sample) {
        case 4:
            encode_ieee_float_32bit(samples, encoded_samples, swavgen_config);
            break;
        case 8:
            encode_ieee_float_64bit(samples, encoded_samples, swavgen_config);
            break;
        default:
            fprintf(stderr, "\nSample bits must be 32 or 64 for float format. Please specify with '-l' or '--sample-length'.\n");

            return 1;
    }

    return 0;
}

void encode_ieee_float_32bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (float*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(float));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((float*) *encoded_samples)[n] = (float) samples[n];
    }
}

void encode_ieee_float_64bit(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    *encoded_samples = (double*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(double));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        ((double*) *encoded_samples)[n] = samples[n];
    }
}

void set_header_a_law(swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* RIFF Chunk */
    memcpy(riff_chunk->chunkID, "RIFF", 4);
    memcpy(riff_chunk->waveID, "WAVE", 4);

    /* Format Chunk */
    memcpy(fmt_chunk->chunkID, "fmt ", 4);
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = swavgen_config->encoding;
    fmt_chunk->nChannels = swavgen_config->channels;
    fmt_chunk->nSamplesPerSec = swavgen_config->f_s;
    fmt_chunk->nAvgBytesPerSec = swavgen_config->f_s * swavgen_config->channels * swavgen_config->bytes_per_sample; // 8 bit data
    fmt_chunk->nBlockAlign = swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * swavgen_config->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    memcpy(fact_chunk->chunkID, "fact", 4);
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Data Chunk */
    memcpy(data_chunk->chunkID, "data", 4);
    data_chunk->chunk_size = swavgen_config->bytes_per_sample * swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        swavgen_config->padding = 1;
    }
}

int8_t convert_pcm_16bit_signed_to_a_law(int16_t x)
{
    int16_t ix, exp;
    int8_t out;

    ix = x < 0          /* 0 <= ix < 2048 */
        ? (~x) >> 4       /* 1's complement for negative values */
        : (x) >> 4;

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

    if (x >= 0)
        ix |= (0x0080);           /* add sign bit */

    out = ix ^ (0x0055);  /* toggle even bits */

    return out;
}

void encode_a_law(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    int16_t pcm_sample;
    *encoded_samples = (int8_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int8_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(samples[n]);
        ((int8_t*) *encoded_samples)[n] = convert_pcm_16bit_signed_to_a_law(pcm_sample);
    }
}

void set_header_mu_law(swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{

    /* RIFF Chunk */
    memcpy(riff_chunk->chunkID, "RIFF", 4);
    memcpy(riff_chunk->waveID, "WAVE", 4);

    /* Format Chunk */
    memcpy(fmt_chunk->chunkID, "fmt ", 4);
    fmt_chunk->chunk_size = 18;
    fmt_chunk->wFormatTag = swavgen_config->encoding;
    fmt_chunk->nChannels = swavgen_config->channels;
    fmt_chunk->nSamplesPerSec = swavgen_config->f_s;
    fmt_chunk->nAvgBytesPerSec = swavgen_config->f_s * swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->nBlockAlign = swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * swavgen_config->bytes_per_sample;
    fmt_chunk->cbSize = 0;

    /* Fact Chunk */
    memcpy(fact_chunk->chunkID, "fact", 4);
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Data Chunk */
    memcpy(data_chunk->chunkID, "data", 4);
    data_chunk->chunk_size = swavgen_config->bytes_per_sample * swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        swavgen_config->padding = 1;
    }
}

int8_t convert_pcm_16bit_signed_to_mu_law(int16_t x)
{
    int16_t segment;                  /* segment (Table 2/G711, column 1) */
    int16_t out;
    int16_t low_nibble, high_nibble;  /* low/high nibble of log companded sample */

    /* Change from 14 bit left justified to 14 bit right justified.
     * Compute absolute value; adjust for easy processing */

    /* Compute 1's complement */
    short absval = x < 0 ? ((~x) >> 2) + 33 : (x >> 2) + 33; /* Absolute value */
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
    if (x >= 0)
        out = out | (0x0080);

    return out;
}

void encode_mu_law(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    int16_t pcm_sample;
    *encoded_samples = (int8_t*) calloc(swavgen_config->total_number_of_samples * swavgen_config->channels, sizeof(int8_t));

    for (size_t n = 0; n < swavgen_config->total_number_of_samples * swavgen_config->channels; n++) {
        pcm_sample = convert_double_to_pcm_16bit_signed(samples[n]);
        ((int8_t*) *encoded_samples)[n] = convert_pcm_16bit_signed_to_mu_law(pcm_sample);
    }
}

int encode_companding(double* restrict samples, void** restrict encoded_samples, swavgen_config_t* restrict swavgen_config)
{
    switch (swavgen_config->encoding) {
        case WAVE_FORMAT_ALAW:
            encode_a_law(samples, encoded_samples, swavgen_config);
            break;
        case WAVE_FORMAT_MULAW:
            encode_mu_law(samples, encoded_samples, swavgen_config);
            break;
        default:
            return 1;
    }

    if (swavgen_config->bytes_per_sample != 1) {
        fprintf(stdout, "\nProgram defaulted to 8 sample bits. No other option available for A-law/Mu-law.\n");
        swavgen_config->bytes_per_sample = 1;
    }

    return 0;
}

void set_header_extensible(swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* RIFF Chunk */
    memcpy(riff_chunk->chunkID, "RIFF", 4);
    memcpy(riff_chunk->waveID, "WAVE", 4);

    /* Format Chunk */
    memcpy(fmt_chunk->chunkID, "fmt ", 4);
    fmt_chunk->chunk_size = 40;
    fmt_chunk->wFormatTag = WAVE_FORMAT_EXTENSIBLE;
    fmt_chunk->nChannels = swavgen_config->channels;
    fmt_chunk->nSamplesPerSec = swavgen_config->f_s;
    fmt_chunk->nAvgBytesPerSec = swavgen_config->f_s * swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->nBlockAlign = swavgen_config->channels * swavgen_config->bytes_per_sample;
    fmt_chunk->wBitsPerSample = 8 * swavgen_config->bytes_per_sample;
    fmt_chunk->cbSize = 22;
    fmt_chunk->wValidBitsPerSample = swavgen_config->valid_bits;
    fmt_chunk->dwChannelMask = swavgen_config->channel_mask; // from 0 to 4 294 967 295
    memcpy(fmt_chunk->SubFormat, "xx\x00\x00\x00\x00\x10\x00\x80\x00\x00\xAA\x00\x38\x9B\x71", 16); // xx gets replaced with the next line.
    memcpy(fmt_chunk->SubFormat, &swavgen_config->encoding, 2);

    /* Fact Chunk */
    memcpy(fact_chunk->chunkID, "fact", 4);
    fact_chunk->chunk_size = 4;
    fact_chunk->dwSampleLength = swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Data Chunk */
    memcpy(data_chunk->chunkID, "data", 4);
    data_chunk->chunk_size = swavgen_config->bytes_per_sample * swavgen_config->channels * swavgen_config->total_number_of_samples;

    /* Check if padding is necessary */
    if (data_chunk->chunk_size % 2 != 0) {
        swavgen_config->padding = 1;
    }
}

int output_pcm(FILE* restrict file, void* restrict encoded_samples, swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->cbSize) + sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat);

    size_t used_fmt_chunk = sizeof(*fmt_chunk) - unused_fmt_chunk;

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + used_fmt_chunk + sizeof(*data_chunk) + (swavgen_config->total_number_of_samples * swavgen_config->bytes_per_sample * swavgen_config->channels) + swavgen_config->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  used_fmt_chunk,  1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_RET(fwrite_data(file, encoded_samples, swavgen_config));

    /* Padding added based on if the data chunk size is odd or even */
    if (swavgen_config->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_non_pcm(FILE* restrict file, void* restrict encoded_samples, swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    /* Calculating the unused format chunk members to fix the effect of padding */
    size_t unused_fmt_chunk = sizeof(fmt_chunk->wValidBitsPerSample) + sizeof(fmt_chunk->dwChannelMask) + sizeof(fmt_chunk->SubFormat);

    size_t used_fmt_chunk = sizeof(*fmt_chunk) - unused_fmt_chunk;

    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + used_fmt_chunk + sizeof(*fact_chunk) + sizeof(*data_chunk) + (swavgen_config->total_number_of_samples * swavgen_config->bytes_per_sample * swavgen_config->channels) + swavgen_config->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  used_fmt_chunk,  1, file), 1);
    CHECK_WRITE(fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(encoded_samples, swavgen_config->total_number_of_samples * swavgen_config->bytes_per_sample * swavgen_config->channels, 1, file), 1);

    /* Padding added based on if the data chunk size is odd or even */
    if (swavgen_config->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_extensible(FILE* restrict file, void* restrict encoded_samples, swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    riff_chunk->chunk_size = sizeof(riff_chunk->waveID) + sizeof(*fmt_chunk) + sizeof(*fact_chunk) + sizeof(*data_chunk) + (swavgen_config->total_number_of_samples * swavgen_config->bytes_per_sample * swavgen_config->channels) + swavgen_config->padding;

    CHECK_WRITE(fwrite(riff_chunk, sizeof(riff_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(fmt_chunk,  sizeof(fmt_chunk_t),  1, file), 1);
    CHECK_WRITE(fwrite(fact_chunk, sizeof(fact_chunk_t), 1, file), 1);
    CHECK_WRITE(fwrite(data_chunk, sizeof(data_chunk_t), 1, file), 1);
    CHECK_RET(fwrite_data(file, encoded_samples, swavgen_config));

    /* Padding added based on if the data chunk size is odd or even */
    if (swavgen_config->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

int output_raw(FILE* restrict file, void* restrict encoded_samples, swavgen_config_t* restrict swavgen_config, riff_chunk_t* restrict riff_chunk, fmt_chunk_t* restrict fmt_chunk, fact_chunk_t* restrict fact_chunk, data_chunk_t* restrict data_chunk)
{
    CHECK_RET(fwrite_data(file, encoded_samples, swavgen_config));

    /* Padding added based on if the data chunk size is odd or even */
    if (swavgen_config->padding) {
        uint8_t padding = 0;
        CHECK_WRITE(fwrite(&padding, sizeof(padding), 1, file), 1);
    }

    return 0;
}

// TODO: Add valid bits, approx., raw, and limit inputs to output file details
int output_file_details(swavgen_config_t* restrict swavgen_config)
{
    printf("\n\tFile Name:\t%s"
            "\n\tWave Type:\t%s"
            "\n\tSize:\t\t%llud\t[Bytes]"
            "\n\tDuration:\t%.4f\t[s]"
            "\n\tEncoding:\t%s"
            "\n\tSampling Freq.:\t%u\t[Hz]"
            "\n\tTone Freq.:\t%.3f\t[Hz]"
            "\n\tWave Period:\t%.4f\t[ms]"
            "\n\tTotal Samples:\t%lld"
            "\n\tChannels:\t%d"
            "\n\tSample Length:\t%d\t[bits]"
            , swavgen_config->file_name, swavgen_config->typestr, swavgen_config->size, swavgen_config->duration, swavgen_config->encodingstr, swavgen_config->f_s, swavgen_config->f, swavgen_config->T, swavgen_config->total_number_of_samples, swavgen_config->channels, swavgen_config->bytes_per_sample * 8);

    printf(swavgen_config->encoding == WAVE_FORMAT_PCM ? 
            "\n\tRepresentation:\t%s"
            : "\r"
            , swavgen_config->representationstr);

    printf(swavgen_config->music_note[0] != 0 ? 
            "\n\tMusic Note:\t%s"
            : "\r"
            , swavgen_config->music_note);

    printf(swavgen_config->extensible == 1 ?
            "\n\tChannel Mask:\t%s"
            : "\r"
            , swavgen_config->channel_mask_str);

    printf("\n\n");

    return 0;
}

char* get_date_string()
{
    time_t time_since_epoch = time(NULL);
    struct tm* tm = localtime(&time_since_epoch);
    static char s[7];
    strftime(s, sizeof(s), "%d%m%y", tm);

    return s;
}

char* get_time_string()
{
    time_t time_since_epoch = time(NULL);
    struct tm* tm = localtime(&time_since_epoch);
    static char s[7];
    strftime(s, sizeof(s), "%H%M%S", tm);

    return s;
}

int generate_file_name_datetime_format(swavgen_config_t* restrict swavgen_config)
{
    return sprintf(swavgen_config->file_name, "swavgen-output-%s%s.wav", get_date_string(), get_time_string());
}

int generate_file_name_properties_format(swavgen_config_t* restrict swavgen_config)
{
    const size_t len_a = MAX_TYPE_STRING + 1 + MAX_FREQ_STRING + 1 + MAX_SAMP_STRING + 1 + MAX_REPR_STRING + 1; 
    const size_t len_b = MAX_ENC_STRING + 1 + MAX_BYTE_STRING + 1 + MAX_DURA_STRING + 1 + MAX_CHAN_STRING + 1 + MAX_NOTE_STRING + 1 + MAX_MASK_STRING;
    char prop_string_a[len_a]; 
    char prop_string_b[len_b]; 

    memset(prop_string_a, '\0', sizeof(char) * len_a);
    memset(prop_string_b, '\0', sizeof(char) * len_b);

    sprintf(prop_string_a, "%s-%.3lf-%d-", 
            swavgen_config->typestr, 
            swavgen_config->f, 
            swavgen_config->f_s
           );

    if (swavgen_config->encoding == WAVE_FORMAT_PCM) {
        strcat(prop_string_a, swavgen_config->representationstr);
        strcat(prop_string_a, "-");
    }

    sprintf(prop_string_b, "%s-%d-%.3lf-%d", 
            swavgen_config->encodingstr, 
            swavgen_config->bytes_per_sample * 8, 
            swavgen_config->duration, 
            swavgen_config->channels
           );

    if (swavgen_config->music_note[0] != '\0') {
        strcat(prop_string_b, "-");
        strcat(prop_string_b, swavgen_config->music_note);
    }

    if (swavgen_config->extensible == 1) {
        strcat(prop_string_b, "-");
        strcat(prop_string_b, swavgen_config->channel_mask_str);
    }

    sprintf(swavgen_config->file_name, "swavgen-output-%s%s.wav", prop_string_a, prop_string_b);

    return 0; 
}

int generate_file_name_custom_format(swavgen_config_t* restrict swavgen_config)
{
    char* format_string = strtok(swavgen_config->custom_string, ":");
    format_string = strtok(NULL, ":");

    if(!(format_string)) {
        fprintf(stderr, "\nError splitting format string\n");
        return 1;
    }

    memset(swavgen_config->file_name, '\0', sizeof(char) * MAX_STRING);
    char* format_token = strtok(format_string, "-");
    char strval[10];
    uint8_t found = 0;

    while (format_token) {
        found = 0;
        if (!(strcmp("swavgen", format_token))) {
            strcat(swavgen_config->file_name, "swavgen");
            found = 1;
        }
        if (!(strcmp("output", format_token))) {
            strcat(swavgen_config->file_name, "output");
            found = 1;
        }
        if (!(strcmp("type", format_token))) {
            strcat(swavgen_config->file_name, swavgen_config->typestr);
            found = 1;
        }
        if (!(strcmp("frequency", format_token))) {
            sprintf(strval, "%.3lf", swavgen_config->f); 
            strcat(swavgen_config->file_name, strval);
            found = 1;
        }
        if (!(strcmp("sampling", format_token))) {
            sprintf(strval, "%u", swavgen_config->f_s); 
            strcat(swavgen_config->file_name, strval);
            found = 1;
        }
        if (!(strcmp("representation", format_token))) {
            strcat(swavgen_config->file_name, swavgen_config->representationstr);
            found = 1;
        }
        if (!(strcmp("encoding", format_token))) {
            strcat(swavgen_config->file_name, swavgen_config->encodingstr);
            found = 1;
        }
        if (!(strcmp("length", format_token))) {
            sprintf(strval, "%u", swavgen_config->bytes_per_sample * 8); 
            strcat(swavgen_config->file_name, strval);
            found = 1;
        }
        if (!(strcmp("duration", format_token))) {
            sprintf(strval, "%.3lf", swavgen_config->duration); 
            strcat(swavgen_config->file_name, strval);
            found = 1;
        }
        if (!(strcmp("channels", format_token))) {
            sprintf(strval, "%u", swavgen_config->channels); 
            strcat(swavgen_config->file_name, strval);
            found = 1;
        }
        if (!(strcmp("note", format_token))) {
            strcat(swavgen_config->file_name, swavgen_config->music_note);
            found = 1;
        }
        if (!(strcmp("mask", format_token))) {
            strcat(swavgen_config->file_name, swavgen_config->channel_mask_str);
            found = 1;
        }
        if (!(strcmp("date", format_token))) {
            strcat(swavgen_config->file_name, get_date_string());
            found = 1;
        }
        if (!(strcmp("time", format_token))) {
            strcat(swavgen_config->file_name, get_time_string());
            found = 1;
        }

        if (!found) {
            fprintf(stderr, "\nUnknown format specifier '%s'.\n", format_token);
            return 1;
        }

        memset(strval, '\0', sizeof(char) * 10);
        strcat(swavgen_config->file_name, "-");
        format_token = strtok(NULL, "-");
    }

    swavgen_config->file_name[strlen(swavgen_config->file_name) - 1] = '\0';
    strcat(swavgen_config->file_name, ".wav");

    return 0;
}

int generate_file_name_ignore(swavgen_config_t* restrict swavgen_config)
{
    /* Do nothing */
    return 0;
}

int output_help()
{
    printf("\n\n"
            "General usage,\n"
            "'swavgen <Wave Type> [<Options>]', with an ability to choose between 'sine', 'square', 'triangle', 'saw' wave types. Use 'random' for some random white noise.\n\n"
            "Available options are,\n"
            "\t-e,\t--encoding <Encoding>\t\t\t= Encoding used for sampled data. Available encodings are 'IEEE-float' (64/32-bit), 'PCM' (signed/unsigned 8/16/24/32-bit), 'A-law', and 'Mu-law'.\n"
            "\t-f,\t--frequency <Frequency [Hz]>\t\t= Input the wave frequency in Hertz.\n"
            "\t-T,\t--period <Time [ms]>\t\t\t= Input the wave period in milliseconds.\n"
            "\t-s,\t--sampling-frequency <Frequency [Hz]>\t= Wave sampling frequency in Hertz.\n"
            "\t-d,\t--duration <Time [s]>\t\t\t= Wave duration in seconds.\n"
            "\t-n,\t--total-samples <Samples>\t\t= Wave total samples. Gets calculated in the tool with sampling frequency, duaration, and channels. Specifying any of those three options and also specifying the total samples can lead to issues.\n"
            "\t-a,\t--amplitude <Amplitude>\t\t\t= Wave amplitude. Affects the amplitude of the generated wave before encoding, therefore it can have some strange effects in the encodings that expect values of -1 to +1.\n"
            "\t-l,\t--sample-length <Length [bits]>\t\t= Encoded wave sample length in bits. Must be divisible by 8.\n"
            "\t-r,\t--representation <Representation>\t= Choose between 'signed' and 'unsigned' PCM encoding.\n"
            "\t-c,\t--channels <Channels>\t\t\t= Choose the number of channels to be created.\n"
            "\t-o,\t--output <File Name>\t\t\t= Specify the output file name.\n"
            "\t-x,\t--extensible\t\t\t\t= Enable the extensible format type for WAV. Mandatory when specifying a channel mask or valid bits but otherwise only necessary for some media players.\n"
            "\t-v,\t--valid-bits <Valid Bits [bits]>\t= Valid bits in the sample. Doesn't seem to do anything and is purely informational. Must be less than the sample length.\n"
            "\t-m,\t--channel-mask <Channel Mask Code>\t= Specify the channel mask to be used for panning. The number of speaker locations specified should be the same as the number of channels. For example with '-c 2' an option of '-m FR,FL' should be used. All channel mask options are listed below, and should be separated with a comma, dash, or dot.\n"
            "\t\t--raw\t\t\t\t\t= Output the data with no header information. Useful for only getting the data of the generated wave.\n"
            "\t\t--limit\t\t\t\t\t= Enable limiting so that the generated wave is limited from -1 to +1 prior to encoding.\n"
            "\t-b,\t--approx <Number of Waves>\t\t= Specify the using an amount of approximated waves using additive synthesis instead of pure digitally created waves.\n"
            "\t\t--output-name-format <Format>\t= Specify the format of the output file name. Choose between 'date/time', 'properties', and 'custom'. Defaults to 'properties'. To use the 'custom' output format, specify with '--output-name-format custom:<SPECIFIERS>'. Separete any of the following specifiers with '-' to create a custom naming format, 'swavgen', 'output', 'type', 'frequency', 'sampling', 'representation', 'encoding', 'length', 'duration', 'channels', 'note', 'mask', 'date', and 'time'.\n"
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
