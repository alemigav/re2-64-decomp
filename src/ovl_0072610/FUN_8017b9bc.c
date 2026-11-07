/* FUN_8017b9bc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b9bc  body 0x8017b9bc..0x8017b9eb  size 48 B
 * body sha256 3fb65108a7ca8c53047a68af1168c01fde5fcd1b3f0a0403f2890cba74e82435
 * recovered byte-exact (read from the words (M370): 12 of 12, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017b9bc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 FUN_8017b98c(void);

u32 FUN_8017b9bc(void)
{
    u32 a = FUN_8017b98c();
    u32 b = FUN_8017b98c();

    return (a << 16) | b;
}
