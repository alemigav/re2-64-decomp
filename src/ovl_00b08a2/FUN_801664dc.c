/* FUN_801664dc
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801664dc  body 0x801664dc..0x8016650f  size 52 B
 * body sha256 34f495871337387378553d3f03da40b21852a37f4a73d116bcfb3f48daec6cd9
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_8016645C_ovl_33, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b08a2/801664dc.c
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


extern int (*D_80167248_overlay_033[])();
void func_8016645C_ovl_33(void *arg0) {
    D_80167248_overlay_033[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
