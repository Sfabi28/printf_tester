#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);

# define TEST(F, ...) \
    do { \
        if (mode == 0) \
            ret = printf(F, ##__VA_ARGS__); \
        else \
            ret = ft_printf(F, ##__VA_ARGS__); \
    } while (0)

void c_case(int mode, int test_id);
void s_case(int mode, int test_id);
void p_case(int mode, int test_id);
void d_case(int mode, int test_id);
void i_case(int mode, int test_id);
void u_case(int mode, int test_id);
void x_case(int mode, int test_id);
void X_case(int mode, int test_id);
void perc_case(int mode, int test_id);
void mix_case(int mode, int test_id);

void bonus_minus(int mode, int test_id);
void bonus_zero(int mode, int test_id);
void bonus_dot(int mode, int test_id);
void bonus_hash(int mode, int test_id);
void bonus_space(int mode, int test_id);
void bonus_plus(int mode, int test_id);
void bonus_combo(int mode, int test_id);

#endif