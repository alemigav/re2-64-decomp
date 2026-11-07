/* FUN_80168ab0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80168ab0  body 0x80168ab0..0x80168ae3  size 52 B
 * body sha256 3149fb78dc9517edd69eddb58b15c414597fb1800cb0ba2a6ffd8c1307eb93e4
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80168A30_ovl_29, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a43b6/80168ab0.c
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


extern int (*D_80169850_overlay_029[])();
void func_80168A30_ovl_29(void *arg0) {
    D_80169850_overlay_029[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
