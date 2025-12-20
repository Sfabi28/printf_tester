#include "header.h"
#include <limits.h>

void mix_case(int mode, int test_id)
{
    int ret = 0;

    // Test 131
    if (test_id == 131)
        TEST("%c %s", 'A', "String");

    // Test 132
    else if (test_id == 132)
        TEST("%d %x", 42, 42);

    // Test 133
    else if (test_id == 133)
        TEST("%d %u %X", -10, 10, 10);

    // Test 134
    else if (test_id == 134)
        TEST("%c %s %d %i %u %x %X %%", 'Z', "Test", 1, 2, 3, 10, 11);

    // Test 135
    else if (test_id == 135)
        TEST("%d%c%d%c%d", 1, 'A', 2, 'B', 3);

    // Test 136
    else if (test_id == 136)
        TEST("Addr: %p is %s", (void *)0x123, "valid");

    // Test 137
    else if (test_id == 137)
        TEST("%s %p", (char *)NULL, (void *)NULL);

    // Test 138
    else if (test_id == 138)
        TEST("Start %d Middle %s End", 100, "Loop");

    // Test 139
    else if (test_id == 139)
        TEST("Lower: %x Upper: %X", 255, 255);

    // Test 140
    else if (test_id == 140)
        TEST("%% %d %% %s %%", 100, "Percent");

    // Test 141
    else if (test_id == 141)
        TEST("%d %u %x", INT_MIN, UINT_MAX, INT_MAX);

    // Test 142
    else if (test_id == 142)
        TEST("%c %d", 65, 'A');

    // Test 143
    else if (test_id == 143)
        TEST("[%s] %d [%s]", "", 0, "");

    // Test 144
    else if (test_id == 144)
        TEST("%d %i %u %x %X", 0, 0, 0, 0, 0);

    // Test 145
    else if (test_id == 145)
        TEST("%p + %d = %p", (void *)1000, 500, (void *)1500);

    // Test 146
    else if (test_id == 146)
        TEST("User: %s (ID: %d) Access: %p", "Admin", 1, (void *)0x999);

    // Test 147
    else if (test_id == 147)
        TEST("%x %d %x %d", 10, 10, 20, 20);

    // Test 148
    else if (test_id == 148)
        TEST("%u %d", -1, -1);

    // Test 149
    else if (test_id == 149)
        TEST("Lorem %s dolor %d sit %c amet", "ipsum", 42, 'X');

    // Test 150
    else if (test_id == 150)
        TEST("%c %d %x", 'A', 65, 65);

    // Test 151
    else if (test_id == 151)
        TEST("%%%d%%", 10);

    // Test 152
    else if (test_id == 152)
        TEST("%p %s", (void *)-1, (char *)NULL);

    // Test 153
    else if (test_id == 153)
        TEST("%x %d %X", -1, 0, -1);

    // Test 154
    else if (test_id == 154)
        TEST("%d %s %c", 42, "42", '4');

    // Test 155
    else if (test_id == 155)
        TEST("%d %s %d %s", 1, "one", 2, "two");

    // Test 156
    else if (test_id == 156)
        TEST("%d %s %d", 31, "Dec", 2024);

    // Test 157
    else if (test_id == 157)
        TEST("%d:%d %s", 11, 59, "PM");

    // Test 158
    else if (test_id == 158)
        TEST("%x.%d.%x.%d", 192, 168, 1, 1);

    // Test 159
    else if (test_id == 159)
        TEST("%s\t%d\t%p", "Name", 123, (void *)0x1);

    // Test 160
    else if (test_id == 160)
        TEST("%% %c %s %d %i %u %x %X %p %%", '!', "DONE", 1, 2, 3, 4, 5, (void *)0);

    fprintf(stderr, "%d", ret);
}