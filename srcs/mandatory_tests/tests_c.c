#include "srcs/header.h"

void c_case(int mode, int test_id)
{
    int ret = 0;

    // Test 1
    if (test_id == 1)
        TEST("%c", 'a');
    
    // Test 2
    else if (test_id == 2)
        TEST("Test: %c done", 'Z');

    // Test 3
    else if (test_id == 3)
        TEST("%c%c%c", '1', '2', '3');

    // Test 4
    else if (test_id == 4)
        TEST("   %c   ", 'A');

    // Test 5
    else if (test_id == 5)
        TEST("%c", 0);

    // Test 6
    else if (test_id == 6)
        TEST("Null %c check", 0);

    // Test 7
    else if (test_id == 7)
        TEST("%c %c %c", 0, 'A', 0);

    // Test 8
    else if (test_id == 8)
        TEST("%c", '\n');

    // Test 9
    else if (test_id == 9)
        TEST("%c", '\t');

    // Test 10
    else if (test_id == 10)
        TEST("%c", '\r');

    // Test 11
    else if (test_id == 11)
        TEST("%c", 65);

    // Test 12
    else if (test_id == 12)
        TEST("%c", 255);

    // Test 13
    else if (test_id == 13)
        TEST("%c", -1);

    // Test 14
    else if (test_id == 14)
        TEST("%c", 127);

    // Test 15
    else if (test_id == 15)
        TEST("%c", 256);

    fprintf(stderr, "%d", ret);
}