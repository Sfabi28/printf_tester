#include "header.h"
#include <limits.h>

void bonus_zero(int mode, int test_id)
{
    int ret = 0;

    // Test 26
    if (test_id == 26)
        TEST("%03d", 5);

    // Test 27
    else if (test_id == 27)
        TEST("%03d", -5);

    // Test 28
    else if (test_id == 28)
        TEST("%010d", 123);

    // Test 29
    else if (test_id == 29)
        TEST("%010d", -123);

    // Test 30
    else if (test_id == 30)
        TEST("%03d", 1234);

    // Test 31
    else if (test_id == 31)
        TEST("%03d", 0);

    // Test 32
    else if (test_id == 32)
        TEST("%05i", 42);

    // Test 33
    else if (test_id == 33)
        TEST("%05u", 42);

    // Test 34
    else if (test_id == 34)
        TEST("%05x", 42);

    // Test 35
    else if (test_id == 35)
        TEST("%05X", 42);

    // Test 36
    else if (test_id == 36)
        TEST("%05X", 0xABC);

    // Test 37
    else if (test_id == 37)
        TEST("%01d", 0);

    // Test 38
    else if (test_id == 38)
        TEST("%02d", 0);

    // Test 39
    else if (test_id == 39)
        TEST("%015d", INT_MAX);

    // Test 40
    else if (test_id == 40)
        TEST("%015d", INT_MIN);

    // Test 41
    else if (test_id == 41)
        TEST("%05u", 0);

    // Test 42
    else if (test_id == 42)
        TEST("%05x", 0);

    // Test 43
    else if (test_id == 43)
        TEST("%03d", -1);

    // Test 44
    else if (test_id == 44)
        TEST("%04d", 10);

    // Test 45
    else if (test_id == 45)
        TEST("%04d", -10);

    // Test 46
    else if (test_id == 46)
        TEST("%012u", 1000000);

    // Test 47
    else if (test_id == 47)
        TEST("%09x", 0xFFFFFF);

    // Test 48
    else if (test_id == 48)
        TEST("%020d", -9999);

    // Test 49
    else if (test_id == 49)
        TEST("%03d", 100);

    // Test 50
    else if (test_id == 50)
        TEST("%04d", 999);

    fprintf(stderr, "%d", ret);
}