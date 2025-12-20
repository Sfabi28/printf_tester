#include "header.h"

void perc_case(int mode, int test_id)
{
    int ret = 0;

    // Test 121
    if (test_id == 121)
        TEST("%%");

    // Test 122
    else if (test_id == 122)
        TEST("%%%%");

    // Test 123
    else if (test_id == 123)
        TEST("Start %% End");

    // Test 124
    else if (test_id == 124)
        TEST("%% Test");

    // Test 125
    else if (test_id == 125)
        TEST("Test %%");

    // Test 126
    else if (test_id == 126)
        TEST("   %%   ");

    // Test 127
    else if (test_id == 127)
        TEST("%% %% %%");

    // Test 128
    else if (test_id == 128)
        TEST("100%%");

    // Test 129
    else if (test_id == 129)
        TEST("%%c");

    // Test 130
    else if (test_id == 130)
        TEST("%%s");

    fprintf(stderr, "%d", ret);
}