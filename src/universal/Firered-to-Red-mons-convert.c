#include <pksm.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool is_odd(int num)
{
    if (num % 2 == 0)
    {
        return false;
    }
    return true;
}

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

    //! IV Conversion calculation
    //* Determine IV (Max of of Sp.Atk/Sp.Def divide by 2)
    //* Speed divide by 2
    //* Attack, Defense divide by 2
    //* Check HP/2 (Check who ood)
    //* Check current HP (Check who ood)
    //* Make Current odd the same as HP odd
    int pkm_g3_spAtk,
        pkm_g3_spDef,
        pkm_g3_speed,
        pkm_g3_atk,
        pkm_g3_def,
        pkm_g3_hp,
        pkm_g1_spAtk,
        pkm_g1_spDef,
        pkm_g1_speed,
        pkm_g1_atk,
        pkm_g1_def,
        pkm_g1_hp;
    int g3_hp_bin[4] = {0, 0, 0, 0};
    int g1_hp_bin[4] = {0, 0, 0, 0};

    pkm_g3_spAtk = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_SPATK) / 2);
    pkm_g3_spDef = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_SPDEF) / 2);
    pkm_g3_speed = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_SPEED) / 2);
    pkm_g3_atk = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_ATK) / 2);
    pkm_g3_def = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_DEF) / 2);
    pkm_g3_hp = floor(pkx_get_value(pkm_g3, GEN_THREE, IV_HP) / 2);

    pkm_g1_spAtk = pkm_g3_spAtk > pkm_g3_spDef ? pkm_g3_spAtk : pkm_g3_spDef;
    pkm_g1_spDef = pkm_g1_spAtk;
    pkm_g1_speed = pkm_g3_speed;
    pkm_g1_atk = pkm_g3_atk;
    pkm_g1_def = pkm_g3_def;

    g3_hp_bin[0] = (pkm_g3_hp >> 3) & 1;
    g3_hp_bin[1] = (pkm_g3_hp >> 2) & 1;
    g3_hp_bin[2] = (pkm_g3_hp >> 1) & 1;
    g3_hp_bin[3] = pkm_g3_hp & 1;

    g1_hp_bin[0] = pkm_g1_atk % 2 == 0 ? 0 : 1;
    g1_hp_bin[1] = pkm_g1_def % 2 == 0 ? 0 : 1;
    g1_hp_bin[2] = pkm_g1_speed % 2 == 0 ? 0 : 1;
    g1_hp_bin[3] = pkm_g1_spAtk % 2 == 0 ? 0 : 1;

    for (int i = 0; i < 4; i++)
    {
        g1_hp_bin[i] = g3_hp_bin[i] - g1_hp_bin[i];
    }

    pkm_g1_atk = pkm_g1_atk + g1_hp_bin[0];
    pkm_g1_def = pkm_g1_def + g1_hp_bin[1];
    pkm_g1_speed = pkm_g1_speed + g1_hp_bin[2];
    pkm_g1_spAtk = pkm_g1_spAtk + g1_hp_bin[3];
    pkm_g1_spDef = pkm_g1_spDef + g1_hp_bin[3];

    //! All data conversion
    for (int i_field = 1; i_field <= 44; i_field++)
    {

        switch (i_field)
        {
        case MOVE: // special case (two values in field)
                   // move: 0 -> 165
        case PP:   // always in range 0 -> 40
        case PP_UPS:
            int move_count = 0;
            for (int m = 0; m < 4; m++)
            {
                if (!pkx_get_value(pkm_g3, GEN_THREE, i_field, m))
                {
                    break;
                }

                int skill_id = pkx_get_value(
                    pkm_g3,
                    GEN_THREE,
                    i_field,
                    m);

                if (skill_id != 0)
                {
                    pkx_set_value(pkm_g1,
                                  GEN_ONE,
                                  i_field,
                                  move_count, skill_id > 165 ? 0 : skill_id);
                    move_count++;
                }
            }
            break;
        case IV_HP:
            break;
        case IV_ATK:
            pkx_set_value(pkm_g1, GEN_ONE, IV_ATK, pkm_g1_atk);
            break;
        case IV_DEF:
            pkx_set_value(pkm_g1, GEN_ONE, IV_DEF, pkm_g1_def);
            break;
        case IV_SPATK:
            pkx_set_value(pkm_g1, GEN_ONE, IV_SPATK, pkm_g1_spAtk);
            break;
        case IV_SPDEF:
            pkx_set_value(pkm_g1, GEN_ONE, IV_SPDEF, pkm_g1_spDef);
            break;
        case IV_SPEED:
            pkx_set_value(pkm_g1, GEN_ONE, IV_SPEED, pkm_g1_speed);
            break;

        default: // only 1 value in field
            if (!pkx_get_value(pkm_g1, GEN_ONE, i_field))
            {
                break;
            }

            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          i_field,
                          pkx_get_value(
                              pkm_g3,
                              GEN_THREE,
                              i_field));

            break;
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