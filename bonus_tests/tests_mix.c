#include "header.h"
#include <limits.h>

void bonus_combo(int mode, int test_id)
{
    int ret = 0;

    // Test 151
    if (test_id == 151)
        TEST("%-+10d", 42);

    // Test 152
    else if (test_id == 152)
        TEST("%-+10d", -42);

    // Test 153
    else if (test_id == 153)
        TEST("%-+5i", 0);

    // Test 154
    else if (test_id == 154)
        TEST("%-+2d", 42);

    // Test 155
    else if (test_id == 155)
        TEST("%-+15d", INT_MAX);

    // Test 156
    else if (test_id == 156)
        TEST("%- 10d", 42);

    // Test 157
    else if (test_id == 157)
        TEST("%- 10d", -42);

    // Test 158
    else if (test_id == 158)
        TEST("%- 5i", 0);

    // Test 159
    else if (test_id == 159)
        TEST("%- 10d", INT_MIN);

    // Test 160
    else if (test_id == 160)
        TEST("%- 2d", 123);

    // Test 161
    else if (test_id == 161)
        TEST("%+010d", 42);

    // Test 162
    else if (test_id == 162)
        TEST("%+010d", -42);

    // Test 163
    else if (test_id == 163)
        TEST("%+05d", 0);

    // Test 164
    else if (test_id == 164)
        TEST("%+03d", 1);

    // Test 165
    else if (test_id == 165)
        TEST("%+012i", INT_MAX);

    // Test 166
    else if (test_id == 166)
        TEST("% 010d", 42);

    // Test 167
    else if (test_id == 167)
        TEST("% 010d", -42);

    // Test 168
    else if (test_id == 168)
        TEST("% 05d", 0);

    // Test 169
    else if (test_id == 169)
        TEST("% 04d", 12345);

    // Test 170
    else if (test_id == 170)
        TEST("% 012d", INT_MIN);

    // Test 171
    else if (test_id == 171)
        TEST("%010.5d", 42);

    // Test 172
    else if (test_id == 172)
        TEST("%010.5d", -42);

    // Test 173
    else if (test_id == 173)
        TEST("%05.5d", 42);

    // Test 174
    else if (test_id == 174)
        TEST("%05.0d", 0);

    // Test 175
    else if (test_id == 175)
        TEST("%010.2d", 5);

    // Test 176
    else if (test_id == 176)
        TEST("%#010x", 42);

    // Test 177
    else if (test_id == 177)
        TEST("%#010X", 42);

    // Test 178
    else if (test_id == 178)
        TEST("%#04x", 42);

    // Test 179
    else if (test_id == 179)
        TEST("%#010x", 0);

    // Test 180
    else if (test_id == 180)
        TEST("%#05x", 1);

    // Test 181
    else if (test_id == 181)
        TEST("%#-10x", 42);

    // Test 182
    else if (test_id == 182)
        TEST("%#-10X", 42);

    // Test 183
    else if (test_id == 183)
        TEST("%#-5x", 1000);

    // Test 184
    else if (test_id == 184)
        TEST("%#-10x", 0);

    // Test 185
    else if (test_id == 185)
        TEST("%#-8x", UINT_MAX);

    // Test 186
    else if (test_id == 186)
        TEST("%-010d", 42);

    // Test 187
    else if (test_id == 187)
        TEST("%+ d", 42);

    // Test 188
    else if (test_id == 188)
        TEST("% +d", 42);

    // Test 189
    else if (test_id == 189)
        TEST("%-010.5d", 42);

    // Test 190
    else if (test_id == 190)
        TEST("%+0-10d", 42);

    // Test 191
    else if (test_id == 191)
        TEST("%#0.0x", 0);

    // Test 192
    else if (test_id == 192)
        TEST("% .d", 0);

    // Test 193
    else if (test_id == 193)
        TEST("%+.d", 0);

    // Test 194
    else if (test_id == 194)
        TEST("%+10.0d", 0);

    // Test 195
    else if (test_id == 195)
        TEST("%#.5x", 1);

    // Test 196
    else if (test_id == 196)
        TEST("%-10.5s", "test");

    // Test 197
    else if (test_id == 197)
        TEST("%05d", INT_MIN);

    // Test 198
    else if (test_id == 198)
        TEST("Mix1: [%-+10d] [%#010x] [% .5i] [%-10s] End", 42, 0xABC, -123, "Hello");

    // Test 199
    else if (test_id == 199)
        TEST("Mix2: %020.10d | %#-10.5X | %-20p | %+d", INT_MIN, 0xFF, (void *)0x1234, 0);

    // Test 200
    else if (test_id == 200)
        TEST("Ultimate: %-+20.10d % #020x %05.2u %-5c %% %s", -987654321, 0x123ABC, 99, 'A', "FINITO");

    fprintf(stderr, "%d", ret);
}