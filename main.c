#include "header.h"
#include "ft_printf.h"

int main(int argc, char **argv)
{
    int test_id = atoi(argv[2]);
    int mode;

    if (strcmp(argv[1], "orig") == 0)
        mode = 0;
    else
        mode = 1;
    
    if (test_id <= 15)
        c_case(mode, test_id);
    else if (test_id <= 30)
        s_case(mode, test_id);
    else if (test_id <= 45)
        p_case(mode, test_id);
    else if (test_id <= 60)
        d_case(mode, test_id);
    else if (test_id <= 75)
        i_case(mode, test_id);
    else if (test_id <= 90)
        u_case(mode, test_id);
    else if (test_id <= 105)
        x_case(mode, test_id);
    else if (test_id <= 120)
        X_case(mode, test_id);
    else if (test_id <= 130)
        perc_case(mode, test_id);
    else
        mix_case(mode, test_id);
    
    return (0);
}