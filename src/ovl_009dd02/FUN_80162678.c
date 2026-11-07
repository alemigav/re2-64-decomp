/* FUN_80162678
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162678  body 0x80162678..0x801626ab  size 52 B
 * body sha256 15ea29c3e8aff8d71d5eafefdf9138436be879f31b03e7f351f25a6f5725ad5b
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801625F8_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/80162678.c
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

void func_801625F8_ovl_26(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x2D4))) == 0x8000) {
        if ((*(u8 *)((s8 *)(arg0) + (0x2D9))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (4))) = 0x030A0000;
            return;
        }
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x07000000;
    }
}
