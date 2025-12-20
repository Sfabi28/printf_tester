#include "header.h"

int main(int argc, char **argv)
{

    if (argc < 4)
        return (1);

    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    int test_id = atoi(argv[2]);
    int mode = (strcmp(argv[1], "orig") != 0);
    char type = argv[3][0];


    if (type == 'm')
    {
        if (test_id <= 15)
            c_case(mode, test_id);      // Tests char
        else if (test_id <= 30)
            s_case(mode, test_id);      // Tests string
        else if (test_id <= 45)
            p_case(mode, test_id);      // Tests pointer
        else if (test_id <= 60)
            d_case(mode, test_id);      // Tests decimal
        else if (test_id <= 75)
            i_case(mode, test_id);      // Tests integer
        else if (test_id <= 90)
            u_case(mode, test_id);      // Tests unsigned
        else if (test_id <= 105)
            x_case(mode, test_id);      // Tests hex lower
        else if (test_id <= 120)
            X_case(mode, test_id);      // Tests hex upper
        else if (test_id <= 130)
            perc_case(mode, test_id);   // Tests percent
        else if (test_id <= 160)
            mix_case(mode, test_id);    // Mixed tests
    }

#ifdef BONUS
    else if (type == 'b')
    {
        if (test_id <= 25)
            bonus_minus(mode, test_id);      // Flag '-'
        else if (test_id <= 50)
            bonus_zero(mode, test_id);       // Flag '0'
        else if (test_id <= 75)
            bonus_dot(mode, test_id);        // Precision '.'
        else if (test_id <= 100)
            bonus_hash(mode, test_id);       // Flag '#'
        else if (test_id <= 125)
            bonus_space(mode, test_id);      // Flag ' '
        else if (test_id <= 150)
            bonus_plus(mode, test_id);       // Flag '+'
        else if (test_id <= 200)
            bonus_combo(mode, test_id);      // Combinazioni multiple
    }
#endif

    return (0);
}