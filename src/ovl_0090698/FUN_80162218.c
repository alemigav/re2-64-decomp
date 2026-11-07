/* FUN_80162218
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162218  body 0x80162218..0x8016224b  size 52 B
 * body sha256 3eeb5c224fbbee1969d391e23539c909b1d9c3e390ecfa28c06c1cca29f8879a
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80162198_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80162218.c
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

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;


extern int (*D_80167D40_overlay_017[])();
void func_80162198_ovl_17(void *arg0) {
    D_80167D40_overlay_017[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
