#include "header.h"
#include <limits.h>

void bonus_plus(int mode, int test_id)
{
    int ret = 0;

    // Test 126
    if (test_id == 126)
        TEST("%+d", 42);

    // Test 127
    else if (test_id == 127)
        TEST("%+d", -42);

    // Test 128
    else if (test_id == 128)
        TEST("%+i", 42);

    // Test 129
    else if (test_id == 129)
        TEST("%+i", -42);

    // Test 130
    else if (test_id == 130)
        TEST("%+d", 0);

    // Test 131
    else if (test_id == 131)
        TEST("%+i", 0);

    // Test 132
    else if (test_id == 132)
        TEST("%+d", 1);

    // Test 133
    else if (test_id == 133)
        TEST("%+d", -1);

    // Test 134
    else if (test_id == 134)
        TEST("%+10d", 42);

    // Test 135
    else if (test_id == 135)
        TEST("%+10d", -42);

    // Test 136
    else if (test_id == 136)
        TEST("%+2d", 42);

    // Test 137
    else if (test_id == 137)
        TEST("%+2d", -42);

    // Test 138
    else if (test_id == 138)
        TEST("%+5d", 0);

    // Test 139
    else if (test_id == 139)
        TEST("%+d", INT_MAX);

    // Test 140
    else if (test_id == 140)
        TEST("%+d", INT_MIN);

    // Test 141
    else if (test_id == 141)
        TEST("%+i", INT_MAX);

    // Test 142
    else if (test_id == 142)
        TEST("%+i", INT_MIN);

    // Test 143
    else if (test_id == 143)
        TEST("%+3d", 5);

    // Test 144
    else if (test_id == 144)
        TEST("%+3d", -5);

    // Test 145
    else if (test_id == 145)
        TEST("%+4d", 100);

    // Test 146
    else if (test_id == 146)
        TEST("%+4d", -100);

    // Test 147
    else if (test_id == 147)
        TEST("%+1d", 0);

    // Test 148
    else if (test_id == 148)
        TEST("%+d", 9999);

    // Test 149
    else if (test_id == 149)
        TEST("%+d", -9999);

    // Test 150
    else if (test_id == 150)
        TEST("%+15d", INT_MIN);

    fprintf(stderr, "%d", ret);
}