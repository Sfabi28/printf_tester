#include "header.h"
#include <limits.h>

void u_case(int mode, int test_id)
{
    int ret = 0;

    // Test 76
    if (test_id == 76)
        TEST("%u", 42);

    // Test 77
    else if (test_id == 77)
        TEST("%u", -42);

    // Test 78
    else if (test_id == 78)
        TEST("%u", 0);

    // Test 79
    else if (test_id == 79)
        TEST("%u", UINT_MAX);

    // Test 80
    else if (test_id == 80)
        TEST("%u", -1);

    // Test 81
    else if (test_id == 81)
        TEST("%u", 1);

    // Test 82
    else if (test_id == 82)
        TEST("%u", 100);

    // Test 83
    else if (test_id == 83)
        TEST("%u", INT_MAX);

    // Test 84
    else if (test_id == 84)
        TEST("%u", INT_MIN);

    // Test 85
    else if (test_id == 85)
        TEST("%u", (unsigned int)LONG_MAX);

    // Test 86
    else if (test_id == 86)
        TEST("%u", (unsigned int)ULONG_MAX);

    // Test 87
    else if (test_id == 87)
        TEST("%u", 9999);

    // Test 88
    else if (test_id == 88)
        TEST("%u", -9999);

    // Test 89
    else if (test_id == 89)
        TEST("%u %u", 0, -1);

    // Test 90
    else if (test_id == 90)
        TEST("%u", 2147483648u);

    fprintf(stderr, "%d", ret);
}