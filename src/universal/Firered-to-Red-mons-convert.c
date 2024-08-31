#include <pksm.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

struct item_dictionary
{
    int id_item_g3;
    int id_item_g1;
};

bool is_odd(int num)
{
    if (num % 2 == 0)
    {
        return false;
    }
    return true;
}

int GetItemIDFromGen3ToGen1(int item_id_gen3)
{
    int item_id_gen1[375] = {0,
                             1,
                             2,
                             4,
                             5,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             18,
                             9,
                             10,
                             11,
                             12,
                             13,
                             14,
                             15,
                             16,
                             17,
                             38,
                             39,
                             40,
                             46,
                             47,
                             48,
                             72,
                             121,
                             122,
                             123,
                             124,
                             63,
                             64,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             139,
                             156,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             26,
                             27,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             28,
                             29,
                             31,
                             32,
                             62,
                             0,
                             0,
                             0,
                             0,
                             44,
                             49,
                             51,
                             52,
                             33,
                             53,
                             37,
                             0,
                             0,
                             42,
                             43,
                             19,
                             20,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             169,
                             8,
                             22,
                             23,
                             24,
                             34,
                             0,
                             0,
                             0,
                             0,
                             0,
                             87,
                             0,
                             110,
                             111,
                             131,
                             132,
                             36,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             3,
                             0,
                             0,
                             0,
                             73,
                             0,
                             0,
                             0,
                             82,
                             0,
                             91,
                             94,
                             0,
                             0,
                             0,
                             106,
                             112,
                             119,
                             126,
                             140,
                             143,
                             146,
                             151,
                             163,
                             76,
                             125,
                             117,
                             102,
                             98,
                             108,
                             95,
                             77,
                             81,
                             107,
                             113,
                             96,
                             138,
                             144,
                             0,
                             172,
                             0,
                             0,
                             0,
                             30,
                             35,
                             118,
                             105,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             68,
                             0,
                             0,
                             0,
                             0,
                             54,
                             55,
                             58,
                             0,
                             61,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             133,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             191,
                             192,
                             193,
                             194,
                             196,
                             197,
                             198,
                             199,
                             200,
                             201,
                             202,
                             203,
                             204,
                             205,
                             206,
                             207,
                             208,
                             209,
                             210,
                             211,
                             212,
                             213,
                             214,
                             215,
                             216,
                             217,
                             218,
                             219,
                             221,
                             222,
                             223,
                             224,
                             225,
                             226,
                             227,
                             228,
                             229,
                             230,
                             231,
                             232,
                             233,
                             234,
                             235,
                             236,
                             237,
                             238,
                             239,
                             240,
                             241,
                             242,
                             243,
                             244,
                             245,
                             246,
                             247,
                             248,
                             249,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             127,
                             0,
                             0,
                             0,
                             0,
                             7,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0,
                             0};
    return item_id_gen1[item_id_gen3];
}

void convert_bank3_to_gen1(int bank_box, int bank_slot, int sav_box, int sav_slot)
{
    enum Generation target_gen = GEN_THREE;

    char field_id_buffer[50];
    char *pkm_g1 = malloc(pkx_box_size(GEN_ONE));
    char *pkm_g3 = bank_get_pkx(&target_gen, bank_box, bank_slot);
    bool is_inject = true;

    if (pkm_g3 == NULL || pkm_g1 == NULL)
    {
        gui_warn("Failed to allocate memory for temporary Pokémon data.");
        return;
    }

    //* Check pkm_g3 is gen 3 or gen 1
    int pkm_g3_species = pkx_get_value(pkm_g3, GEN_THREE, SPECIES);
    if (pkm_g3_species == 0)
    {
        target_gen = GEN_ONE;
    }

    sav_box_decrypt();
    //* Generate a Gen 1 Pokémon
    pkx_generate(pkm_g1,
                 pkx_get_value(
                     pkm_g3,
                     target_gen,
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

    pkm_g3_spAtk = floor(pkx_get_value(pkm_g3, target_gen, IV_SPATK) / 2);
    pkm_g3_spDef = floor(pkx_get_value(pkm_g3, target_gen, IV_SPDEF) / 2);
    pkm_g3_speed = floor(pkx_get_value(pkm_g3, target_gen, IV_SPEED) / 2);
    pkm_g3_atk = floor(pkx_get_value(pkm_g3, target_gen, IV_ATK) / 2);
    pkm_g3_def = floor(pkx_get_value(pkm_g3, target_gen, IV_DEF) / 2);
    pkm_g3_hp = floor(pkx_get_value(pkm_g3, target_gen, IV_HP) / 2);

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
                if (!pkx_get_value(pkm_g3, target_gen, i_field, m))
                {
                    break;
                }

                int skill_id = pkx_get_value(
                    pkm_g3,
                    target_gen,
                    i_field,
                    m);

                if (skill_id != 0 && skill_id < 166)
                {
                    pkx_set_value(pkm_g1,
                                  GEN_ONE,
                                  i_field,
                                  move_count, skill_id);
                    move_count++;
                }
            }
            break;

        case SHINY: // shiny: 0 -> 1
            // IVs in Speed, Defense and Special are all equal to 10.
            // Attack IV is equal to 2, 3, 6, 7, 10, 11, 14, or 15.
            int is_shiny = pkx_get_value(pkm_g3, target_gen, SHINY);
            if (is_shiny)
            {
                pkm_g1_atk = pkm_g1_atk + 2;
                switch (pkm_g1_atk)
                {
                case 1:
                case 4:
                case 5:
                case 8:
                case 9:
                case 12:
                case 13:
                    pkm_g1_atk = pkm_g1_atk + 2;
                    break;
                default:
                    break;
                }
                pkm_g1_def = 10;
                pkm_g1_speed = 10;
                pkm_g1_spAtk = 10;
                pkm_g1_spDef = 10;
                pkx_set_value(pkm_g1, GEN_ONE, SHINY, 1);
                break;
            }
            else
            {
                pkm_g1_atk = pkm_g1_atk - 2;
                pkx_set_value(pkm_g1, GEN_ONE, SHINY, 0);
            }
        case ITEM: // item: 0 -> 375
            int item_id_g3 = pkx_get_value(pkm_g3, target_gen, ITEM);
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          ITEM, 126);
            //   GetItemIDFromGen3ToGen1(item_id_g3)
            break;
        case BALL: // ball: 0 -> 4
            int ball_id = pkx_get_value(pkm_g3, target_gen, BALL);
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          BALL, ball_id > 5 ? 3 : ball_id);
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
                              target_gen,
                              i_field));
            break;
        }
    }

    // Check Valid
    if (!pkx_is_valid(pkm_g1, GEN_ONE))
    {
        snprintf(field_id_buffer, sizeof(field_id_buffer), "Failed to convert Pokémon \nAt slot %d to Gen 1", bank_slot);
        gui_warn(field_id_buffer);

        // snprintf(field_id_buffer, sizeof(field_id_buffer), "Would you still want to Inject invalid  \n Pokemon at %d to Gen 1", bank_slot);
        // int choice = gui_choice(field_id_buffer);
        // if (!choice)
        // {
        //     pkx_set_value(pkm_g1, GEN_ONE, SPECIES, 0);
        // }
    }
    sav_inject_pkx(pkm_g1, GEN_ONE, sav_box, sav_slot, 0);

    //* Free memory
    free(pkm_g1);
    free(pkm_g3);
    sav_box_encrypt();
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

    gui_warn("This script will convert entire Bank 1 (Firered - G3) to Gen 1 (Red/Blue - G1).");

    int bank_current_box = 0;
    int bank_current_slot = 0;

    for (int sav_box = 0; sav_box < 2; sav_box++)
    {
        for (int sav_slot = 0; sav_slot < 20; sav_slot++)
        {
            convert_bank3_to_gen1(
                bank_current_box,
                bank_current_slot,
                sav_box,
                sav_slot);

            bank_current_slot++;

            if (bank_current_slot == 30)
            {
                gui_warn("Pokémon is converted to Gen 1!");
                return 0;
            }
        }
    }

    return 0;
}