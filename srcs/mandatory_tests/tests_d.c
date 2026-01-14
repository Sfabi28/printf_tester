#include "srcs/header.h"
#include <limits.h>

void d_case(int mode, int test_id)
{
    int ret = 0;

    // Test 46
    if (test_id == 46)
        TEST("%d", 42);

    // Test 47
    else if (test_id == 47)
        TEST("%d", -42);

    // Test 48
    else if (test_id == 48)
        TEST("%d", 0);

    // Test 49
    else if (test_id == 49)
        TEST("%d", INT_MAX);

    // Test 50
    else if (test_id == 50)
        TEST("%d", INT_MIN);

    // Test 51
    else if (test_id == 51)
        TEST("%d", 1);

    // Test 52
    else if (test_id == 52)
        TEST("%d", -1);

    // Test 53
    else if (test_id == 53)
        TEST("Value: %d end", 12345);

    // Test 54
    else if (test_id == 54)
        TEST("Start %d Middle %d End", -10, 20);

    // Test 55
    else if (test_id == 55)
        TEST("%d", 100);

    // Test 56
    else if (test_id == 56)
        TEST("%d", -100);

    // Test 57
    else if (test_id == 57)
        TEST("%d %d", INT_MAX, INT_MIN);

    // Test 58
    else if (test_id == 58)
        TEST("%d", 9999);

    // Test 59
    else if (test_id == 59)
        TEST("%d", -9999);

    // Test 60
    else if (test_id == 60)
        TEST("%d%d%d", 0, 42, -42);

    fprintf(stderr, "%d", ret);
}