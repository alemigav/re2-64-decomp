/* FUN_80169f84
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80169f84  body 0x80169f84..0x80169fb7  size 52 B
 * body sha256 948b4f4f3518639b7650825e5d2290c31047d07588e2bed999f7a8a6d344e9dc
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80169F04_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/80169f84.c
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


extern int (*D_8016C48C_overlay_031[])();
void func_80169F04_ovl_31(void *arg0) {
    D_8016C48C_overlay_031[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
