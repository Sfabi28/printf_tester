#include "header.h"

void p_case(int mode, int test_id)
{
    int ret = 0;
    int a = 42;
    char *str = "Test";

    // Test 31
    if (test_id == 31)
        TEST("%p", &a);

    // Test 32
    else if (test_id == 32)
        TEST("%p", str);

    // Test 33
    else if (test_id == 33)
        TEST("Address: %p", &ret);

    // Test 34
    else if (test_id == 34)
        TEST("%p", (void *)NULL);

    // Test 35
    else if (test_id == 35)
        TEST("%p", (void *)0);

    // Test 36
    else if (test_id == 36)
        TEST("%p", (void *)1);

    // Test 37
    else if (test_id == 37)
        TEST("%p", (void *)-1);

    // Test 38
    else if (test_id == 38)
        TEST("%p %p", &a, str);

    // Test 39
    else if (test_id == 39)
        TEST("%p %p", (void *)NULL, &a);

    // Test 40
    else if (test_id == 40)
        TEST("The address is %p inside.", &a);

    // Test 41
    else if (test_id == 41)
        TEST("%p%p%p", &a, &ret, str);

    // Test 42
    else if (test_id == 42)
        TEST("%p", (void *)0x7fffffffffff);

    // Test 43
    else if (test_id == 43)
        TEST("%p", (void *)0x12345678);

    // Test 44
    else if (test_id == 44)
        TEST("%p %p", &a, (void *)NULL);

    // Test 45
    else if (test_id == 45)
        TEST("%p", &p_case);

    fprintf(stderr, "%d", ret);
}