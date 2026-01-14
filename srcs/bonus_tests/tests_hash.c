#include "srcs/header.h"
#include <limits.h>

void bonus_hash(int mode, int test_id)
{
    int ret = 0;

    // Test 76
    if (test_id == 76)
        TEST("%#x", 52);

    // Test 77
    else if (test_id == 77)
        TEST("%#X", 52);

    // Test 78
    else if (test_id == 78)
        TEST("%#x", 0);

    // Test 79
    else if (test_id == 79)
        TEST("%#s", "hello");

    // Test 80
    else if (test_id == 80)
        TEST("%#c", 'd');

    // Test 81
    else if (test_id == 81)
        TEST("%#X", 1);

    // Test 82
    else if (test_id == 82)
        TEST("%#x", 42);

    // Test 83
    else if (test_id == 83)
        TEST("%#X", 42);

    // Test 84
    else if (test_id == 84)
        TEST("%#d", INT_MAX);

    // Test 85
    else if (test_id == 85)
        TEST("%#X", INT_MAX);

    // Test 86
    else if (test_id == 86)
        TEST("%#x", UINT_MAX);

    // Test 87
    else if (test_id == 87)
        TEST("%#5x", 10);

    // Test 88
    else if (test_id == 88)
        TEST("%#5X", 10);

    // Test 89
    else if (test_id == 89)
        TEST("%#4x", 10);

    // Test 90
    else if (test_id == 90)
        TEST("%#4x", 1000);

    // Test 91
    else if (test_id == 91)
        TEST("%#10x", 42);

    // Test 92
    else if (test_id == 92)
        TEST("%#10X", 42);

    // Test 93
    else if (test_id == 93)
        TEST("%#5x", 0);

    // Test 94
    else if (test_id == 94)
        TEST("%#5X", 0);

    // Test 95
    else if (test_id == 95)
        TEST("%#x", -1);

    // Test 96
    else if (test_id == 96)
        TEST("%#X", -1);

    // Test 97
    else if (test_id == 97)
        TEST("%#15x", INT_MAX);

    // Test 98
    else if (test_id == 98)
        TEST("%#2x", 10);

    // Test 99
    else if (test_id == 99)
        TEST("%#3x", 1);

    // Test 100
    else if (test_id == 100)
        TEST("%#11x", INT_MIN);

    fprintf(stderr, "%d", ret);
}