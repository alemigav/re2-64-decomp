/* FUN_80165ad8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80165ad8  body 0x80165ad8..0x80165b1f  size 72 B
 * body sha256 b3296f41b98f0d4f3e30e3216c87215adede2a044fbaea5bc49f87237084d7a6
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_80165A58_ovl_33, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b08a2/80165ad8.c
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
typedef void (*Fn)(u8 *, s32, s32);
extern Fn D_80167210_ovl_33[];
void func_80165A58_ovl_33(u8 *p, s32 x, s32 y) {
    volatile Fn *table = D_80167210_ovl_33;
    u32 n = (p[5] - 1) * 9 + p[0x26E];
    table[n](p, x, y);
}
