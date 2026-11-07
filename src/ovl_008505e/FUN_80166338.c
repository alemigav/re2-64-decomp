/* FUN_80166338
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166338  body 0x80166338..0x8016636f  size 56 B
 * body sha256 0736cef6f0454741d9c1a242ac81c4d8fbbb2984a3f0817f8abb0240f9a128f4
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801662B8_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80166338.c
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

M2C_UNK func_801662F0_overlay_012();                

void func_801662B8_ovl_12(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (5))) == 0) {
        (*(u8 *)((s8 *)(arg0) + (5))) = 1U;
        (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0))) | 2);
    }
    func_801662F0_overlay_012();
}
