/* FUN_801654f8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801654f8  body 0x801654f8..0x8016552b  size 52 B
 * body sha256 05387c070e5fb3ec7b0902913f8be083e35e25d053ee80e6933f435d63568560
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80165478_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/801654f8.c
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


extern int (*D_801667BC_overlay_035[])();
void func_80165478_ovl_35(void *arg0) {
    D_801667BC_overlay_035[(*(u8 *)((s8 *)(arg0) + (6)))]();
}
