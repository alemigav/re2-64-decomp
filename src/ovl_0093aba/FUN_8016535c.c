/* FUN_8016535c
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x8016535c  body 0x8016535c..0x8016538f  size 52 B
 * body sha256 e3e4a057c5996b313d2544b4ba1f43c5ba4cd4aec791b1da312abcca4a54e34f
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801652DC_ovl_19, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0093aba/8016535c.c
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


extern int (*D_801654CC_overlay_019[])();
void func_801652DC_ovl_19(void *arg0) {
    D_801654CC_overlay_019[(*(u8 *)((s8 *)(arg0) + (5)))]();
}
