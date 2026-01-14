#include "srcs/header.h"
#include <limits.h>

void i_case(int mode, int test_id)
{
    int ret = 0;

    // Test 61
    if (test_id == 61)
        TEST("%i", 42);

    // Test 62
    else if (test_id == 62)
        TEST("%i", -42);

    // Test 63
    else if (test_id == 63)
        TEST("%i", 0);

    // Test 64
    else if (test_id == 64)
        TEST("%i", INT_MAX);

    // Test 65
    else if (test_id == 65)
        TEST("%i", INT_MIN);

    // Test 66
    else if (test_id == 66)
        TEST("%i", 1);

    // Test 67
    else if (test_id == 67)
        TEST("%i", -1);

    // Test 68
    else if (test_id == 68)
        TEST("Val: %i end", 12345);

    // Test 69
    else if (test_id == 69)
        TEST("Start %i Middle %i End", -10, 20);

    // Test 70
    else if (test_id == 70)
        TEST("%i", 007);

    // Test 71
    else if (test_id == 71)
        TEST("%i", 0xFF);

    // Test 72
    else if (test_id == 72)
        TEST("%i%i%i", 1, 2, 3);

    // Test 73
    else if (test_id == 73)
        TEST("%i", -9);

    // Test 74
    else if (test_id == 74)
        TEST("%i", 100000);

    // Test 75
    else if (test_id == 75)
        TEST("%i", -100000);

    fprintf(stderr, "%d", ret);
}