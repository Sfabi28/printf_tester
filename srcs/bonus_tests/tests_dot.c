#include "srcs/header.h"
#include <limits.h>

void bonus_dot(int mode, int test_id)
{
    int ret = 0;

    // Test 51
    if (test_id == 51)
        TEST("%.5d", 42);

    // Test 52
    else if (test_id == 52)
        TEST("%.5d", -42);

    // Test 53
    else if (test_id == 53)
        TEST("%.3d", 12345);

    // Test 54
    else if (test_id == 54)
        TEST("%.0d", 0);

    // Test 55
    else if (test_id == 55)
        TEST("%.0d", 42);

    // Test 56
    else if (test_id == 56)
        TEST("%.10u", 42);

    // Test 57
    else if (test_id == 57)
        TEST("%.5x", 0xff);

    // Test 58
    else if (test_id == 58)
        TEST("%.5X", 0xff);

    // Test 59
    else if (test_id == 59)
        TEST("%.3s", "mamma");

    // Test 60
    else if (test_id == 60)
        TEST("%.10s", "ciao");

    // Test 61
    else if (test_id == 61)
        TEST("%.s", "test");

    // Test 62
    else if (test_id == 62)
        TEST("%.0s", "test");

    // Test 63
    else if (test_id == 63)
        TEST("%.3s", (char *)NULL);

    // Test 64
    else if (test_id == 64)
        TEST("%.d", 10);

    // Test 65
    else if (test_id == 65)
        TEST("%.10d", INT_MAX);

    // Test 66
    else if (test_id == 66)
        TEST("%.10d", INT_MIN);

    // Test 67
    else if (test_id == 67)
        TEST("%10.5d", 42);

    // Test 68
    else if (test_id == 68)
        TEST("%10.3s", "banana");

    // Test 69
    else if (test_id == 69)
        TEST("%10.5d", -42);

    // Test 70
    else if (test_id == 70)
        TEST("%.5d", 0);

    // Test 71
    else if (test_id == 71)
        TEST("%.20d", -1);

    // Test 72
    else if (test_id == 72)
        TEST("%.20u", -1);

    // Test 73
    else if (test_id == 73)
        TEST("%.20x", -1);

    // Test 74
    else if (test_id == 74)
        TEST("%.2s", "");

    // Test 75
    else if (test_id == 75)
        TEST("%.3d", -123);

    fprintf(stderr, "%d", ret);
}