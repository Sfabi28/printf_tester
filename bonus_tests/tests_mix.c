#include "header.h"
#include <limits.h>

void bonus_combo(int mode, int test_id)
{
    int ret = 0;

    // TEST: 151
    if (test_id == 151)
        TEST("%-+10d", 42);

    // TEST: 152
    else if (test_id == 152)
        TEST("%-+10d", -42);

    // TEST: 153
    else if (test_id == 153)
        TEST("%-+5i", 0);

    // TEST: 154
    else if (test_id == 154)
        TEST("%- 10d", 42);

    // TEST: 155
    else if (test_id == 155)
        TEST("%- 10d", -42);

    // TEST: 156
    else if (test_id == 156)
        TEST("%-010d", 42);

    // TEST: 157
    else if (test_id == 157)
        TEST("%+010d", 42);

    // TEST: 158
    else if (test_id == 158)
        TEST("%+010d", -42);

    // TEST: 159
    else if (test_id == 159)
        TEST("% 010d", 42);

    // TEST: 160
    else if (test_id == 160)
        TEST("% 010d", -42);

    // TEST: 161
    else if (test_id == 161)
        TEST("%10.5d", 42);

    // TEST: 162
    else if (test_id == 162)
        TEST("%10.5d", -42);

    // TEST: 163
    else if (test_id == 163)
        TEST("%10.0d", 0);

    // TEST: 164
    else if (test_id == 164)
        TEST("%-10.5d", 42);

    // TEST: 165
    else if (test_id == 165)
        TEST("%-10.5d", -42);

    // TEST: 166
    else if (test_id == 166)
        TEST("%#10x", 42);

    // TEST: 167
    else if (test_id == 167)
        TEST("%#10X", 42);

    // TEST: 168
    else if (test_id == 168)
        TEST("%#010x", 42);

    // TEST: 169
    else if (test_id == 169)
        TEST("%#010X", 42);

    // TEST: 170
    else if (test_id == 170)
        TEST("%#-10x", 42);

    // TEST: 171
    else if (test_id == 171)
        TEST("%#.5x", 255);

    // TEST: 172
    else if (test_id == 172)
        TEST("%-10s", "test");

    // TEST: 173
    else if (test_id == 173)
        TEST("%10.3s", "hello");

    // TEST: 174
    else if (test_id == 174)
        TEST("%-10.5s", "testing");

    // TEST: 175
    else if (test_id == 175)
        TEST("%+10d", 42);

    // TEST: 176
    else if (test_id == 176)
        TEST("%+10d", -42);

    // TEST: 177
    else if (test_id == 177)
        TEST("% 10d", 42);

    // TEST: 178
    else if (test_id == 178)
        TEST("% 10d", -42);

    // TEST: 179
    else if (test_id == 179)
        TEST("%-010d", 42);

    // TEST: 180
    else if (test_id == 180)
        TEST("%+.5d", 42);

    // TEST: 181
    else if (test_id == 181)
        TEST("% .5d", 42);

    // TEST: 182
    else if (test_id == 182)
        TEST("%#x", 0);

    // TEST: 183
    else if (test_id == 183)
        TEST("%#10x", 0);

    // TEST: 184
    else if (test_id == 184)
        TEST("%#-8x", 255);

    // TEST: 185
    else if (test_id == 185)
        TEST("%+05d", 42);

    // TEST: 186
    else if (test_id == 186)
        TEST("% 05d", 42);

    // TEST: 187
    else if (test_id == 187)
        TEST("%-+10d", 42);

    // TEST: 188
    else if (test_id == 188)
        TEST("%- 10d", 42);

    // TEST: 189
    else if (test_id == 189)
        TEST("%-10.5d", 42);

    // TEST: 190
    else if (test_id == 190)
        TEST("%#-10x", 42);

    // TEST: 191
    else if (test_id == 191)
        TEST("%-15.7s", "printf");

    // TEST: 192
    else if (test_id == 192)
        TEST("%-05d", 123);

    // TEST: 193
    else if (test_id == 193)
        TEST("%+05d", 42);

    // TEST: 194
    else if (test_id == 194)
        TEST("% 05d", 42);

    // TEST: 195
    else if (test_id == 195)
        TEST("%+.5d", 42);

    // TEST: 196
    else if (test_id == 196)
        TEST("% .5d", 42);

    // TEST: 197
    else if (test_id == 197)
        TEST("%-10x", 255);

    // TEST: 198
    else if (test_id == 198)
        TEST("%10.5u", 42);

    // TEST: 199
    else if (test_id == 199)
        TEST("%#10.5x", 255);

    // TEST: 200
    else if (test_id == 200)
        TEST("%-+15d", INT_MAX);

    fprintf(stderr, "%d", ret);
}