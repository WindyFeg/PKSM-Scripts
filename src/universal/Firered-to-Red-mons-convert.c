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
int GetMovePPFromGen3ToGen1(int move_id_gen3)
{
    int move_pp_gen1[166] = {0,
                             35,
                             25,
                             10,
                             15,
                             20,
                             20,
                             15,
                             15,
                             15,
                             35,
                             30,
                             5,
                             10,
                             20,
                             30,
                             35,
                             35,
                             20,
                             15,
                             20,
                             20,
                             10, // 25 -> 10
                             20,
                             30,
                             5,
                             10,
                             15,
                             15,
                             15,
                             25,
                             20,
                             5,
                             35,
                             15,
                             20,
                             20,
                             10,
                             15,
                             30,
                             35,
                             20,
                             20,
                             30,
                             25,
                             40,
                             20,
                             15,
                             20,
                             20,
                             20,
                             30,
                             25,
                             15,
                             30,
                             25,
                             5,
                             15,
                             10,
                             5,
                             20,
                             20,
                             20,
                             5,
                             35,
                             20,
                             20,
                             20,
                             20,
                             20,
                             15,
                             20, // 25 -> 20
                             15,
                             10,
                             20,
                             25,
                             10,
                             35,
                             30,
                             15,
                             10,
                             40,
                             10,
                             15,
                             30,
                             15,
                             20,
                             10,
                             15,
                             10,
                             5,
                             10,
                             10,
                             25,
                             10,
                             20,
                             40,
                             30,
                             30,
                             20,
                             20,
                             15,
                             10,
                             40,
                             15,
                             5,
                             30,
                             10,
                             20,
                             10,
                             40,
                             40,
                             20,
                             30,
                             30,
                             20,
                             30,
                             10,
                             10,
                             20,
                             5,
                             10,
                             30,
                             20,
                             20,
                             20,
                             5,
                             15,
                             15,
                             20,
                             10,
                             15,
                             35,
                             20,
                             15,
                             5,
                             10,
                             30,
                             15,
                             40,
                             20,
                             10,
                             10,
                             5,
                             10,
                             30,
                             10,
                             15,
                             20,
                             15,
                             40,
                             20,
                             10,
                             5,
                             15,
                             10,
                             5,
                             10,
                             15,
                             30,
                             30,
                             10,
                             10,
                             20,
                             10,
                             0};
    return move_pp_gen1[move_id_gen3];
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

int gender_determine(char *pkx_g1, char *pkx_g3)
{
    int gender_g3 = pkx_get_value(pkx_g3, GEN_THREE, GENDER);
    int gender_g1 = pkx_get_value(pkx_g1, GEN_ONE, GENDER);
    int pkm_g1_spAtk = pkx_get_value(pkx_g1, GEN_ONE, IV_ATK);

    if (gender_g1 == gender_g3)
    {
        return pkm_g1_spAtk;
    }

    // GENDER = 0: MALE
    if (gender_g1 == 0)
    {
        pkx_set_value(pkx_g1, GEN_ONE, IV_ATK, pkm_g1_spAtk - 2);
    }
    // GENDER = 1: FEMALE
    else if (gender_g1 == 1)
    {
        pkx_set_value(pkx_g1, GEN_ONE, IV_ATK, pkm_g1_spAtk + 2);
    }

    return gender_determine(pkx_g1, pkx_g3);
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
        case PP: // always in range 0 -> 40
        case PP_UPS:
            break;
        case MOVE: // special case (two values in field)
                   // move: 0 -> 165
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
                int pp = GetMovePPFromGen3ToGen1(skill_id);

                // Remove HM moves
                if (skill_id != 0 &&
                    skill_id != 15 &&
                    skill_id != 19 &&
                    skill_id != 57 &&
                    skill_id != 70 &&
                    skill_id != 127 &&
                    skill_id != 148 &&
                    skill_id < 166)
                {
                    pkx_set_value(pkm_g1,
                                  GEN_ONE,
                                  i_field,
                                  move_count, skill_id);
                    pkx_set_value(pkm_g1,
                                  GEN_ONE,
                                  PP,
                                  move_count, pp);
                    move_count++;
                }
            }
            break;

        case LEVEL:
            int level = pkx_get_value(
                pkm_g3,
                target_gen,
                LEVEL);
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          LEVEL,
                          level > 50 ? level : level);
            break;

        case EV_HP:
        case EV_ATK:
        case EV_DEF:
        case EV_SPATK:
        case EV_SPDEF:
        case EV_SPEED:
            int ev = pkx_get_value(pkm_g3, target_gen, i_field);
            if (target_gen == GEN_THREE)
            {
                ev = ev * ev;
            }
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          i_field,
                          ev);
            break;

        case OT_NAME:
        case TID:
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          TID,
                          pkx_get_value(pkm_g3,
                                        GEN_THREE,
                                        TID));
            pkx_set_value(pkm_g1,
                          GEN_ONE,
                          OT_NAME,
                          pkx_get_value(pkm_g3,
                                        GEN_THREE,
                                        OT_NAME));
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
    // Fix gender
    pkm_g1_atk = gender_determine(pkm_g1, pkm_g3);

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

    gui_warn("This script will convert from \nPKSM Bank (Firered - G3) to Gen 1 (Red/Blue - G1).");

    int bank_current_box = 0;
    int bank_current_slot = 0;
    unsigned int n_mons;

    gui_numpad(&n_mons, "Please Input Number of pokemon you want to convert\ncount from Bank 1 slot 0:", 151);

    gui_splash("Converting please wait...");

    for (int sav_box = 0; sav_box < 12; sav_box++)
    {
        for (int sav_slot = 0; sav_slot < 20; sav_slot++)
        {
            convert_bank3_to_gen1(
                bank_current_box,
                bank_current_slot,
                sav_box,
                sav_slot);

            bank_current_slot++;

            if (bank_current_slot == n_mons)
            {
                gui_warn("Pokémon is converted to Gen 1!");
                return 0;
            }
        }
    }

    return 0;
}