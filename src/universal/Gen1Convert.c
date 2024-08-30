#include <pksm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void convert_bank3_to_gen1(int box, int slot)
{
    enum Generation gen = GEN_THREE;

    char field_id_buffer[50];
    char *pkm_g1 = malloc(pkx_box_size(GEN_ONE));
    char *pkm_g3 = bank_get_pkx(&gen, box, slot);
    bool is_inject = true;

    if (pkm_g3 == NULL || pkm_g1 == NULL)
    {
        gui_warn("Failed to allocate memory for temporary Pokémon data.");
        return;
    }

    sav_box_decrypt();
    //* Generate a Gen 1 Pokémon
    pkx_generate(pkm_g1,
                 pkx_get_value(
                     pkm_g3,
                     GEN_THREE,
                     SPECIES));

    for (int i_field = 1; i_field <= 44; i_field++)
    {

        snprintf(field_id_buffer, sizeof(field_id_buffer), "Convert PKX Field : %d/44", i_field);
        gui_warn(field_id_buffer);

        switch (i_field)
        {
        case MOVE:
        case PP:
        case PP_UPS:
            for (int m = 0; m < 4; m++)
            {
                if (!pkx_get_value(pkm_g3, GEN_THREE, i_field, m))
                {
                    is_inject = false;
                    break;
                }

                pkx_set_value(pkm_g1,
                              GEN_ONE,
                              i_field,
                              m,
                              pkx_get_value(
                                  pkm_g3,
                                  GEN_THREE,
                                  i_field,
                                  m));
            }
            is_inject = false;
            break;

        case LEVEL:
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          LEVEL, pkx_get_value(pkm_g3, GEN_THREE, LEVEL));
            is_inject = true;
            break;

        case POKERUS:
        case BALL:
        case ABILITY:

            is_inject = false;
            break;

        default:
            if (!pkx_get_value(pkm_g3, GEN_THREE, i_field))
            {
                is_inject = false;
                break;
            }

            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          i_field,
                          pkx_get_value(
                              pkm_g3,
                              GEN_THREE,
                              i_field));

            is_inject = true;
            break;
        }
        //*Encrypt the Gen 1 Pokémon
        // 7 8 10 11 12 14 15 16 17 20 21 22 23 24 25 33 34 35 42 44

        // fixed:
        //       - continue: 7, 10
        //       - change value:

        if (is_inject)
        {
            gui_splash("Injecting ...");
        }
        else
        {
            gui_splash("Skipping ...");
        }
    }
    sav_inject_pkx(pkm_g1, GEN_ONE, 0, 0, 0);

    free(pkm_g1);
    free(pkm_g3);
    sav_box_encrypt();

    gui_warn("Pokémon is converted to Gen 1!");
}

int main(int argc, char **argv)
{
    enum Generation gens[] = {
        GEN_ONE,
        GEN_TWO,
        GEN_THREE,
        GEN_FOUR,
        GEN_FIVE,
        GEN_SIX,
        GEN_SEVEN,
        GEN_LGPE,
        GEN_EIGHT};
    char *dexFiles[] = {
        "PK1", "https://cdn.sigkill.tech/dex/pk1.txt", // contains 1-151
    };

    unsigned int input;
    gui_numpad(&input, "From left to right, top to bottom, count from 0", 30);

    convert_bank3_to_gen1(0, input);

    return 0;
}