#include "header.h"

int main(int argc, char **argv)
{
    if (argc < 4)
        return (1);

    int test_id = atoi(argv[2]);
    int mode = (strcmp(argv[1], "orig") != 0);
    char type = argv[3][0];

    if (type == 'm')
    {
        if (test_id <= 15) c_case(mode, test_id);
        else if (test_id <= 30) s_case(mode, test_id);
        else if (test_id <= 45) p_case(mode, test_id);
        else if (test_id <= 60) d_case(mode, test_id);
        else if (test_id <= 75) i_case(mode, test_id);
        else if (test_id <= 90) u_case(mode, test_id);
        else if (test_id <= 105) x_case(mode, test_id);
        else if (test_id <= 120) X_case(mode, test_id);
        else if (test_id <= 130) perc_case(mode, test_id);
        else if (test_id <= 160) mix_case(mode, test_id);
    }
#ifdef BONUS
    else if (type == 'b')
    {
        if (test_id <= 25) bonus_minus(mode, test_id);
        else if (test_id <= 50) bonus_zero(mode, test_id);
        else if (test_id <= 75) bonus_dot(mode, test_id);
        else if (test_id <= 100) bonus_hash(mode, test_id);
        else if (test_id <= 125) bonus_space(mode, test_id);
        else if (test_id <= 150) bonus_plus(mode, test_id);
        else bonus_combo(mode, test_id);
    }
#endif
    
    return (0);
}