/* FUN_801621a4
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x801621a4  body 0x801621a4..0x801621eb  size 72 B
 * body sha256 392a54a9380d05fb383920e7ee4260480f1b5e9d55261ff238fa50d5a1e6eb64
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_80162124_ovl_34, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b2d7a/801621a4.c
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
extern Fn D_801625A8_ovl_34[];
void func_80162124_ovl_34(u8 *p, s32 x, s32 y) {
    volatile Fn *table = D_801625A8_ovl_34;
    u32 n = (p[5] - 1) * 9 + p[0x26E];
    table[n](p, x, y);
}
