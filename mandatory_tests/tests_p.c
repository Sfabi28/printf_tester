#include "header.h"
#include <limits.h>

void p_case(int mode, int test_id)
{
    int ret = 0;

    // Test 31
    if (test_id == 31)
        TEST("%p", (void *)1);

    // Test 32
    else if (test_id == 32)
        TEST("%p", (void *)0x12345678);

    // Test 33
    else if (test_id == 33)
        TEST("%p", (void *)0);

    // Test 34
    else if (test_id == 34)
        TEST("%p", (void *)-1);

    // Test 35
    else if (test_id == 35)
        TEST("%p", (void *)ULONG_MAX);

    // Test 36
    else if (test_id == 36)
        TEST("Address: %p end", (void *)0xdeadbeef);

    // Test 37
    else if (test_id == 37)
        TEST("%p %p", (void *)0, (void *)0xabc);

    // Test 38
    else if (test_id == 38)
        TEST("%p", (void *)0x7fffffffffff);

    // Test 39
    else if (test_id == 39)
        TEST("Ptr: %p", (void *)0);

    // Test 40
    else if (test_id == 40)
        TEST("%p", (void *)10);

    // Test 41
    else if (test_id == 41)
        TEST("%p", (void *)-42);

    // Test 42
    else if (test_id == 42)
        TEST("%p", (void *)0x100);

    // Test 43
    else if (test_id == 43)
        TEST("Il puntatore è %p", (void *)0x424242);

    // Test 44
    else if (test_id == 44)
        TEST("%p è l'indirizzo", (void *)0x999);

    // Test 45
    else if (test_id == 45)
        TEST("%p%p%p", (void *)1, (void *)2, (void *)3);

    fprintf(stderr, "%d", ret);
}