#include "srcs/header.h"
#include <limits.h>

void X_case(int mode, int test_id)
{
    int ret = 0;

    // Test 106
    if (test_id == 106)
        TEST("%X", 42);

    // Test 107
    else if (test_id == 107)
        TEST("%X", -42);

    // Test 108
    else if (test_id == 108)
        TEST("%X", 0);

    // Test 109
    else if (test_id == 109)
        TEST("%X", UINT_MAX);

    // Test 110
    else if (test_id == 110)
        TEST("%X", -1);

    // Test 111
    else if (test_id == 111)
        TEST("%X", 1);

    // Test 112
    else if (test_id == 112)
        TEST("%X", 10);

    // Test 113
    else if (test_id == 113)
        TEST("%X", 16);

    // Test 114
    else if (test_id == 114)
        TEST("%X", 160);

    // Test 115
    else if (test_id == 115)
        TEST("%X", 255);

    // Test 116
    else if (test_id == 116)
        TEST("%X", 0x12AF5); 

    // Test 117
    else if (test_id == 117)
        TEST("%X", 0xDEADBEEF);

    // Test 118
    else if (test_id == 118)
        TEST("%X", INT_MAX);

    // Test 119
    else if (test_id == 119)
        TEST("%X", INT_MIN);

    // Test 120
    else if (test_id == 120)
        TEST("Hex: %X end", 123456);

    fprintf(stderr, "%d", ret);
}