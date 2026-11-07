/* FUN_801671dc
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801671dc  body 0x801671dc..0x80167227  size 76 B
 * body sha256 851ece3462f9ff4904c8b6921fd3f049d47edc92c1db5f3af7ec9751f6316b41
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_8016715C_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/801671dc.c
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

void func_8016715C_ovl_31(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x234))) + ((0x13 - (arg1 * 5)) * 0x178);
    (*(s32 *)((s8 *)(temp_a0) + (0x130))) = 0x40;
    (*(s32 *)((s8 *)(temp_a0) + (0x134))) = 0x30;
    (*(s32 *)((s8 *)(temp_a0) + (0))) = (s32) ((*(s32 *)((s8 *)(temp_a0) + (0))) | 0x80);
}
