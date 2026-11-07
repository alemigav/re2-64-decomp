/* FUN_80182d00
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182d00  body 0x80182d00..0x80182f77  size 632 B
 * body sha256 2e4b3918a8f2b4960d99fef4575dc7d95f7775f7fd6e27538a1edfd8168e7de4
 * recovered byte-exact (import by content alignment: 158 of 158 words at our own address (func_80182C80_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/80182d00.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
void func_80182C80_ovl_02(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;
    s32 i;
    u32 a;
    u32 b;

    i = 0;
    if (arg3 > 0) {
        p = arg0;
        q = arg1;
        do {
            a = p[0];
            b = p[1];
            q[0] = (u8)((q[0] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[2];
            q[1] = (u8)((q[1] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[3];
            q[2] = (u8)((q[2] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[4];
            q[3] = (u8)((q[3] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[5];
            q[4] = (u8)((q[4] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[6];
            q[5] = (u8)((q[5] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[7];
            q[6] = (u8)((q[6] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[8];
            q[7] = (u8)((q[7] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[9];
            q[8] = (u8)((q[8] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[10];
            q[9] = (u8)((q[9] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[11];
            q[10] = (u8)((q[10] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[12];
            q[11] = (u8)((q[11] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[13];
            q[12] = (u8)((q[12] + ((a + b + 1) >> 1) + 1) >> 1);
            a = p[14];
            q[13] = (u8)((q[13] + ((b + a + 1) >> 1) + 1) >> 1);
            b = p[15];
            q[14] = (u8)((q[14] + ((a + b + 1) >> 1) + 1) >> 1);
            q[15] = (u8)((q[15] + ((b + p[16] + 1) >> 1) + 1) >> 1);
            p += arg2;
            q += arg2;
            i++;
        } while (i < arg3);
    }
}
