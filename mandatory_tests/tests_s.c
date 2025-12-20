#include "header.h"

void s_case(int mode, int test_id)
{
    int ret = 0;

    // Test 16
    if (test_id == 16)
        TEST("%s", "Hello");

    // Test 17
    else if (test_id == 17)
        TEST("Test: %s", "World");

    // Test 18
    else if (test_id == 18)
        TEST("%s", "");

    // Test 19
    else if (test_id == 19)
        TEST("Start %s End", "");

    // Test 20
    else if (test_id == 20)
        TEST("%s", (char *)NULL);

    // Test 21
    else if (test_id == 21)
        TEST("%s", "   ");

    // Test 22
    else if (test_id == 22)
        TEST("%s", "123\n\t\r456");

    // Test 23
    else if (test_id == 23)
        TEST("%s %s", "Hello", "World");

    // Test 24
    else if (test_id == 24)
        TEST("%s %s", "", "Test");

    // Test 25
    else if (test_id == 25)
        TEST("%s %s", (char *)NULL, "Test");

    // Test 26
    else if (test_id == 26)
        TEST("%s%s%s", "A", "B", "C");

    // Test 27
    else if (test_id == 27)
        TEST("%s", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

    // Test 28
    else if (test_id == 28)
        TEST("%s", "42");

    // Test 29
    else if (test_id == 29)
        TEST("%s", "Test %s %d");

    // Test 30
    else if (test_id == 30)
        TEST("%s %s", (char *)NULL, (char *)NULL);

    fprintf(stderr, "%d", ret);
}