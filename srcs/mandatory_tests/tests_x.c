#include "srcs/header.h"
#include <limits.h>

void x_case(int mode, int test_id)
{
    int ret = 0;

    // Test 91
    if (test_id == 91)
        TEST("%x", 42);

    // Test 92
    else if (test_id == 92)
        TEST("%x", -42);

    // Test 93
    else if (test_id == 93)
        TEST("%x", 0);

    // Test 94
    else if (test_id == 94)
        TEST("%x", UINT_MAX);

    // Test 95
    else if (test_id == 95)
        TEST("%x", -1);

    // Test 96
    else if (test_id == 96)
        TEST("%x", 1);

    // Test 97
    else if (test_id == 97)
        TEST("%x", 10);

    // Test 98
    else if (test_id == 98)
        TEST("%x", 16);

    // Test 99
    else if (test_id == 99)
        TEST("%x", 160);

    // Test 100
    else if (test_id == 100)
        TEST("%x", 255);

    // Test 101
    else if (test_id == 101)
        TEST("%x", 256);

    // Test 102
    else if (test_id == 102)
        TEST("%x", INT_MAX);

    // Test 103
    else if (test_id == 103)
        TEST("%x", INT_MIN);

    // Test 104
    else if (test_id == 104)
        TEST("Hex: %x end", 123456);

    // Test 105
    else if (test_id == 105)
        TEST("%x %x", 0, -1);

    fprintf(stderr, "%d", ret);
}