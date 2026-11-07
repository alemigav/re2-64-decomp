/* FUN_8016518c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016518c  body 0x8016518c..0x801651bf  size 52 B
 * body sha256 433f25b8b97f17d00dd6356f91898da8393f5cb75cd31e07e54aa5452aded84a
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_8016510C_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/8016518c.c
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


extern int (*D_801667B0_overlay_035[])();
void func_8016510C_ovl_35(void *arg0) {
    D_801667B0_overlay_035[(*(u8 *)((s8 *)(arg0) + (6)))]();
}
