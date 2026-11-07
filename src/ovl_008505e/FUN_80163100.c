/* FUN_80163100
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163100  body 0x80163100..0x8016313b  size 60 B
 * body sha256 84ddd7e059f244e8765f4d74bc29e484e690c518e27ae2f5d4536854c88662c3
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80163080_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80163100.c
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

s32 func_801630BC_ovl_12();                         

void func_80163080_ovl_12(void *arg0) {
    if (func_801630BC_ovl_12() != 0) {
        (*(s8 *)((s8 *)(arg0) + (5))) = 2;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x2B9))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x2BA))) = 0;
    }
}
