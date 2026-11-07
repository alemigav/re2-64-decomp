/* FUN_80162f54
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162f54  body 0x80162f54..0x80162f97  size 68 B
 * body sha256 bfd18e754105c0760814701da896d3febd65e5ff876e551e54a5b2d81a7c58e5
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_80162ED4_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80162f54.c
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

void func_80162ED4_ovl_12(void *arg0, s16 arg1, s16 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x1F4))) = 8;
    (*(s16 *)((s8 *)(arg0) + (0x1E0))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x1E2))) = arg2;
    (*(s32 *)((s8 *)(arg0) + (0x1E8))) = 0x14000700;
    (*(s8 *)((s8 *)(arg0) + (0x2BA))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x2BB))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (((*(s32 *)((s8 *)(arg0) + (0))) & 0xEFFFFFFF) | 0x04000000);
}
