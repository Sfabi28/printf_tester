#include "srcs/header.h"
#include <limits.h>

void bonus_space(int mode, int test_id)
{
    int ret = 0;

    // Test 101
    if (test_id == 101)
        TEST("% d", 42);

    // Test 102
    else if (test_id == 102)
        TEST("% d", -42);

    // Test 103
    else if (test_id == 103)
        TEST("% i", 123);

    // Test 104
    else if (test_id == 104)
        TEST("% i", -123);

    // Test 105
    else if (test_id == 105)
        TEST("% d", 0);

    // Test 106
    else if (test_id == 106)
        TEST("% d", INT_MAX);

    // Test 107
    else if (test_id == 107)
        TEST("% d", INT_MIN);

    // Test 108
    else if (test_id == 108)
        TEST("% i", INT_MAX);

    // Test 109
    else if (test_id == 109)
        TEST("% i", INT_MIN);

    // Test 110
    else if (test_id == 110)
        TEST("% d", 1);

    // Test 111
    else if (test_id == 111)
        TEST("% d", -1);

    // Test 112
    else if (test_id == 112)
        TEST("% 5d", 42);

    // Test 113
    else if (test_id == 113)
        TEST("% 5d", -42);

    // Test 114
    else if (test_id == 114)
        TEST("% 2d", 42);

    // Test 115
    else if (test_id == 115)
        TEST("% 10d", 12345);

    // Test 116
    else if (test_id == 116)
        TEST("% 10d", -12345);

    // Test 117
    else if (test_id == 117)
        TEST("% 1d", 0);

    // Test 118
    else if (test_id == 118)
        TEST("% 2d", 0);

    // Test 119
    else if (test_id == 119)
        TEST("% 3d", 0);

    // Test 120
    else if (test_id == 120)
        TEST("% 4d", 9);

    // Test 121
    else if (test_id == 121)
        TEST("% 4d", -9);

    // Test 122
    else if (test_id == 122)
        TEST("% d", 99);

    // Test 123
    else if (test_id == 123)
        TEST("% i", 99);

    // Test 124
    else if (test_id == 124)
        TEST("% d", 1000);

    // Test 125
    else if (test_id == 125)
        TEST("% d", -1000);

    fprintf(stderr, "%d", ret);
}