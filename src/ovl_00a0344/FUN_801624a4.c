/* FUN_801624a4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801624a4  body 0x801624a4..0x801624cf  size 44 B
 * body sha256 2d44d708d27c334eb6f7f8023b67cc2960b215c16b2c6c27b6fe31a59cea9a2f
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_80162424_ovl_27, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a0344/801624a4.c
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

void func_80162424_ovl_27(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (4))) == 1) {
        (*(s8 *)((s8 *)(arg0) + (5))) = 2;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0;
        (*(u8 *)((s8 *)(arg0) + (0x2BF))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x2BF))) & 0x7F);
    }
}
