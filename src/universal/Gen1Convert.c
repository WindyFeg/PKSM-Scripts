#include <pksm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_pokemon_red(enum Generation gen, int box, int slot)
{

    char *pkm_temp_gen1 = bank_get_pkx(&gen, 0, 0);
    if (pkm_temp_gen1 == NULL)
    {
        gui_warn("Failed to allocate memory for temporary Pokémon data.");
        return;
    }

    // Retrieve the Pokémon data from the bank
    char *pkm_data = bank_get_pkx(&gen, box, slot);
    char field_id_buffer[50];

    if (pkm_data == NULL)
    {
        gui_warn("Failed to retrieve Pokémon data.");
        free(pkm_temp_gen1);
        return;
    }

    pkx_decrypt(pkm_data, gen, 0);
    pkx_decrypt(pkm_temp_gen1, gen, 0);

    for (int i_field = 0; i_field <= 44; i_field++)
    {
        if (i_field == 6 || i_field == 37 || i_field == 19 | i_field == 38)
        {
            continue;
        }

        if (!pkx_get_value(pkm_temp_gen1, gen, i_field))
        {
            continue;
        }

        snprintf(field_id_buffer, sizeof(field_id_buffer), "Convert : %d", i_field);

        gui_warn(field_id_buffer);

        int i_field_value = pkx_get_value(pkm_data, gen, i_field);
        pkx_set_value(pkm_temp_gen1, gen, i_field, i_field_value);
    }

    pkx_encrypt(pkm_data, gen, 0);
    pkx_encrypt(pkm_temp_gen1, gen, 0);

    bank_inject_pkx(pkm_temp_gen1, gen, 0, 10);

    free(pkm_temp_gen1);

    gui_warn("Pokémon is now ready to be transferred to Gen 1!");
}

void convert_bank_to_gen1()
{
    enum Generation gen = GEN_ONE;
    char *pkm = malloc(pkx_box_size(gen));

    if (pkm == NULL)
    {
        gui_warn("Failed to allocate memory for Pokémon data.");
        return;
    }

    pkx_generate(pkm, 1);

    pkx_set_value(pkm, GEN_ONE, SHINY, 1);
    pkx_set_value(pkm, GEN_ONE, OT_NAME, "PKSM");
    pkx_set_value(pkm, GEN_ONE, MOVE, 0, 100);

    pkx_encrypt(pkm, gen, 0);

    sav_inject_pkx(pkm, gen, 0, 0, 0);

    free(pkm);

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

    // enum Generation gen = GEN_ONE;
    // int box = 0;
    // int slot = 4;

    // convert_to_pokemon_red(gen, box, slot);

    convert_bank_to_gen1();

    return 0;
}