/* FUN_80162f40
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162f40  body 0x80162f40..0x80162f73  size 52 B
 * body sha256 75bbc6afed3de491cd4541c89aa0335c007f6800682145747376501a0c64e354
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80162EC0_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80162f40.c
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


extern int (*D_80167D8C_overlay_017[])();
void func_80162EC0_ovl_17(void *arg0) {
    D_80167D8C_overlay_017[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
