/* FUN_80182f78
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80182f78  body 0x80182f78..0x801830cf  size 344 B
 * body sha256 677b44c992a4a7edd053eb9b6d8af937a0a6c02c92e91906e833a86ae1337dd9
 * recovered byte-exact (import by content alignment: 86 of 86 words at our own address (func_80182EF8_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/80182f78.c
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
void func_80182EF8_ovl_02(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
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
            q[7] = (u8)((q[7] + ((b + p[8] + 1) >> 1) + 1) >> 1);
            p += arg2;
            q += arg2;
            i++;
        } while (i < arg3);
    }
}
