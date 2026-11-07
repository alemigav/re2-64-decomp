/* FUN_80162c6c
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162c6c  body 0x80162c6c..0x80162c8f  size 36 B
 * body sha256 b9c5d6a7757aad51d7149a894fdd4f025008f2c191e0ab717f85c397913680cc
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_80162BEC_ovl_18, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0093192/80162c6c.c
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

void func_80162BEC_ovl_18(void *arg0, s8 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 2;
    (*(s8 *)((s8 *)(arg0) + (5))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (6))) = 0;
    (*(s8 *)((s8 *)(arg0) + (7))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x26F))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x26F))) | 0x80);
}
