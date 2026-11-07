/* FUN_8016250c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016250c  body 0x8016250c..0x80162567  size 92 B
 * body sha256 468ad841528b4223e8d0fda65dc50b0da7a5fa599c8649615c8a6b2fa53d20f5
 * recovered byte-exact (import by content alignment: 23 of 23 words at our own address (func_8016248C_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/8016250c.c
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


extern int (*D_8016C380_overlay_031[])();
void func_8016248C_ovl_31(void *arg0) {
    D_8016C380_overlay_031[(*(u16 *)((s8 *)(arg0) + (0x1AA))) & 0x3F]();
    if (((*(u16 *)((s8 *)(arg0) + (0x2B6))) & 0x180) == 0x100) {
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x03000000;
    }
}
