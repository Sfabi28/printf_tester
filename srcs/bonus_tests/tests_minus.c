#include "srcs/header.h"
#include <limits.h>

void bonus_minus(int mode, int test_id)
{
    int ret = 0;

    // Test 1
    if (test_id == 1)
        TEST("%-10d", 42);

    // Test 2
    else if (test_id == 2)
        TEST("%-10i", -42);

    // Test 3
    else if (test_id == 3)
        TEST("%-10u", 12345);

    // Test 4
    else if (test_id == 4)
        TEST("%-10x", 0xabc);

    // Test 5
    else if (test_id == 5)
        TEST("%-10X", 0XABC);

    // Test 6
    else if (test_id == 6)
        TEST("%-10s", "left");

    // Test 7
    else if (test_id == 7)
        TEST("%-5c", 'L');

    // Test 8
    else if (test_id == 8)
        TEST("%-10%", 0); 

    // Test 9
    else if (test_id == 9)
        TEST("%-10s", ""); 

    // Test 10
    else if (test_id == 10)
        TEST("%-10s", (char *)NULL); 

    // Test 11
    else if (test_id == 11)
        TEST("%-1d", 12345);

    // Test 12
    else if (test_id == 12)
        TEST("%-2s", "longstring");

    // Test 13
    else if (test_id == 13)
        TEST("%-1x", 0xFF);

    // Test 14
    else if (test_id == 14)
        TEST("%-1p", (void *)0x12345);

    // Test 15
    else if (test_id == 15)
        TEST("%-3u", 10000);

    // Test 16
    else if (test_id == 16)
        TEST("%-20p", (void *)0x12345);

    // Test 17
    else if (test_id == 17)
        TEST("%-20p", (void *)0);

    // Test 18
    else if (test_id == 18)
        TEST("%-12d", INT_MAX);

    // Test 19
    else if (test_id == 19)
        TEST("%-12d", INT_MIN);

    // Test 20
    else if (test_id == 20)
        TEST("%-12u", UINT_MAX);

    // Test 21
    else if (test_id == 21)
        TEST("|%-10d|", 42);

    // Test 22
    else if (test_id == 22)
        TEST("|%-10s|", "test");

    // Test 23
    else if (test_id == 23)
        TEST("A %-5c B", 'X');

    // Test 24
    else if (test_id == 24)
        TEST("%-010d", 42); 

    // Test 25
    else if (test_id == 25)
        TEST("%-10s %-10d", "Mix", 123);

    fprintf(stderr, "%d", ret);
}